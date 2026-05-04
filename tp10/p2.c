/* Files: p2.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "p2.h"
#include "key_change.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(){
    int have_to_change = 1;
    int tab[SIZE_TAB] = {19, 4, 52};

    int mutex_can_use_tab = sem_get(KEY_MUTEX_CAN_USE_TAB);
    int mutex_p2 = sem_get(KEY_MUTEX_P2);
    int sem_p0 = sem_get(KEY_SEM_P0);
    int tab_int_id = shmget(KEY_TAB_INT, 3 * sizeof(int), 0);

    int* tab_int = shmat(tab_int_id, NULL, 0);

    printf("[");
    for (int i = 0; i < SIZE_TAB; i++){
        printf("%d,", tab[i]);
    }
    printf("]\n");

    while(have_to_change == 1){
        int min_value = min(tab);
        printf("Le min est %d\n", min_value);

        P(mutex_can_use_tab);
        tab_int[1] = tab[min_value];
        V(mutex_can_use_tab);
        V(sem_p0);

        P(mutex_p2);
        if (tab_int[2] == -1){
            have_to_change = 2;
        } else {
            tab[min_value] = tab_int[1];
        }
    }

    puts("P2 :");
    printf("[");
    for (int i = 0; i < SIZE_TAB; i++){
        printf("%d,", tab[i]);
    }
    printf("]");
    return 0;
}