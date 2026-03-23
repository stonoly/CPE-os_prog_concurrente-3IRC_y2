/* Fichier: sum.c
* TP 6: Tubes Anonymes
* auteur: Pierre MOLY
* Exercice 3
*/

#include "sum.h"

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>


int main(){

    int num;

    printf("Combien de nombres voulez vous générez : ");
    scanf("%d", &num);

    int pipe_gene_filt[2];
    int pipe_filt_pair[2];
    int pipe_filt_impair[2];
    int pipe_pair_gene[2];
    int pipe_impair_gene[2];

    int pipe_gene_filt_res = pipe(pipe_gene_filt);
    int pipe_filt_pair_res = pipe(pipe_filt_pair);
    int pipe_filt_impair_res = pipe(pipe_filt_impair);
    int pipe_pair_gene_res = pipe(pipe_pair_gene);
    int pipe_impair_gene_res = pipe(pipe_impair_gene);

    if (pipe_gene_filt_res == -1 || pipe_filt_pair_res == -1 || pipe_filt_impair_res == -1 || pipe_pair_gene_res == -1 || pipe_impair_gene_res == -1) {
        perror("Création Pipe");
        exit(-1);
    }
    
    if(fork() == 0){
        if (fork() == 0){
            //Pair
            int random_filt;
            int sum;

            close(pipe_filt_pair[1]);
            close(pipe_pair_gene[0]);

            while(random_filt != -1) {
                read(pipe_filt_pair[0], &random_filt, sizeof(int));
                if(random_filt != -1){
                    sum += random_filt;
                }
            }
            close(pipe_filt_pair[0]);

            write(pipe_pair_gene[1], &sum, sizeof(int));
            close(pipe_pair_gene[1]);
            

            return 0;
        }

        if (fork() == 0){
            // Impair
            int random_filt;
            int sum;

            close(pipe_filt_impair[1]);
            close(pipe_impair_gene[0]);

            while(random_filt != -1){
                read(pipe_filt_impair[0], &random_filt, sizeof(int));
                if(random_filt != -1){
                    sum += random_filt;
                }
            }
            close(pipe_filt_impair[0]);

            write(pipe_impair_gene[1], &sum, sizeof(int));
            close(pipe_impair_gene[1]);

            return 0;
        }

        // Filtre
        int random_gene;

        close(pipe_gene_filt[1]);
        close(pipe_filt_pair[0]);
        close(pipe_filt_impair[0]);

        while(random_gene != -1){
            read(pipe_gene_filt[0], &random_gene, sizeof(int));

            if (random_gene != -1){
                if (random_gene % 2 == 0){
                    write(pipe_filt_pair[1], &random_gene, sizeof(int));
                } else {
                    write(pipe_filt_impair[1], &random_gene, sizeof(int));
                }
            } else {
                write(pipe_filt_pair[1], &random_gene, sizeof(int));
                write(pipe_filt_impair[1], &random_gene, sizeof(int));
            }
        }

        close(pipe_gene_filt[0]);
        close(pipe_filt_pair[1]);
        close(pipe_filt_impair[1]);
        return 0;
    }

    // Générateur
    int exit = -1;
    int random;

    int result_pair;
    int result_impair;

    close(pipe_gene_filt[0]);
    close(pipe_pair_gene[1]);
    close(pipe_impair_gene[1]);

    for (int i = 0; i < num; i++){
        random = generationRandom(i);
        printf("---- Générateur : %d -----\n", random);
        write(pipe_gene_filt[1], &random, sizeof(int));
    }
    write(pipe_gene_filt[1], &exit, sizeof(int));
    close(pipe_gene_filt[1]);

    read(pipe_pair_gene[0], &result_pair, sizeof(int));
    read(pipe_impair_gene[0], &result_impair, sizeof(int));

    printf("------Résultat------\n Paire : %d\n Impaire : %d\n", result_pair, result_impair);

    close(pipe_pair_gene[0]);
    close(pipe_impair_gene[0]);

    return 0;
}

int generationRandom(int seed){
    srand(getpid() + seed);
    return rand()%MAX_SIZE;
}