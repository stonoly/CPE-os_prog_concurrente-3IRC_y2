/* Files: max.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 3
*/

#include "max.h"
#include "key_change.h"


int max(int tab[SIZE_TAB]){
    int max = 0;
    int ind_max = 0;
    for(int i = 0; i < SIZE_TAB; i++){
        if (tab[i] > max){
            max = tab[i];
            ind_max = i;
        }
    }
    return ind_max;
}