# Introduction

Aujourd'hui, on va voir les manipulations de base des threads. Pour cela, on va utiliser les fonctions suivantes : 

* "int pthread_create(pthread_t *thread, const pthread_attr_t *attr, void*(*start_routine) (void *), void *arg);" : Cette fonction permet de démarrer un nouveau thread depuis l'appelant. On lui passe en premier argument un pointeur vers un pthread_t qui correspond au thread créé. Le 2e argument correspond aux options que l'on veut donner au thread que l'on créé, si on passe NULL, il utilise les options par défaut. Ensuite, on lui passe un pointeur de fonction, c'est cette fonction qui sera utilisée par le thread créé. Le dernier argument correspond aux arguments à passer à la fonction.
* "void pthread_exit( void* retval);" : Termine le thread appelant, et retourne une valeur via `retval`.
* "int pthread_join(pthread_t thread, void **retval);" : L'appelant attends que le thread passé en premier argument se termine, et récupère la valeur de retour dans `retval`.


# Exercice 1 

3 fichiers texte sont fournis avec l'enoncé des exercices.On va utiliser plusieurs threads pour lire dans ces différents fichiers et afficher le résultat dans le terminal. Créez une fonction qui permet de lire le contenu d'un fichier et le retourne. Dans votre `main`, faites en sorte de créer 3 threads qui vont exécuter cette fonction. Chaque thread lira l'un des trois fichiers fournis. Récupérez les valeurs à l'aide de `pthread_join` et affichez les dans la console dans l'ordre des fichiers (file1, file2, file3).

# Exercice 2

Le fichier "seq_qsrt.c" correspond à l'implémentation séquentielle de l'algorithme QuickSort, qui sert à trier un tableau avec une complexité moyenne n log n. Analysez son fonctionnement et trouvez quelle partie de l'algorithme peut être parallelisée en utilisant les méthodes sur les threads que l'on vient de voir. Une fois que vous avez identifié la partie parallelisable, implémentez-là.
