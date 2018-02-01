#include <stdio.h>
#define MIN_SIZE 6
#define MAX_SIZE 20
#define MAX_CHAR 4095

int strongPasswordChecker(char * s){
	int sSize = 0;
	
	int hasLower = 0;
	int hasUpper = 0;
	int hasDigit = 0;

	int unvalidChar = 0;
	int consecutiveChar = 2; //The code will only count 3 consecutive characters if it sees the same char twice before
	int repeatedChar = 0;

	char prevChar = s[0];
	char lastChar = s[1];
	for (int i = 0; i < MAX_CHAR; ++i)
	{
		if (i > 1)
		{
			if ((char)s[i] == lastChar && (char)s[i] == prevChar )//Here it needs to see 2 of the same characters before this one
			{
				consecutiveChar += 1;
			}else{
				repeatedChar += consecutiveChar/3; //3 is the number of repetitions in a row that is not allowed
				consecutiveChar = 2;//Restart the variable
			}
		}
		prevChar = lastChar;
		lastChar = (char)s[i];
		if (s[i] == 0)
		{
			break;
		}else{
			sSize += 1;
			if (s[i] >= 65 && s[i] < 91) //From A to Z
			{
				hasUpper = 1;
			}else if (s[i] >= 97 && s[i] < 123) //From a to z
			{
				hasLower = 1;
			}else if (s[i] >= 48 && s[i] < 58) //From 0 to 9
			{
				hasDigit = 1;
			}else{
				unvalidChar += 1;
			}
		}
	}

	int charReq = 0;
	int deletions = 0;
	int insertions = 0;
	printf("Your password has lenght of: %d\n",sSize );
	if (!hasUpper)
	{
		charReq += 1;
		printf("Your password needs an UPPERCASE letter\n");
	}
	if (!hasLower)
	{
		charReq += 1;
		printf("Your password needs a LOWERCASE letter\n");
	}
	if (!hasDigit)
	{
		charReq += 1;
		printf("Your password needs a NUMBER\n");
	}

	printf("%d needs replacement\n", repeatedChar);

	int changesNeeded = 0;
	if (sSize < MIN_SIZE)
	{
		insertions += MIN_SIZE-sSize;
		printf("Your password needs %d more characters\n", MIN_SIZE-sSize);
		if (charReq > repeatedChar)
		{
			if(insertions > charReq){
				changesNeeded = insertions;
			}else{
				changesNeeded = charReq;
			}
		}else{
			changesNeeded = insertions + repeatedChar;
		}
	}else if (sSize > MAX_SIZE)
	{
		deletions += sSize - MAX_SIZE;
		printf("Your password needs %d less characters\n", sSize - MAX_SIZE);
		if (charReq > repeatedChar)
		{
			changesNeeded = deletions + charReq;
		}else{
			if (deletions >= repeatedChar)
			{
				changesNeeded = deletions + charReq;
			}else{
				changesNeeded = repeatedChar;
			}	
		}
	}else{
		if (charReq > repeatedChar)
		{
			changesNeeded = charReq;
		}else{

			changesNeeded = repeatedChar;
		}
	}
	return(changesNeeded);
}

int main(){
	//char password[] = "aaaaa"; //2
	//char password[] = "thisisaverylargestring"; //4
	//char password[] = "aaaabbbbB1testing190"; //2
	//char password[] = "aaabbcccddeeeffggghhii"; //4
	//char password[] = "aaaaaaaabbbbbbbbcccccccc"; //8
	//char password[] = "bbbqaaaaqcccqqrrqqrr123"; //5
	//char password[] = "a"; //5
	//char password[] = "aaaaaaaaaaaaaaaaaaaaa"; //7
	//char password[] = "aaAaa1aaCaaDaaEaaFaGa"; //1
	//char password[] = "hoAISJDBVWD09232UHJEPODKNLADU1"; //10
	//char password[] = "1010101010aaaB10101010"; //2
	//char password[] = "abAbabababababababaaa"; //2
	char password[] = "1234567890123456Baaaaa"; //This one is wrong
	printf("You need %d changes in your password\n", strongPasswordChecker(password));
	return 0;
}