// Matrícula: A00831289
// Nomber: Daniel Evaristo Escalera
#include <queue>
#include <stack>

#include "NodeT.h"

class BST
{
	public:
		BST();
		~BST();
		bool search(int data);
		void add(int data);
		void remove(int data);
		void print(int tipo);	
		int size();
		int height();
		void ancestors(int data);
		int whatLevelAmI(int data);
	private:
		NodeT *root;
		int howManyChildren(NodeT *r);
		int succ(NodeT *r);
		int pred(NodeT *r);
		void preOrden(NodeT *r);
		void inOrden(NodeT *r);
		void postOrden(NodeT *r);
		void destruye_Helper(NodeT *r);
		int size_Helper(NodeT *r);
		int height_Helper(NodeT *r);
};

BST::BST(){
	root = nullptr;
}

BST::~BST(){
	destruye_Helper(root);
}

void BST::destruye_Helper(NodeT *r){
	if (r != nullptr){
		destruye_Helper(r->getLeft());
		destruye_Helper(r->getRight());
		delete r;
	}
}

// Complejidad: O(n)
int BST::howManyChildren(NodeT *r){
	int cont = 0;
	if (r->getLeft() != nullptr){
		cont++;
	}
	if (r->getRight() != nullptr){
		cont++;
	}
	return cont;
}

// Menor de los Mayores;
// Complejidad: O(height)
int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

// Mayor de los Menores
// Complejidad: O(height)
int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}

