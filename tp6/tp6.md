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
