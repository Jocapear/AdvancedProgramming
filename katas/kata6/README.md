=================================================================================================
###Kata 6: Shadows of the Knight - Episode 1
=================================================================================================

What will I learn?

Binary searchIntervals

You have to manage indexes and list of a 2 dimensional array in this puzzle. You also discover the binary search algorithm and finally, it makes you know that batman is really good at cleaning windows.
External resources Multidimensional arrayBinary search2D Binary Search explained by Gaurav Sen
Statement

The goal of this puzzle is to guess the coordinate of a bomb (line and column of a 2 dimensional array). You will have to make a guess at each step of the puzzle and adjust it from given feedbacks. Of course, you have a limited number of guess.


---------------------------------------------------------------------------------------------------------------------------------------------
Before each jump, the heat-signature device will provide Batman with the direction of the bombs based on Batman current position:

    U (Up)
    UR (Up-Right)
    R (Right)
    DR (Down-Right)
    D (Down)
    DL (Down-Left)
    L (Left)
    UL (Up-Left)


Your mission is to program the device so that it indicates the location of the next window Batman should jump to in order to reach the bombs' room as soon as possible.

Buildings are represented as a rectangular array of windows, the window in the top left corner of the building is at index (0,0).


Constraints
1 = W = 10000
1 = H = 10000
2 = N = 100
0 = X, X0 < W
0 = Y, Y0 < H
Response time per turn = 150ms
Response time per turn = 150ms

We only know the size of the building, batman's position and a hit to the bomb. Every time we make a jump is better to make it the closest we can from our objective, to achieve this we can move half the distance to the corner of the building and each turn keep doing the same. 
Similar to a binary search, if we jump half the distance each turn we will reach our target faster than just checking each window.
We just need to check the direction to make the jumps in the 8 directions.
For each direction I calculate how many windows i have left and calculate the half of them, then substract or add that to the actual positiona accordingly to the direction. To avoid getting off the building i'm going to have coordinates that restric the area where batman can jump.

This solution is going to have 8 if cases where it checks the direction, then execute a binary search for both dimensions. The solution is making two binary search at the same time, each has log(n) complexity. So the final complexity is log(max(n,m)) as depends of the greatest size
of the building. 
 