#include <stdio.h>
#include <string.h>

int main(int argc, char **argv){
	char *fileName = "myFile.txt";
	char *search = argv[1];
	char *replace = argv[2];
	int character;
	int firstCharacter;
	long streamPos =0;
	int i = 0;
	int isReplaced = 0;
	FILE *myFile = fopen(fileName, "rw");
	while(1){
		streamPos = ftell(myFile);
		firstCharacter = character;
		character = fgetc(stdin);
		if(feof(stdin)){
			break;
		}
		if (character == search[0])
		{
			i = 0;
			while(!feof(myFile) && search[i] == character){
				character = fgetc(stdin);
				i++;
			}
			if(feof(myFile)){
				break;
			}
			if (i == strlen(search))
			{
				fputs(replace, stdout);
				isReplaced = 1;
				fseek(myFile, -1, SEEK_CUR);
			}else{
				//rewind
				character = firstCharacter;
				fseek(myFile, streamPos, SEEK_SET);
			}
		}
		if(!isReplaced){
			fputc(character,stdout);
		}
		isReplaced = 0;
	}
	fclose(myFile);
	return 0;
}