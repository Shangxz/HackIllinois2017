import processing.core.PApplet;

/**
 * Created by David Sun on 2/25/2017.
 */

//Visualizer interactable. Base of all elements
public abstract class VInteractable {
    //relative coordinates to parent
    int x, y, width, height;

    //abstract public void update();
    abstract public void render(PApplet pApplet);

    //x and y coordinates relative to parent
    //i.e. top left corner of parent is 0,0
    public boolean onMouseDown(int x, int y){
        return false;
    }

    //x and y coordinates relative to parent
    //i.e. top left corner of parent is 0,0
    public boolean onMouseUp(int x, int y){
        return false;
    }
}
