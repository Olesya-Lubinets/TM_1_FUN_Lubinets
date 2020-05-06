
#include "movie.h"
using namespace std;


fiction* In_fiction( ifstream& ifst);
cartoon* In_cartoon(ifstream& ifst);
documentary* In_documentary(ifstream& ifst);
void Out_fiction(fiction* t, ofstream& ofst);
void Out_cartoon(cartoon* r, ofstream& ofst);
int Count(movie& obj);
void Out_documentary(documentary* r, ofstream& ofst);


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
        case 3:
        {
            sp = new movie;
            sp->k = movie::key::DOCUMENTARY;
            sp->documentary = *(In_documentary(ifst));
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
        case movie::key::DOCUMENTARY:
            Out_documentary(&(obj.documentary), fout);
            break;
        default: 
            return;
        }
        fout << "Title: " << obj.title << endl;
        fout << "Country: " << obj.country << endl;
        
    }

 int Count( movie& obj)
 {
     int count = 0;
     string vowels = "óå¸ýîàûÿþèeyuoai";
     for (int i = 0; i < obj.title.length(); i++)
     {
         for (int k = 0; k < vowels.length(); k++)
             if ((char)tolower(obj.title[i]) == vowels[k])
             {
                 count++;
                 break;
             }
     }
     return count;
 }
 bool Compare(movie* first, movie* second) {
     return Count(*first) < Count(*second);
 }