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

   void MultiMethod(container &c, ofstream &ofst) {
          ofst << "Multimethod." << endl<<endl;
           for (int i = 0; i < c.len - 1; i++) {
            for (int j = i + 1; j < c.len; j++) {
              switch (c.cont[i]->k) {
                case movie::FICTION:
                  switch (c.cont[j]->k) {
                    case movie::FICTION:
                      ofst << endl << "FICTION and FICTION." << endl;
                      break;
                    case movie::CARTOON:
                      ofst << endl << "FICTION and CARTOON." << endl;
                      break;
                    default:
                      ofst << "Unknown type" << endl;
                  }
                  break;
                case movie::CARTOON:
                  switch (c.cont[j]->k) {
                    case movie::FICTION:
                      ofst << endl << "CARTOON and FICTION." << endl;
                      break;
                    case movie::CARTOON:
                      ofst << endl << "CARTOON and CARTOON." << endl;
                      break;
                    default:
                      ofst << "Unknown type" << endl;
                  }
                  break;
                default:
                  ofst << "Unknown type" << endl;
              }
              Out_movie(*(c.cont[i]), ofst);
              Out_movie(*(c.cont[j]), ofst);
            }
          }
        }
