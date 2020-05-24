#include <iostream>
#include <fstream>
#include "container.h"
using namespace std;

void Init(Container& c);
void Clear(Container& c);
void In(Container& c, ifstream& ifst);
void Out(Container& c, ofstream& ofst);
void Sort(Container& c);
void OutOnlyCartoon(Container& c, ofstream& ofst);
void MultiMethod(Container& c, ofstream& ofst);

int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command infile outfile" << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    if (!ifst.is_open()){
        cout << "No input file found or could not open!" << endl;
        system("pause");
        return 1;
    }

    ofstream ofst(argv[2]);
	if (!ofst.is_open()){
        cout << "No output file found or could not open!" << endl;
        system("pause");
        return 1;
    }
    cout << "Start" << endl;
    Container c;
    Init(c);
    In(c, ifst);
    Sort(c);
    ofst << "Filled container. " << endl<<endl;
    Out(c, ofst);
    OutOnlyCartoon(c, ofst);
    MultiMethod(c, ofst);
    Clear(c);
    ofst << "Empty container. " << endl<<endl;
    Out(c, ofst);
    cout << "Stop" << endl;
    return 0;
}
