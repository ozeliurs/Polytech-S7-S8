## Les Exceptions

Le but d'une exception est de signaler une erreur. Cela permet de traiter l'erreur à un autre que le lieu où elle est détectée.

Si un exception n'est pas traitée, le programme s'arrête.

Les exceptions sont des objets, elles peuvent donc être de n'importe quel type (int, string, classe, ...).

#### Envoi d'une exception

```cpp
class MVector {
    std::vector<float> v;
    
public:
    class BadIndex : public std::exception {};

    float& operator[](int i) {
        if (i < 0 || i >= v.size()) {
            throw BadIndex();
        }
        return v[i];
    }
}
```

#### Traitement d'une exception

```cpp
try {
    // ...
} catch (MVector::BadIndex& e) {
    // ...
} catch (std::exception& e) {
    // ...
}
```

## Les références

Une référence est un alias pour une variable. Elle permet de manipuler une variable sans la copier.

```cpp
std::ostream& operator<<(std::ostream& os, Date d) {
    os << d.jour << "/" << d.mois << "/" << d.annee;
    return os;
}
```

Ici Date est passé par valeur, donc copié. Si on veut éviter la copie, on peut passer par référence.

```cpp
std::ostream& operator<<(std::ostream& os, const Date& d) {
    os << d.jour << "/" << d.mois << "/" << d.annee;
    return os;
}
```

⚠️ Attention à ne pas oublier le const, sinon on aura des probleme en appelant certaines méthodes ⚠️

```cpp
std::cout << (d1 + d2) << std::endl;
```

Ici, on appelle l'opérateur + de Date. Si on ne met pas const, on ne pourra pas appeler l'opérateur + car il est défini comme ceci:

```cpp
Date operator+(const Date& d) const;
```

---

Dans certains cas on veut pouvoir modifier la valeur de retour d'une fonction. On peut donc utiliser une référence non constante.

```cpp
float& operator[](int i) {
    return v[i];
}
```

Ceci nous permet de faire:

```cpp
MVector v;

v[0] = 1;
v[1] = 2;
```

Dans ce cas précis, on veut aussi pouvoir lire la valeur, donc on peut définir un opérateur[] const.

```cpp
float& operator[](int i) const {
    return v[i];
}
```

Le const à la fin de la fonction signifie que la fonction ne modifie pas l'objet. (l'argument implicite).

## Conversions

On a des contructeurs de conversion qui permettent de convertir un type en celui de la classe.

```cpp
class Date {
    Date(int n) {
        // ...
    }
}
```

Mais on peut aussi écrire des opérateurs de conversion.

```cpp
class Date {
    operator int() {
        // ...
    }
}
```

Ici int correspond à la fois au type de retour et au type de conversion.

On peut l'utiliser comme ceci:

```cpp
Date d(1, 1, 2000);
int n(d);
```

De la même manière que pour les contructeurs, on peut définir des opérateurs de conversion explicites.

```cpp
class Date {
    explicit operator int() {
        // ...
    }
}
```