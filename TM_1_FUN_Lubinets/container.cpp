#include "container.h"
#include "movie.h"
#define max_len 100

movie* In_movie(ifstream& ifst);
void Out_movie(movie& obj, ofstream& fout);
    
    void Init(container &c) { c.len = 0; }
 
    void Clear(container &c) {
        for (int i = 0; i < c.len; i++) {
            delete c.cont[i];
        }
        c.len = 0;
    }

        
  void In(container &c, ifstream &ifst) {
    int k = 0;
    ifst >> k;
    if (k > max_len)
    {
        exit(1);
    }
    else
    {
        for (int i = 0; i < k; i++) {

            c.cont[c.len] = In_movie(ifst);
            c.len++;

        }
    }
    }
    
   void Out(container &c, ofstream &ofst) {
            ofst << "Container contains " << c.len
                << " elements." << endl;
            for (int i = 0; i < c.len; i++) 
            {
                ofst << i << ": ";
                Out_movie(*(c.cont[i]), ofst);
                ofst << endl;
            }
        }

   void Out_Cartoon(container& c, ofstream& ofst) {
       ofst << "Only cartoons." << endl;
       for (int i = 0; i < c.len; i++) {
           ofst << i << ": ";
           if (c.cont[i]->k == movie::CARTOON)
               Out_movie(*(c.cont[i]), ofst);
           else
               ofst << endl;
       }
   }