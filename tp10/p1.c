/* Files: p1.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "p1.h"
#include "key_change.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>


int main(){
    int have_to_change = 1;
    int tab[SIZE_TAB] = {28, 41, 3};

    int mutex_can_use_tab = sem_get(KEY_MUTEX_CAN_USE_TAB);
    int mutex_p1 = sem_get(KEY_MUTEX_P1);
    int sem_p0 = sem_get(KEY_SEM_P0);
    int tab_int_id = shmget(KEY_TAB_INT, 3 * sizeof(int), 0);

    int* tab_int = shmat(tab_int_id, NULL, 0);

    printf("[");
    for (int i = 0; i < SIZE_TAB; i++){
        printf("%d,", tab[i]);
    }
    printf("]\n");

    while(have_to_change == 1){
        int max_value = max(tab);
        printf("Le max est %d\n", max_value);

        P(mutex_can_use_tab);
        tab_int[0] = tab[max_value];
        V(mutex_can_use_tab);
        V(sem_p0);

        P(mutex_p1);
        if (tab_int[2] == -1){
            have_to_change = 2;
        } else {
            tab[max_value] = tab_int[0];
        }
    }
    puts("P1 :");
    printf("[");
    for (int i = 0; i < SIZE_TAB; i++){
        printf("%d,", tab[i]);
    }
    printf("]\n");

    return 0;
}