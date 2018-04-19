=================================================================================================
###Kata 8: inflight entertainment system
=================================================================================================

You've built an inflight entertainment system with on-demand movie streaming.

Users on longer flights like to start a second movie right when their first one ends, but they complain that the plane usually lands before they can see the ending. So you're building a feature for choosing two movies whose total runtimes will equal the exact flight length.

Write a function that takes an integer flight_length (in minutes) and a list of integers movie_lengths (in minutes) and returns a boolean indicating whether there are two numbers in movie_lengths whose sum equals flight_length.

When building your function:

    Assume your users will watch exactly two movies
    Don't make your users watch the same movie twice
    Optimize for runtime over memory


---------------------------------------------------------------------------------------------------------------------------------------------
Lets say that the input is a list if touples, the first value is the name of the movie and the second value is the length of it. Also, we receive an extra number that is the flight length.
Our function is going to receive then a list and an integer.

It is possible that multiple answers exists, for example:
	For a flight that lasts 3 hours we could watch two movies that last 1 hour and 2 hours in different order.
	1 -> 2 = 3
	2 -> 1 = 3
I'm going to create a solution that takes only the first answer it finds.

As the problem is asking for runtime over memory I think I need a hash table, that would make the searches more time efficient.
First I have to initialize the hash table, each element in the list is going to be saved in the hashing table with the movie's length as the key and the movie's name as the value.
If a movie has a lenght greater than the flight lenght then it not saved in the hash table as the user would never finish watching it.
I use the movie's lenght as the key because fo each movie I'm looking for another movie that completes the flight time, I can search by the movie's length and get all the movies that last that time.

This will lead us toa problem. If a movie of half the lenght of the flight is taken a the first movie, then the same movie can be returned as the second movie as well when I look at it at the hash table.
A conditional that checks that the movie is not the same can solve this problem.

The solution would go like this:

def findTwoMoviesForFlight(moviesList, flightLenght):
	moviesLenghtDict = {}
	for movie in moviesList:
		if movie.lenght < flightLenght:
			moviesLenghtDict[movie.lenght] = movie.name
	
	for movieTuple in moviesLenghtDict:
		remainingTime = flightLenght - movieTuple.key 
		if moviesLenghtDict[remainingTime] != null:
			if moviesLenghtDict[remainingTime] != movieTuple.value:
				return movieTuple.value + moviesLenghtDict[remainingTime] 
	return 'No pair of movies found for flight time'

As I was writing this solution I realized that the problem was a lot easier.
Input: int flightLength, int[] moviesLenght
Output: bool - If two numbers are found

As my previous solution was similar I'm going to stick with that, I'm just changing some little things. 

