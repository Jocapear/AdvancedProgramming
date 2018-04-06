=========================================================
Round 1C 2015: Problem A. Brattleship
========================================================

You're about to play a simplified "battleship" game with your little brother. The board for this game is a rectangular grid with R rows and C columns. At the start of the game, you will close your eyes, and you will keep them closed until the end of the game. Your little brother will take a single rectangular 1 x W ship and place it horizontally somewhere on the board. The ship must always fit entirely on the board, with each cell of the ship occupying exactly one of the grid's cells, and it can never be rotated.

In each turn of the game, you name a cell on the board, and your little brother tells you whether that is a hit (one of the cells occupied by the ship) or a miss. (Your little brother doesn't say which part of the ship was hit -- just that the cell you named has a part of the ship in it.) You have perfect memory, and can keep track of all the information he has given you. Once you have named all of the cells occupied by the ship, the game is over (the ship is sunk), and your score is the number of turns taken. Your goal is to minimize your score.

Although the ship is not supposed to be moved once it is placed, you know that your little brother, who is a brat, plans to cheat by changing the location of the ship whenever he wants, as long as the ship remains horizontal and completely on the board, and the new location is consistent with all the information he has given so far. For example, for a 1x4 board and 1x2 ship, your little brother could initially place the ship such that it overlaps the leftmost two columns. If your first guess was row 1, column 2, he could choose to secretly move the ship to the rightmost two columns, and tell you that (1, 2) was a miss. If your next guess after that was (1, 3), though, then he could not say that was also a miss and move the ship back to its original location, since that would be inconsistent with what he said about (1, 2) earlier.

Not only do you know that your little brother will cheat, he knows that you know. If you both play optimally (you to minimize your score, him to maximize it), what is the lowest score that you can guarantee you will achieve, regardless of what your little brother does?

Input

The first line of the input gives the number of test cases, T. T lines follow, each with three space-separated integers R, C, and W: the number of rows and columns of the board, followed by the width of the ship.
Output

For each test case, output one line containing "Case #x: y", where x is the test case number (starting from 1) and y is the minimum score you can guarantee.
Limits

1 = W = C.

Small dataset

T = 55.
R = 1.
1 = C = 10.

Large dataset

1 = T = 100.
1 = R = 20.
1 = C = 20.

Input	Output
 

3	
1 4 2	Case #1: 3
1 7 7	Case #2: 7
2 5 1	Case #3: 10




----------------------------------------------------------------------------------------------------------------------------------------

<<<BREAKDOWN>>>
The first solution I thought about was to try each possible case and taking the one with less moves but after reading better the problem
I realized this was useless because they don't want the less number of moves but the less possible moves taking all cases, not one by one.
Also, that solution would be very inneficient. Then, I tried to look for patterns in the results because I probably don't need to emulate
a matrix, perhaps I just need to find a formula that leads to the result. The characteristics I could think of were:
-I need at least W turns to find a complete ship
-If the number of slots RxC is equal to the width of the ship W then the answer is W
-If W is 1 then the answer is RxC

For a simple case like R = 1 and C = 4 I tried to get answers for different W:
1 4 1	4
1 4 2	3
1 4 3	4
1 4 4	4
Now for R = 2 and C = 4, this gets a little bit trickier bucause I need to check both rows:
2 4 1	8
2 4 2	5
2 4 3	5
2 4 4	5
For each row we have to check first if a ship is there, for all the rows except the last one
we have to do the necessary number to check all the core rows, most of the times its the middle ones,
the trick is to never check the corners and just the necessary blocks in the middle.
To do this calculation I did a few experiments, to check if a W of 3 fits in a 4 you only need to check
the 1 of the middle blocks, if you hace a W of 2 in a 4 you need to check the 2 middle blocks, looking for
a patter here I decided to perform more cases(Remember that this is only for checking that a ship is not there):
C W		C W		C W
5 2	3	7 1	7	8 1 	8
5 3	1	7 2	5	8 2	6
5 4	1	7 3	3	8 3	4
5 5	1	7 4	1	8 4	2
6 2	4	7 5	1	8 5	1
6 3	2	7 6	1	8 6	1
6 4	1	7 7	1	8 7	1
6 5	1			8 8	1
6 6 	1
I smell a pattern, lets see. I detected these characteristics:
-If W is 1 it takes C
-If W is lesser or equal than the half of C then you have to do (Wx2)-2 to get the empty spaces of the corners
	and substract that to C.
-If W is greater than the half of C then you need to check only one block.

This will be useful to get the number of turns we need for each row each time we have more than 1 row to check,
this calculation is performed on all the rows except the last one. For the last row we need to do something a little
bit different, that is not only checking that it exists but also add the extra slots you need to find the complete ship.
This means we will take the a little bit more than the half of the row covered.
Doing a experiment with different column sizes I realized that with a W of 2 finding a ship always take
C-1 turns, and that if W = C-1 then you need C turns. To be more specific about these findings I tested several cases
again:
C W		C W		C W
5 2	2	7 1	7	8 1 	8
5 3	3	7 2	6	8 2	7
5 4	4	7 3	5	8 3	6
5 5	5	7 4	5	8 4	5
6 2	5	7 5	6	8 5	6
6 3	4	7 6	7	8 6	7
6 4	5	7 7	7	8 7	8
6 5	6			8 8	8
6 6 	6
This one has a very similar pattern but with different results.
-If W is 1 it takes C turns
-If W is lesser or equal than the half of C then it takes C-(W-1) turns
-If W is greater than the half of C then it takes W+1 turns.

With both parts of the process already solved the last thing we need to do is sum the turns taken for each row
and that should give us the final result.

<<<SOLUTION>>>  
The solution would be something like this:
int brattleship(int r, int c, int w){
	int rowi;
	int turns = 0;
	for (rowi = 1; rowi <= r; ++rowi)
	{
		//printf("We are in %d\n",rowi );
		if (rowi == r) //On the last row
		{
			if (w == 1)
			{
				//printf("W = 1\n");
				turns += c;
			}else if((float)w <= ((float)c/2)){
				printf("Less or equal than the half\n");
				turns += c-(w-1);
			}else{
				printf("Greater than the half\n");
				if (w == c)
				{
					turns += w;
				}else{
					turns += w+1;
				}	
			}
		}else{ //Any other row
			if (w == 1)
			{
				turns += c;
			}else if((float)w <= ((float)c/2)){
				turns += c-((w*2)-2);
			}else{
				turns += 1;
			}
		}
	}
	return turns;
}

<<<ANALYSIS>>>

This solution takes 



