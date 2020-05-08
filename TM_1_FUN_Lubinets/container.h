#ifndef CONTAINER_H
#define CONTAINER_H

#include <iostream>
#include <fstream>
#include "string.h"
#include <string>
#include "movie.h"
using namespace std;

struct Movie;

struct Container{
    int len; // текущая длина
    Movie* cont[100];
};

#endif