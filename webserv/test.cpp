// #include <stdio.h>
// #include <stdlib.h>
// #include <time.h>
// #include <sys/stat.h>
// #include <sys/types.h>
// #include <dirent.h>
// #include <cstring>

// void getFileCreationTime(char *path)
// {
//     struct stat attr;
//     stat(path, &attr);
//     printf("Last modified time: %s", ctime(&attr.st_mtime));
// }

// int main(void)
// {
//   DIR           *d;
//   struct dirent *dir;
//   d = opendir("./src"); //path
//   if (d)
//   {
//     while ((dir = readdir(d)) != NULL)
//     {
//         //exclude
//         if(strcmp( dir->d_name, "." ) == 0 ||
//         strcmp( dir->d_name, ".." ) == 0 )
//         {
//             continue;
//         }
//         printf("%s\n", dir->d_name);
//         getFileCreationTime(dir->d_name);
//     }
//     closedir(d);
//   }
//   return(0);
// }