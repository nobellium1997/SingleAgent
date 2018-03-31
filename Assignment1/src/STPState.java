
public class STPState
{
    private int[][] arr;
    private int xBlank;
    private int yBlank;

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
    }

    public STPState(STPState s) {
        this.arr = new int[5][3];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                this.arr[i][j] = s.arr[i][j];
            }
        }
        this.xBlank = s.xBlank;
        this.yBlank = s.yBlank;
    }

    public STPState(int[][] array) {
        //intitialize array
        this.arr = array;

        //find the blank tile and initialize coords
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                if(this.arr[i][j] == 0)
                {
                    this.xBlank = j;
                    this.yBlank = i;
                }
            }
        }

    }

    public int[][] getArr() {
        return arr;
    }

    public int getxBlank() {
        return xBlank;
    }

    public int getyBlank() {
        return yBlank;
    }

    public String toString() {
        String ret = new String();
        for(int i = 0; i < 5; i++) {
            for (int j = 0; j < 3; j++) {
                ret += arr[i][j] + "  ";
            }
            ret += "\n";
        }
        return ret;
    }

}
