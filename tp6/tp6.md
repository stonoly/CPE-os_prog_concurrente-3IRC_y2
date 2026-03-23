# TP6
*Global:*

`Makefile`

## Exercice 1: Premiers Tubes
> Écrivez un programme (guess) dont le processus père demande a l’utilisateur un nombre et le transmet à l’aide d’un pipe à son processus fils.Le processus fils génère un nombre et compare celui-ci au nombre reçu de son père. Si le nombre est plus petit que celui généré, il répond au père dans un second pipe `+`, si le nombre est plus grand `-` et s’il est identique `=` Les deux processus se terminent lorsque le bon nombre a été trouvé par l’utilisateur.

Files : 
- `guess.h`
- `guess.c`

## Exercice 2: Tubes et Redirection
> Lors des TP d’administration système vous avez déjà utilisé les pipes et redirection. Dans cet exercice, vous allez à l’aide de pipe et de redirection l’équivalent d’une série de commandes. Le but n’est pas de réécrire ces commandes mais d’utiliser celle existante dans vos programmes.

### Variant 1: Redirection Simple
> Écrivez un programme dont le code correspond à la commande suivante: `wc < /etc/passwd`

Files:
- `simple_redirection.h`
- `simple_redirection.c`

### Variant 2: Pipe Simple
> Écrivez un programme dont le code correspond à la commande suivante: `cut -f 1 -d : /etc/passwd | tr a-z A-Z`

Files:
- `pipe_simple.h`
- `pipe_simple.c`

### Variant 3: Pipeline Complet
> Écrivez un programme dont le code correspond à la commande suivante: `cut -f 1,3 -d : < /etc/passwd | sed 's+^\(.*\):\(.*\)+\2:\1+' | sort -n > users` ⚠ cut n’a pas connaissance ici qu’il manipule le fichier /etc/passwd contrairement au cas précédent. Il en va de même pour sort qui ne sait pas qu’il écrit dans un fichier nommé users.

Files:
- `complete_pipeline.h`
- `complete_pipeline.c`

## Exercice 3: Filtres
> Écrivez un programme (somme) composé de 4 processus réalisant les traitements suivants (voir Schéma) Un premier processus (générateur), génère N nombres aléatoires positifs ou nuls. Il dépose chacun de ses nombres dans un tube. Une fois la génération terminée, il envoie -1 dans le tube. Il se met alors en attente des sommes issus des processus pair et impair. Un second processus (filtre) récupère les différents nombre depuis le tube et en s’ils sont pairs ou impairs les déposes respectivement dans un tube ou un autre. Il dépose -1 dans chacun des tubes. Un troisième processus (pair) récupère les nombres pairs reçus depuis le tube et les somme. Une fois le dernier nombre reçu, il envoie la somme totale au processus générateur. Un quatrième processus (impair) récupère les nombres impairs reçus depuis le tube et les somme. Une fois le dernier nombre reçu, il envoie la somme totale au processus générateur.

Files:
- `sum.h`
- `sum.c`