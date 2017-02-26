import processing.core.PApplet;
import processing.core.PConstants;

/**
 * Created by David Sun on 2/26/2017.
 */
public class StatusTab extends Tab {
    public StatusTab(TabFrame frame){
        super(frame);
    }

    public void render(PApplet pApplet) {
        pApplet.textAlign(PConstants.LEFT, PConstants.TOP);
        pApplet.textSize(70);
        pApplet.fill(255);
        pApplet.text("You've been feeling a lot of " +
                (((NowTab)Visualizer.getVisualizer().vFrame.tabFrame.interactables.get(0)).topEmotion).toLowerCase() +
                ".\nWhy not take a break and go outside?", 0, 0);
    }
}
