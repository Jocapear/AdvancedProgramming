=========================================================
1180. Stone Game
========================================================

Two Nikifors play a funny game. There is a heap of N stones in front of them. Both Nikifors in turns take some stones from the heap. 
One may take any number of stones with the only condition that this number is a nonnegative integer power of 2 (e.g. 1, 2, 4, 8 etc.).
Nikifor who takes the last stone wins. You are to write a program that determines winner assuming each Nikifor does its best.

Input
An input contains the only positive integer number N (condition N = 10250 holds).

Output
The first line should contain 1 in the case the first Nikifor wins and 2 in case the second one does. 
If the first Nikifor wins the second line should contain the minimal number of stones he should take at the first move in order to 
guarantee his victory.

Sample
input	output

8	1
	2
----------------------------------------------------------------------------------------------------------------------------------------

<<<BREAKDOWN>>>

While reading the problem description I found a difficulty very quicly, I didn't understand what "assuming each Nikifor does its 
best" means, at first. I could ignore this phrase and check every case with brute force and a thousand nested Fors but I had
to try at least to understand what is asking me. I get it, it's like a competition and every player has to do its best to win but 
that part is what wasn't clear to me. I din't know ho to chose what is better for each player so I had to think on all the 
possibilities firsts, that would help me to understand the game better and define what is a good move for each player.
To explain myself better I'm going to show a few scenarios for different quantity of stones:

O is a stone picked by the player 1 and 0 is a stone picked by player 2
1 Stone  [O] 	  	Player 1 always wins

2 Stones [O0]		If player 1 picks one rock it would surrender the game to player 2.
2 Stones [OO]		Player 1 can win in 1 turn

3 Stones [O00]		Happens the same, player 1 shouldn't start picking 1 rock
3 Stones [OO0]		But, if it picks 2 the game is lost anyways, player 2 always wins.

4 Stones [O00O]		If player 1 picks 1 rock and player 2 goes with 2 player 1 wins
4 Stones [O0O0]		Same starting scenario but player 2 choses to go with 1, player 1 could pick two and win but its dumb 
			and chose one and loses. Here I started to understand that going for each case on this problem It's not
			what I should do.
4 Stones [O0OO]		If player 1 does its best it will take the win. This confirms that if player 1 starts with one stone it
			will win.
4 Stones [OO00]		If player 1 picks 2 rocks it loses unless player 2 is dumb and next scenario happens.
4 Stones [OO0O]		Another dumb scenario, but for player 2. Clearly this should't happen. Supposing that each player does its
			best if player 1 starts with 2 will lose. 
4 Stones [OOOO]		Player 1 wins instantly. This is not what we are looking for unless it's the only way to win.
5 Stones [O0000]	Player 1 shouldn't start with one.
5 Stones [O00OO]	Dumb scenario.
5 Stones [O00O0]	Very dumb scenario.
5 Stones [O0OO0]	Another way for player 2 to win, but first is better. Dumb scenario.
5 Stones [O0O00]	Dumb scenario.
5 Stones [OO00O]	If player 2 picks 2 stones after 2 were picked it will lose, it should try a different number
5 Stones [OO0OO]	Player 1 is smart and wins anyways
5 Stones [OO0O0]	Dumb scenario.
5 Stones [OOOO0]	Dumb scenario.
6 Stones [O0000O]	Here i'm starting to see how I make this process. I always start low for player 1 picking the less posible
			to see if this is the answer, then player 2 picks the most it can to see if it can instantly win, if player
			2 loses I move to the next case, picking less. Dumb scenario.
6 Stones [O00OO0]	Now player 2 wins, after picking 2 rocks player 1 follows with the same logic and tries to take the most
			rocks it can but player 2 wins, so it will move to the next case.
6 Stones [O00O00]	Player 2 won anyway, player 1 should pick another number to start. Dumb case.
			If player 2 is not dumb, player 1 can't win. So picking 1 stone is a definitive loss for player 1.
6 Stones [OO0000]	Player 1 shouldn't start with 2. As the remaining stones are exactly a power of 2 it's useless to process
			the remaining cases. This is a definitive move so I will not write the remaining cases for 2 starting rocks.
6 Stones [OOOO00]	Again, player 1 instantly loses. 2 remaining rocks makes player 2 a winner. 

At this point I understood more or less the choices I have to make to build te behaviour for my algorith. I have to think as the
2 players and if I lose I should try picking less rocks. Only the first move start from 1, the others always try to take the maximum
possible. If the remaining rocks are a power of two that makes the player in turn an instant winner. Every time player one wins
I have to give him priority over player 2, player 2 is only the winner if player 1 can't win by picking any number.
To make it short the answers 
for the cases I stated above are:

