# Introduction

Pour la 6e semaine de démonstration, on attaque les fonctions d'allocation de mémoire ! 


* `void* malloc(size_t size)` Alloue un emplacement de taille `size` et retourne un pointeur vers celui-ci. Attention, la fonction `malloc` ne clean pas la mémoire à cet emplacement, il peut y avoir n'importe quelle valeur. Elle retourne NULL si l'allocation a échoué.

* `void* calloc(size_t nitems, size_t size)` Alloue un emplacement de `nitems` * `size` et retourne un emplacement vers celui-ci. Contrairement à `malloc`, `calloc` s'assure que toute la mémoire allouée est mise à 0. Retourne NULL si l'allocation a échoué.

* `void* realloc(void *ptr, size_t size)` Essaie de réallouer l'emplacement mémoire pointé par `ptr` qui a été précédemment alloué par `malloc` ou `calloc`. Retourne un pointeur vers le nouvel emplacement, NULL si la fonction a échoué. Si le paramètre `size` est à 0, la mémoire pointée par `ptr` est désalouée, et NULL est retourné.

* `void free(void* ptr)` Désalloue la mémoire qui a été allouée à l'aide de `malloc`, `calloc`, ou `realloc`. Ne retourne rien.

Lorsque ces fonctions échouent, on peut utiliser la variable `errno` (#include <errno.h>), qui contient alors le code d'erreur nous permettant de savoir ce qui n'a pas été. Pour obtenir un message d'erreur sous forme de chaîne de caractère correspondant à l'erreur qui vient de se produire, il faut alors utiliser la fonction `char* strerror(int errnum)`, en lui passant `errno` en paramètre.


Pas d'exercices aujourd'hui, on fera des exemples au projecteur ! 

