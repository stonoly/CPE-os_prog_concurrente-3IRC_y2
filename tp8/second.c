/* Fichier: second.c
* TP 8: Semaphore
* auteur: Pierre MOLY
* Exercice 1
*/

#include "second.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    puts("-- Second : Launch -->");

    int sem_1 = sem_get(1);

    P(sem_1);
    puts("-- Second : P(sem_1) -->");

    srand(getpid());
    int nb_rand = rand() % 4 + 1;

    printf("-- Second : le rand est %d -->\n", nb_rand);
    
    sleep(nb_rand);

    V(sem_1);
    puts("-- Second : J'ai finis de dormir et V(sem_1) -->");
    
    return 0;
}