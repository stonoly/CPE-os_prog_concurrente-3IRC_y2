/* Files: ignore.c
* TP 9: Signaux
* autor: Pierre MOLY
* Exercice 2
*/

#include "ignore.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>
#include <string.h>


int main(){
    struct sigaction act;
    memset(&act,0,sizeof(act));
    act.sa_handler = SIG_IGN;
    sigaction(SIGINT,&act,NULL);
    
    while(1 == 1){
        puts("J'attends le Stop !!");
        sleep(10);
    }

    puts("Là c'est la fin par épuisement");
    return 0;
}