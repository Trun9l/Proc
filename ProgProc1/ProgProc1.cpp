#include <iostream>
#include <fstream>
#include "Container.h"
//#include "Sort.h"
#include <crtdbg.h>
using namespace std;
void Init(container& c);
void Clear(container& c);
void In(container& c, ifstream& ifst);
void Out(container& c, ofstream& ofst);
void Sort(container& c);
void OutBalls(container& c, ofstream& ofst);
int main(int argc, char* argv[])
{
	if (argc != 3) {
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	if (!ifst.is_open())
	{
		cout << "Can't open input file" << endl;
		return -1;
	}
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled container. " << endl;
	Out(c, ofst);
	OutBalls(c, ofst);
	ofst << "Sort container by volume. " << endl;
	Sort(c);
	Out(c, ofst);
	Clear(c);
	ofst << "Empty container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	_CrtDumpMemoryLeaks();
	return 0;
}
