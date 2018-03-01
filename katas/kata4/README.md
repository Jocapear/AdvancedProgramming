=========================================================
Kata 4: 65. Valid Number
========================================================

Validate if a given string is numeric.

Some examples:
"0" => true
" 0.1 " => true
"abc" => false
"1 a" => false
"2e10" => true

Note: It is intended for the problem statement to be ambiguous. You should gather all requirements up front before implementing one.
------------------------------------------------------------------------------------------------------------
Constrains:
	-Max string input is 255 char.
	-Numbers can have commas, not obligatory.
	-Only "e" is accepted in a number, after an "e" only integers are accepted.
	-Operations are not numbers.
	-Symbols "+" and "-" are accepted at the beginning of the number or after and "e"
	-White spaces may appear at the end or the beginning of the string but not in the middle.
	-Only decimal numbers are accepted
I think in this problem as an automaton. There are states and transitions, each time you receive an input you decide if it is correct
or wrong and then move to another state. I'm going to write down some intial thoughs about each state:

-First, I know I can start with a "+" sign , a "-" sign, a not zero number and a dot. It is important to say that after a sign I need
at least one number to be a valid number. Also, after a dot I need at least one number. 
-Second, after I started I can write as many numbers as I want. This state is going to be twice because we need one before and after
a dot. On the first appearance of this step I can encounter two exits, a dot or an "e". Each one leads me to a different part of the
automaton.
-Third, after writting a dot I need a number generator state, and if it receives an "e" I´m going to need a state that waits for a 
sign or a number. Like in the first state after the sign I need to write at least one number, I'm just going to handle a non final
state when receiving a sign that waits for a number input.
-Fourth, I need a state for failure that returns false inmediately. 

Not all states or cases are covered in the epxplanations above. To be more accurate I'm going to include a photo with the automaton
I drew in one of my notebooks. Before starting with the solution I need to know how I'm going to handle the input, what is each automaton
going to receive and what is going to send. What comes to my mind is that the first state gets the whole string, checks the first 
position and then passes the rest of the string to the next state, all the states work the same way. Now lets start with the solution.


def isNumber(string s):
	if s[0]=="+" or s[0] == "-" :
		standBy(s[1::])
	elif s[0].isDigit and s[0] != "0":
		numberState(s[1::])
	elif s[0] == ".":
		standBy2(s[1::])
	else:
		print(false)

def standBy(string s):
	if s[0].isDigit and s[0] != "0":
		numberState(s[1::])
	else:
		print(false)

def numberState(string s):
	if s[0].isDigit:
		if len(s) >= 2:
			numberState(s[1::])
		else:
			print(true)
	elif s[0] == ".":
		standBy2(s[1::])
	else:
		print(false)
def standBy2(string s):
	if s[0].isDigit and s[0] != "0":
		numberState2(s[1::])
	else:
		print(false)
def numberState2(string s):
	if s[0].isDigit:
		if len(s) >= 2:
			numberState2(s[1::])
		else:
			print(true)
	elif s[0] == "e":
		eState(s[1::])
	else:
		print(false)
def eState(string s):
	if s[0]=="+" or s[0] == "-" :
		standBy3(s[1::])
	elif s[0].isDigit and s[0] != "0":
		numberState3(s[1::])
	else:
		print(false)
def standBy3(string s):
	if s[0].isDigit and s[0] != "0":
		numberState3(s[1::])
	else:
		print(false)
def numberState3(string s):
	if s[0].isDigit:
		if len(s) >= 2:
			numberState3(s[1::])
		else:
			print(true)
	else:
		print(false)

This solution takes O(n) of time complexity as it needs to pass through the whole string to check each character.
