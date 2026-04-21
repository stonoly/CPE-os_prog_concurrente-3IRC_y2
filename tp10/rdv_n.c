/* Files: rdv_n.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 1
*/

#include "rdv_n.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(int argc, char* argv[]){
   
    if (argc != 2){
        perror("Error: there too much argument or no argument. Only 1 argument is need");
    }

    int nbr_pro = atoi(argv[1]);

    srand(getpid());

    int shmid = shmget(1234, sizeof(int), 0);
    int sem_1 = sem_get(1);
    int sem_2 = sem_get(2);

    int nb_rand = rand() % 20 + 3;
    printf("Salut je suis un porcessus qui attends %d secondes\n", nb_rand);
    sleep(nb_rand);

    int* mem = shmat(shmid,NULL,0);

    P(sem_2);
    *mem += 1;
    printf(" On est %d arrivé \n", *mem);

    if(*mem == nbr_pro){
        //Liberation
        V(sem_2);
        for(int i = 0; i < nbr_pro - 1; i++){
            V(sem_1);
            puts("je libère");
        }
    } else {
        //Attente
        V(sem_2);
        puts("On va attendre");
        P(sem_1);
    }  

    puts("Lets go tout le monde est là on peut commencer");

    return 0;
}