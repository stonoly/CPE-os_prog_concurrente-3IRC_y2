/* Files: p0.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "p0.h"
#include "key_change.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(){
    int have_to_change = 1;
    int mutex_can_use_tab = sem_get(KEY_MUTEX_CAN_USE_TAB);
    int mutex_p1 = sem_get(KEY_MUTEX_P1);
    int mutex_p2 = sem_get(KEY_MUTEX_P2);
    int sem_p0 = sem_get(KEY_SEM_P0);
    int tab_int_id = shmget(KEY_TAB_INT, 3 * sizeof(int), 0);

    int* tab_int = shmat(tab_int_id, NULL, 0);


    while(have_to_change == 1){
        P(sem_p0);
        P(sem_p0);
        P(mutex_can_use_tab);
        int p1 = tab_int[0];
        int p2 = tab_int[1];
        printf("p1: %d\n p2: %d\n", p1, p2);
        if (p1 > p2){
            tab_int[0] = p2;
            tab_int[1] = p1;
        } else {
            tab_int[2] = -1;
            have_to_change = 2;
        }
        V(mutex_can_use_tab);
        V(mutex_p1);
        V(mutex_p2);
    }

    puts("Je finis");
    return 0;
}