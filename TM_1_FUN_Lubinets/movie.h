#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#include "cartoon.h"
#include "fiction.h"
#include "documentary.h"

   
struct movie {
    string title;
    string country;
    movie() { };
    ~movie() {};
    enum key { FICTION, CARTOON, DOCUMENTARY    } k;
    union { 
        cartoon cartoon;
        fiction fiction;
        documentary documentary;
    };
};


  
   
