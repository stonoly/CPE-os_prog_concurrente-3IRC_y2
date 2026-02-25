/* Fichier: mirroir_v2.c
* Mirror
* auteur: Pierre MOLY
* Exercice 1
*/

// ----------------- Variante 2 -----------------

#include "mirroir.h"
#include <stdio.h>

int main(int argc, char* argv[]){

    if (argc < 2){
        puts("Error: 1 rgument or more is needed");
        return 1;
    }

    for (int indice_arg = 1; indice_arg < argc; indice_arg++){

        int i = 0;
        while(argv[indice_arg][i] != '\0'){
            i++;
        }
    
        for(int j = 0; j <= i ; j++){
            printf("%c", argv[indice_arg][i-j]);
        }

        printf(" ");
    }

    printf("\n");

    return 0;
}