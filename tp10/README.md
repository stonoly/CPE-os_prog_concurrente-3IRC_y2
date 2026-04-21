# TP10 - Mémoire Partagée

*Global:*
 
- `Makefile`
- `dijkstra.c`
- `dijkstra.h`
- `init.h`
- `clean.h`

## Exercice 1: Rendez-vous à N
> Écrivez un programme souhaitant établir un rendez-vous avec N version de lui-même. N est un argument reçu sur la ligne de commande. Vous simulerez les traitements des différents processus à l’aide de sleep et vous aiderez de puts/prints afin de suivre aisément les différentes étapes rencontrées par chacun des processus. ⚠ Tous les processus reçoivent le même N.

Files:
- `rdv_n.c`
- `rdv_n.h`
- `clean.c`
- `init.c`

## Exercice 2: Producteur/Consommateur
> Un processus prod produit des informations qui sont consommées par un autre processus conso. La communication entre les processus se fait par l’intermédiaire d’un segment de mémoire partagée nommé buffer de taille N fixée suivant les règles suivantes :
> • prod dépose des informations dans le buffer. Ce processus doit attendre si buffer est plein.
> • conso récupère les informations stockées dans buffer. Ce processus doit attendre si buffer est vide.
> • Le segment mémoire buffer est une ressource critique (partagée par plusieurs processus).
> • Les informations sont consommées dans l’ordre où elles sont produites [Premier Arrivé/Premier Consommé - FIFO].
> • Il peut y avoir plusieurs prod et conso partageant la ressource buffer

Files:
- `prod.c`
- `prod.h`
- `conso.c`
- `conso.h`
- `clean_prod.c`
- `init_prod.c`