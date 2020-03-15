
#include "movie.h"
using namespace std;


fiction* In_fiction( ifstream& ifst);
cartoon* In_cartoon(ifstream& ifst);
documentary* In_documentary(ifstream& ifst);
void Out_fiction(fiction* t, ofstream& ofst);
void Out_cartoon(cartoon* r, ofstream& ofst);
void Out_documentary(documentary* r, ofstream& ofst);


    movie* In_movie(ifstream& ifst)
    {
        movie* sp;
        int m;
        ifst >> m;
        string title;
        ifst >> title;
        switch (m) {
        case 1:
        {
            sp = new movie;
            sp->k = movie::key::FICTION;
            sp->fiction = *(In_fiction( ifst));
            sp->title = title;
            return sp;
            break;
        }
        case 2:
        {
            sp = new movie;
            sp->k = movie::key::CARTOON;    
            sp->cartoon = *(In_cartoon(ifst));
            sp->title = title;
            return sp;
            break;
        }
        case 3:
        {
            sp = new movie;
            sp->k = movie::key::DOCUMENTARY;
            sp->documentary = *(In_documentary(ifst));
            sp->title = title;
            return sp;
            break;
        }
        default:
            return 0;
        }
        
    } 

 void Out_movie(movie &obj, ofstream& fout)
    {
        switch (obj.k)
        {
        case movie::key::CARTOON:
            Out_cartoon(&(obj.cartoon), fout);
            break;
        case movie::key::FICTION:
            Out_fiction(&(obj.fiction), fout);
            break;
        case movie::key::DOCUMENTARY:
            Out_documentary(&(obj.documentary), fout);
            break;
        default: 
            return;
        }
        fout << "Title: " << obj.title << endl;
    }