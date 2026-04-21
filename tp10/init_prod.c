/* Fichier: init_prod.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 2
*/

#include "init.h"
#include "key_prod.h"


int main()
{
    sem_create(KEY_SEM_READ, 0);
    sem_create(KEY_SEM_WRITE, SIZE_BUFFER);
    sem_create(KEY_MUTEX_WRITE, 1);
    sem_create(KEY_MUTEX_READ, 1);
    int shmid_buffer = shmget(KEY_BUFFER,SIZE_BUFFER * sizeof(int),IPC_CREAT|IPC_EXCL|0600);
    if (shmid_buffer == -1) {
        perror("Shmget shmid_buffer Memory");
    }
    int shmid_indice = shmget(KEY_INDICE,SIZE_INDICE * sizeof(int),IPC_CREAT|IPC_EXCL|0600);
    if (shmid_indice == -1) {
        perror("Shmget shmid_indice Memory");
    }
    return 0;
}