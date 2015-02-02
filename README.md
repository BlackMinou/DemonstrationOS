# Exercice 1 :

Ecrire un programme qui prend en paramètre un nom fichier et permet d'écrire dedans depuis la console.

	1. Récupérez le nom du fichier comme paramètre du programme.
	2. Ouvrez le fichier en écriture à l'aide de fopen.
	3. Récupérez la valeur entrée par l'utilisateur avec fgets tant qu'il rentre des caractères dans la console (On considère qu'une ligne vide correspond à la fin du programme).
	4. Ecrivez dans le fichier au fur et à mesure avec fprintf.
	5. N'oubliez pas de fermer votre fichier à l'aide de fclose.


# Exercice 2 :

Ecrire un programme qui écrit une structure dans un fichier binaire.

	1. Définissez la structure suivante au début de votre fichier : 
~~~C
	typedef struct {
		char first_name[50];
		char name[50];
		int age;
	}Person;
~~~

	2. Au début de votre programme, créez trois ou quatre personnes
	3. Créez un fichier binaire avec la fonction fopen puis insérez-y vos personnes avec la fonction `fwrite`. 
	4. Essayez maintenant de récupérer la deuxième personne que vous avez inséré dans le fichier, à l'aide des fonctions `fseek` et `fread`.


# Exercice 3 :
Créez un répertoire « exercice3 ». A l'intérieur, créez un ou plusieurs fichiers texte simples. Maintenant, écrivez un programme qui permet de lister le contenu de ce répertoire de manière détaillée, en utilisant les fonctions `opendir`, `readdir` et `fstat`. Le Programme doit prendre en paramètre le nom du dossier et afficher son contenu, on doit voir le plus d'informations possible sur chaque fichier appartenant au répertoire.

Pour les plus motivés, vous pouvez essayer de rendre ce programme récursif, c'est-à-dire que si le répertoire en contient un autre, votre programme listera aussi les fichiers de cet autre répertoire.
