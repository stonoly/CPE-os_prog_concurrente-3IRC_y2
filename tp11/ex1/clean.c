/* Files: clean.c
* TP 11: Producer/Consumer
* autor: Pierre MOLY
* Exercice 1
*/

#include "clean.h"
#include "key_calculator.h"


int main(){

    int tab_request_input_id = shmget(KEY_REQUEST_INPUT, sizeof(struct requete_client_serveur), 0);
    int res = shmctl(tab_request_input_id, IPC_RMID, NULL);
    if (res == -1) {
        perror("Delete Tab Request input");
    }

    int sem_read_server = sem_get(KEY_SEM_READ_SERVER);
    sem_delete(sem_read_server);

    return 0;
}