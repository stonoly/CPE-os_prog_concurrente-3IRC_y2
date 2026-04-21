/* Fichier: clean_prod.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 2
*/

#include "clean.h"
#include "key_prod.h"


int main()
{
    int buffer = shmget(KEY_BUFFER, SIZE_BUFFER * sizeof(int), 0);
    int res_buffer = shmctl(buffer, IPC_RMID, NULL);
    if (res_buffer == -1) {
        perror("Delete Buffer");
    }
    int indice = shmget(KEY_INDICE, SIZE_INDICE * sizeof(int), 0);
    int res_indice = shmctl(indice, IPC_RMID, NULL);
    if (res_indice == -1) {
        perror("Delete indice");
    }
    int sem_read = sem_get(KEY_SEM_READ);
    sem_delete(sem_read);
    int sem_write = sem_get(KEY_SEM_WRITE);
    sem_delete(sem_write);

    int mutex_write = sem_get(KEY_MUTEX_WRITE);
    sem_delete(mutex_write);
    int mutex_read = sem_get(KEY_MUTEX_READ);
    sem_delete(mutex_read);
    return 0;
}