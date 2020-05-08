#include "documentary.h"

Documentary* InDocumentary(ifstream& ifst) {
  string temp;
  ifst >> temp;
  if (temp.length() != 4) return nullptr;
  for (int i = 0; i < 4; i++) {
    if (!isdigit((unsigned char)temp[i])) return nullptr;
  }
  int year_film = stoi(temp); 
  Documentary* documentary_in = new Documentary;
  documentary_in->year_release = year_film;
  return documentary_in;
}


void OutDocumentary(Documentary* documentary_out, ofstream& ofst) {
  ofst << "It is a documentary movie" << endl;
  if (documentary_out == nullptr) {
    ofst << "Incorrect data" << endl;
  } else {
    ofst << "Year:  " << documentary_out->year_release << endl;
  }
}