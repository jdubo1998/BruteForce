#include <stdio.h>

void readFile(char file[]);
int getFileLength();
void BruteForce(char plaintext[]);

//int main (int argc, char *argv[])  {

int main() {
    int argc = 3;
    if (argc != 3) {
        printf("%s\n", "ERROR: BruteForce input_file output_file");
        return 1;
    }

    char fileName[] = "test.txt";
    //readFile(fileName);

    char text[] = "Higmtliv";
    BruteForce(text);

    printf("%s\n", "Program Finished");
    return 0;
}

// int getFileLength(FILE *fp) {
int getFileLength() {
    FILE *fp;
    fp = fopen("words", "r");
    int c;
    int length = 0;

    while (1) {
        c = fgetc(fp);
        if (c != 1 && c != 10) length++;

        if (c == EOF) break;
    }

    fclose(fp);
    return length;
}

int compareWord(int *word1, int *word2, int word1_len, int word2_len) {
	int threshold;
    int length;

    if (word1_len >= word2_len) {
        length = word2_len;
    } else {
        length = word1_len;
    }

	if (length > 3) {
		threshold = (int) (length / 4) * 3; // At least 75% of the word has to be right. This is due to capitol special characters within the string.
	} else {
		threshold = 1;
	}

    for (int i = 0; i < length; i++) {
        printf("%c", word[i]);
        if (word1[i] == word2[i]) threshold -= 1;
        if (threshold < 1) return 1;
    }

    return 0;
}

void BruteForce(char plaintext[]) {
    int length = (sizeof (plaintext) / sizeof (plaintext[0]));
    int target_score = (int) (length / 3) * 2;

    int score = 0;
    int word[20];
    int deciphered = 0;
    char buffer[length - 1];
    int alph = 65;
    int strin = 0;

    FILE *fp;
    fp = fopen("words", "r");
    int c = 0;
    int file_len = getFileLength();
    //printf("Length: %d\n", file_len);
    int words[123][file_len][20];

    for (int charin = 0; charin < file_len; charin++) {
        c = fgetc(fp);
        //printf("%c", c);

        //printf("%c\n", c);

        //int letter = 0;
        if (c = feof(fp)) break;
        else {
            if (c == 10) {
                c = fgetc;
                if (alph == c) strin += 1;
                else {
                    strin = 0;
                    alph = c;
                }
                alph = charin;
                strin += 1;
            }
            // printf("Alph: %c (%d)\n", alph, alph);
            // printf("Strin: %d\n", strin);
            // printf("Charin: %d\n", charin);
            words[alph][strin][charin] = c;
        }
    }
    fclose(fp);

    int shifted = 0;

    for (int i = 0; i < length; i++) {
        buffer[i] = plaintext[i];
    }

    while (deciphered == 0) {
        int wordAt = 0;
        int score = 0;

        /* Shifts each char by 1. */
        for (int i = 0; i < length; i++) {
            buffer[i] += 1;
        }

        shifted += 1;

        //printf("Shifted: %d\n", shifted);
        if (shifted > 10) {
            break;
        }

        /* Compares words with dictionary.
        =================================
        Cycles through entire text file */
        for (int i = 0; i < length; i++) {
            /* Seperates words into arrays. */
            int max_size = 0;
            for (int j = i; word[j] < length; j++) {
                if (max_size < 100) {
                    if (buffer[j] != 32) {
                        word[j] = buffer[i];
                        max_size++;
                    } else {
                        wordAt = i; // Index of first char within the array, index of word.
                        i = j + 1;
                        word[j] = -1; // Sets value of space as -1, to indicate end of word.
                        max_size = 0;
                        break;
                    }
                }
            }

            int alphabetic = word[0];

            // How many words are in that section of alphabet.
            int alph_len = (int) (sizeof(words[alphabetic]) / sizeof(words[alphabetic][0]));

            /* Get word size of ciphered message */
            int word2_len = 100;
            for (int i = 0; i < 100; i++) {
                if (word[i] == -1) {
                    word2_len = i + 1;
                }
            }

            /* For each word with the same letter */
            for (int l = 0; l < alph_len; l++) {
                int word1_len = (int) sizeof(words[alphabetic][l]) / sizeof(words[alphabetic][l][0]);

                score += compareWord(words[alphabetic][l], word, word1_len, word2_len);
                printf("        %d\n", words[alphabetic][l][], compareWord(words[alphabetic][l], word, word1_len, word2_len));
            }
            printf("----------------------------------------------\n");
        }
        //printf("Score: %d\n", score);
        if (score >= target_score) {
            deciphered = 1;
        }
    }

    // for (int i = 0; i < length; i++) {
    //     printf("%c\n", buffer[i]);
    // }
}
