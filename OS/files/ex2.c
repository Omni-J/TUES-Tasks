#include <stdio.h>
#include <sys/stat.h>
#include <unistd.h>
#include <sys/types.h>

// get pass for id func in docs
// get group id
// local time the year is 1900 and months are 11 and many more shit
// getopt(3)  

int main(){
  struct stat st;
  stat("a.out", &st);
  printf("%d\n", st.st_size);
  printf("%d\n", st.st_uid);

  struct passwd *pwd = getpwduid(st.st_uid);
  printf("%d\n", pwd->pw_name);
  printf("%d\n", st.st_mtime);

  struct tm *modifier = localtime(st.st_mtime);
  printf("%d\n", modifier->tm_min);

  return 0;
}
