# Introduction

Aujourd'hui, on approfondit la gestion des processus, en particulier la façon dont on les termine. Pour cela, on va utiliser les fonctions suivantes :


* `void exit(int status)` termine le processus normalement et la valeur de `status` est retournée au parent. Toutes les fonctions enregistrées avec `atexit` ou `on_exit` sont appelées dans l'ordre inverse de leur enregistrement. Les streams ouverts sont fermés et flushés, et les fichiers temporaires supprimés. La fonction ne retourne pas.
* `int atexit(void(*function)(void))` permet d'enregistrer la fonction passée en paramètre pour qu'elle soit exécutée si le processus se termine normalement ( appel à `exit()` ou fin de la fonction `main()` du programme. Les fonctions enregistrées avec cette méthode sont appelées dans l'ordre inverse de leur enregistrement. Une fonction peut être enresitrée plusieurs fois et sera appelée une fois par enregistrement. Retourne `0` si la fonction a bien été enregistrée, une autre valeur si il y a eu un problème.
* `void on_exit(void(*function)(int, void*), void *arg)` fonctionne de la même manière qu'`atexit()`, sauf qu'on peut donner des arguments à la fonction appelée.
* `void quick_exit(int status)` termine le processus immédiatement, en appelant les fonctions enregistrées à l'aide de `at_quick_exit()`, mais pas celles enregistrées avec `atexit()`. Envoie un signal `SIGCHLD` au processus parent.Les streams ouverts sont fermés et flushés, et les fichiers temporaires supprimés. La fonction ne retourne pas.
* `void at_quick_exit(void (function*)(void))` permet d'enregistrer des fonctions, comme `atexit()`, mais celles-ci seront appelées seulement si le processus se termine avec `at_quick_exit()̀`.
* `void abort(void)` termine le processus de façon brutale et anormale en levant le signal `SIGABRT`. Tous les streams ouverts par le processus sont fermés et flushés. La fonction ne retourne pas.

On verra aussi les fonctions suivantes qui permettent de gérer l'environnement du processus :

* `char* getenv(const char *name)` cherche la variable d'environnement `name`et retourne un pointeur correspondant à sa valeur.
* `int system(const char *command)` exécute une commande spécifiée par `command` et retourne après que la commande soit exécutée. Retourne - 1 s'il y a eu une erreur, sinon retourne le statut de la commande. 



# Exercice 1 : abort, exit, atexit et on_exit

Entre chaque étape, lancez votre programme et vérifiez ce qu'il se passe.

1) Ecrivez un programme simple qui utilise la fonction `abort()` pour quitter le processus lancé. 

2) Commentez la ligne qui appelle la fonction `abort()`, remplacez là par un appel à `exit()`. Rajoutez une fonction qui affiche quelque chose dans la console, enregistrez là à l'aide d'`atexit()`.

3) Rajoutez une fonction, Elle écrit aussi dans la console mais prend en paramètre la châine de caractère qu'elle va afficher. Enregistrez cette fonction avec `on_exit()`, plusieurs fois.

4) Décommentez la ligne qui appelle `abort()` et commentez celle qui appelle `exit()`. Que se passe-t-il ? pourquoi ?


# Exercice 2 : quick_exit, at_quick_exit

Entre chaque étape, lancez votre programme et vérifiez ce qu'il se passe.

1) Au lieu d'appeler `abort()` ou `exit()`, appelez maintenant la fonction `quick_exit()`. Quelle est la différence avec `exit()` ? avec `abort()` ? 

2) Enregistrez la fonction de l'etape `(2` de l'`exercice` 1 avec `at_quick_exit()`.

3) Remarquez que vous ne pouvez pas enregistrer la fonction qui prend des paramètres.

# Exercice 3 : rajout de fork

Cette fois, on va rajouter la notion de processus parent et enfant avec `fork()` que l'on a vu lors d'une des démonstrations précédentes.

1) Commencez par utiliser `fork()` pour créer un processus enfant ! Le parent attends la fin de l'exécution de l'enfant avec la fonction `wait()`, puis se termine avec `exit()`.

2) Enregistrez des fonctions avec `at_exit()` ou `on_exit()`, avant la création du processus enfant. 

3) Dans le code correspondant au processus enfant, enregistrez à nouveau des fonctions avec `at_exit()` ou `on_exit()`. Que se passe-il lorsque vous lancez le programme ? 

4) Maintenant, faites en sorte que le processus enfant se termine avec `quick_exit()` et qu'il enregistre ses fonctions avec `at_quick_exit()`. Le code du parent ne change pas.

# Exercice 4 : getenv et system

Jouez avec les fonctions `getenv()` et `system()` pour récupérer des variables d'environnement et exécuter des commandes, faites-donc des trucs funky ! 
