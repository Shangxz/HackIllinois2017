import processing.core.PApplet;

/**
 * Created by David Sun on 2/25/2017.
 */
public class TabButton extends VInteractable{
    private String title;

    public TabButton(TabBar bar, String title, int x, int y){
        this.x = x;
        this.y = y;
        width = bar.width;
        height = bar.buttonCount == 0 ? bar.height : bar.height / bar.buttonCount;

        this.title = title;
    }

    public void update(){
        return;
    }

    public void render(PApplet pApplet) {
        pApplet.fill(0, 0);
        pApplet.stroke(128);
        pApplet.rect(0, 0, width, height, 40);
    }

    public boolean onMouseDown(int x, int y){
        System.out.println(title);
        return true;
    }
}
