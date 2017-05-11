#include "MyStack.h"

MyStack::MyStack():
	s(nullptr)
{
}

MyStack::MyStack(MyStack & original)
{
	if (s != nullptr) {
		s->info = original.s->info;
		if (original.s->next != nullptr) {
			s->next = new node{ original.s->next->info, nullptr };
			node* aux = s->next;
			node* auxOrig = original.s->next;
		}
	}
	else
	{
		s = nullptr;
	}
}

void MyStack::pop()
{
	node* aux = s->next;
	delete s;
	s = aux;
}

void MyStack::push(int info)
{
	s = new node{info, s};
}

int MyStack::top()
{
	return s->info;
}

int MyStack::size()
{
	node* n = s;
	int size = 0;
	while (n->next != nullptr) 
	{
		size++;
		n = n->next;
	}
	return size;
}

bool MyStack::isEmpty()
{
	return s == nullptr;
}
