For testing skip the paragraphs, comments are in header files and in main:

So this project kinda went spaghetti real fast so let me explain what files you should look at. 
The way I implemented a star is that I created a data structure with an api and then coded a star
with that data structure. VectorList.cpp is just a vector with an api so that I could use it for 
the open and closed list.

So for inefficient I made:
Vectorlist.cpp, VectorList.h,
InefficientAStar.cpp, InefficientAStar.h,

For the "efficient" data structure I was trying to create a priority queue that updated indicies 
on insert and delete so that lookup would be O(1) but the problem is my queue implementation isn't
great and I think I'm using heapify wrong since instead of inserting and heapifying based on the insert
I just blindly add to the deque and heapify the whole thing. If I had more time and a stronger will, 
I might have done a better job but as it stands now, efficient a star runs slower than inefficient.

Files to look at:
EfficientDataStructure.cpp, EfficientDataStructure.h,
AStar.cpp, AStar.h

For the map structure I simply read in the .map file and in main I read in .scen to fill in an array of points.
You'll see something in main that shows you how to test different test cases from the .scen file. I used another
vector for the open and closed list as well.

Files to look at:
VectorlistMap.cpp, VectorlistMap.h,
AStarMap.cpp, AStarMap.had

TESTING: