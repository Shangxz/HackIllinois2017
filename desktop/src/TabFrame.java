import processing.core.PApplet;

import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
public class TabFrame extends VContainer {
    VInteractable activeTab;

    public TabFrame(VFrame vFrame, float x, float y){
        width = vFrame.width * 0.75f;
        height = vFrame.height;
        this.x = x;
        this.y = y;

        interactables = new ArrayList<>();
        interactables.add(new NowTab(this));
        interactables.add(new Tab(this, 0xFF00FF00));
        interactables.add(new Tab(this, 0xFF0000FF));

        activeTab = interactables.get(0);
    }

    public void changeTab(int n){
        if(interactables.size() > n && interactables.get(n) != null){
            activeTab = interactables.get(n);
        }
    }

    public void render(PApplet pApplet) {
        pApplet.pushMatrix();
        pApplet.translate(activeTab.x, activeTab.y);
        activeTab.render(pApplet);
        pApplet.popMatrix();
    }


    public boolean onMouseDown(float x, float y){
        return activeTab.onMouseDown(x - activeTab.x, y - activeTab.y);
    }

    public boolean onMouseUp(float x, float y){
        return activeTab.onMouseUp(x - activeTab.x, y - activeTab.y);
    }
}
