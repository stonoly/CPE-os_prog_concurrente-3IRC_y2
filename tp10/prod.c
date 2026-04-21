/* Files: prod.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 2
*/

#include "prod.h"
#include "key_prod.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(){
    //Init
    int buffer_id = shmget(KEY_BUFFER, SIZE_BUFFER * sizeof(int), 0);
    int indice_id = shmget(KEY_INDICE, SIZE_INDICE * sizeof(int), 0);
    int sem_read = sem_get(KEY_SEM_READ);
    int sem_write = sem_get(KEY_SEM_WRITE);
    int mutex_write = sem_get(KEY_MUTEX_WRITE);

    srand(getpid());
    int nb_rand = rand() % 100;

    int* buffer = shmat(buffer_id, NULL, 0);
    int* indice = shmat(indice_id, NULL, 0);

    P(sem_write);

    P(mutex_write);
    buffer[indice[0]] = nb_rand;
    printf("J'ai produis: %d\n", buffer[indice[0]]);
    printf("[");
    for(int i = 0; i < SIZE_BUFFER; i++){
        printf("%d,", buffer[i]);
    }
    printf("]\n");
    
    indice[0] = (indice[0] + 1) % SIZE_BUFFER;
    printf("Mon indice est maintenant: %d\n", indice[0]);
    V(mutex_write);

    V(sem_read);

    return 0;
}