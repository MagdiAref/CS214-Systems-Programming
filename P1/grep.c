/*Write a program that takes a string as a command-line argument and then                                                                                                              
reads from stdin until the user closes stdin (with ctrl-d). It should print                                                                                                            
every line that contains the given string. It should be case-sensitive by                                                                                                              
default, but case-insensitive if the command line option -i is given before                                                                                                            
the string.*/

#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[]) {

   int caseSensitive = 1;
   char* grepWord;

   if(strcmp(argv[1], "-i") == 0){
      caseSensitive = 0;
      grepWord = argv[2];
   }
   else{
      grepWord = argv[1];
   }

   while(1){
      char input[1000];

      char *line = fgets(input, 1000, stdin);

      if(line == NULL){
         break;
      }

      char* ret;

      if(caseSensitive){
         ret = strstr(input, grepWord);
      }
      else{
        ret = strcasestr(input, grepWord);
      }

      if(ret){
         printf("%s", input);
      }
   };
   return 0;
}

