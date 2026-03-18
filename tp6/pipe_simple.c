/* Fichier: pipe_simple.c
* TP 6: Tubes Anonymes
* auteur: Pierre MOLY
* Exercice 2 - Variant 2
*/

#include "pipe_simple.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

    int force[2];
    int res = pipe(force);
    if (res == -1) {
        perror("Création Pipe");
        exit(-1);
    }

    // Separation Anakin / Luke 
    if (fork() == 0) {
        // Luke
        close(force[1]);

        dup2(force[0],0);
        close(force[0]);

        execlp("tr", "tr", "a-z", "A-Z", NULL);

    } else {
        // Anakin
        close(force[0]);

        dup2(force[1],1);
        close(force[1]);

        execlp("cut", "cut", "-f", "1", "-d", ":", "/etc/passwd", NULL);
    }

    return 0;
}