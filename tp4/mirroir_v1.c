/* Fichier: mirroir_v1.c
* Mirror
* auteur: Pierre MOLY
* Exercice 1
*/

// ----------------- Variante 1 -----------------

#include "mirroir.h"
#include <stdio.h>

int main(int argc, char* argv[]){

    if (argc != 2){
        puts("Error: there too much argument or no argument. Only 1 argument is need");
        return 1;
    }

    int i = 0;
    while(argv[1][i] != '\0'){
        i++;
    }

    for(int j = 0; j <= i ; j++){
        printf("%c", argv[1][i-j]);
    }
    printf("\n");

    return 0;
}