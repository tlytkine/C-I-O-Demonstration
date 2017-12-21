#include <stdio.h>
#include <math.h>
#include <string.h>
#include <stdlib.h>

int numWordsFirst;
int numWordsSecond;
int i;
char **words = NULL;
char **first = NULL;
char **second = NULL;
int lineNum [7];
int lineNumber;
int charNum;
int j;

void makeWordList (char *fileName)
{	
	char **words = malloc(10 * sizeof(char*));
	for(i=0; i<10; i++){
        words[i] = (char *)malloc(10+1);
        }
	for(i=0; i<10; i++){
	words[i] = NULL;
	}
        int maxChar;
        char inputLine [10]; 
        char ch;;
        int cursorPosition;
        FILE *dataFile;

        dataFile = fopen (fileName, "r");

        lineNumber = 0;
        cursorPosition = 0;
	charNum = 0;

        ch = fgetc (dataFile);

        while (ch != EOF) {
                if (ch != '\n') {
		if (ch == ' '){
		inputLine[cursorPosition]= '\0';
		printf( "%s", inputLine);
                printf("\n");
		words[lineNumber] = inputLine;
                lineNum[charNum] = lineNumber;
		charNum++;
		lineNumber++;
		cursorPosition = 0;
                }
		inputLine[cursorPosition] = ch;
		words[lineNumber] = inputLine;
		lineNum[charNum] = lineNumber;		
		charNum ++;
		cursorPosition ++;	
		}
                else {
                inputLine[cursorPosition] = '\0';
		words[lineNumber] = inputLine;
                lineNum[charNum] = lineNumber;
		lineNumber ++;
		charNum ++;
                printf(" %s", inputLine);
		printf("\n");
                cursorPosition = 0;
                }
                ch = fgetc (dataFile);
                }
                fclose (dataFile);
		free(words);
           
}


char **getWordList ()
{
return (char **)words;
}

int getNumWords ()
{
int x = lineNum[charNum]; 
return x;
}

void compareFiles (char *fileName1, char* fileName2)
{

makeWordList (fileName1);
first = (char**) getWordList ();
numWordsFirst = getNumWords();

makeWordList (fileName2);
second = (char**) getWordList ();
numWordsSecond = getNumWords();

// Compares and prints result 
for (i=0; i<numWordsFirst; i++) {
for (j=0; j<numWordsSecond; j++) {
int d = 0;
  if (strcmp(first[i],second[j]) == 0){
printf("Word #: %d: same in each file", d);
printf("On line %d in file fileName1: %s", i, first[i]);
printf("On line %d in file fileName1: %s", j, second[j]);
}
d++;
}
}

}
