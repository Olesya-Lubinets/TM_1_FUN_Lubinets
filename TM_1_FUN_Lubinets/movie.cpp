
#include "movie.h"
using namespace std;


fiction* In_fiction( ifstream& ifst);
cartoon* In_cartoon(ifstream& ifst);
void Out_fiction(fiction* t, ofstream& ofst);
void Out_cartoon(cartoon* r, ofstream& ofst);


    movie* In_movie(ifstream& ifst)
    {
        movie* sp;
        int m;
        ifst >> m;
        string title;
        ifst >> title;
        string country;
        ifst >> country;
        switch (m) {
        case 1:
        {
            sp = new movie;
            sp->k = movie::key::FICTION;
            sp->fiction = *(In_fiction( ifst));
            sp->title = title;
            sp->country = country;
            return sp;
            break;
        }
        case 2:
        {
            sp = new movie;
            sp->k = movie::key::CARTOON;    
            sp->cartoon = *(In_cartoon(ifst));
            sp->title = title;
            sp->country = country;
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
        default: 
            return;
        }
        fout << "Title = " << obj.title << endl;
        fout << "Country of Origin: " << obj.country << endl;
    }