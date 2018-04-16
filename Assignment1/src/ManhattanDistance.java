public class ManhattanDistance extends Heuristic {
    public ManhattanDistance() {
    }

    @Override
    public int manhattan_distance(STPState compare_state, STPState goal) {
        int compareX;
        int compareY;
        int goalX;
        int goalY;
        int mh_distance = 0;
        for(int i = 0; i < 5; i++) {
            for(int j = 0; j < 3; j++) {
                if (compare_state.getArr()[i][j] == 0) {
                    continue;
                }
                compareX = j;
                compareY = i;
                for(int x = 0; x < 5; x++) {
                    boolean is_added = false;
                    for(int z = 0; z < 3; z++) {
                        if(goal.getArr()[x][z] == compare_state.getArr()[i][j]) {
                            goalX = z;
                            goalY = x;
                            mh_distance += (Math.sqrt(Math.pow((compareX-goalX), 2))) + (Math.sqrt(Math.pow((compareY - goalY),2)));
                            is_added = true;
                            break;
                        }
                    }
                    if(is_added) {
                        break;
                    }
                }
            }
        }

        return mh_distance;
    }
}
