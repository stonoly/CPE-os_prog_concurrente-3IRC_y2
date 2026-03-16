/* Fichier: simultane.c
* TP 5: Fork & Exec
* auteur: Pierre MOLY
* Exercice 1 - Variant 1
*/

#include "simultane.h"

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>


int main() {

    pid_t son = fork();
    if (son == 0){

        pid_t grand_son = fork();
        if (grand_son == 0){

            int error_gs = execlp("ps","ps",NULL);
            if (error_gs == -1){
                perror("exec fail");
                exit(-1);
            }  

        }

        int error_s = execlp("ls","ls","-l",NULL);
        if (error_s == -1){
            perror("exec fail");
            exit(-1);
        }  

        wait(NULL);
    }

    int error = execlp("du","du","-sh","/usr/share", NULL);
    if (error == -1){
        perror("exec fail");
        exit(-1);
    }  

    wait(NULL);

    return 0;
}