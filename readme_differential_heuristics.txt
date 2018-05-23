I couldn't copy and paste all the test cases and I thought it'd be easier to tell the difference with the final large
test case. With differential heuristic, only 2206 nodes while only octile distance expanded 11410 nodes.
However for some reason there is a ton of overhead when getting the heuristic values form the unordered map library
which makes using just octile distance way faster than using unordered map despite the node expansions being much smaller with
the differential heuristics. After doing some research, apparantly the unordered_map library is actually quite inefficient 
which makes the naive approach much faster. 

FINAL TEST WITH ONLY OCTILE DISTANCE 

Solution from 77, 43 to 115, 119
Right Right Right Down-Right Right Right Right Right Right 
Right Right Right Right Right Right Right Right Right Right 
Right Right Right Right Right Right Right Right Right Right 
Right Right Right Right Down-Right Down-Right Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Right Down-Right Right Down-Right Down Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down Down Down Down Down Down 
Down Down Down Down Down Down Down Down Down Down-Right 
Down Down Down-Right Down-Right Down-Right Down-Right Down-Right Down Down Down 
Down Down Down-Left Down-Left Down-Left Down-Left Down-Left Down Down Down-Left 
Down Down Down Down Down Down Down Down Down Down 
Down Down Down Down Down Down-Left Down-Left Down-Left Down-Left Down-Left 
Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left 
Down Down Down Left Down-Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Left Down-Left Down-Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Up-Left Left Left Left Up-Left Up-Left Up-Left Up-Left 
Up-Left Up-Left Up-Left Up-Left Up-Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Down-Left Left Down-Left 
Left Down-Left Down-Left Left Left Left Left Left Up-Left Up 
Up Up Up Up-Right Up Up-Right Up-Right Up-Right Up-Right Up-Right 
Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right 
Up-Right Up-Right Up-Right Up-Right Up Up Up Up Up Up 
Up Up Up Up Up Up Up Up Up Up 
Up Up-Right Up Up-Right Up Up Up Up Up Up 
Up Up Up-Right Up-Right Up-Right Up-Right Up Up Up Up 
Up Up Up Up-Right Up Right Right Up-Right Right Right 
Right Up-Right Up-Right Right Right Right Down-Right Down-Right Down Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down Down Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down 

Nodes Expanded: 11410
g-cost of goal: 420.132

FINAL TEST WITH BOTH DIFFERENTIAL HEURISTIC AND OCTILE DISTANCE

Solution from 77, 43 to 115, 119
Right Right Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Right Right Right Right Right Right Right Right Right Right 
Right Right Right Right Right Right Right Right Right Right 
Right Right Down-Right Right Right Right Down-Right Down-Right Right Right 
Right Right Right Right Down-Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down 
Down Down Down Down Down Down Down Down Down Down 
Down Down Down Down Down Down Down Down Down Down 
Down Down Down-Left Down-Left Down-Left Down-Left Down-Left Down Down Down-Left 
Down Down Down Down Down Down Down Down Down Down 
Down Down Down Down Down Down-Left Down-Left Down-Left Down-Left Down-Left 
Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left 
Down Down Down Down-Left Down-Left Down-Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Up-Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Up-Left Left Up-Left Up-Left Up-Left 
Up-Left Up-Left Up-Left Up-Left Up-Left Left Left Left Left Left 
Left Left Left Left Down-Left Down-Left Down-Left Down-Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Up-Left Up 
Up Up Up Up-Right Up Up-Right Up-Right Up-Right Up-Right Up-Right 
Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right 
Up-Right Up-Right Up-Right Up-Right Up Up Up Up Up Up 
Up Up Up Up Up Up Up Up Up Up 
Up Up-Right Up Up-Right Up Up Up Up Up Up 
Up Up Up-Right Up-Right Up-Right Up-Right Up Up Up Up 
Up Up Up Up-Right Up Up-Right Up-Right Up-Right Right Right 
Right Right Right Right Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down Down Down Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down 

Nodes Expanded: 2206
g-cost of goal: 420.132

