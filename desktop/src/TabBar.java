import processing.core.PApplet;

import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
public class TabBar extends VContainer {
    int buttonCount;

    public TabBar(VFrame frame, float x, float y){
        this.x = x;
        this.y = y;

        width = frame.width * 0.3f;
        height = frame.height;

        buttonCount = 2;
        interactables = new ArrayList<>();
        interactables.add(new TabButton(this, "Test Button",
                width * 0.1f, height * 0.3f));
    }

    public void update(){

    }

    public void render(PApplet pApplet){
        pApplet.pushMatrix();
        for(int i = 0; i < interactables.size(); i ++){
            if(interactables.get(i) != null){
                pApplet.translate(0, height / buttonCount * i);
                interactables.get(i).render(pApplet);
            }
        }
        pApplet.popMatrix();
    }
}
