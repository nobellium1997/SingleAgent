import java.util.Comparator;

public class JankSort implements Comparator<STPState> {
    public int compare(STPState s1, STPState s2) {
        if(s1.getfCost() < s2.getfCost()) {
            return -1;
        } else if (s1.getfCost() == s2.getfCost()) {
            return 0;
        } else {
            return 1;
        }
    }
}