// Complejidad: O(height)
bool BST::search(int data){
	NodeT *curr = root;
	while (curr != nullptr){
		if (curr->getData() == data){
			return true;
		}
//		if (curr->getData() > data){
//			curr = curr->getLeft();
//		}
//		else{
//			curr = curr->getRight();
//		}
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	return false; // Por aquí se sale si root es nullptr o no esta el dato
}

// Complejidad: O(height)
void BST::add(int data){
	if (root == nullptr){
		root = new NodeT(data);
	}
	else{
		NodeT *curr = root;
		NodeT *parent = nullptr;
		while (curr != nullptr){
			if (curr->getData() == data){
				return;
			}
			parent = curr;
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
		}
		// if (parent->getData() > data){
		// 	parent->setLeft(new NodeT(data));
		// }
		// else{
		// 	parent->setRight(new NodeT(data));
		// }
		(parent->getData() > data) ? parent->setLeft(new NodeT(data)) : parent->setRight(new NodeT(data));
	}
}

// Complejidad: O(height)
void BST::remove(int data){
	NodeT *curr = root;
	NodeT *parent = nullptr;
	// Voy a ciclar vea que No esta en el árbol o lo encuentre
	while (curr != nullptr && curr->getData() != data){
		parent = curr;
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight();
	}
	if (curr == nullptr){
		return; 	// Me salgo al no encontrar al dato
	}
	int cantHijos = howManyChildren(curr);
	switch (cantHijos){
		case 0:	if (parent == nullptr){
					root = nullptr;
				}
				else{
					if (parent->getData() > data){
						// El que quiero borrar esta a las izq del padre
						parent->setLeft(nullptr);
					}
					else{
						// El que quiero borrar esta a la der del padre
						parent->setRight(nullptr);
					}
				}
				delete curr;
				break;
		case 1: if (parent == nullptr){ // El que quiero borrar es root
					// El que quiero borrar esta como root y tiene un hijo
					if (curr->getLeft() != nullptr){ // El único hijo esta a la izq
						root = curr->getLeft();
					}
					else{	// El único hijo esta a la der
						root = curr->getRight();
					}
				}
				else{	// El que quiero borrar esta adentro del árbol
					if (parent->getData() > data){ // El quiero borrar esta a la izq de parent
						if (curr->getLeft() != nullptr){ // El único hijo esta a la izq de curr
							parent->setLeft(curr->getLeft());
						}
						else{ // El único hijo esta a la der de curr
							parent->setLeft(curr->getRight());
						}
					}
					else{	// El que quiero borrar esta a la der del parent
						if (curr->getLeft() != nullptr){ // El único hijo esta a la izq de curr
							parent->setRight(curr->getLeft());
						}
						else{	// El único hijo esta a la derecha de curr
							parent->setRight(curr->getRight());
						}
					}
				}
				delete curr;
				break;
		case 2: int sucesor = succ(curr); // curr tiene 2 hijos
				remove(sucesor); // sucesor tiene garantia que tiene 0 o 1 hijos.
				curr->setData(sucesor);
				break;
	}
}

// Complejidad: Mejor caso O(1) Peor caso O(n)
// Tipo:
// 1 : PreOrden
// 2 : InOrden
// 3 : PostOrden
// 4 : NivelPorNivel
void BST::print(int tipo){
	switch (tipo){
		case 1:	preOrden(root);
				break;
		case 2: inOrden(root);
				break;
		case 3: postOrden(root);
				break;
		case 4: if(root != nullptr){ // Si el arbol tiene datos
			// Se crea una fila y se introduce el nodo raíz
			queue<NodeT*> fila;
			fila.push(root);
			while (fila.empty() == false){ // Mientras la fila no este vacía
				cout << fila.front()->getData() << " "; // Imprimir nodo
				if(fila.front()->getLeft() != nullptr){ // Si el nodo tiene hijos agregarlos a la fila (Caso izquierdo)
					fila.push(fila.front()->getLeft());
				}
				if(fila.front()->getRight() != nullptr){ // Si el nodo tiene hijos agregarlos a la fila (Caso derecho)
					fila.push(fila.front()->getRight());
				}
				fila.pop(); // Borrar el padre
			}
		}
	}
	cout << endl;
}

// Complejidad: O(n)
void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

// Complejidad: O(n)
void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

// Complejidad: O(n)
void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

// Complejidad: O(n)
int BST::size(){
	return size_Helper(root);
}

// Complejidad: O(n)
int BST::size_Helper(NodeT *r){
	if (r != nullptr){
		return 1 + size_Helper(r->getLeft()) + size_Helper(r->getRight());
	}
	else{
		return 0;
	}
}

int BST::height(){ // Para determinar la altura del albor se llama al helper con la raíz como parámetro
	return height_Helper(root);
}

//Complejidad: Mejor caso O(1) Peor caso O(n)
int BST::height_Helper(NodeT *r){ 
	int left_height = 0, right_heigth = 0; // Se crean variables para cada rama que sale del nodo
	if(r != nullptr){ // Si el valor es nulo regresa 0
		left_height += 1 + height_Helper(r->getLeft()); // Se obtiene la altura de la izquierda de manera recursiva
		right_heigth += 1 + height_Helper(r->getRight()); // Se obtiene la altura de la derecha de manera recursiva
		return (left_height > right_heigth) ? left_height: right_heigth; // Se regresa el mayor valor
	}
	else{
		return 0;
	}
}

//Complejidad: Mejor caso O(1) Peor caso O(n)
void BST::ancestors(int data){
	stack<NodeT*> ancestros; // Se crea un stack para guardar los ancestros
	NodeT *curr = root;
	if(curr != nullptr){ // Se comprueba que el arbol tiene datos
		while (curr != nullptr && curr->getData() != data){ // Mientras no se llegue al final del arbol o al dato buscado
			ancestros.push(curr); // Se guarda el dato actual como ancestro en el fondo del stack
			curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight(); // Cambiar de nodo dependiendo del valor del dato respecto al valor actual
		}
		if(ancestros.empty()){ // Si al salir del while el stack esta vacío, significa que se buscó el primer nodo el cual no tiene ancestros
			cout << "SIN ANCESTROS" << endl;
		}
		else if(curr == nullptr){ // Si al salir no se encontró el dato no se despliegan los ancestros y se notifica
			cout << "DATO INEXISTENTE" << endl;
		}
		else{ // Si se encontró el dato se despliegan y borran uno a uno los ancestros en el stack
			while (ancestros.empty() == false){
				cout << ancestros.top()->getData() << endl;
				ancestros.pop();
			}
		}
	}
	else{
		cout << "DATO INEXISTENTE" << endl;
	}
}

//Complejidad: Mejor caso O(1) Peor caso O(n)
int BST::whatLevelAmI(int data){  // Recibe el dato al cual se debe buscar su nivel
	NodeT *curr = root;
	int contador = 0; // Inicializar contador
	while (curr != nullptr &&  curr->getData() != data){ // Mientras no encuentre el final del arbol o el dato a buscar
		curr = (curr->getData() > data) ? curr->getLeft() : curr->getRight(); // Cambiar de nodo dependiendo del valor del dato respecto al valor actual
		contador++; // Aumentar contador
	}
	if(curr == nullptr){ // Si el dato no se encuentra en el arbol regresar -1
		return -1;
	}
	else{ // Si se encuentra el dato se regresa el contador
		return contador;
	}
}









