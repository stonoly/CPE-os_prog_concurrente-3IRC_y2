/* Files: intercept.c
* TP 9: Signaux
* autor: Pierre MOLY
* Exercice 1
*/

#include "intercept.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <signal.h>


void handler(int sig){
    puts("");
    puts("Le Ctrl C est bien reçus chef, je close dans 3sec");
    puts("3");
    sleep(1);
    puts("2");
    sleep(1);
    puts("1");
    sleep(1);
    exit(0);

}

int main(){
    struct sigaction act;
    act.sa_handler = handler;
    sigaction(SIGINT, &act, NULL);

    while(1 == 1){
        puts("J'attends le Stop !!");
        sleep(1.75);
    }

    puts("Là c'est la fin par épuisement");
    return 0;
}