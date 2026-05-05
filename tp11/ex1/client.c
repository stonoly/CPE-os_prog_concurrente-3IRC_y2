/* Files: client.c
* TP 11: Producer/Consumer
* autor: Pierre MOLY
* Exercice 1
*/

#include "client.h"
#include "key_calculator.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int main(int argc, char* argv[]){
    if (argc != 4) {
        puts("Pas le bon nombres d'argument");
        return 1;
    }

    int sem_read_server = sem_get(KEY_SEM_READ_SERVER);
    int request_input_id = shmget(KEY_REQUEST_INPUT, sizeof(struct requete_client_serveur), 0);

    struct requete_client_serveur *request_input = shmat(request_input_id, NULL, 0);

    request_input->clientId = "allo";
    request_input->nombre1 = atoi(argv[1]);
    request_input->operateur = argv[2][0];
    request_input->nombre2 = atoi(argv[3]);

    V(sem_read_server);

    return 0;
}