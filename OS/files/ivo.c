#include <sys/types.h>
#include <sys/stat.h>
#include <pwd.h>
#include <dirent.h>
#include <stdio.h>
#include <time.h>

// 1. opendir, readdir, closedir
// 2. stat (problems: relative/absolute paths - opendir .., string concat
// memory!!)
// getpwuid() / getgrgid()
// localtime() and tm (tm struct - CAREFUL!!)
// filter hidden dirs
// myls -> different block size (x2)
// getopt for arguments
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
