import processing.core.PApplet;

/**
 * Created by David Sun on 2/25/2017.
 */
public class TabButton extends VInteractable{
    private String title;
    private int id;

    public TabButton(NavBar bar, String title){
        this(bar, title, 0, 0);
    }

    public TabButton(NavBar bar, String title, int id){
        this(bar, title);
        this.id = id;
    }

    public TabButton(NavBar bar, String title, float x, float y){
        this.x = x;
        this.y = y;
        width = bar.width;
        height = bar.height * 0.10f;

        this.title = title;
        this.id = 0;
    }

    public void update(){
        return;
    }

    public void render(PApplet pApplet) {
        pApplet.fill(VisualConstants.HIGHLIGHT_COLOR);
        pApplet.strokeWeight(1);
        pApplet.rect(0, 0, width, height);

        pApplet.fill(0);
        pApplet.textSize(30);
        pApplet.text(title, width / 2, height / 2);
    }

    @Override
    public boolean onMouseDown(float x, float y){
        if(x > width || y > height)
            return false;
        //System.out.println(title);
        Visualizer.getVisualizer().vFrame.changeTab(id);
        return true;
    }
}
