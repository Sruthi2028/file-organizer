#include <stdio.h>
#include <dirent.h>
#include <string.h>
#include <sys/stat.h>

int main() {

    DIR *dir;
    struct dirent *entry;

    mkdir("Images");
    mkdir("Documents");
    mkdir("Text");

    dir = opendir(".");

    while ((entry = readdir(dir)) != NULL) {

        char *ext = strrchr(entry->d_name, '.');

        if (ext != NULL) {

            if (strcmp(ext, ".png") == 0 || strcmp(ext, ".jpg") == 0) {

                char newpath[200];
                sprintf(newpath, "Images/%s", entry->d_name);
                rename(entry->d_name, newpath);

            }

            else if (strcmp(ext, ".txt") == 0) {

                char newpath[200];
                sprintf(newpath, "Text/%s", entry->d_name);
                rename(entry->d_name, newpath);

            }

            else if (strcmp(ext, ".pdf") == 0) {

                char newpath[200];
                sprintf(newpath, "Documents/%s", entry->d_name);
                rename(entry->d_name, newpath);

            }
        }
    }

    closedir(dir);

    printf("Files organized!\n");

    return 0;
}