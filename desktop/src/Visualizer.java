/**
 * Created by David Sun on 2/25/2017.
 */
import processing.core.*;

public class Visualizer extends PApplet{
    //self object for gui elements to grab
    private static Visualizer visualizer;

    //Internal frame to standardize display size
    VFrame vFrame;

    float frameWidth, frameHeight;

    public static void main(String[] args) {
        PApplet.main("Visualizer");
    }

    public static Visualizer getVisualizer(){
        return visualizer;
    }

    public void settings(){
        //fullScreen(P2D);
        size(1920, 1080, P2D);
    }

    public void setup(){
        visualizer = this;

        frameWidth = width * 0.85f;
        frameHeight = height * 0.70f;
        vFrame = new VFrame(this,
                (this.width - frameWidth)/2, (this.height - frameHeight)/2);

        textAlign(PConstants.CENTER, PConstants.CENTER);
    }

    public void draw(){
        //Render background
        background(VisualConstants.BACKGROUND_COLOR);

        //Update all elements
        vFrame.update(this, mouseX - vFrame.x, mouseY - vFrame.y);

        //Render main frame in center of screen
        pushMatrix();
        translate(vFrame.x, vFrame.y);
        vFrame.render(this);
        popMatrix();

        //framerate
        /*
        fill(255);
        text(frameRate, 100, 100);
        */
    }

    public void mousePressed(){
        vFrame.onMouseDown(mouseX - vFrame.x, mouseY - vFrame.y);
    }

    public void mouseReleased(){
        vFrame.onMouseUp(mouseX - vFrame.x, mouseY - vFrame.y);
    }
}
