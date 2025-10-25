# Construire le projet
Vous pouvez utiliser un dev container de base C++ de VScode.
Le projet utilise cmake, pensez à l'inclure dans votre dev container.

Voici les lignes de commandes pour compiler le projet:
```
$ mkdir build
$ cd build
$ cmake ..
$ make
```

# Répertoire data

Il contient 2 fichiers `books.txt`et `users.txt` que vous pouvez utilisez pour tester votre code.
Pour ca il suffit de les copiers dans le repertoire `build` avec l'application `bibliotheque`

# 1. Expliquez en détails une fonctionnalité / notion dans le code que ne nous avons pas ou peu vu en cours.

Dans ce projet, j’ai utilisé la fonction de tri de la STL (Standard Template Library) avec une fonction lambda. Une fonction lambda, c’est simplement une petite fonction écrite directement dans le code, sans avoir besoin de la déclarer à part. Par exemple, je m’en suis servi pour trier les livres par titre ou par auteur de façon simple et rapide.


# Proposez une solution plus adaptée pour la gestion de bibliothèque et faisant appel éventuellement à une technologie autre que le C++, et expliquez comment vous interfaceriez ça avec le C++. Pensez au futur de cette bibliothèque à Alexandrie qui pourrait éventuellement contenir des millions de livres.

Si la bibliothèque devient grosse par exmeple millier de livre, ce ne serait plus efficace d’utiliser seulement des fichiers texte en C++. La recherche deviendrait lente et il serait difficile de tout charger en mémoire. Une meilleure solution serait d’utiliser une base de données comme MySQL. Ensuite, on pourrait créer un petit programme en Python qui parle avec MySQL et s’occupe de gérer les données (ajouter, modifier, rechercher des livres). Le programme C++ pourrait simplement envoyer des demandes par exmepel ajoute ce livre ou cherche ce titre et recevoir la réponse. Celas serait plus optimiser et plus rapide.