# Introduction

Avant de commencer à réaliser les exercices suivants, regardez les pages de manuel des commandes `ps` et `kill`. Si lors de la réalisation de l'un des exercices suivants, vous n'arrivez pas à arrêter l'un de vos programme, utilisez la commande `ps` pour récupérer son pid et la commande `kill`pour le tuer.
includes : 
	unistd.h pour le `fork()`
	sys/types.h pour `getpid()` et `getppid()`
	sys/wait.h pour `wait()`
	signal.h pour `kill()`

# Exercice 1
Ecrivez un programme qui créé un processus enfant à l'aide de `fork()`. Faites en sorte que le processus enfant soit dans une boucle infinie (il n s'arrête jamais), et le processus parent attend la fin de l'exécution du fils (`waitpid()`).
Trouvez le pid du processus fils à l'aide de la commande `ps` vue précédemment et tuez le à l'aide de la commande `kill`.
Que se passe-t-il pour le processus parent ? Pourquoi ?

# Exercice 2
Reprenez le code de l'exercice précédent. Ajoutez des instructions afin que le processus enfant affiche son propre pid, ainsi que celui de son parent (utilisez `getpid()` et `getppid()`). Mettez en pause votre processus parent pendant quelques secondes à l'aide de la fonction `sleep()` puis utilisez la fonction `kill()` pour tuer le processus enfant.

# Exercice 3
Ecrivez un programme qui créé un processus enfant, cette fois ce processus enfant doit utiliser `execve()` pour lancer le programme que vous avez réalisé dans l'exercice 2.
