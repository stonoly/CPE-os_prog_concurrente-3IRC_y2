/* Fichier: clean_change.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "clean.h"
#include "key_change.h"


int main()
{
    int mutex_can_use_tab = sem_get(KEY_MUTEX_CAN_USE_TAB);
    sem_delete(mutex_can_use_tab);

    int mutex_p1 = sem_get(KEY_MUTEX_P1);
    sem_delete(mutex_p1);

    int mutex_p2 = sem_get(KEY_MUTEX_P2);
    sem_delete(mutex_p2);

    int sem_p0 = sem_get(KEY_SEM_P0);
    sem_delete(sem_p0);

    int tab_int = shmget(KEY_TAB_INT, 3 * sizeof(int), 0);
    int del_tab_int = shmctl(tab_int, IPC_RMID, NULL);
    if (del_tab_int == -1) {
        perror("Delete Tab Int");
    }

    return 0;
}