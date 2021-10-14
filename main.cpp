#include <iostream>

using namespace std;

#include "BST.h"

int main(){
    
    BST miArbol1, miArbol2, miArbol3, miArbolVacio, miArbolDerecho, miArbolIzquierdo, miArbolUno, miArbolMixto1, miArbolMixto2, miArbolMixto3, arbolProfe;

    miArbol1.add(19);
    miArbol1.add(26);
    miArbol1.add(16);
    miArbol1.add(8);
    miArbol1.add(27);
    miArbol1.add(13);
    miArbol1.add(3);
    miArbol1.add(7);
    miArbol1.add(14);
    miArbol1.add(24);

    miArbol1.print(1);
    miArbol1.print(2);
    miArbol1.print(3);
    miArbol1.print(4);

    cout << miArbol1.height() << endl;

    miArbol1.ancestors(19);
    miArbol1.ancestors(1);
    miArbol1.ancestors(14);

    cout << "-----------------------" << endl;

    miArbol2.add(25);
    miArbol2.add(13);
    miArbol2.add(5);
    miArbol2.add(7);
    miArbol2.add(46);
    miArbol2.add(16);
    miArbol2.add(11);
    miArbol2.add(9);
    miArbol2.add(22);
    miArbol2.add(42);

    miArbol2.print(1);
    miArbol2.print(2);
    miArbol2.print(3);
    miArbol2.print(4);

    cout << miArbol2.height() << endl;

    miArbol2.ancestors(25);
    miArbol2.ancestors(1);
    miArbol2.ancestors(22);

    cout << "-----------------------" << endl;

    miArbol3.add(55);
    miArbol3.add(11);
    miArbol3.add(82);
    miArbol3.add(19);
    miArbol3.add(38);
    miArbol3.add(73);
    miArbol3.add(26);
    miArbol3.add(71);
    miArbol3.add(54);
    miArbol3.add(42);

    miArbol3.print(1);
    miArbol3.print(2);
    miArbol3.print(3);
    miArbol3.print(4);

    cout << miArbol3.height() << endl;

    miArbol3.ancestors(55);
    miArbol3.ancestors(1);
    miArbol3.ancestors(42);

    cout << "-----------------------" << endl;

    miArbolVacio.print(1);
    miArbolVacio.print(2);
    miArbolVacio.print(3);
    miArbolVacio.print(4);

    cout << miArbolVacio.height() << endl;

    miArbolVacio.ancestors(0);
    miArbolVacio.ancestors(1);
    miArbolVacio.ancestors(14);

    cout << "-----------------------" << endl;

    miArbolDerecho.add(1);
    miArbolDerecho.add(2);
    miArbolDerecho.add(3);
    miArbolDerecho.add(4);
    miArbolDerecho.add(5);
    miArbolDerecho.add(6);
    miArbolDerecho.add(7);
    miArbolDerecho.add(8);
    miArbolDerecho.add(9);
    miArbolDerecho.add(10);

    miArbolDerecho.print(1);
    miArbolDerecho.print(2);
    miArbolDerecho.print(3);
    miArbolDerecho.print(4);

    cout << miArbolDerecho.height() << endl;

    miArbolDerecho.ancestors(1);
    miArbolDerecho.ancestors(11);
    miArbolDerecho.ancestors(8);

    cout << "-----------------------" << endl;

    miArbolIzquierdo.add(10);
    miArbolIzquierdo.add(9);
    miArbolIzquierdo.add(8);
    miArbolIzquierdo.add(7);
    miArbolIzquierdo.add(6);
    miArbolIzquierdo.add(5);
    miArbolIzquierdo.add(4);
    miArbolIzquierdo.add(3);
    miArbolIzquierdo.add(2);
    miArbolIzquierdo.add(1);

    miArbolIzquierdo.print(1);
    miArbolIzquierdo.print(2);
    miArbolIzquierdo.print(3);
    miArbolIzquierdo.print(4);

    cout << miArbolIzquierdo.height() << endl;

    miArbolIzquierdo.ancestors(10);
    miArbolIzquierdo.ancestors(11);
    miArbolIzquierdo.ancestors(3);

    cout << "-----------------------" << endl;

    miArbolUno.add(1);

    miArbolUno.print(1);
    miArbolUno.print(2);
    miArbolUno.print(3);
    miArbolUno.print(4);

    cout << miArbolUno.height() << endl;

    miArbolUno.ancestors(1);
    miArbolUno.ancestors(2);
    miArbolUno.ancestors(1);

    cout << "-----------------------" << endl;

    miArbolMixto1.add(-10);
    miArbolMixto1.add(-2);
    miArbolMixto1.add(-5);
    miArbolMixto1.add(-3);
    miArbolMixto1.add(7);

    miArbolMixto1.print(1);
    miArbolMixto1.print(2);
    miArbolMixto1.print(3);
    miArbolMixto1.print(4);

    cout << miArbolMixto1.height() << endl;

    cout << "-----------------------" << endl;

    miArbolMixto2.add(9);
    miArbolMixto2.add(-10);
    miArbolMixto2.add(10);
    miArbolMixto2.add(-5);
    miArbolMixto2.add(-4);

    miArbolMixto2.print(1);
    miArbolMixto2.print(2);
    miArbolMixto2.print(3);
    miArbolMixto2.print(4);

    cout << miArbolMixto2.height() << endl;

    cout << "-----------------------" << endl;

    miArbolMixto3.add(5);
    miArbolMixto3.add(-8);
    miArbolMixto3.add(-4);
    miArbolMixto3.add(9);
    miArbolMixto3.add(3);

    miArbolMixto3.print(1);
    miArbolMixto3.print(2);
    miArbolMixto3.print(3);
    miArbolMixto3.print(4);

    cout << miArbolMixto3.height() << endl;

    cout << "-----------------------" << endl;

    arbolProfe.add(21);
    arbolProfe.add(13);
    arbolProfe.add(33);
    arbolProfe.add(10);
    arbolProfe.add(18);
    arbolProfe.add(25);
    arbolProfe.add(40);
    arbolProfe.add(29);
    arbolProfe.add(27);
    arbolProfe.add(30);

    arbolProfe.print(1);
    arbolProfe.print(2);
    arbolProfe.print(3);
    arbolProfe.print(4);

    cout << arbolProfe.height() << endl;

    arbolProfe.ancestors(21);
    arbolProfe.ancestors(1);
    arbolProfe.ancestors(29);
}