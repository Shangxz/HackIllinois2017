import processing.core.PApplet;
import processing.core.PImage;
import sun.security.krb5.internal.PAData;

/**
 * Created by David Sun on 2/26/2017.
 */
public class HistoryTab extends Tab {
    PImage image;
    public HistoryTab(TabFrame frame){
        super(frame);
        image = Visualizer.getVisualizer().loadImage("line-graph.png");
    }

    public void render(PApplet pApplet){
        pApplet.image(image, 0, 0);
    }
}
