#include <stdio.h>
#include <dirent.h>

// man 2 stat

int main(){
  DIR *dir = opendir("..");
  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL){
    printf("%s\n", entry->d_name);
  }
  closedir(dir);
  return 0;
}
