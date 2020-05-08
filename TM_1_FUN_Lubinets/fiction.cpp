#include "fiction.h"

Fiction* InFiction(ifstream& ifst) {
  string* temp = new string;
  ifst.ignore();
  getline(ifst, *temp, '\n');
  if ((*temp) == "\0") return nullptr;
  if (isdigit((unsigned char)(*temp).front()) != 0) return nullptr;
  Fiction* fiction_in = new Fiction;
  fiction_in->director = temp;
  return fiction_in;
}

void OutFiction(Fiction* fiction_out, ofstream& ofst) {
  ofst << "It is a fiction movie" << endl;
  if (fiction_out == nullptr) {
    ofst << "Incorrect data" << endl;
  } else {
    ofst << "Director:  " << *(fiction_out->director) << endl;
  }
}