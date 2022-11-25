#include <iostream>
#include <fstream>
#include "Container.h"
//#include "Sort.h"
#include <crtdbg.h>
using namespace std;
void Init(Container& c);
void Clear(Container& c);
void In(Container& c, ifstream& ifst);
void Out(Container& c, ofstream& ofst);
void Sort(Container& c);
void OutBalls(Container& c, ofstream& ofst);
int main(int argc, char* argv[])
{
	if (argc != 3)
	{
		cout << "incorrect command line! "
			"Waited: command infile outfile" << endl;
		exit(1);
	}
	ifstream ifst(argv[1]);
	ofstream ofst(argv[2]);
	cout << "Start" << endl;
	Container c;
	Init(c);
	In(c, ifst);
	ofst << "Filled Container. " << endl;
	Out(c, ofst);
	OutBalls(c, ofst);
	ofst << "Sort Container by volume. " << endl;
	Sort(c);
	Out(c, ofst);
	Clear(c);
	ofst << "Empty Container. " << endl;
	Out(c, ofst);
	cout << "Stop" << endl;
	_CrtDumpMemoryLeaks();
	return 0;
}
