=========================================================
Kata 3: 657. Judge Route Circle
========================================================

Initially, there is a Robot at position (0, 0). Given a sequence of its moves, judge if this robot makes a circle, which means it moves back to the original place.

The move sequence is represented by a string. And each move is represent by a character. The valid robot moves are R (Right), L(Left), U (Up) and D (down). 
The output should be true or false representing whether the robot makes a circle.

Example 1:

Input: "UD"  Output: true  

Example 2:

Input: "LL"  Output: false  

------------------------------------------------------------------------------------------------------------
Constrains:
	-Only "L", "R", "D", "U" letters are accepted
	-The letters are only uppercase

This problem can be easily seen as a grid and each letter represents a movement in the grid. We need to iterate trough the whole word and simulate the robot movement
in the grid. Each movement is going to add or substract 1 either in the X axis or the Y axis. For each letter we are going to use these cases:
	L -> (-1, 0)
	R -> (+1,0)
	U -> (0,+1)
	D -> (0,-1)
To determine if it ends in the same place at the end of passing through the whole word we just have to check if it is equal to (0,0).

The iteration of the string is going to cost us O(n). For each letter we have to check the movement in the grid and its really just several "if"'s cases for each of 
the four letters and inside we just need to make one opperation so we can count it as constant time O(1). Overall the program is just O(n). 