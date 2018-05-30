To change the heuristic simply uncomment one of the lines in main from line 84-86
To change the map file go to EightwayMovement and change the file name in the cpp file on line 11
AND change the scen file in main on line 27

I fixed my performance bug in this one so once the pivot points generate it should run crazy fast now.
I only tested the last case because I thought it would be pointless to write all the tests to a file, so 
I simply compared the last one accross for an easier readme.


Randomized pivots performed worse than optimized pivots as optimized pivots expanded 2656 nodes whereas 
randomized expanded 3614 nodes. Octile distance obviously expanded the most nodes with 11140 node expansions.

OPTIMIZED PIVOTS:
Solution from 77, 43 to 115, 119
2656Right Right Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
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
Down Down Down Down-Left Left Left Left Left Left Left 
Down-Left Down-Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Up-Left Left Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Left Left Left Left Up-Left Left Up-Left Up-Left Up-Left 
Up-Left Up-Left Up-Left Up-Left Up-Left Left Left Left Left Left 
Left Left Left Left Down-Left Down-Left Left Left Left Left 
Left Left Left Left Left Left Left Left Left Left 
Left Down-Left Down-Left Left Left Left Left Left Up-Left Up 
Up Up Up Up-Right Up Up-Right Up Up Up Up 
Up Up Up Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right 
Up-Right Up-Right Up Up Up Up Up Up Up Up 
Up Up Up-Right Up-Right Up-Right Up Up Up Up Up 
Up Up Up Up Up Up Up Up Up Up 
Up Up Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right Up-Right 
Up-Right Up-Right Up-Right Up-Right Up-Right Right Right Up-Right Up-Right Up-Right 
Right Right Right Right Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down Down Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down 

Nodes Expanded: 2656
g-cost of goal: 420.132

Solution from 77, 43 to 115, 119
3614Right Right Right Right Right Right Right Right Right 
Right Right Right Right Right Right Right Right Right Right 
Right Right Right Right Right Right Right Right Right Right 
Right Right Right Right Right Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right Down-Right 
Down-Right Down-Right Down-Right Down-Right Down Down Down Down Down Down 
Down Down Down Down Down Down Down Down Down Down-Right 
Down Down Down-Right Down-Right Down-Right Down-Right Down-Right Down Down Down 
Down Down Down-Left Down-Left Down-Left Down-Left Down Down Down Down 
Down Down Down Down Down Down Down Down Down Down 
Down Down Down Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left 
Down-Left Down Down Down Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left 
Down-Left Down-Left Down-Left Down-Left Down-Left Down-Left Left Left Left Left 
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

Nodes Expanded: 3614
g-cost of goal: 420.132

Octile distance
Solution from 77, 43 to 115, 119
11410Right Right Right Down-Right Right Right Right Right Right 
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

