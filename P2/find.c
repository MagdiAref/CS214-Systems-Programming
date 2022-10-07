/*
The findcommand takes a pattern as a command-line argument and recur-sively searches through directories to find a 
filename matching that pattern.
It should print a relative path starting with “./” for every file/directorythat matches.
For example, running./find ls.cfrom within thehw2directory shouldprint./ls.c. 
If run from the parent directory, the output would be./hw2/ls.c.There may be multiple matches. 
If we run./find .cfrom within thehw2directory, we should see:./find.c./ls.c./tree.cThe output does not need to be sorted. 
If nothing matches, it shouldn’tprint anything. Pattern matching should be case sensitive.

*/
#define _GNU_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

// want to create a method that will find and transver
void findDIR(const char *target_name, int counter ){
     DIR *dir;
    struct dirent *entry;

    if (!(dir = opendir(target_name)))
        return;

    while ((entry = readdir(dir)) != NULL) {

}

}
int main(){
     int target,counter;
     DIR *fp;
   struct dirent *dir;
   fp = opendir(".");
 
   if (fp){
       while ((dir = readdir(fp)) != NULL){
           printf("%s\n", dir->d_name);
       }
       closedir(fp);
   }
   findDIR(target,counter);
   return 0;
}
