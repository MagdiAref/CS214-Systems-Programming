#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]){
  int wordCount = 0;
  char listWords[200][100];
  char tempArr[200];
  
  for (int i = 0; i < 100; i++){
    fgets(listWords[i], sizeof(listWords[i]), stdin);
    wordCount++;
    }
  
  for (int j = 0; j < wordCount; ++j){
    for (int k = j + 1; k < wordCount; ++k){
      if (strcasecmp(listWords[j], listWords[k]) > 0){
	strcpy(tempArr, listWords[j]);
	strcpy(listWords[j], listWords[k]);
	strcpy(listWords[k], tempArr);
      }
    }
  }

  for (int q = 0; q < wordCount; ++q){
    fputs(listWords[q], stdout);
  }
  return 0;

}
