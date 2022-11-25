#include "Container.h"
#include <fstream>
using namespace std;
shape* InShape(ifstream& ifst);
void OutShape(shape* s, ofstream& ofst);
float volume(shape* s);
// Очистка контейнера от элементов
// (освобождение памяти)
// Инициализация контейнера
void Init(container& c) {
	c.head = NULL;
	c.size = 0;
}
void Clear(container& c) {
	while (c.size) {
		node* tmp = c.head;
		c.head = c.head->next;
		delete tmp->sp;
		delete tmp;
		c.size--;
	}
}
node* GetTail(container list) {
	node* tail = NULL;
	if (list.size==0)
		return NULL;
	tail = list.head;
	while (tail->next != NULL)
		tail = tail->next;
	return tail;
}
node* InsertAfter(node* leftNode, node* newNode) {
	if (leftNode != NULL) {
		newNode->next = leftNode->next;
		leftNode->next = newNode;
	}
	return newNode;
}
node* PushBack (container list, node* newNode) {
	node* last = GetTail(list);	
	return InsertAfter(last, newNode);
}
void InitNode(node*& newNode, shape*& newShape) {
	newNode->sp = newShape;
	newNode->next = NULL;
}
void In(container& c, ifstream& ifst) {
	shape* newShape = NULL;
	//container* newContainer = NULL;
	while (!ifst.eof()) {
		newShape = InShape(ifst);
		if (newShape != 0) {
			node* newNode = new node;
			InitNode(newNode, newShape);
			PushBack(c, newNode);
			if (c.size == 0)
				c.head = newNode;
			c.size++;
		}
		//if ((c.cont[c.len] = In(ifst)) != 0) { c.len++; }
	}
}
int GetLength(container c) {
	return c.size;
}
void Out(container& c, ofstream& ofst) {
	int length = GetLength(c);
	ofst << "Container contains " << length	<< " elements." << endl;
	node* pointer = c.head;
	for (int i = 0; i < length; i++) {
		//container* pointer = c;
		ofst << i << ": ";
		OutShape(pointer->sp, ofst);
		ofst << "volume = " << volume(pointer->sp) << endl;
		pointer = pointer->next;
	}
}