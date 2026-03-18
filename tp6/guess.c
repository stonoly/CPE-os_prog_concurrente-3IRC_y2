/* Fichier: guess.c
* TP 6: Tubes Anonymes
* auteur: Pierre MOLY
* Exercice 1
*/

#include "guess.h"

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>


int main(){

    int force_a_l[2];
    int force_l_a[2];
    int res1 = pipe(force_a_l);
    int res2 = pipe(force_l_a);
    if (res1 == -1 || res2 == -1){
        perror("Creation Pipe"); exit(-1);
    }

    // Separation Anakin / Luke 
    if (fork() == 0) {
        // Luke
        close(force_l_a[0]);
        close(force_a_l[1]);
        
        srand(getpid());
        int random = rand()%MAX_SIZE;

        int int_anakin;
        char return_user;

        while(int_anakin != random){
            
            read(force_a_l[0], &int_anakin, sizeof(int));

            if (int_anakin != random){
                if(int_anakin < random){
                    return_user = '+';
                } else {
                    return_user = '-';
                }
                write(force_l_a[1], &return_user, sizeof(char));
            }
        }
        
        return_user = '=';
        write(force_l_a[1], &return_user, sizeof(char));


        close(force_l_a[1]);
        close(force_a_l[0]);

    } else {
        // Anakin
        close(force_l_a[1]);
        close(force_a_l[0]);

        int input_user;
        char char_luke;

        printf("Veuillez entrer un nombre entre 0 et 100 : ");
        scanf("%d", &input_user);

        while(char_luke != '='){
            write(force_a_l[1], &input_user, sizeof(int));
            read(force_l_a[0], &char_luke, sizeof(char));

            if (char_luke != '='){
                if(char_luke == '+'){
                    printf("C'est plus réessayez : ");
                } else {
                    printf("C'est moins réessayez : ");
                }
                scanf("%d", &input_user);
            }
        }

        puts("Bravo vous avez gagné");

        close(force_l_a[0]);
        close(force_a_l[1]);
    }

    return 0;
}