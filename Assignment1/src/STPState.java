
public class STPState
{
    private int[][] arr;
    private String string = new String();

    public STPState()
    {
        arr = new int[5][3];

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