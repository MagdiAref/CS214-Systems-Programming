#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <dirent.h>

int main(int argc, char* argv[])
{

  int fileCount = 0;
  char listFiles[10][10];
  char tempArr[20];

  for (int j = 0; j < fileCount; ++j)
  {
    for (int k = j + 1; k < fileCount; ++k)
    {
      if (strcasecmp(listFiles[j], listFiles[k]) > 0)
      {
        strcpy(tempArr, listFiles[j]);
        strcpy(listFiles[j], listFiles[k]);
        strcpy(listFiles[k], tempArr);
      }

    }
  }
  for (int q = 0; q < fileCount; ++q)
  {
    fputs(listFiles[q], stdout);
  }
    struct dirent *de;
    DIR *dr = opendir(".");

    if (dr == NULL)
    {
        printf("Could not open current directory" );
  }
    while ((de = readdir(dr)) != NULL)
            printf("%s\n", de->d_name);

    closedir(dr);
    return 0;
