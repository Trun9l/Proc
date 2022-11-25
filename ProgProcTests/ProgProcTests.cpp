#include "pch.h"
#include "CppUnitTest.h"
#include "../ProgProc1/Ball.h"
#include "../ProgProc1/Parallelepiped.h"
#include "../ProgProc1/Tetrahedron.h"
#include "../ProgProc1/Shape.h"
#include "../ProgProc1/Container.h"
#include <fstream>
#include <string>
using namespace std;
using namespace Microsoft::VisualStudio::CppUnitTestFramework;
float volume(ball& b);
void Out(ball& b, ofstream& ofst);
void In(ball& b, ifstream& ifst);
void In(parallelepiped& p, ifstream& ifst);
void Out(parallelepiped& p, ofstream& ofst);
float volume(parallelepiped& p);
void In(tetrahedron& b, ifstream& ifst);
void Out(tetrahedron& b, ofstream& ofst);
float volume(tetrahedron& p);
float volume(shape* s);
shape* InShape(ifstream& ifst);
void OutShape(shape* s, ofstream& ofst);
void Init(container& c);
void Clear(container& c);
node* GetTail(container list);
node* PushBack(container list, node* newNode);
void InitNode(node*& newNode, shape*& newShape);
void In(container& c, ifstream& ifst);
void Out(container& c, ofstream& ofst);
void In(container& c, ifstream& ifst);
void Sort(container& c);
void OutBalls(container& c, ofstream& ofst);
namespace ProgProcTests
{
	TEST_CLASS(ProgProcTests)
	{
	public:
		
		TEST_METHOD(BallVolumeTest)
		{
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			float pi = 3.14;
			Assert::IsTrue((4 / 3) * pi * rad * rad == volume(myBall), L"Неправильно рассчитан объем");
		}
		TEST_METHOD(BallOutTest)
		{
			ofstream ofst("..\\ProgProcTests\\BallOut.txt");
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			Out(myBall, ofst);
			//ofst << "\n3"; //сделать вывод больше
			ofst.close();
			//ifstream ifst("BallOut.txt");
			ifstream ifst;
			ifst.open("..\\ProgProcTests\\BallOut.txt", std::ifstream::in);
			ifstream ifstCorrect;
			ifstCorrect.open("..\\ProgProcTests\\BallOutCorrect.txt", std::ifstream::in);
			//ifstream ifstCorrect("BallOutCorrect.txt");
			string str, strCorrect;
			if (ifst.is_open() && ifstCorrect.is_open())
			{
				while (!ifst.eof())
				{
					//string str, strTest;
					//ifst >> str;
					//ifstCorrect >> strTest;
					std::getline(ifst, str);
					std::getline(ifstCorrect, strCorrect);
					Assert::IsTrue(str.compare(strCorrect) == 0, L"Не сходятся строки в выводе");
					Assert::IsTrue(ifstCorrect.eof() == ifst.eof(), L"Вывод больше, чем планировалось");
				}
				ifstCorrect.close();
				ifst.close();
			}
			else
				Assert::Fail(L"Не открылись файлы");
			Assert::IsTrue(ifstCorrect.eof() == true, L"Вывод меньше, чем планировалось");
		}
		TEST_METHOD(BallInTest)
		{
			string file = "BallIn.txt";
			int rad = 5;
			ofstream ofst(file);
			ofst << rad;
			ofst.close();
			ball myball;
			ifstream ifst("..\\Debug\\" + file);
			In(myball, ifst);
			Assert::IsTrue(myball.r == rad, L"Неправильный ввод");
		}
		TEST_METHOD(ParallelepipedInTest)
		{
			string file = "ParallelepipedIn.txt";
			int a = 3, b = 7, c = 19;
			ofstream ofst(file);
			ofst << a << " " << b << " " << c;
			ofst.close();
			parallelepiped myParal;
			ifstream ifst("..\\Debug\\" + file);
			In(myParal, ifst);
			Assert::IsTrue(myParal.a == a && myParal.b == b && myParal.c == c, L"Неправильный ввод");
		}
		TEST_METHOD(ParallelepipedOutTest)
		{
			ofstream ofst("..\\ProgProcTests\\ParallelepipedOut.txt");
			parallelepiped myParal;
			int a = 3, b = 7, c = 19;
			myParal.a = a;
			myParal.b = b;
			myParal.c = c;
			Out(myParal, ofst);
			ofst.close();
			ifstream ifst;
			ifst.open("..\\ProgProcTests\\ParallelepipedOut.txt", std::ifstream::in);
			ifstream ifstCorrect;
			ifstCorrect.open("..\\ProgProcTests\\ParallelepipedOutCorrect.txt", std::ifstream::in);
			string str, strCorrect;
			if (ifst.is_open() && ifstCorrect.is_open())
			{
				while (!ifst.eof())
				{
					std::getline(ifst, str);
					std::getline(ifstCorrect, strCorrect);
					Assert::IsTrue(str.compare(strCorrect) == 0, L"Не сходятся строки в выводе");
					Assert::IsTrue(ifstCorrect.eof() == ifst.eof(), L"Вывод больше, чем планировалось");
				}
				ifstCorrect.close();
				ifst.close();
			}
			else
				Assert::Fail(L"Не открылись файлы");
			Assert::IsTrue(ifstCorrect.eof() == true, L"Вывод меньше, чем планировалось");
		}
		TEST_METHOD(ParallelepipedVolumeTest)
		{
			parallelepiped myParal;
			int a = 3, b = 7, c = 19;
			myParal.a = a;
			myParal.b = b;
			myParal.c = c;
			Assert::IsTrue(a*b*c == volume(myParal), L"Неправильно рассчитан объем");
		}
		//Tetrahedron
		TEST_METHOD(TetrahedronInTest)
		{
			string file = "TetrahedronIn.txt";
			int a = 3;
			ofstream ofst(file);
			ofst << a;
			ofst.close();
			tetrahedron myTet;
			ifstream ifst("..\\Debug\\" + file);
			In(myTet, ifst);
			Assert::IsTrue(myTet.a == a, L"Неправильный ввод");
		}
		TEST_METHOD(TetrahedronOutTest)
		{
			ofstream ofst("..\\ProgProcTests\\TetrahedronOut.txt");
			tetrahedron myTet;
			int a = 3;
			myTet.a = a;
			Out(myTet, ofst);
			ofst.close();
			ifstream ifst;
			ifst.open("..\\ProgProcTests\\TetrahedronOut.txt", std::ifstream::in);
			ifstream ifstCorrect;
			ifstCorrect.open("..\\ProgProcTests\\TetrahedronOutCorrect.txt", std::ifstream::in);
			string str, strCorrect;
			if (ifst.is_open() && ifstCorrect.is_open())
			{
				std::getline(ifst, str);
				std::getline(ifstCorrect, strCorrect);
				Assert::IsTrue(str.compare(strCorrect) == 0, L"Не сходятся строки в выводе");
				Assert::IsTrue(ifstCorrect.eof() == ifst.eof(), L"Вывод больше, чем планировалось");
			}
			else
				Assert::Fail(L"Не открылись файлы");
			Assert::IsTrue(ifstCorrect.eof() == true, L"Вывод меньше, чем планировалось");
		}
		TEST_METHOD(TetrahedronVolumeTest)
		{
			tetrahedron myTet;
			int a = 7;
			myTet.a = a;
			//(a* a* a)* (sqrt(2) / 12);
			float calculatedVol = (a * a * a) * (sqrt(2) / 12);
			Assert::IsTrue(calculatedVol == volume(myTet), L"Неправильно рассчитан объем");
		}
		TEST_METHOD(ShapeVolumeTest)
		{
			shape* myShape = new shape;
			myShape->k = shape::key::BALL;
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			float pi = 3.14;
			myShape->b = myBall;
			Assert::IsTrue((4 / 3) * pi * rad * rad == volume(myShape), L"Неправильно рассчитан объем");
		}
		TEST_METHOD(ShapeInTest)
		{
			string file = "ShapeIn.txt";
			shape::key key = shape::key::BALL;
			int k = 1;
			float density = 17;
			int meltingPoint = 10;
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			shape* myShape ;
			/*myShape->k = shape::key::BALL;
			myShape->b = myBall;
			myShape->meltingPoint = meltingPoint;
			myShape->density = density;*/
			ofstream ofst(file);
			ofst << k << '\n';
			ofst << meltingPoint << " " << density << " ";
			ofst << rad << '\n';
			ofst.close();
			ifstream ifst("..\\Debug\\" + file);
			myShape = InShape(ifst);
			Assert::IsTrue(myShape->k == shape::key::BALL && myShape->density == density && myShape->meltingPoint == meltingPoint
				&& myShape->b.r == myBall.r, L"Неправильный ввод");
			delete myShape;
		}
		TEST_METHOD(ShapeOutTest)
		{
			shape::key key = shape::key::BALL;
			int k = 1;
			float density = 17;
			int meltingPoint = 10;
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			shape* myShape = new shape;
			myShape->k = shape::key::BALL;
			myShape->b = myBall;
			myShape->meltingPoint = meltingPoint;
			myShape->density = density;
			ofstream ofst("..\\ProgProcTests\\ShapeOut.txt");
			OutShape(myShape, ofst);
			ofst.close();
			ifstream ifst;
			ifst.open("..\\ProgProcTests\\ShapeOut.txt", std::ifstream::in);
			ifstream ifstCorrect;
			ifstCorrect.open("..\\ProgProcTests\\ShapeOutCorrect.txt", std::ifstream::in);
			string str, strCorrect;
			if (ifst.is_open() && ifstCorrect.is_open())
			{
				while (!ifst.eof())
				{
					std::getline(ifst, str);
					std::getline(ifstCorrect, strCorrect);
					Assert::IsTrue(str.compare(strCorrect) == 0, L"Не сходятся строки в выводе");
					Assert::IsTrue(ifstCorrect.eof() == ifst.eof(), L"Вывод больше, чем планировалось");
				}
			}
			else
				Assert::Fail(L"Не открылись файлы");
			Assert::IsTrue(ifstCorrect.eof() == true, L"Вывод меньше, чем планировалось");
		}
		TEST_METHOD(ContainerInitTest)
		{
			container cont;
			Init(cont);
			Assert::IsTrue(cont.head == 0 && cont.size == 0, L"Неправильная инициализация");
		}
		TEST_METHOD(ContainerClearTest)
		{
			container cont;
			Init(cont);
			node* myNode = new node;
			myNode->sp = 0;
			myNode->next = 0;
			cont.head =  myNode;
			cont.size++;
			Clear(cont);
			Assert::IsTrue(cont.head == 0 && cont.size == 0, L"Неправильная чистка");
		}
		TEST_METHOD(ContainerGetTailPushBackInsertAfterTest)
		{
			container cont;
			Init(cont);
			node* firstNode = new node;
			shape* firstShape = new shape;
			firstShape->k = shape::key::BALL;
			//firstNode->sp = firstShape;
			InitNode(firstNode, firstShape);
			node* secondNode = new node;
			shape* secondShape = new shape;
			secondShape->k = shape::key::PARALLELEPIPED;
			//secondNode->sp = secondShape;
			InitNode(secondNode, secondShape);
			PushBack(cont, firstNode);
			if (cont.size == 0)
				cont.head = firstNode;
			cont.size++;
			PushBack(cont, secondNode);
			if (cont.size == 0)
				cont.head = secondNode;
			cont.size++;
			Assert::IsTrue(GetTail(cont)->sp->k == shape::key::PARALLELEPIPED, L"Неправильная работа PushBack/InsAfter/GetTail");
			Clear(cont);
		}
		TEST_METHOD(InitNodeTest)
		{
			node* newNode = new node;
			shape* newShape = new shape;
			newShape->k = shape::key::BALL;
			InitNode(newNode, newShape);
			Assert::IsTrue(newNode->sp->k == shape::key::BALL, L"Неправильная инициализация");
			delete newShape;
			delete newNode;
		}
		TEST_METHOD(ContainerInTest)
		{
			string file = "ContainerIn.txt";
			shape::key key = shape::key::BALL;
			int k = 1;
			float density = 17;
			int meltingPoint = 10;
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			shape* myShape;
			ofstream ofst(file);
			ofst << k << '\n';
			ofst << meltingPoint << " " << density << " ";
			ofst << rad << '\n';
			ofst.close();
			ifstream ifst("..\\Debug\\" + file);
			container cont;
			Init(cont);
			In(cont, ifst);
			Assert::IsTrue(cont.head->sp->k == shape::key::BALL && cont.head->sp->density == density && cont.head->sp->meltingPoint == meltingPoint
				&& cont.head->sp->b.r == myBall.r, L"Неправильный ввод");
		}
		TEST_METHOD(ContainerOutTest)
		{
			shape::key key = shape::key::BALL;
			int k = 1;
			float density = 17;
			int meltingPoint = 10;
			ball myBall;
			int rad = 5;
			myBall.r = rad;
			shape* myShape = new shape;
			myShape->k = shape::key::BALL;
			myShape->b = myBall;
			myShape->meltingPoint = meltingPoint;
			myShape->density = density;
			node* myNode = new node;
			InitNode(myNode, myShape);
			container cont;
			Init(cont);
			PushBack(cont, myNode);
			if (cont.size == 0)
				cont.head = myNode;
			cont.size++;
			ofstream ofst("..\\ProgProcTests\\ContainerOut.txt");
			Out(cont, ofst);
			ofst.close();
			ifstream ifst;
			ifst.open("..\\ProgProcTests\\ContainerOut.txt", std::ifstream::in);
			ifstream ifstCorrect;
			ifstCorrect.open("..\\ProgProcTests\\ContainerOutCorrect.txt", std::ifstream::in);
			string str, strCorrect;
			if (ifst.is_open() && ifstCorrect.is_open())
			{
				while (!ifst.eof())
				{
					std::getline(ifst, str);
					std::getline(ifstCorrect, strCorrect);
					Assert::IsTrue(str.compare(strCorrect) == 0, L"Не сходятся строки в выводе");
					Assert::IsTrue(ifstCorrect.eof() == ifst.eof(), L"Вывод больше, чем планировалось");
				}
			}
			else
				Assert::Fail(L"Не открылись файлы");
			Assert::IsTrue(ifstCorrect.eof() == true, L"Вывод меньше, чем планировалось");
		}
		TEST_METHOD(ContainerSortTest)
		{
			string file = "..\\ProgProcTests\\SortTest.txt";
			container cont;
			Init(cont);
			ifstream ifst;
			ifst.open(file);
			if (ifst.is_open())
				In(cont, ifst);
			else
				Assert::Fail(L"Не открылись файлы");
			Sort(cont);
			Assert::IsTrue(cont.head->sp->k == shape::key::TETRAHEDRON, L"Неправильная сортировка");
		}
		TEST_METHOD(ContainerOutBallsTest)
		{
			string file = "..\\ProgProcTests\\SortTest.txt";
			container cont;
			Init(cont);
			ifstream ifstInput;
			ifstInput.open(file);
			if (ifstInput.is_open())
				In(cont, ifstInput);
			else
				Assert::Fail(L"Не открылись файлы");
			ofstream ofst("..\\ProgProcTests\\ContainerOutBalls.txt");
			OutBalls(cont, ofst);
			ifstream ifst;
			ifst.open("..\\ProgProcTests\\ContainerOutBalls.txt", std::ifstream::in);
			ifstream ifstCorrect;
			ifstCorrect.open("..\\ProgProcTests\\ContainerOutBallsCorrect.txt", std::ifstream::in);
			string str, strCorrect;
			if (ifst.is_open() && ifstCorrect.is_open())
			{
				while (!ifst.eof())
				{
					std::getline(ifst, str);
					std::getline(ifstCorrect, strCorrect);
					Assert::IsTrue(str.compare(strCorrect) == 0, L"Не сходятся строки в выводе");
					Assert::IsTrue(ifstCorrect.eof() == ifst.eof(), L"Вывод больше, чем планировалось");
				}
			}
			else
				Assert::Fail(L"Не открылись файлы");
			Assert::IsTrue(ifstCorrect.eof() == true, L"Вывод меньше, чем планировалось");
		}
	};
}
