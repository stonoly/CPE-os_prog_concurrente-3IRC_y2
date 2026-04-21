/* Fichier: clean.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 1
*/

#include "clean.h"

#include <sys/shm.h>


int main()
{

    int shmid = shmget(1234,sizeof(int),0);
    int res = shmctl(shmid,IPC_RMID,NULL);
    if (res == -1) {
        perror("Delete Shm");
    }
    int semWaitFirst = sem_get(1);
    sem_delete(semWaitFirst);
    int semWaitSecond = sem_get(2);
    sem_delete(semWaitSecond);
    return 0;
}