#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <math.h>
/*
//be able to read from stdin 
int main (int argc, char* argv[argc+1]){
int word_counter;
char 
  while ( (word = gerchar()) != EOF)
     putchar(tolower(word);
             return 0;
             
*/

int main(int argc, char* argv[argc + 1])
{
    int i = 0;
    int j = 0;
    // Finding the contents for the string and storing them into my temp
    char temp_str[100][50] = { "" };       
    // loop to check all the wrods up to 100 for the stdin
    while(i < 100) {   
        if (!fgets (temp_str[i], sizeof temp_str[i], stdin)) {
            break; 
        }
        // finding the length of the string and storing it
        size_t len = strlen (temp_str[i]); 
        if (temp_str[i][len-1] == '\n') {
            temp_str[i][--len] = 0;     
        }
        ++i;
    }
    j = i;
    putchar('\n');
    // creating a word counter to store the words that are repeated 
    int word_counter;
    word_counter = 1;
    i = 1;
    // check over and if the words are equal to each other then keeping adding to the counter
    while(i < 100){
        if (strcmp(temp_str[i-1],temp_str[i]) == 0){
            word_counter++;
            // print out the contents if the last string is met 
            if (i == j-1){
                printf ("%d %s\n", word_counter, temp_str[i-1]);
                return 0;
            }
            // else print out the counter and reset it back to zero 
        } else{
            printf ("%d %s\n", word_counter, temp_str[i-1]);
            word_counter = 1;
        }
        ++i;
    }    
        
}
