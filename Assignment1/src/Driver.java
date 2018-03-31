import java.util.ArrayList;

public class Driver
{
    public static void main(String[] args) {
        STPState s = new STPState();
        ArrayList<STPState> arr = STP.GetSuccessors(s);
        for(int i = 0; i < arr.size(); i++) {
            System.out.println(arr.get(i));
            System.out.println("x is " + arr.get(i).getxBlank() + "y is " + arr.get(i).getyBlank());
            System.out.println(arr.get(i).getArr()[arr.get(i).getxBlank()][arr.get(i).getyBlank()]);
        }

        System.out.println();
        System.out.println("Second array");
        ArrayList<STPState> arr2 = STP.GetSuccessors(arr.get(0));
        for(int i = 0; i < arr2.size(); i++) {
            System.out.println(arr2.get(i));
        }

    }
}
