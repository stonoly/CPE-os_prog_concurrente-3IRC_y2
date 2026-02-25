/* Fichier: boucle.c
* Loop
* auteur: Pierre MOLY
* Exercice 3
*/

#include "boucle.h"

#include <stdio.h>
#include <unistd.h>


int main(){

    for (int i = 0; i < 3; i++){
        
        pid_t pid_son = fork();
        pid_t pid_me = getpid();
        pid_t pid_dad = getppid();

        printf("%d: Je suis le processus %d, mon père est le processus %d fork a retourné %d\n", i, pid_me, pid_dad, pid_son);
    }

    return 0;
}