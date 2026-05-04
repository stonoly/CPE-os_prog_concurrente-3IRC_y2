/* Fichier: init_change.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "init.h"
#include "key_change.h"


int main()
{
    sem_create(KEY_MUTEX_CAN_USE_TAB, 1);

    sem_create(KEY_SEM_P0, 0);

    sem_create(KEY_MUTEX_P1, 0);
    sem_create(KEY_MUTEX_P2, 0);

    int shmid_buffer = shmget(KEY_TAB_INT, 3 * sizeof(int),IPC_CREAT|IPC_EXCL|0600);
    if (shmid_buffer == -1) {
        perror("Shmget shmid_buffer Memory tab _int");
    }

    return 0;
}