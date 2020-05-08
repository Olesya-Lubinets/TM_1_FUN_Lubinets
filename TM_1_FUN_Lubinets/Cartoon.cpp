#include "cartoon.h"

Cartoon* InCartoon(ifstream& ifst) {
  string temp;
  ifst >> temp;
  if (temp.length() != 1) return nullptr;
  if (isdigit((unsigned char)temp[0]) == 0) return nullptr;
  int cartoon_type = std::stoi(temp);
  Cartoon* cartoon_in = new Cartoon;
  switch (cartoon_type) {
    case 1:
      cartoon_in->way = Cartoon::DRAWN;
      break;
    case 2:
      cartoon_in->way = Cartoon::PUPPET;
      break;
    case 3:
      cartoon_in->way = Cartoon::PLASTICINE;
      break;
    default:
      return nullptr;
  }
  return cartoon_in;
}

void OutCartoon(Cartoon* cartoon_out, ofstream& ofst) {
  ofst << "It is a cartoon" << endl;
  if (cartoon_out == nullptr) {
    ofst << "Incorrect data" << endl;
  } else {
    switch (cartoon_out->way) {
      case 1:
        ofst << "It's a drawn cartoon" << endl;
        break;
      case 2:
        ofst << "It's a puppet cartoon" << endl;
        break;
      case 3:
        ofst << "It's a plasticine cartoon" << endl;
        break;
    }
  }
}
