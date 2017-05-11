#pragma once
class MyStack
{
public:
	MyStack();							//Constructor predeterminado
	MyStack(MyStack &);					//Copia
	MyStack(int, int);					//num elementos, elemento de init
	~MyStack();							//Destructor

	struct node {
		int info;
		node* next;
	};

	node* s;							//Apunta a la primera posicion del stack

	void pop();							//Eliminar el primer elemento
	void push(int);						//Nuevo elemento en la primera posicion
	int top();							//
	int size();							//Devuelve el numero de elementos en el stack
	bool isEmpty();						//True si no hay ningun elemento

};

