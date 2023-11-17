//=======================================================================
// Basic C++: a simple (and uncomplete) class List of int's
//      Utilization
//-----------------------------------------------------------------------
// Jean-Paul Rigault --- Copyright 2003
// $Id: main_List.cpp,v 1.4 2004/11/20 17:02:51 jpr Exp $
//=======================================================================

#include "list-copy.h"
#include "common_defs.h"

int sum(List l) {
    int s = 0;

    while (!l.is_empty()) s += l.get_first();
    return s;
}

int main() {
    int i;

    MSG(List operations);

    List la, lb, l1, l2;

    OUT(l1);
    for (i = 0; i < 10; i++) {
        l1.append(i);
        l2.prepend(i);
    }
    OUT(l1);
    OUT(l2);

    l1.prepend(99);
    l2.append(99);
    OUT(l1);
    OUT(l2);

    OUT(l1.get_first());
    OUT(l1);
    OUT(l2.get_first());
    OUT(l2);

    while (!l1.is_empty()) OUT(l1.get_first());
    OUT(l1);

    MSG(List copy);

    lb.append(1);
    lb.append(2);
    lb.append(3);
    // 0. uncomment these lines... strange, isn't it ?
    la = lb;
    la.max() = 100;
    OUT(la);
    OUT(lb);

    l1.append(1);
    l1.append(2);
    l1.append(3);

    // 3. implement list destructor
    //
    // List Destructor
    List* ld = new List();
    ld->append(1);
    ld->append(2);

    OUT(ld);
    OUT(*ld);

    delete ld;

    // 4. concatenation
    //
    OUT(l1 + l2); // returns concatenation

    // 5. odd-even shuffle
    //
    OUT(l1 * l2); //  returns odd-even shuffle (suppose l1 and l2 have same length)

    return 0;
}
