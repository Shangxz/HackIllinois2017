import processing.core.PApplet;
import processing.core.PConstants;

/**
 * Created by David Sun on 2/25/2017.
 */
public class PieChart extends VInteractable {
    private float radius, animation;
    private NowTab nowTab;

    float emotions[][] = new float[3][6];
    private float total;

    long lastUpdate = 0;
    boolean toggle = true;

    public PieChart(NowTab nowTab, float x, float y, float r){
        this.x = x;
        this.y = y;
        this.radius = r;
        this.nowTab = nowTab;

        //Calculate emotion information
        float temp[] = {1, 5, 8, 4, 3, 7};
        emotions[0] = temp;
        for(float f : emotions[0])
            total += f;
        float cur = 0;
        for(int i = 0; i < emotions[0].length; i ++){
            emotions[1][i] = cur / total * PApplet.TAU;
            emotions[2][i] = (cur + emotions[0][i]) / total * PApplet.TAU;
            cur += emotions[0][i];
        }
    }

    public void update(PApplet pApplet, float x, float y){
        //update the animations
        if(animation >= 0 && animation < 1)
            animation += 0.1;

        if(x < - radius * 1.5 || x > radius * 1.5
                || y < - radius * 1.5 || y > radius * 1.5)
            return;

        float dX = x - height / 2;

        float theta = PApplet.atan(y / dX);
        if((dX < 0)) {
            theta -= PApplet.PI;
        }
        if(theta < 0)
            theta += PApplet.TAU;

        for(int i = 0; i < emotions[0].length; i ++){
            if(theta > emotions[1][i] && theta <= emotions[2][i]) {
                if(nowTab.index != i) {
                    animation = 0;
                    nowTab.triggerAnimation(i);
                }
                break;
            }
        }

        //every few seconds, update the emotions
        if(toggle && pApplet.millis() - lastUpdate > 500){
            updateEmotions(pApplet);
            lastUpdate = pApplet.millis();
        }
    }

    public void render(PApplet pApplet) {
        pApplet.stroke(100);
        for (int i = 0; i < emotions[0].length; i++) {
            if (nowTab.index == i) {
                pApplet.fill(VisualConstants.CONTRAST_COLOR);
                pApplet.arc(0, 0,
                        (2 + 0.5f * animation) * radius,
                        (2 + 0.5f * animation) * radius,
                        emotions[1][i],
                        emotions[2][i],
                        PConstants.PIE);
            } else {
                pApplet.fill(VisualConstants.HIGHLIGHT_COLOR);
                pApplet.arc(0, 0, 2 * radius, 2 * radius,
                        emotions[1][i],
                        emotions[2][i],
                        PConstants.PIE);
            }
        }
    }

    public void updateEmotions(PApplet pApplet){
        //grab the now tab
        NowTab now = ((NowTab)Visualizer.getVisualizer().vFrame.tabFrame.interactables.get(0));

        //randomly change new values, update stats
        total = 0;
        float max = emotions[0][0];
        int maxIndex = 0;
        for(int i = 0; i < emotions[0].length; i ++){
            emotions[0][i] += pApplet.random(emotions[0][i] / 10) - emotions[0][i] / 20;
            now.stats[i].value = emotions[0][i];
            total += emotions[0][i];
            if(emotions[0][i] > max) {
                max = emotions[0][i];
                maxIndex = i;
            }
        }

        //update sections of the pie chart
        float cur = 0;
        for(int i = 0; i < emotions[0].length; i ++){
            emotions[1][i] = cur / total * PApplet.TAU;
            emotions[2][i] = (cur + emotions[0][i]) / total * PApplet.TAU;
            cur += emotions[0][i];
        }

        //set top emotions
        now.topEmotion = now.stats[maxIndex].name;
    }

    public boolean onMouseDown(float x, float y){
        toggle = !toggle;
        return false;
    }
}
