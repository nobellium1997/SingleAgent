The readme for the last project is included to compare times with just the manhattan distance.
Below is the distribution for the second pdb table, forgot to print the first one and didn't wanna wait the 
20 minutes. 

IDA* with both pdbs and mh ran much faster and expanded way fewer nodes for each test except for the first few where there was really only 
one limit to choose from. Times are listed under the distribution along with the path.

DISTRIBUTION FOR PDB2
0: 1
1: 2
2: 3
3: 3
4: 4
5: 8
6: 17
7: 27
8: 54
9: 98
10: 184
11: 294
12: 540
13: 863
14: 1582
15: 2471
16: 4440
17: 6836
18: 11915
19: 17564
20: 29623
21: 41898
22: 68189
23: 91631
24: 142003
25: 179843
26: 266385
27: 319689
28: 455866
29: 520655
30: 720291
31: 789805
32: 1062662
33: 1117571
34: 1453505
35: 1457091
36: 1820909
37: 1730218
38: 2067704
39: 1863445
40: 2138225
41: 1833591
42: 2021831
43: 1644785
44: 1735078
45: 1331858
46: 1337673
47: 963259
48: 915737
49: 614432
50: 551891
51: 343792
52: 291498
53: 167802
54: 133293
55: 68521
56: 49397
57: 21711
58: 13909
59: 4827
60: 2605
61: 508
62: 252
63: 22
64: 14

 PDB DONE 
3  1  2  
6  4  5  
7  8  0  
9  10 11 
12 13 14 

Goal found at cost 4; 4 total expansions
Left Left Up Up 
Time is 0.0001005 seconds 

3  4  1  
6  0  2  
7  8  5  
9  10 11 
12 13 14 

Goal found at cost 8; 8 total expansions
Up Right Down Down Left Left Up Up 
Total time is 0.0001661 seconds 

3  4  1  
6  8  2  
9  7  5  
10 13 11 
12 14 0  

Bound 12 complete; 3 total expansions (3 new)
Goal found at cost 14; 18 total expansions
Left Up Left Up Right Up Up Right Down Down Left Left Up Up 
Total time is 0.0003993 seconds 

0  3  1  
6  4  8  
9  7  2  
10 13 5  
12 14 11 

Bound 16 complete; 3 total expansions (3 new)
Bound 18 complete; 17 total expansions (14 new)
Goal found at cost 20; 50 total expansions
Right Down Right Down Down Down Left Up Left Up Right Up Up Right Down Down Left Left Up Up 
Total time is 0.0011459 seconds 

6  3  1  
4  0  8  
9  7  2  
10 13 5  
12 14 11 

Bound 16 complete; 1 total expansions (1 new)
Bound 18 complete; 14 total expansions (13 new)
Goal found at cost 20; 55 total expansions
Right Down Down Down Left Up Left Up Right Up Left Up Right Right Down Down Left Left Up Up 
Total time is 0.0012835 seconds 

6  3  0  
9  8  1  
7  4  2  
10 13 5  
12 14 11 

Bound 20 complete; 4 total expansions (4 new)
Bound 22 complete; 41 total expansions (37 new)
Goal found at cost 24; 120 total expansions
Down Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 
Total time is 0.0028458 seconds 

6  3  1  
9  0  8  
7  4  2  
10 13 5  
12 14 11 

Bound 20 complete; 11 total expansions (11 new)
Bound 22 complete; 75 total expansions (64 new)
Goal found at cost 24; 128 total expansions
Right Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 
Total time is 0.0031443 seconds 

0  6  1  
9  3  8  
7  4  2  
10 13 5  
12 14 11 

Bound 22 complete; 13 total expansions (13 new)
Bound 24 complete; 90 total expansions (77 new)
Goal found at cost 26; 147 total expansions
Right Down Right Down Left Left Up Up Right Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Up 
Total time is 0.0037293 seconds 

6  1  8  
9  2  4  
7  3  0  
10 13 5  
12 14 11 

Bound 22 complete; 6 total expansions (6 new)
Bound 24 complete; 48 total expansions (42 new)
Bound 26 complete; 197 total expansions (149 new)
Goal found at cost 28; 244 total expansions
Left Left Up Up Right Right Down Left Up Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Right Up Left 
Total time is 0.006087 seconds 

6  1  8  
9  2  4  
7  5  13 
10 14 3  
0  12 11 

Bound 24 complete; 1 total expansions (1 new)
Bound 26 complete; 16 total expansions (15 new)
Bound 28 complete; 79 total expansions (63 new)
Bound 30 complete; 401 total expansions (322 new)
Bound 32 complete; 1784 total expansions (1383 new)
Goal found at cost 34; 5309 total expansions
Right Up Up Right Down Left Up Left Up Up Right Right Down Left Up Right Down Down Down Down Left Up Left Up Right Up Right Down Left Left Up Right Up Left 
Total time is 0.138066 seconds 

6  1  8  
9  0  2  
7  5  4  
14 12 13 
10 11 3  

