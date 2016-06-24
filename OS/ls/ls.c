#include <stdio.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <dirent.h>
#include <unistd.h>
#include <pwd.h>
#include <string.h>
#include <stdbool.h>

bool hidden_files_flag;
struct stat file_stat;

/*
Should use stat readdir closedir getopt
*/

/* Ivo's sample code:
// 1. opendir, readdir, closedir
// 2. stat (problems: relative/absolute paths - opendir .., string concat
// memory!!)
// getpwuid() / getgrgid()
// localtime() and tm (tm struct - CAREFUL!!)
// filter hidden dirs
// myls -> different block size (x2)
// getopt for arguments
//man 2 stat

// get pass for id func in docs
// get group id
// local time the year is 1900 and months are 11 and many more shit
// getopt(3)

int main() {
    DIR *dir = opendir(".");

    struct dirent *entry;
    while ((entry = readdir(dir)) != NULL) {
        printf("%s\n", entry->d_name);
    }

    closedir(dir);

    struct stat st;
    stat("a.out", &st); // TODO: check result of stat!!

    printf("%d\n", st.st_size);

    struct passwd *pwd = getpwuid(st.st_uid);
    printf("%s\n", pwd->pw_name);

    printf("%u\n", st.st_mtime);
    struct tm *modified = localtime(&st.st_mtime);
    printf("%d\n", modified->tm_min);

}
*/

void print_file_type(int mode){
  if(S_ISREG(mode)){
    printf("-");
  }
  if(S_ISDIR(mode)){
    printf("d");
  }
  if(S_ISCHR(mode)){
    printf("b");
  }
  if(S_ISBLK(mode)){
    printf("c");
  }
  if(S_ISFIFO(mode)){
    printf("p");
  }
  if(S_ISLNK(mode)){
    printf("l");
  }
  if(S_ISSOCK(mode)){
    printf("s");
  }
}

int main(int argc, char **argv){

  int opt;
  while ((opt = getopt(argc, argv, "a")) != -1){
    switch(opt){
      case 'a':
        hidden_files_flag = true;
        break;
      default:
        printf("No such option as %c", opt);
      break;
    }
  }

  DIR *dir = opendir(".");

  struct dirent *entry;
  while ((entry = readdir(dir)) != NULL) {
      printf("%s\n", entry->d_name);
  }

  stat("./", &file_stat);
  printf("%d\n", file_stat.st_size);
  printf("%d\n", file_stat.st_uid);
  print_file_type(file_stat.st_mode);

  struct passwd *pwd = getpwuid(file_stat.st_uid);
  printf("%d\n", pwd->pw_name);

  printf("%d\n", file_stat.st_mtime);

  return 0;
}
