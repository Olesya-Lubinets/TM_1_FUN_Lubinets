
#include "fiction.h"

fiction* In_fiction(ifstream& ifst)
{
    fiction* t = new fiction;
    string* b = new string;
    ifst >> *b;
    t->director = b;
    return t;
}


void Out_fiction(fiction* t, ofstream& ofst)
{
    ofst << "It is a fiction movie " << endl;
    ofst << "Director:  " << *(t->director) << endl;
}