/* Fichier: greter.c
* TP 7: Tubes Anonymes Part 2
* auteur: Pierre MOLY
* Exercice 1
*/

#include "greater.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(){

    int tube1[2];
    int tube2[2];
    int tube3[2];
    int res1 = pipe(tube1);
    int res2 = pipe(tube2);
    int res3 = pipe(tube3);

        if (fork() == 0){
            if (fork() == 0){
                //petit fils
                int position = 3;
                int pid_pt_fils = getpid();

                 //generation random
                 srand(pid_pt_fils);
                 int random_pt_fils = rand() % 50;

                 printf(" Petit fils %d\n", random_pt_fils);
 
                 struct data_pipe valueReceiptTube_pt_fils;

                 struct data_pipe max;
 
                 //préparation tube
                 close(tube2[1]);
                 close(tube3[0]);

                 read(tube2[0], &valueReceiptTube_pt_fils, sizeof(struct data_pipe));
                 close(tube2[0]);

                 if (valueReceiptTube_pt_fils.value > random_pt_fils){
                    puts("En petit fils plus grands est le recu");
                    max = valueReceiptTube_pt_fils;
                 } else {
                    puts("En petit fils plus grands est le miens");
                    max.value = random_pt_fils;
                    max.pid = pid_pt_fils;
                    max.ord = position;
                 }
                 //retour data
                 write(tube3[1], &max, sizeof(struct data_pipe)); //Écriture dans le tube
                 close(tube3[1]);
            } else {
                //Fils

                int position = 2;
                int pid_fils = getpid();
                //generation random
                srand(pid_fils);
                int random_fils = rand() % 50;

                printf(" Fils %d\n", random_fils);

                struct data_pipe valueReceiptTube_fils;

                struct data_pipe max;

                //préparation tube
                close(tube1[1]);
                close(tube2[0]);

                read(tube1[0], &valueReceiptTube_fils, sizeof(struct data_pipe));
                close(tube1[0]);

                if (valueReceiptTube_fils.value > random_fils){
                   puts("En fils plus grands est le recu");
                   max = valueReceiptTube_fils;
                } else {
                   puts("En fils plus grands est le miens");
                   max.value = random_fils;
                   max.pid = pid_fils;
                   max.ord = position;
                }
                //retour data
                write(tube2[1], &max, sizeof(struct data_pipe)); //Écriture dans le tube
                close(tube2[1]);
            }
        } else {
            int position = 1;
            int pid_pere = getpid();
            //pere
            srand(pid_pere);
            int random_pere = rand() % 50;

            printf(" Pere %d\n", random_pere);

            struct data_pipe valueReceiptTube_pere;

            struct data_pipe valueSendTube_pere;

            valueSendTube_pere.value = random_pere;
            valueSendTube_pere.pid = pid_pere;
            valueSendTube_pere.ord = position;


             //préparation tube
             close(tube3[1]);
             close(tube1[0]);

             write(tube1[1], &valueSendTube_pere, sizeof(struct data_pipe));
             close(tube1[1]);

             read(tube3[0], &valueReceiptTube_pere, sizeof(struct data_pipe));
             close(tube3[0]);

            printf("Le plus grand nombre = %d - pid = %d - Numéro %d\n", valueReceiptTube_pere.value, valueReceiptTube_pere.pid, valueReceiptTube_pere.ord);
        }
    return 0;

}