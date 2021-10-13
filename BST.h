// Matrícula: A00831289
// Nomber: Daniel Evaristo Escalera
#include "NodeT.h"
#include "queue.h"

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
int BST::succ(NodeT *r){
	NodeT *curr = r->getRight();
	while (curr->getLeft() != nullptr){
		curr = curr->getLeft();
	}
	return curr->getData();
}

// Mayor de los Menores
int BST::pred(NodeT *r){
	NodeT *curr = r->getLeft();
	while (curr->getRight() != nullptr){
		curr = curr->getRight();
	}
	return curr->getData();
}

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

void BST::preOrden(NodeT *r){
	if (r != nullptr){
		cout << r->getData() << " ";
		preOrden(r->getLeft());
		preOrden(r->getRight());
	}
}

void BST::inOrden(NodeT *r){
	if (r != nullptr){
		inOrden(r->getLeft());
		cout << r->getData() << " ";
		inOrden(r->getRight());
	}
}

void BST::postOrden(NodeT *r){
	if (r != nullptr){
		postOrden(r->getLeft());
		postOrden(r->getRight());
		cout << r->getData() << " ";
	}
}

int BST::size(){
	return size_Helper(root);
}

int BST::size_Helper(NodeT *r){
	if (r != nullptr){
		return 1 + size_Helper(r->getLeft()) + size_Helper(r->getRight());
	}
	else{
		return 0;
	}
}


















