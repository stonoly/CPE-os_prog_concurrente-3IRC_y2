/* Fichier: init.c
* TP 11: Producer/Consumer
* autor: Pierre MOLY
* Exercice 1
*/

#include "init.h"
#include "key_calculator.h"


int main()
{

    sem_create(KEY_SEM_READ_SERVER, 0);

    int shmid_input = shmget(KEY_REQUEST_INPUT, sizeof(struct requete_client_serveur), IPC_CREAT|IPC_EXCL|0600);
    if (shmid_input == -1) {
        perror("Shmget Memory Port Input");
    }

    return 0;
}