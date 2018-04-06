=========================================================
Partial 2: Save humanity
========================================================

Oh!! Mankind is in trouble again. This time, it's a deadly disease spreading at a rate never seen befo
re. The need of the hour is to set up efficient virus detectors. You are the lead at Central Hospital and 
you need to find a fast and reliable way to detect the footprints of the virus DNA in that of the patient.
The DNA of the patient as well as of the virus consists of lowercase letters. Since the collected data
is raw, there may be some errors. You will need to find all substrings in the patient DNA that either exactly
matches the virus DNA, or has at most one mismatch, i.e., a difference in at most one location.
For example, "aa" and "aa" are matching, "ab" and "aa
" are matching, while "ab" and "ba" are not.

Input Format
The first line contains the number of test cases, t. t test cases follow.
Each test case consists of a single line containing two space-separated strings 
p(the patient DNA) and v(the virus DNA).

Constraints
-1 <= t <= 10 
-p and v contain at most 10^5 characters each.
-All characters in p and v are lowercase English letters.

Output Format
For each test case, output a single line containing a space-delimited list of starting indices 
(0-indexed) of substrings of p which are matching with v according to the condition mentioned above.
The indices have to be in increasing order. If there is no matching substring, output 
No Match!.

----------------------------------------------------------------------------------------------------------------------------------------

The first solution attempt I can think of is to iterate trough the whole array and taking each index as the start of the substring.
Then, for each position in both the first word as in the substring I'm going to compare the chars and count how many matches with the
substring it has, if the number of matches is less than the size_of_the_substring-1 then it is not a match and advances with the next
index taking it as the start of the substring. While checking for matches I'm going to print each index separated with a space.
I realized that if the virusDNA size is grater than the humanDNA size then it can´t be a match.

Solution Pseudo-code:

def checkPatient(patientDNA, virusDNA){
	patientDNASize = size(patientDNA)
	virusDNASize = size(virusDNA)
	
	if virusDNASize > patientDNASize:
		print("No match!\n")
		return
	matched = false;
	for (i = 0; i < patientDNASize-virusDNASize; i++):
		matches = 0
		for (j = 0; j < virusDNASize; j++):
			if patientDNA[i+j] == virusDNA[j]:
				matches+=1
		if matches >= (virusDNASize-1):
			matched = true;
			print(i + " ")
	if matched:
		print("\n")
	else:
		print("No match!\n")	
}
	
As if it is in C the problems I'm going to have it's while printing the solutions, perhaps I'm going to need to build a string instead
of sepparating prints by commas. Also, getting the size of a string passed as a parameter and reading the input can be a little bit tricky.

Complexity:
I'm going to iterate each character of the string that has size N and for each character I'm going to check the substring with size M.
As the substring is always shorter than the string we can remove the last iterations of the string M spaces. This means that the first
iteration is only going to do N-M steps, then for each step we do M steps and that let us with a O((N-M)^M).