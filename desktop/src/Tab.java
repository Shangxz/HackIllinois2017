import processing.core.PApplet;

import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
public class Tab extends VContainer {

    int color;

    public Tab(TabFrame frame){
        this(frame, 0xFFFFFFFF);
    }

    public Tab(TabFrame frame, int color){
        width = frame.width;
        height = frame.height * 0.85f;
        x = 0;
        y = frame.height * 0.15f;

        this.color = color;
        interactables = new ArrayList<>();
    }

    public void render(PApplet pApplet) {
        pApplet.fill(color);
        pApplet.rect(0, 0, width, height);
    }
}
