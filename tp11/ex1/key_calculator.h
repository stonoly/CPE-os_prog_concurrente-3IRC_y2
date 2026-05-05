/* Fichier: key_calculator.h
* TP 11: Producer/Consumer
* autor: Pierre MOLY
* Exercice 1
*/

#ifndef KEY_CALCULATOR_H
#define KEY_CALCULATOR_H

#define KEY_REQUEST_INPUT 5400
#define SIZE_REQUEST 3

#define KEY_SEM_READ_SERVER 53278

struct requete_client_serveur {
    int clientId;
    int nombre1;
    int nombre2;
    char operateur;
};

#endif