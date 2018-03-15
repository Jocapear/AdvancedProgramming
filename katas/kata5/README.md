=================================================================================================
###Kata 5: Infografic
=================================================================================================
You want to build a word cloud, an infographic where the size of a word corresponds to how often it appears in the body of text.

To do this, you'll need data. Write code that takes a long string and builds its word cloud data in a hash table ? , where the keys are words and the values are the number of times the words occurred.

Think about capitalized words. For example, look at these sentences:

"After beating the eggs, Dana read the next step:"

"Add milk and eggs, then add flour and sugar."

What do we want to do with "After", "Dana", and "add"? In this example, your final hash table should include one "Add" or "add" with a value of  2

---------------------------------------------------------------------------------------------------------------------------------------------
Constrains:
	-Will always receive a string
	-It is not case sensitive

To simplify the problem I'm going to think of it as a word counter, we need to know how many times a word is repeated in a given string. To know if I'm in a different word I need to
differentiate spaces, to do this I'm going to iterate through the char array constructing a word character by character until I see a space, then I add the constructed word to the hash
table and continue iterating the input string until I reach the end. While iterating I can set all the character I see to lowercase and thats how I solve the not case sensitive problem.
When adding a word I need to check if it's a new word, if that's the case then I insert a new key with value of one, otherwise I modify a key and add one to the previous value.   

The teacher already shared with us an implementation of a hash table, to use it in another file I needed to make both C files a compiled form with the "g++ -c" command, that creates
O files that i can use later to create an executable file that uses both compiled versions with the command "g++ main.o hash.o". 

The process iterates through the whole input characters, that give us a n in time complexity. Then it makes searches and inputs in the hash but those operations are O(1). 
At the end we iterate the hash map to print the results and we can surely say that the number of characters in the hash map can be less or equal than the number of characters in the input because we are eliminating duplicates. So, m <= n and results in O(n+m). 

The complexity of this process is O(n+m), n being the charactes of the input and m being the number of unique characters. 