/* Fichier: simple_redirection.c
* TP 6: Tubes Anonymes
* auteur: Pierre MOLY
* Exercice 2 - Variant 1
*/

#include "simple_redirection.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>


int main(){

    int files = open("/etc/passwd",O_RDONLY);    
    dup2(files,0);

    execlp("wc","wc",NULL);

    return 0;
}