## Les Fonctions Amies

Les fonctions amies ne sont membres d'aucune classe, ce sont des focntions ordinaires avec des droits d'accès privilégiés à une certaine classe. Une fonction amie aura accès aux membres privés de la classe dont on est ami.

### Exemple

```cpp
class Rat {
private:
    int num;
    int denum;
public:
    ...
friend:
    ostream &operator<<(ostream& os, Rat r) {
        ...
    };  // Ami pour raisons syntaxiques
}
```

## Séparation du code

On sépare le code d'une classe (ou autre) dans deux fichiers:

### Les Headers (Déclarations) 

```cpp
#ifndef RAT_H
#define RAT_H

#include <iostream>

class Rat {
private:
    int num;
    int denum;
public:
    Rat operator -();
friend ostream<<(ostream& o, Rat r);
}

#endif
```

### Les Sources (Implémentations)

```cpp
#include "rat.h"

Rat Rat::operator-() {...}
```

### Compiler des sources et headers

Génération des binaires pour le fichier `rat.cpp`
```bash
g++ -c rat.cpp
```

Génération des binaires pour le fichier `main.cpp`
```bash
g++ -c main.cpp
```
Edition des liens pour créer l'executable `main`
```bash
g++ rat.o main.o -o main
```

### Compiler avec un Makefile

```makefile
rat.o: rat.h rat.cpp
    g++ -c rat.cpp

main.o: main.cpp rat.h
    g++ -c main.cpp

main: main.o rat.o
    g++ rat.o main.o -o main
```

On n'a plus qu'à lancer la compilation avec:
`make main`

`main` est la cible que l'on veut fabriquer.

`make` lancé sans arguments choisira la première déclaration dans le makefile.

## Différence entre une `struct` et une `class`

```cpp
struct Book {
    string nom;
    int montant;
};
```

Equivaut à

```cpp
class Book {
public:
    string nom;
    int montant;
}
```

## Les sous-classes

On a le droit de déclarer des classes au sin d'une classe.

```cpp
class Point {
public:
    enum Couleur {
        bleu;
        rouge;
    }
}

main() {
    Point::Couleur c = rouge;
}
```