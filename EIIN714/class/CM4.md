## Les constructeurs

```cpp

class Date {
    Date(int n) {
        // ...
    }
}

Date d1, d2;

std::cout << (d1 == d2) << std::endl; // Ceci appelle l'opérateur == de Date
```

### La conversion Implicite

```cpp
std::cout << (d1 == 212697) << std::endl;
```

Le compilateur voit que l'opérateur == de Date n'est pas défini pour un int, il va donc chercher un constructeur de Date qui prend un int en paramètre. Si il en trouve un, il va créer un objet de type Date avec ce constructeur puis appeler l'opérateur == de Date.

### La conversion Explicite

```cpp
std::cout << (212697 == d1) << std::endl;
```

Le compilateur voit que l'opérateur == de int. Il va donc chercher un constructeur de int qui prend un Date en paramètre. Mais il n'en trouve pas. On doit donc définir un opérateur == pour int qui prend un Date en paramètre.

```cpp
bool operator==(int n, const Date& d) {
    // ...
}
```

On peut aussi définir notre operator== comme ami pour définir explicitement les types des paramètres.

```cpp
class Date {
    friend bool operator==(const Date& d, const Date& d) {
        // ...
    }
};
```

### Interdire la conversion implicite

Si on veut interdire la conversion automatique, on peut déclarer le constructeur comme explicit.

```cpp
class Date {
    explicit Date(int n) {
        // ...
    }
}
```

```cpp
class A {
    A(int n) {
        // ...
    }
}

class B {
    B(int n) {
        // ...
    }
}

int func(A a) {
    // ...
}

int func(B b) {
    // ...
}

main() {
    std::cout << func(123) << std::endl;
}
```

Dans le cas ci dessus le compilateur ne peux pas savoir quel contructeur de conversion utiliser pour appeler func.

Pour lever l'ambiguité, on doit soit définir un constructeur comme explicite, soit rendre les deux explicites et appeler le contructeur de conversion à la main.

## Initialisation et Affectation

```cpp
class Point {
    int x, y;
    public:
        // ...
}

class Segment {
    Point start, end;
    public:
        Segment(Point s, Point e) {
            start = s;  // Affectation
            end = e;    // Affectation
        }
}
```

Pour éviter les affectations et bien faire une initialisation on peux utiliser l'opérateur `:`.

```cpp
class Segment {
    Point start, end;
    public:
        Segment(Point s, Point e): start(s), end(e) {}  // Initialisation
}
```

Pareil pour `Point`

```cpp
class Point {
    int x, y;

    public:
        Point(int x, int y): x(x), y(y) {}  // Initialisation
}
```

Le Contructeur par défaut n'est synthétisé que si on ne définit aucun constructeur.

Il faut donc utiliser le constructeur par défaut pour initialiser les attributs et non pas les affecter. De même pour les valeurs constantes.