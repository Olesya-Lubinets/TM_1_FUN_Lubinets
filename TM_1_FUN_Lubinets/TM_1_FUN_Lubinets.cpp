#include <iostream>
#include <fstream>

#include "container.h"

using namespace std;
void Init(container& c);
void Clear(container& c);
void In(container& c, ifstream& ifst);
void Out(container& c, ofstream& ofst);
void Sort(container& c);
void Out_Only_Cartoon(container& c, ofstream& ofst);



int main(int argc, char* argv[]) {
    if (argc != 3) {
        cout << "incorrect command line! "
            "Waited: command infile outfile" << endl;
        exit(1);
    }
    ifstream ifst(argv[1]);
    if (!ifst.is_open())
    {
        cout << "No input file found or could not open!" << endl;
        system("pause");
        return 1;
    }
    ofstream ofst(argv[2]);
   
    cout << "Start" << endl;
    container c;
    Init(c);
    In(c, ifst);
    Sort(c);
   ofst << "Filled container. " << endl<<endl;
   Out(c, ofst);
    
    Out_Only_Cartoon(c, ofst);
   Clear(c);
    ofst << "Empty container. " << endl<<endl;
    Out(c, ofst);
    cout << "Stop" << endl;
    return 0;
}
