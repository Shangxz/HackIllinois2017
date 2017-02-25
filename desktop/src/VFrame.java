import processing.core.PApplet;

import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
public class VFrame extends VContainer{

    public VFrame(Visualizer visualizer, float x, float y){
        //get width and height from Visualizer
        width = visualizer.frameWidth;
        height = visualizer.frameHeight;

        this.x = x;
        this.y = y;

        interactables = new ArrayList<>();
        interactables.add(new TabBar(this, 0, 0));
    }

    public void update() {
        //check mouse position

        //refresh data
    }

    public void render(PApplet pApplet) {
        pApplet.fill(0, 0);
        pApplet.stroke(255);
        pApplet.rect(0, 0, width, height, 40);

        for(VInteractable i : interactables){
            i.render(pApplet);
        }
    }
}
