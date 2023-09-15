#

## Définition de la Programmation MultiParadigmes

Paradigmes:
- Impératif (C)
- Objet (Java)
- Fonctionnel (Lisp, Haskell)

## ELements de C++

La doc référente: [cppreference.com](https://en.cppreference.com/w/)

### Programme Minimal
```cpp
#include <iostream>

// using namespace std; // Pour éviter std:: devant les éléments de la librairie standard

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

### Saisie de données

```cpp
#include <iostream>

int main() {
    int i;
    std::cout << "Saisir un entier: ";
    std::cin >> i;
    std::cout << "Vous avez saisi: " << i << std::endl;
    return 0;
}
```

