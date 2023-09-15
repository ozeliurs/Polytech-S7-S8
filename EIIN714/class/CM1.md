# CM1 - Introduction à C++

## Définition de la Programmation MultiParadigmes

Paradigmes:
- Impératif (C)
- Objet (Java)
- Fonctionnel (Lisp, Haskell)

## ELements de C++

La doc référente: [cppreference.com](https://en.cppreference.com/w/)

### Flux

#### Programme Minimal
```cpp
#include <iostream>

// using namespace std; // Pour éviter std:: devant les éléments de la librairie standard

int main() {
    std::cout << "Hello World!" << std::endl;
    return 0;
}
```

#### Saisie de données

```cpp
#include <iostream>

int main() {
    int i;
    int j;
    std::cout << "Saisir un entier: ";
    std::cin >> i >> j;
    std::cout << "Vous avez saisi: " << i << << " et " << j << std::endl;
    return 0;
}
```

#### Boucle de saisie

Boucle de saisie jusqu'à EOF (End Of File) (Ctrl+D sur Linux, Ctrl+Z sur Windows)

```cpp
#include <iostream>

int main() {
    int i;
    std::cout << "Saisir un entier: ";
    while (std::cin >> i) {
        std::cout << "Vous avez saisi: " << i << std::endl;
        std::cout << "Saisir un entier: ";
    }
}
```

#### Ecriture vers un fichier

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ofstream f("test.txt");
    f << "Hello World!" << std::endl;
    // f.close(); // Not needed as the destructor will close the file
    return 0;
}
```

#### Lecture depuis un fichier

```cpp
#include <iostream>
#include <fstream>

int main() {
    std::ifstream f("test.txt");
    std::string s;
    f >> s;
    std::cout << s << std::endl;
    // f.close(); // Not needed as the destructor will close the file
    return 0;
}
```

### Les types

Entiers: `int`

Charactères: `char`

Booléens: `bool`

Flottants: `float`, `double`

Vecteurs: `std::vector`

```cpp
#include <iostream>
#include <vector>

int main() {
    std::vector<int> v(10); // Vecteur de 10 entiers

    v.push_back(1); // Ajoute un élément à la fin du vecteur
}
```

Chaines de caractères: `std::string`