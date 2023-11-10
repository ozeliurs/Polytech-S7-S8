## Les valeurs par défaut des arguments

```c
int func(string s, int n, char c);

// On peut définir une valeur par défaut aux arguments
int func(string s, int n, char c = 'A');

// On continue et on définit une valeur par défaut pour n
int func(string s, int n = 2, char c = 'A');

// Pareil pour le string
int func(string s = "hello", int n = 2, char c = 'A');

// On ne peut donner de valeur par défaut qu'aux X derniers arguments.
```

## Les opératuers à effet de bord

```c
operator<<(ostream & os, const Matrix &m);

// Pourquoi le premier argument est il passé par référence ?
// Pour que << modifie l'argument qui lui est passé.

// Pourquoi le deuxième argument est il passé par référence ?
// Pour des raisons d'efficacité (d'ou le const).
```

## Les pointeurs

⚠️ Attention ⚠️

Le caractère **\*** sert à la fois à déclarer un pointeur:

```c
int * ptr;
```

Et aussi à déréférencer un pointeur

```c
cout << (*ptr);
```

### La fonction swap

```c
void swap(int *p, int *q) {
    int tmp = *p;
    *p = *q;
    *q = tmp;
}
```

Pour l'appel on va chercher l'adresse de la variable avec l'opérateur **&** (à ne pas confondre avec le & de la référence)

```c
main() {
    int a = 1;
    int b = 2;
    swap(&a, &b);
}
```

## Les allocations dynamiques de mémoire

```c
main() {
    A* ptr;
    ptr = new A; // allocation mémoire et appel du contructeur par défaut
    // ou
    ptr = new A(2, 3); // allocation mémoire et appel du contructeur avec deux args int
}
```

L'intéret de définir un pointeur et de créer A avec new c'est que la durée de vie de la variable n'est pas limitée au bloc dans lequel la variable à été instanciée. On doit appeler **delete** pour libérer l'espace mémoire.


### Exemple
```c
struct Cell {
    int val;
    Cell* next;
    Cell(int n=0, Cell* ptr=0): val(n), next(ptr) {}
}

main() {
    Cell * debut;
    debut = new Cell(12);
    debut = new Cell(24, debut);
    debut = new Cell(13, debut);

    // Pour afficher le premier element on déréférence le pointeur (attention . est prioritaire sur *, il faut donc utiliser des parenthèses)
    cout << (*debut).val << endl;

    // Ou alternativement on peut utiliser l'operateur ->
    cout << debut->val << endl;

    // Pour afficher la deuxième valeur on doit d'abord accéder au deuxième élément
    cout << debut->next->val << endl;
}
```

```c
class List {
    Cell* debut;
    public:
        bool empty() { return debut == 0; }
        void prepend(int n) {
            // On aurait tendance à écrire
            // Cell c(n, debut);
            // debut = &c;
            // Mais c est une variable locale qui sera détruite à la fin de la fonction.

            debut = new Cell(n, debut);
        }
}

