import processing.core.PApplet;

import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
public class VFrame extends VContainer{
    private TabFrame tabFrame;

    public VFrame(Visualizer visualizer, float x, float y){
        //get width and height from Visualizer
        width = visualizer.frameWidth;
        height = visualizer.frameHeight;

        this.x = x;
        this.y = y;

        interactables = new ArrayList<>();
        interactables.add(new NavBar(this, 0, 0));
        tabFrame = new TabFrame(this, width * 0.25f, 0);
        interactables.add(tabFrame);
    }

    public void changeTab(int n){
        tabFrame.changeTab(n);
    }

    public void render(PApplet pApplet) {

        pApplet.fill(0, 0);
        pApplet.stroke(255);
        pApplet.rect(0, 0, width, height, 40);


        for(VInteractable i : interactables){
            pApplet.pushMatrix();
            pApplet.translate(i.x, i.y);
            i.render(pApplet);
            pApplet.popMatrix();
        }
    }
}
