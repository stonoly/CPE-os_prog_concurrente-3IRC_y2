# TP7 - Programmation Concurrente: Tubes Anonymes Suite

## Exercice 1: Plus grand nombre
> Écrivez un programme (greater) créant N processus. Chacun de ces N processus génère et affiche un nombre tiré aléatoirement. Le nombre de processus est spécifié en argument. Chacun des processus créé est identifié par un pid et un numéro d’ordre de création. L’objectif est de déterminer le processus qui a généré le plus grand nombre. Pour cela, les N processus sont organisés en anneau au travers de leur entrée et de leur sortie standard en utilisant les tubes anonymes. Le processus 0 va être connecté au processus 1 par un premier tube, le processus 1 est connecté au processus 2 par un deuxième tube, le processus 2 connecté au processus 3 et ainsi de suite… Le dernier processus de l’anneau doit être connecté au processus 0. Lorsque les processus et les tubes sont créés, le processus 0 envoie sa valeur générée, son identifiant et son numéro d’ordre vers le processus 1. Le processus 1 compare la valeur reçue à sa valeur et envoie au processus 2 la valeur la plus grande.
> - Si la valeur la plus grande était celle reçue de 0, alors il transmet l’identifiant et le numéro d’ordre reçu par le tube.
>
> - Si c’était celle produite par le processus 1, alors il transmet sa valeur générée, son identifiant et son numéro d’ordre.
>Chaque processus de l’anneau va appliquer le même traitement. À la fin, le processus 0 doit recevoir sur son tube la plus grande valeur, l’identifiant du processus l’ayant généré et son numéro d’ordre.

Files:
- `greater.c`
- `greater.h`