Bound 30 complete; 3 total expansions (3 new)
Bound 32 complete; 93 total expansions (90 new)
Bound 34 complete; 532 total expansions (439 new)
Bound 36 complete; 2643 total expansions (2111 new)
Bound 38 complete; 12855 total expansions (10212 new)
Bound 40 complete; 60837 total expansions (47982 new)
Goal found at cost 42; 136380 total expansions
Right Down Down Down Left Up Left Up Up Up Right Down Right Up Left Down Down Down Right Up Left Down Left Down Right Right Up Up Up Left Down Down Down Right Up Left Left Up Up Right Up Left 
Total time is 3.59675 seconds 

6  1  8  
9  5  2  
7  12 4  
14 13 3  
10 11 0  

Bound 28 complete; 7 total expansions (7 new)
Bound 30 complete; 65 total expansions (58 new)
Bound 32 complete; 280 total expansions (215 new)
Bound 34 complete; 1200 total expansions (920 new)
Bound 36 complete; 5167 total expansions (3967 new)
Bound 38 complete; 21873 total expansions (16706 new)
Goal found at cost 40; 23363 total expansions
Left Left Up Right Right Down Left Left Up Up Right Down Left Up Up Up Right Down Right Up Left Down Down Right Down Down Left Left Up Up Up Right Down Down Right Up Up Up Left Left 
Total time is 0.619017 seconds 

6  1  8  
9  5  2  
7  12 4  
14 0  13 
10 11 3  

Bound 30 complete; 9 total expansions (9 new)
Bound 32 complete; 110 total expansions (101 new)
Bound 34 complete; 594 total expansions (484 new)
Bound 36 complete; 3045 total expansions (2451 new)
Bound 38 complete; 14522 total expansions (11477 new)
Bound 40 complete; 67131 total expansions (52609 new)
Goal found at cost 42; 113428 total expansions
Right Down Left Left Up Right Right Down Left Left Up Up Right Down Left Up Up Up Right Down Right Up Left Down Down Right Down Down Left Left Up Up Up Right Down Down Right Up Up Up Left Left 
Total time is 2.99518 seconds 

6  1  8  
9  5  2  
7  12 4  
14 0  11 
10 3  13 

Bound 28 complete; 3 total expansions (3 new)
Bound 30 complete; 38 total expansions (35 new)
Bound 32 complete; 274 total expansions (236 new)
Bound 34 complete; 1379 total expansions (1105 new)
Bound 36 complete; 6487 total expansions (5108 new)
Goal found at cost 38; 6714 total expansions
Left Up Right Right Down Left Left Up Up Up Right Down Right Up Left Down Down Down Down Left Up Up Right Down Down Right Up Up Up Left Down Left Up Right Right Up Left Left 
Total time is 0.178189 seconds 

6  1  8  
9  5  2  
7  12 4  
10 14 11 
3  13 0  

Bound 32 complete; 30 total expansions (30 new)
Bound 34 complete; 326 total expansions (296 new)
Bound 36 complete; 1963 total expansions (1637 new)
Bound 38 complete; 9653 total expansions (7690 new)
Goal found at cost 40; 14165 total expansions
Left Left Up Up Right Right Down Left Left Up Up Up Right Down Right Up Left Down Down Down Down Left Up Up Right Down Down Right Up Up Up Left Down Left Up Right Right Up Left Left 
Total time is 0.38401 seconds 

6  1  8  
9  5  2  
7  12 4  
10 0  14 
3  13 11 

Bound 30 complete; 13 total expansions (13 new)
Bound 32 complete; 128 total expansions (115 new)
Bound 34 complete; 783 total expansions (655 new)
Bound 36 complete; 4042 total expansions (3259 new)
Bound 38 complete; 19381 total expansions (15339 new)
Goal found at cost 40; 22261 total expansions
Left Up Right Down Left Down Right Right Up Left Left Up Right Down Down Left Up Up Up Up Right Down Right Up Left Down Down Right Down Left Left Up Up Right Down Right Up Up Left Left 
Total time is 0.6109 seconds 

6  1  8  
9  5  2  
10 7  4  
12 0  14 
3  13 11 

Bound 30 complete; 10 total expansions (10 new)
Bound 32 complete; 118 total expansions (108 new)
Bound 34 complete; 849 total expansions (731 new)
Bound 36 complete; 4596 total expansions (3747 new)
Goal found at cost 38; 11381 total expansions
Right Up Left Left Down Down Right Up Left Up Right Down Right Down Left Left Up Up Up Up Right Down Right Up Left Down Down Down Left Up Up Right Down Right Up Up Left Left 
Total time is 0.308527 seconds 

5  13 14 
2  4  12 
0  6  8  
3  1  9  
11 7  10 

Bound 46 complete; 89 total expansions (89 new)
Bound 48 complete; 1597 total expansions (1508 new)
Bound 50 complete; 15791 total expansions (14194 new)
Bound 52 complete; 131132 total expansions (115341 new)
Bound 54 complete; 963109 total expansions (831977 new)
Goal found at cost 56; 3570694 total expansions
Right Down Left Up Right Up Up Left Down Down Right Right Up Left Down Down Down Right Up Up Up Up Left Left Down Down Right Down Right Up Up Left Left Down Down Right Down Right Up Up Left Down Down Left Up Right Down Right Up Left Up Right Up Up Left Left 
Total time is 92.355 seconds 
