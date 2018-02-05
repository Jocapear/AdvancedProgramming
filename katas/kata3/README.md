=========================================================
Kata 2: 420. Strong Password Checker
========================================================

A password is considered strong if below conditions are all met:

    It has at least 6 characters and at most 20 characters.
    It must contain at least one lowercase letter, at least one uppercase letter, and at least one digit.
    It must NOT contain three repeating characters in a row ("...aaa..." is weak, but "...aa...a..." is strong, 
	assuming other conditions are met).

Write a function strongPasswordChecker(s), that takes a string s as input, and return the MINIMUM change required to 
make s a strong password. If s is already strong, return 0.

Insertion, deletion or replace of any one character are all considered as one change.



------------------------------------------------------------------------------------------------------------
Constrains:
	-Only letters and digits
	-More than 20 characters is a weak password
	-The string can't be empty
	-There are only numbers and letters

One simple solution is to have flags for the lower caseletter, uppercase letter and digit. Update the flags while iterating the
string and count the number of characters. That will only tell us if our password is strong. To detect flaws we could have a variable
that keeps track of the extra characters we have, "aaaa" would count two extra or replasable characters. For this we are going to 
need a variable that saves our last seen character and based on that keep counting if we still see it. Also, if a flag is still
false we could count it as a character that we need to insert. Finally, if our string is short we add to a variable of insertions
we need, if its to long we add to a variable of deletions. For each insertion we need we can replace a deletion.

Now we need to solve the special cases. For that i'm going to need a few input examples.
"aaaaa" Size = 5
For this case I have 3 extra letters, I'm still missing a uppercase and a digit, and to get to the minimum size I need one more
character. The minimum move is 2 since i can only replace one in the middle with an uppercase and then add one digit like this
"aaAaa2". To get this done in my code I need to know the amount of characters in a row I have to see how many replacements I
need to cut the chain. For 3 I need 1, for 4 I need 1 too, for 5 I need 1 too, for 6 I need 2, 7 I need 2, 8 I need 2, 9 I need
3... this patter tells me that the size of the chain divided by 3 and a floor tells me the number of replacements I need to make.

There are a lot more cases, the number of replacements is defined by the maximum between repeated characters and number of
character types remaining. If we need to replace 5 characters to break repetitivity, but we are also missing a number and an
uppercase we could simply say that we need 5 replacements, only taking the maximum of the two as changing a repeated letter 
for a number or an uppercase does 2 corrections at the same time. Same could be said if we have to add an uppercase and a number
and we have to replace just one letter to break repetitive instances, we only need 2 moves(the maximum of the both), one for 
replacing the letter for a number and another for adding an uppercase.

I programmed my solution trying to avoid harcoding numbers, all the static numbers are defined on the top of the code so I can 
use them as variables. It´s still very harcoded tho, but I wrote a comment trying to explaing where those numbers came from. 
