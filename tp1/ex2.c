/* Fichier: ex2.c
* Enigma
* auteur: Pierre MOLY
* Exercice 2
*/

#include "ex2.h"

int generateLine(int* tab, int start, int nbr_elem_in_tab){
    int i = start;
    int compt = 0;
    while(tab[start] == tab[i] && i < nbr_elem_in_tab){
        i++;
        compt++;
    }
    
    return compt;
}


int main (){
    int tab[SIZE_TAB] = {1, 1, 1, 3};
    int nbr_elem = 4;

    puts("debug");
    for(int j = 0; j < nbr_elem; j++){
        int compt = generateLine(tab, j, nbr_elem); 
        printf("%d %d, ", compt, tab[j]);
    }

    printf("\n");

    return 0;
}