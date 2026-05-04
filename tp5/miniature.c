/* Fichier: miniature.c
* TP 5: Fork & Exec
* auteur: Pierre MOLY
* Exercice 2
*/

#include "simultane.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <dirent.h>
#include <errno.h>


int main(int argc, char* argv[]){

    if (argc < 2){
        if (argc != 2){
            puts("Error: there is no Argument");
            return 1;
        }
    }

    DIR* directory = opendir(argv[1]);
    //get one entry of the directory
    errno = 0;
    while (readdir(directory) != NULL) {
        struct dirent* entry = readdir(directory);
        printf("%s\n", entry->d_name);
    }
    if (errno != 0) {
        perror("readdir");
    }
    //close directory
    closedir(directory);



        
    // pid_t son = fork();
    // if (son == 0){
    //     int error_gs = execlp("convert", "convert", "TP5_extra/exercice_2/images/3.jpg", "-resize", "10%", "TP5_output/exercice_2/images/3.jpg", NULL);
    //     if (error_gs == -1){
    //         perror("exec fail");
    //         exit(-1);
    //     }  
    // }
    wait(NULL);
    return 0;
}

