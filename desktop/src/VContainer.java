import java.util.ArrayList;

/**
 * Created by David Sun on 2/25/2017.
 */
abstract public class VContainer extends VInteractable {
    protected ArrayList<VInteractable> interactables;

    //pass mouse events to children, returns true to consume
    public boolean onMouseDown(float x, float y){
        if(x > this.width || y > this.height)
            return false;

        for(VInteractable c : interactables){
            if(c.onMouseDown(x - c.x, y - c.y))
                return true;
        }
        return false;
    }

    //pass mouse events to children, returns true to consume
    public boolean onMouseUp(float x, float y){
        if(x > this.width || y > this.height)
            return false;

        for(VInteractable c : interactables){
            if(c.onMouseUp(x - c.x, y - c.y)){
                return true;
            }
        }
        return false;
    }
}
