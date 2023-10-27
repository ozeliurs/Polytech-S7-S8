## Héritage

### Règles de Base

- on hérite toujours de **tous les membres** (données et méthodes) de la classe mère
- les membres **private** de la classe mère ne sont **pas accessibles** dans les classes filles
- les droits d'accès restent identiques ou diminuent (on ne peut pas augmenter les droits d'accès)
- par défaut, c'est le contructeur par défaut de la classe mère qui est appelé

```cpp
class A {
    public:
        A() {};
        A(int n) {};
};

class B: public A {
    public:
        B() {
            // on appelle implicitelent A()
        }

        B(int n, int p): A(n) {
            // on appelle explicitement B(int n)
        }
}
```

### Héritage public

```cpp
class Point {
    int x, y;
}

class Pixel: public Point {
    string color;
}
```

L'héritage public traduit le fait qu'un pixel est un point **particulier**. En conséquence on à la conversion implicite de `Pixel` vers `Point`.

L'encombrement mémoire de l'instance d'une classe fille sera toujours supérieur à celui de la classe mère.

```cpp
main () {
    Point pt();
    Pixel px();

    Point pt2 = px; // Cela est possible grâce à l'héritage.
}
```

### Héritage private