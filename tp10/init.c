/* Fichier: init.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 1
*/

#include "init.h"

#include <sys/shm.h>


int main()
{
    sem_create(1, 0);
    int shmid = shmget(1234, sizeof(int),IPC_CREAT|IPC_EXCL|0600);
    if (shmid == -1) {
        perror("Shmget Memory");
    }
    return 0;
    
}