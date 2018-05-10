For testing skip the paragraphs, COMMENTS are in header files and in main:

So this project kinda went spaghetti real fast so let me explain what files you should look at. 
The way I implemented a star is that I created a data structure with an api and then coded a star
with that data structure. VectorList.cpp is just a vector with an api so that I could use it for 
the open and closed list.

So for inefficient I made:
Vectorlist.cpp, VectorList.h,
InefficientAStar.cpp, InefficientAStar.h,

For the efficient data structure, I built a minheap and tie broke on lower hcost since that's going to be closer
to the correct path. This only runs better on the harder problems namely ones halfway down. The last test case I ran took only 4 seconds
for efficient a star and took 46 seconds for inefficient a star. However there must be some overhead in my implementation as the smaller test cases
ran slower for efficient and faster for inefficient.

The reason for the minheap is that maintanence always takes O(ln) so insert and remove would take
O(ln) and lookup would be O(1) since I modified the hashmap each time I heapfied to keep track of the indicies. 

Files to look at:
EfficientDataStructure.cpp, EfficientDataStructure.h,
HashmapList.cpp, HashmapList.h, (just for the closed list)
AStar.cpp, AStar.h

For the map structure I simply read in the .map file and in main I read in the .scen file to fill in an array of points.
You'll see something in main that shows you how to test different test cases from the .scen file. I used another
vector for the open and closed list as well.

Files to look at:
VectorlistMap.cpp, VectorlistMap.h,
AStarMap.cpp, AStarMap.had
MDFourway.h, MDFourway.cpp (this is just the manhattan distance for the fourway map implementation)

TESTING:
GOAL FOUND
x coord is 1 y coord is 125
Up Right Up 
map nodes expanded 3

3  1  2  
6  4  5  
7  8  0  
9  10 11 
12 13 14 

goal found 
Left Left Up Up 

Efficient a star time is 0.000269049 seconds 
Efficient a star nodes expanded 4

goal found 
Left Left Up Up 

Inefficient a star time is 0.000109248 seconds 
Inefficient a star nodes expanded 4

3  4  1  
6  0  2  
7  8  5  
9  10 11 
12 13 14 

goal found 
Up Right Down Down Left Left Up Up 

Efficient a star Time is 0.000615511 seconds 
Efficient a star nodes expanded 8

goal found 
Up Right Down Down Left Left Up Up 

Inefficient a star time is 0.00026067 seconds 
Inefficient a star nodes expanded 8

3  4  1  
6  8  2  
9  7  5  
10 13 11 
12 14 0  

goal found 
Left Up Left Up Right Up Up Right Down Down Left Left Up Up 

Efficient a star Time is 0.00101159 seconds 
Efficient a star nodes expanded 14

goal found 
Left Up Left Up Right Up Up Right Down Down Left Left Up Up 

Inefficient a star time is 0.000265882 seconds 
Inefficient a star nodes expanded 14

0  3  1  
6  4  8  
9  7  2  
10 13 5  
12 14 11 

goal found 
Right Down Right Down Down Down Left Up Left Up Right Up Up Right Down Down Left Left Up Up 

Efficient a star Time is 0.00227043 seconds 
Efficient a star nodes expanded 26

goal found 
Right Down Right Down Down Down Left Up Left Up Right Up Up Right Down Down Left Left Up Up 

Inefficient a star time is 0.00047831 seconds 
Inefficient a star nodes expanded 26

6  3  1  
4  0  8  
9  7  2  
10 13 5  
12 14 11 

goal found 
Right Down Down Down Left Up Left Up Right Up Left Up Right Right Down Down Left Left Up Up 

Efficient a star Time is 0.00218608 seconds 
Efficient a star nodes expanded 26

goal found 
Right Down Down Down Left Up Left Up Right Up Left Up Right Right Down Down Left Left Up Up 

Inefficient a star time is 0.00046091 seconds 
Inefficient a star nodes expanded 26

6  3  0  
9  8  1  
7  4  2  
10 13 5  
12 14 11 

goal found 
Down Down Left Left Up Up Right Right Down Down Down Down Left Up Up Up Right Down Left Down Left Up Up Up 

Efficient a star Time is 0.00402467 seconds 
Efficient a star nodes expanded 47

goal found 
Down Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 

Inefficient a star time is 0.000835475 seconds 
Inefficient a star nodes expanded 46

6  3  1  
9  0  8  
7  4  2  
10 13 5  
12 14 11 

goal found 
Right Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 

Efficient a star Time is 0.00621396 seconds 
Efficient a star nodes expanded 73

goal found 
Right Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 

Inefficient a star time is 0.00170083 seconds 
Inefficient a star nodes expanded 73

0  6  1  
9  3  8  
7  4  2  
10 13 5  
12 14 11 

goal found 
Right Down Right Down Left Left Up Up Right Right Down Down Down Down Left Up Up Up Right Down Left Down Left Up Up Up 

Efficient a star Time is 0.00793987 seconds 
Efficient a star nodes expanded 84

goal found 
Right Down Right Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 

Inefficient a star time is 0.00187112 seconds 
Inefficient a star nodes expanded 85

6  1  8  
9  2  4  
7  3  0  
10 13 5  
12 14 11 

goal found 
Left Left Up Up Right Down Right Up Left Down Right Down Down Down Left Up Up Up Right Down Left Down Left Up Up Right Up Left 

Efficient a star Time is 0.0150575 seconds 
Efficient a star nodes expanded 152

goal found 
Left Left Up Up Right Down Right Up Left Down Right Down Down Down Left Up Left Up Right Up Right Down Left Left Up Right Up Left 

Inefficient a star time is 0.0039482 seconds 
Inefficient a star nodes expanded 153

6  1  8  
9  2  4  
7  5  13 
10 14 3  
0  12 11 

goal found 
Right Up Up Right Down Left Right Left Up Up Right Right Down Left Up Right Left Down Down Down Left Up Up Up Right Down Left Down Left Up Up Right Up Left 

Efficient a star Time is 0.126492 seconds 
Efficient a star nodes expanded 1107

goal found 
Right Up Up Right Down Left Right Left Up Up Right Down Right Up Left Down Right Down Down Down Left Up Left Up Right Up Right Down Left Left Up Right Up Left 

Inefficient a star time is 0.101991 seconds 
Inefficient a star nodes expanded 1123

6  1  8  
9  0  2  
7  5  4  
14 12 13 
10 11 3  

goal found 
Down Left Down Right Down Right Up Left Down Left Up Up Right Down Left Up Up Up Right Down Right Up Left Down Down Right Down Left Left Up Up Right Down Down Down Right Up Up Up Up Left Left 

Efficient a star Time is 4.2039 seconds 
Efficient a star nodes expanded 26405

goal found 
Right Down Down Down Left Up Up Right Down Left Left Down Right Up Down Left Up Up Right Down Right Up Left Down Right Down Down Down Left Up Left Up Right Up Right Down Left Left Up Right Up Left 

Inefficient a star time is 46.0004 seconds 
Inefficient a star nodes expanded 27137