#include <stdio.h>

typedef struct s {
	char name[20];
	char lastName[20];
	unsigned int id;
	unsigned char cal;
} Student;

int main(){
	Student myStudent;
	char * lastName = "studentDb.data";
	char *lastName = "Perez7";
	FILE *data;

	data = fopen(studentDb, "rb");
	while(1){
		fread(&myStudent, sizeof(Student), 1, data);
		if(feof(data)){
			break;
		}

		if (!strcmp(myStudent.lastName, lastName)){
			printf("name %s\n",myStudent.name );
			printf("name %s\n",myStudent.lastName );
			printf("name %d\n",myStudent.id );
			printf("name %d\n",myStudent.cal );
			break;
		}
	}

	fclose(data);

	return 0;
}