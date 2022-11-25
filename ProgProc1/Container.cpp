#include "Container.h"
#include <fstream>
using namespace std;
Shape* InShape(ifstream& ifst);
void OutShape(Shape* s, ofstream& ofst);
float Volume(Shape* s);
// Очистка контейнера от элементов
// (освобождение памяти)
// Инициализация контейнера
void Init(Container& c)
{
	c.head = NULL;
	c.size = 0;
}
void Clear(Container& c)
{
	while (c.size)
	{
		Node* tmp = c.head;
		c.head = c.head->next;
		delete tmp->sp;
		delete tmp;
		c.size--;
	}
}
Node* GetTail(Container list)
{
	Node* tail = NULL;
	if (list.size==0)
		return NULL;
	tail = list.head;
	while (tail->next != NULL)
		tail = tail->next;
	return tail;
}
Node* InsertAfter(Node* leftNode, Node* newNode)
{
	if (leftNode != NULL)
	{
		newNode->next = leftNode->next;
		leftNode->next = newNode;
	}
	return newNode;
}
Node* PushBack (Container list, Node* newNode)
{
	Node* last = GetTail(list);	
	return InsertAfter(last, newNode);
}
void InitNode(Node*& newNode, Shape*& newShape)
{
	newNode->sp = newShape;
	newNode->next = NULL;
}
void In(Container& c, ifstream& ifst)
{
	Shape* newShape = NULL;
	//Container* newContainer = NULL;
	while (!ifst.eof())
	{
		newShape = InShape(ifst);
		if (newShape != 0)
		{
			Node* newNode = new Node;
			InitNode(newNode, newShape);
			PushBack(c, newNode);
			if (c.size == 0)
				c.head = newNode;
			c.size++;
		}
		//if ((c.cont[c.len] = In(ifst)) != 0) { c.len++; }
	}
}
int GetLength(Container c)
{
	return c.size;
}
void Out(Container& c, ofstream& ofst)
{
	int length = GetLength(c);
	ofst << "Container contains " << length	<< " elements." << endl;
	Node* pointer = c.head;
	for (int i = 0; i < length; i++)
	{
		//Container* pointer = c;
		ofst << i << ": ";
		OutShape(pointer->sp, ofst);
		ofst << "volume = " << Volume(pointer->sp) << endl;
		pointer = pointer->next;
	}
}
bool Compare(Shape* first, Shape* second) 
{
	return Volume(first) < Volume(second);
}
void ChangePlaces(Node& pointer1, Node& pointer2)
{
	Shape*& tempSp = pointer1.sp;
	//Node*& tempNext = pointer1.next;
	pointer1.sp = pointer2.sp;
	//pointer1.next = pointer2.next;
	pointer2.sp = tempSp;
	//pointer2.next = tempNext;
}
Node* NodeAt(Container& c, int x)
{
	Node* current = c.head;
	for (int i = 0; i < x; ++i)
	{
		current = current->next;
	}
	return current;
}
void Sort(Container& c)
{
	for (int i = 0; i < c.size - 1; i++)
	{
		Node* NodeAtI = NodeAt(c, i);
		for (int j = i + 1; j < c.size; j++) 
		{
			Node* NodeAtJ = NodeAt(c, j);
			if (Compare(NodeAtI->sp, NodeAtJ->sp)) 
			{
				Shape* tmp = NodeAtI->sp;
				NodeAtI->sp = NodeAtJ->sp;
				NodeAtJ->sp = tmp;
			}
		}
	}
}


void OutBalls(Container& c, ofstream& ofst)
{
	int length = GetLength(c);
	ofst << "Only balls." << endl;
	Node* pointer = c.head;
	for (int i = 0; i < length; i++)
	{
		//Container* pointer = c;
		if (pointer->sp->k == Shape::Key::BALL)
		{
			ofst << i << ": ";
			OutShape(pointer->sp, ofst);
			ofst << "volume = " << Volume(pointer->sp) << endl;
		}
		pointer = pointer->next;
	}
}