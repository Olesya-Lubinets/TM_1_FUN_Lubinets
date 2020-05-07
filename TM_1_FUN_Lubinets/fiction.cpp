
#include "fiction.h"
#include <string>

fiction* In_fiction(ifstream& ifst)
{
    fiction* t = new fiction;
    string* temp =new string;
    ifst.ignore();
    getline(ifst, *temp, '\n');
    if ((*temp) == "\0")
    {
        return NULL;
    }
    if (isdigit((*temp).front()) != 0)
    {
        return NULL;
    }
    t->director = temp;
    return t;
}


void Out_fiction(fiction* t, ofstream& ofst)
{
    ofst << "It is a fiction movie" << endl;
    if (t == NULL)
        ofst << "Incorrect data" << endl;
    else {
        ofst << "Director:  " << *(t->director) << endl;
    }
}