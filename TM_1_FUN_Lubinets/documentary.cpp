#include "documentary.h"
#include "string.h"
#include <iostream>
#include <fstream>

using namespace std;


documentary* In_documentary(ifstream& ifst)
{
    documentary* t = new documentary;
    int year_film;
    ifst >> year_film;
    t->year_release = year_film;
    return t;
}


void Out_documentary(documentary* t, ofstream& ofst)
{
    ofst << "It is a documentary movie " << endl;
    ofst << "Year:  " << t->year_release << endl;
}