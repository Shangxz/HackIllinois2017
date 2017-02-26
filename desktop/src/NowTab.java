import processing.core.PApplet;
import processing.core.PConstants;
import processing.core.PImage;

/**
 * Created by David Sun on 2/25/2017.
 */
public class NowTab extends Tab{
    int index = 0;
    int animation = -1;

    EmotionStat[] stats = new EmotionStat[6];
    EmotionStat currentStat;
    PieChart pieChart;
    String topEmotion = "TEST";

    public NowTab(TabFrame frame){
        super(frame);

        pieChart = new PieChart(this, height / 2, height * 0.35f, height * 0.35f);
        interactables.add(pieChart);

        stats[0] = new EmotionStat(this, "Anger", pieChart.emotions[0][0],
                "Top words:\nBug fixes, code reviews, traffic jams");
        stats[1] = new EmotionStat(this, "Disgust", pieChart.emotions[0][1],
                "Top words:\nLife");
        stats[2] = new EmotionStat(this, "Fear", pieChart.emotions[0][2],
                "Top words:\nHeights, death, disappearing into the void");
        stats[3] = new EmotionStat(this, "Happiness", pieChart.emotions[0][3],
                "Top words:\nPeeling new electronics, smelling flowers");
        stats[4] = new EmotionStat(this, "Surprise", pieChart.emotions[0][4],
                "Top words:\nNothing surprises you");
        stats[5] = new EmotionStat(this, "Sadness", pieChart.emotions[0][5],
                "Top words:\n2016");

        for(int i = 0; i < stats.length; i ++) {
            stats[i].x = height * 1.2f;
            stats[i].y = 0;
        }
        currentStat = stats[0];
    }

    public void update(PApplet pApplet, float x, float y){
        super.update(pApplet, x, y);
    }

    public void render(PApplet pApplet) {
        for(VInteractable i : interactables){
            pApplet.pushMatrix();
            pApplet.translate(i.x, i.y);
            i.render(pApplet);
            pApplet.popMatrix();
        }

        pApplet.pushMatrix();
        pApplet.translate(currentStat.x, currentStat.y);
        currentStat.render(pApplet);
        if(animation >= 0 && animation < 10) {
            animation++;
            currentStat.x += height * 0.02f;
        }
        pApplet.popMatrix();
    }

    public void triggerAnimation(int i){
        index = i;
        animation = 0;
        currentStat = stats[i];
        currentStat.x = height;
    }
}
