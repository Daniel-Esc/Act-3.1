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

    cout << miArbol1.whatLevelAmI(19) << " ";
    cout << miArbol1.whatLevelAmI(26) << " ";
    cout << miArbol1.whatLevelAmI(16) << " ";
    cout << miArbol1.whatLevelAmI(8) << " ";
    cout << miArbol1.whatLevelAmI(27) << " ";
    cout << miArbol1.whatLevelAmI(13) << " ";
    cout << miArbol1.whatLevelAmI(3) << " ";
    cout << miArbol1.whatLevelAmI(7) << " ";
    cout << miArbol1.whatLevelAmI(14) << " ";
    cout << miArbol1.whatLevelAmI(24) << endl;

    cout << miArbol1.whatLevelAmI(1) << endl;

    cout << "Altura: " << miArbol1.height() << endl;

    miArbol1.ancestors(19);
    miArbol1.ancestors(1);
    miArbol1.ancestors(14);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbol2.whatLevelAmI(25) << " ";
    cout << miArbol2.whatLevelAmI(13) << " ";
    cout << miArbol2.whatLevelAmI(5) << " ";
    cout << miArbol2.whatLevelAmI(7) << " ";
    cout << miArbol2.whatLevelAmI(46) << " ";
    cout << miArbol2.whatLevelAmI(16) << " ";
    cout << miArbol2.whatLevelAmI(11) << " ";
    cout << miArbol2.whatLevelAmI(9) << " ";
    cout << miArbol2.whatLevelAmI(22) << " ";
    cout << miArbol2.whatLevelAmI(42) << endl;

    cout << miArbol2.whatLevelAmI(1) << endl;

    cout << "Altura: " << miArbol2.height() << endl;

    miArbol2.ancestors(25);
    miArbol2.ancestors(1);
    miArbol2.ancestors(22);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbol3.whatLevelAmI(55) << " ";
    cout << miArbol3.whatLevelAmI(11) << " ";
    cout << miArbol3.whatLevelAmI(82) << " ";
    cout << miArbol3.whatLevelAmI(19) << " ";
    cout << miArbol3.whatLevelAmI(38) << " ";
    cout << miArbol3.whatLevelAmI(73) << " ";
    cout << miArbol3.whatLevelAmI(26) << " ";
    cout << miArbol3.whatLevelAmI(71) << " ";
    cout << miArbol3.whatLevelAmI(54) << " ";
    cout << miArbol3.whatLevelAmI(42) << endl;

    cout << miArbol3.whatLevelAmI(1) << endl;

    cout << "Altura: " << miArbol3.height() << endl;

    miArbol3.ancestors(55);
    miArbol3.ancestors(1);
    miArbol3.ancestors(42);

    cout << "-----------------------" << endl;

    miArbolVacio.print(1);
    miArbolVacio.print(2);
    miArbolVacio.print(3);
    miArbolVacio.print(4);

    cout << miArbolVacio.whatLevelAmI(3) << " ";
    cout << miArbolVacio.whatLevelAmI(1) << endl;

    cout << "Altura: " << miArbolVacio.height() << endl;

    miArbolVacio.ancestors(0);
    miArbolVacio.ancestors(1);
    miArbolVacio.ancestors(14);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbolDerecho.whatLevelAmI(1) << " ";
    cout << miArbolDerecho.whatLevelAmI(2) << " ";
    cout << miArbolDerecho.whatLevelAmI(3) << " ";
    cout << miArbolDerecho.whatLevelAmI(4) << " ";
    cout << miArbolDerecho.whatLevelAmI(5) << " ";
    cout << miArbolDerecho.whatLevelAmI(6) << " ";
    cout << miArbolDerecho.whatLevelAmI(7) << " ";
    cout << miArbolDerecho.whatLevelAmI(8) << " ";
    cout << miArbolDerecho.whatLevelAmI(9) << " ";
    cout << miArbolDerecho.whatLevelAmI(10) << endl;

    cout << miArbolDerecho.whatLevelAmI(11) << endl;
    
    cout << "Altura: " << miArbolDerecho.height() << endl;

    miArbolDerecho.ancestors(1);
    miArbolDerecho.ancestors(11);
    miArbolDerecho.ancestors(8);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbolIzquierdo.whatLevelAmI(10) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(9) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(8) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(7) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(6) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(5) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(4) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(3) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(2) << " ";
    cout << miArbolIzquierdo.whatLevelAmI(1) << endl;

    cout << miArbolIzquierdo.whatLevelAmI(11) << endl;

    cout << "Altura: " << miArbolIzquierdo.height() << endl;

    miArbolIzquierdo.ancestors(10);
    miArbolIzquierdo.ancestors(11);
    miArbolIzquierdo.ancestors(3);

    cout << "Fin prueba ancestros" << endl;

    cout << "-----------------------" << endl;

    miArbolUno.add(1);

    miArbolUno.print(1);
    miArbolUno.print(2);
    miArbolUno.print(3);
    miArbolUno.print(4);

    cout << miArbolUno.whatLevelAmI(1) << " ";
    cout << miArbolUno.whatLevelAmI(2) << " ";
    cout << miArbolUno.whatLevelAmI(3) << endl;

    cout << miArbolUno.whatLevelAmI(0) << endl;

    cout << "Altura: " << miArbolUno.height() << endl;

    miArbolUno.ancestors(1);
    miArbolUno.ancestors(2);
    miArbolUno.ancestors(1);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbolMixto1.whatLevelAmI(-10) << " ";
    cout << miArbolMixto1.whatLevelAmI(-2) << " ";
    cout << miArbolMixto1.whatLevelAmI(-5) << " ";
    cout << miArbolMixto1.whatLevelAmI(-3) << " ";
    cout << miArbolMixto1.whatLevelAmI(7) << endl;

    cout << miArbolMixto1.whatLevelAmI(1) << endl;

    cout << "Altura: " << miArbolMixto1.height() << endl;

    miArbolMixto1.ancestors(-10);
    miArbolMixto1.ancestors(1);
    miArbolMixto1.ancestors(-5);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbolMixto2.whatLevelAmI(9) << " ";
    cout << miArbolMixto2.whatLevelAmI(-10) << " ";
    cout << miArbolMixto2.whatLevelAmI(10) << " ";
    cout << miArbolMixto2.whatLevelAmI(-5) << " ";
    cout << miArbolMixto2.whatLevelAmI(-4) << endl;

    cout << miArbolMixto2.whatLevelAmI(1) << endl;

    cout << "Altura: " << miArbolMixto2.height() << endl;

    miArbolMixto2.ancestors(9);
    miArbolMixto2.ancestors(1);
    miArbolMixto2.ancestors(-10);
    miArbolMixto2.ancestors(10);

    cout << "Fin prueba ancestros" << endl;

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

    cout << miArbolMixto3.whatLevelAmI(5) << " ";
    cout << miArbolMixto3.whatLevelAmI(-8) << " ";
    cout << miArbolMixto3.whatLevelAmI(-4) << " ";
    cout << miArbolMixto3.whatLevelAmI(9) << " ";
    cout << miArbolMixto3.whatLevelAmI(3) << endl;

    cout << miArbolMixto3.whatLevelAmI(1) << endl;


    cout << "Altura: " << miArbolMixto3.height() << endl;

    miArbolMixto3.ancestors(5);
    miArbolMixto3.ancestors(1);
    miArbolMixto3.ancestors(-4);
    miArbolMixto3.ancestors(9);

    cout << "Fin prueba ancestros" << endl;

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

    cout << arbolProfe.whatLevelAmI(21) << " ";
    cout << arbolProfe.whatLevelAmI(13) << " ";
    cout << arbolProfe.whatLevelAmI(33) << " ";
    cout << arbolProfe.whatLevelAmI(10) << " ";
    cout << arbolProfe.whatLevelAmI(18) << " ";
    cout << arbolProfe.whatLevelAmI(25) << " ";
    cout << arbolProfe.whatLevelAmI(40) << " ";
    cout << arbolProfe.whatLevelAmI(29) << " ";
    cout << arbolProfe.whatLevelAmI(27) << " ";
    cout << arbolProfe.whatLevelAmI(30) << endl;

    cout << arbolProfe.whatLevelAmI(1) << endl;

    cout << "Altura: " << arbolProfe.height() << endl;

    arbolProfe.ancestors(21);
    arbolProfe.ancestors(1);
    arbolProfe.ancestors(29);
    arbolProfe.ancestors(30);

    cout << "Fin prueba ancestros" << endl;

}