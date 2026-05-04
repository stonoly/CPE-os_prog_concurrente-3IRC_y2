# TP8
*Global:*

- `Makefile`
- `dijkstra.c`
- `dijkstra.h`
- `init.c`
- `init.h`
- `clean.c`
- `clean.h`

## Exercice 1: Précédence
> Écrivez deux programmes (first et second), chacun d’eux réalise un affichage au lancement. first génère un nombre entre 3 et 5 et attends autant de seconde que le nombre généré. Il affiche ensuite un message au moment de se terminer. Second doit être en attente jusqu’à ce que first ait fini son attente. Il génère ensuite un nombre entre 1 et 4 et attends autant de seconde que le nombre généré. Il affiche ensuite un message au moment de se terminer. Aucun lien de parenté n’existe entre first et second. Peu importe à quel moment et comment sont lancé les programmes, second doit être en attente que first ait fini son attente.

Files: 
- `first.c`
- `first.h`
- `second.c`
- `second.h`

## Exercice 2: Rendez-vous
> Plusieurs processus souhaitent établir un rendez-vous. Chaque processus exécutent certain traitement mais ne peuvent continuer leur exécution que si l’ensemble des processus sont arrivés à la fin de leur traitement respectif. Une fois, cela fait, chacun reprend son exécution indépendamment des autres. L’ordre d’exécution de chaque process, le moment d’exécution des programmes ou le temps d’exécution de ceux-ci ne doit pas influencer le rendez-vous. Tant que tous les processus ne sont pas au rendez-vous, les autres doivent attendre.

### Variante 1: Rendez-vous à deux
> Écrivez deux programmes souhaitant établir un rendez-vous. Vous simulerez les traitements des différents programmes à l’aide de sleep et vous aiderez de puts/printf afin de suivre aisément les différentes étapes rencontrées par chacun des processus.