import java.util.ArrayList;

public class Driver
{

    public static void main(String[] args) {
        int[][] STP = new int[5][3];

        int counter = 0;
        for (int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                STP[i][j] = counter;
                counter++;
            }


        ArrayList<int[][]> states_arrays = new ArrayList<>();
        states_arrays.add(STP);
    }
}
