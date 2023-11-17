## Pointeurs: La fuite mémoire

En quelques mots, c'est l'instruction **delete** qui est manquante.

```cpp
class List {
    Cell *head;

public:
    Cell get_first() {
        // Supprimme le premier element
        int r = head->val;

        head = head->next;

        return r;
    }
}
```

Le code ci dessus pose problème, en effet la première cellule n'est jamais libérée. C'est une fuite mémoire. Il suffit de supprimmer la cellule pour régler ce problème.

```cpp
class List {
    Cell *head;

public:
    Cell get_first() {
        // Supprimme le premier element
        Cell *p = d;
        int r = head->val;

        head = head->next;

        delete p;

        return r;
    }
}
```

## Les membres par défaut

```cpp
class A {
public:
    // Constructeur par défaut
    A();
    // Destruteur par défaut
    ~A();
    // Affectation
    A& operator=(const A&);
    // Contructeur de copie
    A(const A& a);
}
```

```cpp
main() {
    A x;            // Appelle le construteur par défaut A()

    A y = x;        // Appelle le contructeur par copie A(A a)
                    // Attention ici c'est un égal d'initialisation qui est appelé.

    A y(x);         // Ici aussi c'est le contructeur de copie qui est appelé

    A z;

    z = y;          // Ici c'est operator= qui est appelé
                    // C'est un égal d'affectation
}
```

### Comment sont générés les membres par défaut

Par défaut `A& operator=(const A&);` recopiera toutes les données membres.

## L'héritage private

Tout ce qui était public devient private (on perd l'interface publique de base)

```cpp
class Pile: private vector<int> {
    int nb_elem;

public:
    Pile(int length): vector<int>(length), nbelemn(0) {}

    void push(int value) {
        *this[nb_elem] = n;
        nb_elem++;
    }

    int pop() {
        return (*this)[--nb_elem];
    }
}
```

Quand l'utilisateur tilise notre pile, il aura accès aux fonctions définies par Pile (`push`, `pop`) et ne pourra pas modifier l'objet hérité (`vector<int>`).

