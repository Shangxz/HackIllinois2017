/**
 * Created by David Sun on 2/25/2017.
 */
import processing.core.*;

public class Visualizer extends PApplet{
    //Internal frame to standardize display size
    private VFrame vFrame;

    float frameWidth, frameHeight;

    private int bottom = VisualConstants.BACKGROUND_GRADIENT_BOTTOM,
            top = VisualConstants.BACKGROUND_GRADIENT_TOP;

    public static void main(String[] args) {
        PApplet.main("Visualizer");
    }

    public void renderBackground(){
        //Render background gradient from bottom to top
        for (int i = 0; i < displayHeight; i++) {
            float inter = map(i, 0, displayHeight, 0, 1);
            int c = lerpColor(top, bottom, inter);
            stroke(c);
            line(0, i, displayWidth, i);
        }
    }

    public void settings(){
        //fullScreen();
        size(1500, 1000);
    }

    public void setup(){
        frameWidth = width * 0.70f;
        frameHeight = height * 0.70f;
        vFrame = new VFrame(this,
                (this.width - frameWidth)/2, (this.height - frameHeight)/2);
    }

    public void draw(){
        //Render background
        renderBackground();

        //Update all elements
        //vFrame.update(this);

        //Render main frame in center of screen
        pushMatrix();
        translate(vFrame.x, vFrame.y);
        vFrame.render(this);
        popMatrix();
    }

    public void mousePressed(){
        vFrame.onMouseDown(mouseX - vFrame.x, mouseY - vFrame.y);
    }

    public void mouseReleased(){
        vFrame.onMouseUp(mouseX - vFrame.x, mouseY - vFrame.y);
    }
}
