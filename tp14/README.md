# TP14 - Programmation Concurrente: Thread (Suite)

***Fichier globaux:***

[Consigne](./tp14.pdf)

## Exercice 1: Gestionnaire de Billes
> On souhaite réaliser l’exemple suivant:
> - N threads (par ex. N = 4) ont besoin chacun d’un nombre k d’une ressource (par ex. des Billes) pour avancer leur travail
> - Cette ressource existe en un nombre limité : on ne peut satisfaire la demande de tout le monde en même temps. Par exemple, la demande des N (N=4) est de (4, 3, 5, 2) billes et on ne dispose que de nb_max_billes = 9 billes
> - Chaque thread répète la séquence (par ex. m fois) : “demander k ressources, utiliser ressources, rendre k ressources”
> - Le “main” crée les N threads. Il crée également un thread contrôleur qui vérifie en permanence si le nombre de Billes disponible est dans l’intervalle [0..nb_max_billes]
> - Pour chaque thread 𝑇𝑖, l’accès à la ressource se fait par une fonction “demander(k)” qui doit bloquer le demandeur tant que le nombre de billes disponible est inférieur à k
> - 𝑇𝑖, rend les k billes acquises après son travail et recommence sa séquence
### Algorithme
#### Main
```
Créer Contrôleur
Lancer Contrôleur
Créer N threads travailleurs
Attendre la fin des N threads
Terminer le Contrôleur
```
#### Travailleur
```
itérer m fois
Demander(k_billes)
simuler un travaille avec une attente aléatoire (sleep)
Rendre(k_billes)
```

#### Demander
```
Tant que nbr_billes_disponible < k_billes:
se bloquer sur un semaphore d'attente
nbr_billes_disponible = nbr_billes_disponible - k_billes
```

#### Rendre
```
nbr_billes_disponible = nbr_billes_disponible - k_billes
réveiller ceux qui sont en attente (cf Demander)
```

#### Contrôleur
```
Iterer toujours
Verifer que 0 <= nbr_billes_disponible <= max_billes
delai(1 sec)
```
#### Remarques
> nbr_billes_disponible est une ressource partagée il faudra donc évidemment protéger les accès en lecture et en écriture. Quand les threads en attente sont réveillés, ça ne veut pas dire que le nombre de billes dont ils ont besoin sont disponibles mais simplement qu’un thread a posé des billes et qu’il est possible qu’ils en aient suffisamment pour travailler. Si ce n’est pas le cas, ils vont se remettre en attente. L’usage du semaphore pour l’attente est là pour garantir une attente passive. Il ne sert à rien de regarder le nombre de billes disponible tant qu’un thread n’en a pas rendu.


Files:
- `ex1/include/billes.h`
- `ex1/src/billes.c`
- `ex1/src/main.c`
- `ex1/src/travailleur.c`
- `ex1/src/controleur.c`