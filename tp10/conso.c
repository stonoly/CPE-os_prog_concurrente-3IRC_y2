/* Files: conso.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 2
*/

#include "conso.h"
#include "key_prod.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(){
    int buffer_id = shmget(KEY_BUFFER, SIZE_BUFFER * sizeof(int), 0);
    int indice_id = shmget(KEY_INDICE, SIZE_INDICE * sizeof(int), 0);
    int sem_read = sem_get(KEY_SEM_READ);
    int sem_write = sem_get(KEY_SEM_WRITE);
    int mutex_read = sem_get(KEY_MUTEX_READ);

    int* buffer = shmat(buffer_id, NULL, 0);
    int* indice = shmat(indice_id, NULL, 0);
    P(sem_read);
    
    P(mutex_read);
    printf("Buffer = %d\n", buffer[indice[1]]);
    indice[1] = (indice[1] + 1) % SIZE_BUFFER;
    printf("Mon indice est maintenant: %d\n", indice[1]);
    V(mutex_read);
    
    V(sem_write);
    return 0;
}