 TP9 - Signaux
*Global:*

- `Makefile`

## Exercice 1: Interception de signal
> Écrire un programme qui réalise un affichage dans une boucle infinie, mais qui prévoit de s’arrêter à la réception du signal SIGINT. La fonction d’interception affichera un message signalant la réception du signal avant de terminer le programme par un appel exit(). Après avoir vérifier que votre programme marchait correctement. Lancez-le en tâche de fond ./exo1 & et essayer de l’interrompre avec contrôle+C (^C). Que constatez-vous?