#ifndef MOVIE_H
#define MOVIE_H

#include <iostream>
#include <fstream>
#include "string.h"
#include <string>
#include "cartoon.h"
#include "fiction.h"
#include "documentary.h"
using namespace std;

struct Movie {
    string title;
    string country;
    Movie() { };
    ~Movie() {};
    enum key { FICTION=1, CARTOON, DOCUMENTARY } k;
    union { 
        Cartoon cartoon;
        Fiction fiction;
        Documentary documentary;
    };
};

#endif


  
   
