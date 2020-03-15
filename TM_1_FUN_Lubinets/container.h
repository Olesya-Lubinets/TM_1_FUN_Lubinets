#pragma once


#include <iostream>
#include <fstream>

#include "movie.h"

using namespace std;

struct movie;

struct container
{
    
    int len; // текущая длина
    movie* cont[100];
};

void In(container& c, ifstream& ifst);
void Out(container& c, ofstream& ofst);