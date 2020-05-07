
#include "movie.h"
#include <string>
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
        string temp;
        string waste;
        ifst >> temp;
        if (temp.length() != 1)
        { 
            for (int i = 0; i < 3; i++) {
                ifst.ignore();
                getline(ifst, waste, '\n');
            }
            return NULL;
        }
        if (isdigit((unsigned char)temp[0])==0) {
            ifst.ignore();
            for (int i = 0; i < 3; i++) 
            {             
                getline(ifst, waste, '\n');
            } 
            return NULL; 
        }
        int m=stoi(temp);    
        ifst.ignore();
        getline(ifst, temp, '\n');
        if ((temp) == "\0")
        {
            for (int i = 0; i < 2; i++) {
                getline(ifst, waste, '\n');
            }
            return NULL;
        }
        string title=temp;
        getline(ifst, temp, '\n');
        if ((temp) == "\0")
        {
            for (int i = 0; i < 1; i++) {
                  getline(ifst, waste, '\n');
            }
            return NULL;
        }     
        string country=temp;     
        switch (m) {
        case 1:
        {
            sp = new movie;
            fiction* temp;
            temp = In_fiction(ifst);
            if (temp == NULL) { return NULL; }
            else {
                sp->k = movie::key::FICTION;
                sp->fiction = *temp;
                sp->title = title;
                sp->country = country;
                return sp;
            }
            break;
        }
        case 2:
        {
            sp = new movie;          
            cartoon* temp;
            temp=(In_cartoon(ifst));
            if (temp==NULL) { return NULL; }
            else {
                sp->k = movie::key::CARTOON;
                sp->cartoon = *temp;
                sp->title = title;
                sp->country = country;
                return sp;
            } 
            break;
        }
        case 3:
        {
            sp = new movie;
            documentary* temp;
            temp = In_documentary(ifst);
            if (temp == NULL) { return NULL; }
            else {
                sp->k = movie::key::DOCUMENTARY;
                sp->documentary = *temp;
                sp->title = title;
                sp->country = country;
                return sp;
            }
            break;
        }
        default:
            return 0;
        }
        
    } 

 void Out_movie(movie &obj, ofstream& fout)
    {
     if (&obj == NULL)
         fout << "Incorrect data" << endl;
     else {
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
    }

 int Count( movie& obj)
 {
     if (&obj != NULL)
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
 }
 bool Compare(movie* first, movie* second) {
     if (first == NULL || second == NULL) { return false; }
     return Count(*first) < Count(*second);
 }