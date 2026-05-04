# TP11 - Producteur/Consommateur (Mémoire Partagée/Semaphore)

## Exercice 1: Calculateur
> Écrivez le programme client qui envoie des requêtes à des serveurs de calcul. Le client envoie des expressions arithmétiques simples de type a + b, a - b, a * b, a / b et attends le résultat avant tout autre requête. Écrivez un programme serveur qui reçoit et traite les requêtes envoyées par différents clients. Le nombre de client est fourni au programme en argument. Après traitement, le serveur transmet les résultats aux clients. Il faut permettre à plusieurs clients d’envoyer des requêtes aux serveurs. Plusieurs serveurs sont à même de traiter les calculs. Par exemple, si un client envoie la requête 4+5, un serveur évalue cette expression et retourne le résultat 9 au client concerné. Vous utiliserez la mémoire partagée pour gérer les échanges.
> • Une mémoire partagée pour établir la communication avec les serveurs (sens client vers serveur).
> • Une mémoire partagée pour que le serveur puisse retourner le résultat de l’évaluation. Il faut une zone mémoire dédiée à chaque client. (sens serveur vers client)
> La requête d’un client doit contenir un identifiant qui permet de retrouver facilement à quel client le serveur doit répondre. Vous pouvez utiliser les structures suivantes pour représenter une requête et une réponse :
> ```
>    struct requete_client_serveur {
>        int clientId;
>        int nombre1;
>        int nombre2
>        char operator;
>    };
>```
> ``` 
>   struct resultat_client_serveur {
>       int nombre1;
>       int nombre2;
>       int resultat;
>       char operator;
>   };
> ```

Files:
- `Makefile`
- `dijkstra.c`
- `dijkstra.h`
- `init.h`
- `clean.h`
- `client.c`
- `client.h`
- `serveur.c`
- `serveur.h`
- `init.c`
- `clean.c`