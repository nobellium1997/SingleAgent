import java.util.Arrays;

public class STPState
{
    private int[][] arr;
    private int xBlank;
    private int yBlank;
    private int depth;
    private int gCost;
    private int hCost;
    private int fCost;
    private SlideDir direction;
    private STPState parent;

    public STPState()
    {
        gCost = 0;
        hCost = 0;
        fCost = 0;
        depth = 0;
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
        parent = this;
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
        this.parent = s.parent;
        this.depth = s.depth;
        this.hCost = s.hCost;
        this.gCost = s.gCost;
        this.fCost = s.fCost;
        this.direction = s.direction;
        this.parent = s.parent;
    }

    public STPState(int[][] array) {
        // initialize array
        this.arr = new int[5][3];
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                this.arr[i][j] = array[i][j];
            }
        }

        //find the blank tile and initialize coords
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                if(this.arr[i][j] == 0)
                {
                    this.xBlank = i;
                    this.yBlank = j;
                }
            }
        }
        this.depth = 0;
        this.hCost = 0;
        this.fCost = 0;
        this.gCost = 0;
        this.parent = null;
    }

    // GET METHODS
    public int[][] getArr() {
        return arr;
    }

    public int getxBlank() {
        return xBlank;
    }

    public int getyBlank() {
        return yBlank;
    }

    public int getDepth() {
        return depth;
    }

    public STPState getParent() {
        return parent;
    }

    public int getfCost() {
        return fCost;
    }

    public int getgCost() {
        return gCost;
    }

    public int gethCost() {
        return hCost;
    }

    // SET METHODS
    public void setDirection(SlideDir direction) {
        this.direction = direction;
    }

    public SlideDir getDirection() {
        return direction;
    }

    public void setParent(STPState parent) {
        this.parent = parent;
    }

    public void setDepth(int depth) {
        this.depth = depth;
    }

    public void setfCost(int fCost) {
        this.fCost = fCost;
    }

    public void setgCost(int gCost) {
        this.gCost = gCost;
    }

    public void sethCost(int hCost) {
        this.hCost = hCost;
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

    public boolean equals(STPState compare) {
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                if(this.arr[i][j] != compare.arr[i][j]) {
                    return false;
                }
            }
        }
        return true;
    }

}
