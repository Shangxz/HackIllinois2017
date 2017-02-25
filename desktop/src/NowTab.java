import processing.core.PApplet;
import processing.core.PConstants;
import processing.core.PImage;

/**
 * Created by David Sun on 2/25/2017.
 */
public class NowTab extends Tab{
    float total, radius;
    float emotions[][] = new float[3][8];

    int index = 0;

    public NowTab(TabFrame frame){
        super(frame);
        radius = height * 0.35f;

        float temp[] = {1, 1, 1, 1, 1, 1, 1, 1};
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
        if(x < height / 2 - radius * 1.5 || x > height / 2 + radius * 1.5
                || y < 0 || y > radius * 3)
            return;

        float dX = x - height / 2;
        float dY = y - radius;

        float theta = PApplet.atan(dY / dX);
        if((dX < 0)) {
            theta -= PApplet.PI;
        }
        if(theta < 0)
            theta += PApplet.TAU;

        for(int i = 0; i < emotions[0].length; i ++){
            if(theta > emotions[1][i] && theta <= emotions[2][i])
                index = i;
        }
    }

    public void render(PApplet pApplet){
        pApplet.ellipse(height / 2, radius, 2 * radius, 2 * radius);

        float cur = 0;
        for(int i = 0; i < emotions[0].length; i ++){
            if(index == i){
                pApplet.fill(255, 0, 0);
                pApplet.arc(height / 2, radius, 2.5f * radius, 2.5f * radius,
                        emotions[1][i],
                        emotions[2][i],
                        PConstants.PIE);
            }
            else {
                pApplet.fill(200);
                pApplet.arc(height / 2, radius, 2 * radius, 2 * radius,
                        emotions[1][i],
                        emotions[2][i],
                        PConstants.PIE);
            }
        }
    }

    public boolean onMouseDown(float x, float y){
        float dX = x - height / 2;
        float dY = y - radius;
        float h = PApplet.sqrt(dX*dX + dY*dY);
        //if(h > radius)
        //return;

        return false;
    }
}
