## Références en C++

```cpp
void wrap (int &p, int &q) {
    int tmp = p;
    p = q;
    q = tmp;
}
```

## Les opérateurs

### Les opérateurs << >>.

```cpp
#include <iostream>


std::ostream &operator<<(std::ostream &o, BookRecord br) {
    o << b.name << b.price;
}

std::istream &operator>>(std::istream &i, BookRecord& br) {
    i >> br.name;
    i >> br.price;
}
```

Après on peux utiliser

```cpp
BookRecord br = BookRecord("test", 10)

std::cout << br << std::endl;

// Equivalent à

std::operator<<(std::cout, br);
```

### Les opérateurs ==

```cpp
bool operator==(BookRecord b1, BookRecord b2) {
    return b1.name == b2.name && b1.price == b2.price;
}
```

On peux ensuite l'utiliser:

```cpp
BookRecord br = BookRecord("test", 10)
BookRecord br2 = BookRecord("test", 10)
BookRecord br3 = BookRecord("test", 9)

br1 == br2; // True
br1 == br3;

// Equivalent à

std::operator==(br1, br2);
```

## Les classes

Un programme c++ est composé de:
- Variables Globales
- Fonctions Ordinaires (qui n'appartiennent à personne)
- Classes
- une fonction `main`

```cpp
class Rat {
    
};
```

```cpp
Rat r(2, 3);
Rat r;
Rat r(2);
Rat r = 2;
```

`this` est un pointeur vers l'objet courant.

#### Vocabulaire

Attributs == Données Membres<br>
Méthodes == Fonctions Membres