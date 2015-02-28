# Introduction

Aujourd'hui, on va réutiliser les manipulations de base des threads. Cette fois, on rajoute la gestion des mutex.Les mutex sont des primitives de synchronisation qui permettent de contrôler l'accès aux ressources partagées par différents threads. On peut les manipuler avec les fonctions suivantes :



*  Pour Créer un mutex, on déclare une variable de type pthread_mutex_t et on l'initialise avec la constante PTHREAD_MUTEX_INITIALIZER.
* "int pthread_mutex_lock(pthread_mutex_t * mutex);" permet de déterminer le début d'une zone critique. Elle renvoie 0 en cas de succès et EINVAL si le mutex n'est pas initialisé ou EDEADLK si le mutex est déjà vérouillé par un thread différent.
* "int pthread_mutex_unlock(pthread_mutex_t* mutex);" permet de relâcher le verrou passé en argument détermine la fin d'une zone critique. Elle renvoie 0 en cas de succèsn EINVAL si le mutex n'est pas initialisé ou EPERM si le thread n'a pas la main sur le mutex.

On peut aussi utiliser "in pthread_mutex_init(pthread_mutex_t* mutex, const pthread_mutexattr_t* mutexattr);" pour initialiser un mutex avec des attributs particuliers et "int pthread_mutex_destroy(pthread_mutex_t *mutex);" pour détruire un mutex mais nous n'aurons pas besoin de ces fonctions pour les exercices.


# Exercice 1 

Ecrivez un programme dans lequel deux threads accèdent au même fichier pour en lire le contenu (pas besoin d'afficher le contenu du fichier. Identifiez la partie critique du programme et protégez là avec des mutex.

# Exercice 2 

Utilisez le code fournit (starterpack.c) pour écrire un programme qui possède les caractéristiques suivantes : 

* Le but du programme est de simuler des dépenses et revenu d'argent jusqu'à ce qu'il n'y ai plus d'argent dans la variable `account.money`. Le programme doit donc se terminer lorsque cette variable passe en dessous de 0.
* La fonction principale doit créer "NB_SPENDINGS" threads et "NB_EARNINGS" threads qui décrémenteront ou incrémenteront l'argent dans `account.money`, ainsi qu'un thread de contrôle qui vérifie s'il reste de l'argent.
* Pour que le programme ne se termine pas en quelques secondes, n'hésitez pas à utiliser la fonction `sleep()` durant l'exécution de vos différents threads, ce sera plus fun !
* Ajoutez de l'aléatoire dans les dépenses, les revenus, la durée du `sleep()`.
* Une fois que vous avez écrit le programme, identifiez les zones critiques et ajoutez un mutex afin de bien gérer la synchronisation.
