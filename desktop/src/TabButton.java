import processing.core.PApplet;

/**
 * Created by David Sun on 2/25/2017.
 */
public class TabButton extends VInteractable{
    private String title;

    float gutter;

    public TabButton(TabBar bar, String title, float x, float y){
        this.x = x;
        this.y = y;
        width = bar.width;
        height = bar.buttonCount == 0 ? bar.height : bar.height * 0.2f;

        this.title = title;

        gutter = height * 0.1f;
    }

    public void update(){
        return;
    }

    public void render(PApplet pApplet) {
        pApplet.fill(0, 0);
        pApplet.strokeWeight(8);
        pApplet.stroke(VisualConstants.HIGHLIGHT_COLOR);
        pApplet.rect(0, 0, width, height, 10);

        pApplet.fill(VisualConstants.HIGHLIGHT_COLOR);
        pApplet.strokeWeight(1);
        pApplet.rect(gutter, gutter, width - 2 * gutter, height - 2 * gutter, 6);
    }

    public boolean onMouseDown(int x, int y){
        System.out.println(title);
        return true;
    }
}
