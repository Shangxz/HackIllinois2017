import processing.core.PApplet;
import processing.core.PConstants;
import processing.core.PImage;

/**
 * Created by David Sun on 2/25/2017.
 */
public class NowTab extends Tab{
    int index = 0;
    int animation = -1;

    EmotionStat[] stats = new EmotionStat[6];
    EmotionStat currentStat;
    PieChart pieChart;

    public NowTab(TabFrame frame){
        super(frame);

        pieChart = new PieChart(this, height / 2, height * 0.35f, height * 0.35f);
        interactables.add(pieChart);

        for(int i = 0; i < stats.length; i ++) {
            stats[i] = new EmotionStat(this, "Emotion #" + (i + 1), pieChart.emotions[0][i],
                    "Filler text. Something will go here soon.");
            stats[i].x = height;
            stats[i].y = 0;
        }
        currentStat = stats[0];
    }

    public void update(PApplet pApplet, float x, float y){
        super.update(pApplet, x, y);
    }

    public void render(PApplet pApplet) {
        for(VInteractable i : interactables){
            pApplet.pushMatrix();
            pApplet.translate(i.x, i.y);
            i.render(pApplet);
            pApplet.popMatrix();
        }

        if(animation >= 0 && animation < 10) {
            animation++;
            currentStat.y -= 10;
        }

        pApplet.pushMatrix();
        pApplet.translate(currentStat.x, currentStat.y);
        currentStat.render(pApplet);
        pApplet.popMatrix();
    }

    public void triggerAnimation(int i){
        index = i;
        animation = 0;
        currentStat = stats[i];
        currentStat.y = 100;
    }
}
