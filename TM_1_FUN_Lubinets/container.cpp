#include "container.h"
#include "movie.h"
#define max_len 100

Movie* InMovie(ifstream& ifst);
void OutMovie(Movie& obj, ofstream& fout);
int Count(Movie& obj);
bool Compare(Movie* first, Movie* second);
void MultiMethod(Container& c, ofstream& ofst);   
void Init(Container& c) { c.len = 0; }

void Clear(Container& c) {
  for (int i = 0; i < c.len; i++) delete c.cont[i];
  c.len = 0;
}
     
void In(Container& c, ifstream& ifst) {
  int k = 0;
  ifst >> k;
  if (k > max_len) {
    cout << "100 records will be processed";
    k = 100;
  } else {
    for (int i = 0; i < k; i++) {
      c.cont[c.len] = InMovie(ifst);
      c.len++;
    }
  }
}
    
void Out(Container& c, ofstream& ofst) {
  ofst << "Container contains " << c.len << " elements." << endl;
  for (int i = 0; i < c.len; i++) {
    ofst << i << ": ";
    OutMovie(*(c.cont[i]), ofst);
    if ((c.cont[i]) != nullptr)
      ofst << "Number of vowels: " << Count(*(c.cont[i])) << endl;
    ofst << endl;
  }
}

void OutOnlyCartoon(Container& c, ofstream& ofst) {
  ofst << "Only cartoons." << endl;
  for (int i = 0; i < c.len; i++) {
    ofst << i << ": ";
    if (((c.cont[i]) != nullptr) && (c.cont[i]->k == Movie::CARTOON)) {
      OutMovie(*(c.cont[i]), ofst);
      ofst << "Number of vowels: " << Count(*(c.cont[i])) << endl;
    } else {
      ofst << endl;
    }     
  }
}
   
void Sort(Container& c) {
  for (int i = 0; i < c.len - 1; i++) {
    for (int j = i + 1; j < c.len; j++) {
      if (Compare(c.cont[i], c.cont[j])) {
        Movie* tmp = c.cont[i];
        c.cont[i] = c.cont[j];
        c.cont[j] = tmp;
      }
    }
  }
}

void MultiMethod(Container& c, ofstream& ofst) {
  ofst << endl << "Multimethod." <<  endl;
  for (int i = 0; i < c.len - 1; i++) {
	if ((c.cont[i]) == nullptr) continue;
    for (int j = i + 1; j < c.len; j++) {
	  if ((c.cont[j]) == nullptr) continue;
      switch (c.cont[i]->k) {
        case Movie::FICTION:
          switch (c.cont[j]->k) {
            case Movie::FICTION:
              ofst << endl << "FICTION and FICTION." << endl;
              break;
            case Movie::CARTOON:
              ofst << endl << "FICTION and CARTOON." << endl;
              break;
            case Movie::DOCUMENTARY:
              ofst << endl << "FICTION and DOCUMENTARY" << endl;
              break;
            default:
              ofst << "Unknown type" << endl;
          }
          break;
        case Movie::CARTOON:
          switch (c.cont[j]->k) {
            case Movie::FICTION:
              ofst << endl << "CARTOON and FICTION." << endl;
              break;
            case Movie::CARTOON:
              ofst << endl << "CARTOON and CARTOON." << endl;
              break;
            case Movie::DOCUMENTARY:
              ofst << endl << "CARTOON and DOCUMENTARY" << endl;
              break;
            default:
              ofst << "Unknown type" << endl;
          }
          break;
        case Movie::DOCUMENTARY:
          switch (c.cont[j]->k) {
            case Movie::FICTION:
              ofst << endl << "DOCUMENTARY and FICTION." << endl;
              break;
            case Movie::CARTOON:
              ofst << endl << "DOCUMENTARY and CARTOON." << endl;
              break;
            case Movie::DOCUMENTARY:
              ofst << endl << "DOCUMENTARY and DOCUMENTARY" << endl;
              break;
            default:
              ofst << "Unknown type" << endl;
          }
          break;
        default:
          ofst << "Unknown type" << endl;
      }
      OutMovie(*(c.cont[i]), ofst);
      OutMovie(*(c.cont[j]), ofst);
    }
  }
}