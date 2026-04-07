# TP9 - Signaux

*Global:*

- `Makefile`

## Exercice 1: Interception de signal
> Écrire un programme qui réalise un affichage dans une boucle infinie, mais qui prévoit de s’arrêter à la réception du signal SIGINT. La fonction d’interception affichera un message signalant la réception du signal avant de terminer le programme par un appel exit(). Après avoir vérifier que votre programme marchait correctement. Lancez-le en tâche de fond ./intercept & et essayer de l’interrompre avec contrôle+C (^C). Que constatez-vous?

Files:
- `intercept.c`
- `intercept.h`

## Exercice 2:  Ignorer un signal
> Modifier le programme précédent pour qu’il ignore le signal SIGINT. Pour l’arrêter, il faut taper `ps –aux | grep ./ignore` pour obtenir son numéro de processus (pid) et lancer la commande : `kill -KILL pid` (pour envoyer le signal SIGKILL)

Files:
- `ignore.c`
- `ignore.h`