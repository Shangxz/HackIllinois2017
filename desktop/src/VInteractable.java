import processing.core.PApplet;

/**
 * Created by David Sun on 2/25/2017.
 */

//Visualizer interactable. Base of all elements
public abstract class VInteractable {
    //relative coordinates to parent
    float x, y, width, height;

    public void update(PApplet pApplet, float x, float y){
        return;
    }

    abstract public void render(PApplet pApplet);

    //x and y coordinates relative to parent
    //i.e. top left corner of parent is 0,0
    public boolean onMouseDown(float x, float y){
        return false;
    }

    //x and y coordinates relative to parent
    //i.e. top left corner of parent is 0,0
    public boolean onMouseUp(float x, float y){
        return false;
    }
}
