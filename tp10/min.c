/* Files: min.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "min.h"
#include "key_change.h"


int min(int tab[SIZE_TAB]){
    int min = tab[0];
    int ind_min = 0;
    for(int i = 0; i < SIZE_TAB; i++){
        if (tab[i] < min){
            min = tab[i];
            ind_min = i;
        }
    }
    return ind_min;
}