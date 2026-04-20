/* Fichier: clean.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 1
*/

#include "clean.h"


int main()
{
    int semWaitFirst = sem_get(1);
    sem_delete(semWaitFirst);

    return 0;
}