import processing.core.PApplet;
import processing.core.PConstants;

/**
 * Created by David Sun on 2/25/2017.
 */
public class EmotionStat extends VInteractable {
    private String name, description;
    float value;

    public EmotionStat(Tab tab, String name, float value, String description){
        this.name = name;
        this.description = description;
        this.value = value;

        width = tab.width / 2;
        height = tab.height;
    }

    public void render(PApplet pApplet) {
        //pApplet.fill(255);
        //pApplet.rect(0, 0, width, height);

        pApplet.fill(VisualConstants.CONTRAST_COLOR);
        pApplet.textSize(50);
        pApplet.textAlign(PConstants.LEFT, PConstants.TOP);
        pApplet.text(name + " " + value, 0, 0);

        pApplet.fill(VisualConstants.HIGHLIGHT_COLOR);
        pApplet.textSize(30);
        pApplet.text(description, 0, 80, 500, 500);
    }
}
