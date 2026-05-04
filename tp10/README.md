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

## Exercice 3: Échange de valeur
> Deux processus P1 et P2 disposant chacun d’un tableau stockant N entiers. P1 et P2 veulent pouvoir s’échanger des nombres de leur tableau de manière à ce que, à la fin de leur exécution réciproque, P1 dispose des N plus petites valeurs et P2 des N plus grandes. À l’aide de sémaphore, d’une mémoire partager permettant de stocker 3 entiers, le fonctionnement sera le suivant:
> • P1 cherche le maximum dans son tableau et l’écrit dans la 1ère case de la mémoire partagée.
> • P2 cherche le minimum dans son tableau et l’écrit dans la 2ème case de la mémoire partagée.
> • P0 vérifie que la valeur de la première case est supérieure à la valeur de la seconde case. Si c’est le cas, P0 effectue l’échange des valeurs, sinon il met la valeur -1 dans la troisième case de la mémoire partagée.
> • Chaque processus (P1 et P2) récupère sa nouvelle valeur dans la case respective, l’écrit à la place de l’ancienne, puis recommence le même travail.
> Si la valeur de la troisième case est égale à -1, les processus n’effectuent aucun échange. Ils affichent leur tableau et s’arrêtent. Écrivez les programmes de P0, P1 et P2.

Files:
- `p1.c`
- `p1.h`
- `p2.c`
- `p2.h`
- `p0.c`
- `p0.h`
- `key_change.h`
- `clean_change_value.c`
- `init_change_value.c`