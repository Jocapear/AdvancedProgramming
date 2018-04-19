#include <stdio.h>
#include <string.h>
//The first solution attempt I can think of is to iterate trough the whole array and taking each index as the start of the substring.
//Then, for each position in both the first word as in the substring I'm going to compare the chars and count how many matches with the
//substring it has, if the number of matches is less than the size_of_the_substring-1 then it is not a match and advances with the next
//index taking it as the start of the substring. While checking for matches I'm going to print each index separated with a space.
//I realized that if the virusDNA size is grater than the humanDNA size then it can´t be a match.

int checkPatient(char* patientDNA,char* virusDNA){
	int patientDNASize = strlen(patientDNA);
	int virusDNASize = strlen(virusDNA);

	//printf("%d\n", patientDNASize);
	//printf("%d\n", virusDNASize);
	
	if (virusDNASize > patientDNASize){
		//printf("Too long :(\n");
		printf("No Match!\n");
		return -1;
	}
		
	int matched = 0;
	int i;
	for (i = 0; i < patientDNASize-virusDNASize; i++){
		//printf("We are in %d\n", i);
		int matches = 0;
		int j;
		for (j = 0; j < virusDNASize; j++){
			//printf("Comparing %c with %c\n", patientDNA[i+j], virusDNA[j]);
			if (patientDNA[i+j] == virusDNA[j]){
				matches += 1;
			}
		}
		if (matches >= (virusDNASize-1)){
			//printf("Match found with %d matches\n", matches);
			matched = 1;
			printf("%d ", i);
		}		
	}
		
	if (matched){
		printf("\n");
		return 0;
	}else{
		printf("No match!\n");
		return -1;
	}
		
}
	
int main(int argc, char const *argv[])
{
	char patientDNA[] = "abbab";
	char virusDNA[] = "ba";

	char patientDNA2[] = "hello";
	char virusDNA2[] = "world";

	char patientDNA3[] = "banana";
	char virusDNA3[] = "nan";

	checkPatient(patientDNA, virusDNA);
	checkPatient(patientDNA2, virusDNA2);
	checkPatient(patientDNA3, virusDNA3);
}