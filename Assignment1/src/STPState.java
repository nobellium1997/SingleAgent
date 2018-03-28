
public class STPState
{
    private int[][] arr;
    private int xBlank;
    private int yBlank;
    private String string = new String();

    public STPState()
    {
        arr = new int[5][3];
        xBlank = 0;
        yBlank = 0;
        int counter = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                arr[i][j] = counter;
                counter++;
            }
        }
        string = "succ";
    }

}