/* Files: rdv_n.c
* TP 10: Share Memory
* autor: Pierre MOLY
* Exercice 1
*/

#include "rdv_n.h"

#include <stdio.h>


int main(int argc, char* argv[]){
    if (argc != 2){
        puts("Error: there too much argument or no argument. Only 1 argument is need");
        return 1;
    }

    puts(argv[1]);
    return 0;
}