#include <sys/types.h>
#include <sys/stat.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <dirent.h>
#include <time.h>
#include <pwd.h>
#include <grp.h>


int main(int argc, char* argv[])
{
    DIR *thedirectory;
       
    struct dirent *thefile;
    struct stat thestat;
    struct passwd *tf;
    struct group *gf;
    
   char buf[512];
    //  char *buf = malloc( sizeof(char) * ( len + 1 ) )
    
    thedirectory = opendir(argv[1]);
    while((thefile = readdir(thedirectory)) != NULL)
    {
        sprintf(buf, "%s/%s", argv[1], thefile->d_name);
        
        stat(buf, &thestat);
        // [file type]
        switch (thestat.st_mode & S_IFMT) 
        {
            case S_IFBLK:  printf("b "); break;
            case S_IFCHR:  printf("c "); break;
            case S_IFDIR:  printf("d "); break; 
            case S_IFIFO:  printf("p "); break; 
            case S_IFLNK:  printf("l "); break; 
            case S_IFSOCK: printf("s "); break;
           
                //Filetype isn't identified
            default:       printf("- "); break;
         }
        //[permissions]
        printf( (thestat.st_mode & S_IRUSR) ? " r" : " -");
        printf( (thestat.st_mode & S_IWUSR) ? "w" : "-");
        printf( (thestat.st_mode & S_IXUSR) ? "x" : "-");
        printf( (thestat.st_mode & S_IRGRP) ? "r" : "-");
        printf( (thestat.st_mode & S_IWGRP) ? "w" : "-");
        printf( (thestat.st_mode & S_IXGRP) ? "x" : "-");
        printf( (thestat.st_mode & S_IROTH) ? "r" : "-");
        printf( (thestat.st_mode & S_IWOTH) ? "w" : "-");
        printf( (thestat.st_mode & S_IXOTH) ? "x" : "-");

        // [number of hard links]
        printf("\t%ld ", (thestat.st_nlink));

        //[owner]
        tf = getpwuid(thestat.st_uid);
        printf("\t%s ", tf->pw_name);

        //[group]
        gf = getgrgid(thestat.st_gid);
        printf("\t%s ", gf->gr_name);

        //[size in bytes] [time of last modification] [filename]
        printf("%zu",thestat.st_size);
        printf(" %s", thefile->d_name);
        printf(" %s", ctime(&thestat.st_mtime));
    }
    closedir(thedirectory);
}
