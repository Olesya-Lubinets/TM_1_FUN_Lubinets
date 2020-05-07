#include "documentary.h"
#include "string.h"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;


documentary* In_documentary(ifstream& ifst)
{
    documentary* t = new documentary;
    string temp;
    ifst >> temp;
    if (temp.length() != 4) { return NULL; }
    for (int i = 0; i < 4; i++)
    {
        if (!isdigit(temp[i]))
            return NULL;
    }
    int year_film;
    year_film=stoi(temp);
    t->year_release = year_film;
    return t;
}


void Out_documentary(documentary* t, ofstream& ofst)
{
    ofst << "It is a documentary movie" << endl;
    if (t == NULL)
        ofst << "Incorrect data" << endl;
    else {
        ofst << "Year:  " << t->year_release << endl;
    }
}