1	1
	1

2	1
	2

3	2

4	1
	1

5	1
	2

6	2

7	??	Let's see. 1-|4|-2, retry, 1-|2|-4, again, 1-1-|4|-1, it works but not for player 1, 1-1-|2|-2-1 , player 2
		has its last chance, 1-1-2-1-2. Its decided, player 1 always wins.  
7	1
	1

One problem I noticed is how I would know how deep in the iteration I'm. When to stop? When do I know I have no more options or
that I have more chances? 
	It's simple. If I'm in my turn I have to see one turn ahead, If I see the remaining rocks are a power of two I rest one
	to the rocks I was going to pick until the remainig rocks are not a power of two. If I find I can't reduce more then I
	lose. This will avoid dumb moves. 
	
	When I pass the turn the other player does the same and looks one turn ahead. It he can procced with a save move it
	will give the turn to the other player until one sees that has no choice and loses. That's what will give the result
	taking account the best effort of each player.

	I think this problem is easily coded with recursion, to prove the method stated before I'm going to draw the process.
	1 - [4] 2 Loses	
	1 - [2] 2 Loses
	1 - [1 It's possible, return recursion
	1 - [1 - 4] 1 Loses
	1 - [1 - 2 It's possible, return recursion
	1 - [1 - 2 - 2] 2 Loses
	1 - [1 - 2 - 1] 2 Loses
 	1 - [1 - 2 - Oh noes, player 2 can't go further, player 2 must surrender and player 1 wins]
	1 - [1 - Player 1 wins]
	1 - [Oh noes, player 2 can't go further, player 2 must surrender and player 1 wins]
	1 - Receives a player 1 win
	Return 1
	 
Another problem is to decide when player 2 wins. If I know player 1 win then that's what I return, but when the first recursion
gets that player 2 wins then it should increase the number of stones. For that I'm going to make two separate parts, one to
simulate the first turn by picking the less rocks I can and another process to look turns ahead (the recursive part) and depending
what I get from the recursion I'm going to decide if I return the answer or if I increase the number of rocks I pick from the 
beginning.

The last problem I can think of is how I'm going to know what is the biggest power of two by looking at the remaining rocks. I
know that the next power of two is only multiplying the number by two, and to move one down is dividing it by two. But what should
I do if I see 6 rocks remaining and I want to take the greatest power of two that I can? One simple solution is to start from one
and iterate until a power of two is greater than the remaining rocks and return the last one I saw. I'm going to go for that
solution and will try to avoid any more complications.

<<<SOLUTION>>>  
The solution will go like this

for i = 1, i <= n, i*2
	if i == n
		print(1)
		print(i)
	else
		if n-i == greatestPowerOfTwo(n-i)
			//Continue with the for, increment your picked rocks
		else if lookAhead(n-i, 2) 
			print(1)
			print(i)
		else
			break
print(2)

function lookAhead(stones, turn)
	stonesPicked = greatestPowerOfTwo(stones)
	
	if stones == stonesPicked
		if turn == 1
			return True
		else
			return False
	else
		remainingStones = stones - stonesPicked
		while remainingStones == greatestPowerOfTwo(remainingStones)
			if stonesPicked == 1
				if turn == 1
					return False
				else
					return True
			else
				stonesPicked /= 2
				remainingStones = stones - stonesPicked
		if turn == 1
			return lookAhead(remainingStones, 2)
		else
			
			return lookAhead(remainingStones, 1)

function greatestPowerOfTwo(n)
	if n == 1
		return 1
	temp = 1
	while temp*2 <= n
		temp *= 2
	return temp 

<<<ANALYSIS>>>

The main procedure starts with a for loop that increase multiplying the number by two, that means that we have log(n) steps there. Inside the loop we call for recursion
every time every time we don´t lose, on each recursion we have another log(n) loop until we see that we don't lose and then we enter another recursion. As deeper as
we go in the recursion we always decrease the number of n. This decremental is importan because it tells us the number of recursions we perform, for simplicity
i'm going to say that we do log(n) recursions with a log(n) loop inside. So, for the main process we got a log(n) loop with a log(n) recursion inside, that makes
log(n) * log(n) but that recursion makes another log(n) loop inside each time it goes in, that makes log(n)*log(n)*log(n). In conclusion, this algorithm has O(log(n)^3)
complexity. I can't think of a better way rather than just finding the greatest power of two in a faster, probably having a hash table that saves every power of two
we need from the beginning and for each number from 1 to n saves a value. 


