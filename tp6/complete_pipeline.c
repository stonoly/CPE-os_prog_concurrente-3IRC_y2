/* Fichier: complete_pipeline.c
* TP 6: Tubes Anonymes
* auteur: Pierre MOLY
* Exercice 2 - Variant 3
*/

#include "complete_pipeline.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main() {

    int obscure_force[2];
    int light_force[2];
    int obscure_res = pipe(obscure_force);
    int light_res = pipe(light_force);

    if (obscure_res == -1 || light_res == -1) {
        perror("Création Pipe");
        exit(-1);
    }

    // Separation Anakin / Obiwan 
    if (fork() == 0) {

        // Separation Anakin / Luke
        if (fork() == 0){
            // Luke
            close(obscure_force[1]);
            close(obscure_force[0]);
            close(light_force[1]);

            dup2(light_force[0], 0);
            close(light_force[0]);

            int files_luke = open("usersa", O_CREAT | O_WRONLY | O_TRUNC, 0644);
            dup2(files_luke, 1);

            execlp("sort", "sort", "-n", NULL);

        }

        // Anakin
        close(obscure_force[1]);
        close(light_force[0]);

        dup2(obscure_force[0], 0);
        dup2(light_force[1], 1);

        close(obscure_force[0]);
        close(light_force[1]);

        execlp("sed", "sed", "s+^\\(.*\\):\\(.*\\)+\\2:\\1+", NULL);
    } else {
        // Obi-wan
        close(light_force[0]);
        close(light_force[1]);
        close(obscure_force[0]);

        dup2(obscure_force[1],1);
        close(obscure_force[1]);

        int files_obiwan = open("/etc/passwd",O_RDONLY);    
        dup2(files_obiwan,0);
    
        execlp("cut","cut", "-f", "1,3", "-d", ":", NULL);
    }

    return 0;
}