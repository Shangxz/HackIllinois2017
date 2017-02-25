import processing.core.PApplet;

import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
public class NavBar extends VContainer {
    int buttonCount;

    public NavBar(VFrame frame, float x, float y){
        this.x = x;
        this.y = y;

        width = frame.width * 0.2f;
        height = frame.height;

        buttonCount = 2;
        interactables = new ArrayList<>();
        addTabButton(new TabButton(this, "Current", 0));
        addTabButton(new TabButton(this, "This Week", 1));
        addTabButton(new TabButton(this, "Report", 2));
    }

    private void addTabButton(TabButton button){
        button.x = 0;
        button.y = height * 0.15f + interactables.size() * height * 0.15f;
        interactables.add(button);
    }

    public void update(){

    }

    @Override
    public void render(PApplet pApplet) {
        for(VInteractable i : interactables){
            pApplet.pushMatrix();
            pApplet.translate(i.x, i.y);
            i.render(pApplet);
            pApplet.popMatrix();
        }
    }
}
