#include <stdio.h>
#include <string.h>
#include <sys/types.h>
#include <dirent.h>

/*                                                                                                                                     
 * The tree command prints all files/directories contained in the current directory as a tree.                                         
 * The first line of output is always “.” to denote the current directory. tree recurses into directories to print all                 
 * files/directories within them. For each subdirectory, two spaces of indentation are added.                                          
 */

// function that will check the entry and see if it matches the target
// counter will be able to read over and implent the list as the path is being created 
void recurDirect(const char *target_name, int counter)
{
    DIR *dir;
    struct dirent *key_word;
    // this will be able to check if the statements will be able to continue 
    int pathCheck_open;
    pathCheck_open = 0; 

    // If the directory is existing 
    if (!(dir = opendir(target_name)))
        return;
    // check to make sure that the directory is not empty 
    while ((key_word = readdir(dir)) != NULL) {

      if (key_word->d_type == DT_DIR) {

            // create a path for the directories to be list in 
            char created_path[1024];

            // compare the strings of the files to see if they start a double to single period
            if (strcmp(key_word->d_name, ".") == pathCheck_open || strcmp(key_word->d_name, "..") == pathCheck_open)
                continue;
            // if so then continue on 
            // print of the path and check the size and save that 
            snprintf(created_path, sizeof(created_path), "%s/%s", target_name, key_word -> d_name);
            // print out the list
            printf("%*s[%s]\n", counter, "", key_word -> d_name);
            // increase the counter by to 
            counter = counter + 2;
            // recursively run the program 
            recurDirect(created_path, counter);
        }
        
        // if none of the above then 
        else {
            printf("%*s- %s\n", counter, "", key_word -> d_name);
        }
    }
    
    // closes the directory 
    closedir(dir);
}

// main will just serve to call the function 
int main() {
    // print the first line and new line 
  printf(".\n");
    // call it and set it equal to 0 to start the count
  recurDirect(".", 0);
    // success
  return 0;
}
