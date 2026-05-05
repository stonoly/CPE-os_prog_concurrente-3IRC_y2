/* Files: server.c
* TP 11: Producer/Consumer
* autor: Pierre MOLY
* Exercice 1
*/

#include "server.h"
#include "key_calculator.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/shm.h>

int main(){
    int sem_read_server = sem_get(KEY_SEM_READ_SERVER);
    int request_input_id = shmget(KEY_REQUEST_INPUT, sizeof(struct requete_client_serveur), 0);

    struct requete_client_serveur *request_input = shmat(request_input_id, NULL, 0);

    int result;

    P(sem_read_server);

    int num1 = request_input->nombre1;
    int num2 = request_input->nombre2;
    int op = request_input->operateur;

    if (op == '*'){
        puts("*");
        result = num1 * num2;
    }else if(op == '/'){
        puts("/");
        result = num1 / num2;
    }else if(op == '+'){
        puts("+");
        result = num1 + num2;
    }else{
        puts("-");
        result = num1 - num2;
    }

    printf("%d %c %d = %d\n", num1, op, num2, result);
    return 0;
}