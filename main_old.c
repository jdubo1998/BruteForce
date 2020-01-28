//#include <stdio.h>

void overload (int a);
void bruteForce (char file[]);
int getFilelength (char file[]);
//char readFile[] (char file[]);

int main_old (int argc, char *argv[])  {
	if (argc != 3) {
		printf("%s\n", "ERROR: BruteForce input_file output_file");
		return 1;
	}


}
//============================================================================
//char readFile[] (char file[] ) {
//    FILE *fp;
//	int c;
//
//	fp = fopen(file, "r");
//	while(1)
//	{
//		c = fgetc(fp);
//		if( feof(fp) )
//		{
//			break ;
//		}
//		printf("%c", c);
//	}
//	fclose(fp);
//}
//============================================================================


//============================================================================
//void bruteForce (char ciphertext[]) {
//    int arraySize = (int) sizeof(ciphertext) / sizeof(ciphertext[0]);
//
//    for (int i = 0; i < arraySize; i++) {
//            ciphertext[i] += 1;
//    }
//
//    FILE *fp;
//	int c;
//
//	fp = fopen("", "r");
//	while(1)
//	{
//		c = fgetc(fp);
//		if( feof(fp) )
//		{
//			break ;
//		}
//		printf("%c", c);
//	}
//	fclose(fp);
//}
//============================================================================

int getFileLength (char file[]) {
    FILE *fp;
    fp = fopen(file, "r");

    int c;
    int length = 0;

    while((c=fgetc(fp))) {
        length++;
        if(c == EOF) break;
    }

    fclose(fp);

    return length;
}

void bruteForce (char file[]) {
    int length = getFileLength(file);

    char ciphertext[length];

    // ==========================================================
    FILE *fp;
    fp = fopen(file, "r");

    int c;

    for (int i = 0; i < length; i++) {
        c = fgetc(fp);
        if (c == EOF) break;
        else ciphertext[i] = c;
    }

    fclose(fp);
    // ==========================================================

    for (int i = 0; i < length; i++) {
        ciphertext[i] += 1;
    }

    FILE *fp;
	int c;

	fp = fopen("", "r");
	while(1)
	{
		c = fgetc(fp);
		if( feof(fp) )
		{
			break ;
		}
		printf("%c", c);
	}
	fclose(fp);
}
