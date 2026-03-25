/* Fichier: second.c
* TP 8: Semaphore
* auteur: Pierre MOLY
* Exercice 1
*/

#include "first.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(){
    puts("-- First : Launch -->");

    int sem_1 = sem_get(1);

    srand(getpid());
    int nb_rand = rand() % 3 + 3;

    printf("-- First : le rand est %d -->\n", nb_rand);
    
    sleep(nb_rand);

    V(sem_1);
    puts("-- First : J'ai finis de dormir et V(sem_1) -->");
    
    return 0;
}