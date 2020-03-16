#pragma once
#include <iostream>
#include <fstream>

using namespace std;

#include "cartoon.h"
#include "fiction.h"

   
struct movie {
    string title;
    string country;
    movie() { };
    ~movie() {};
    enum key { FICTION, CARTOON } k;
    union { 
        cartoon cartoon;
        fiction fiction;
    };
};


  
   
