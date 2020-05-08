#include "movie.h"

Fiction* InFiction( ifstream& ifst);
Cartoon* InCartoon(ifstream& ifst);
Documentary* InDocumentary(ifstream& ifst);
void OutFiction(Fiction* fiction_out, ofstream& ofst);
void OutCartoon(Cartoon* cartoon_out, ofstream& ofst);
int Count(Movie& obj);
void OutDocumentary(Documentary* documentary_out, ofstream& ofst);

Movie* InMovie(ifstream& ifst){
  string temp;
  string waste;
  ifst >> temp;
  if (temp.length() != 1) {
    for (int i = 0; i < 3; i++) {
      ifst.ignore();
      getline(ifst, waste, '\n');
    }
    return nullptr;
  }
  if (isdigit((unsigned char)temp[0]) == 0) {
    ifst.ignore();
    for (int i = 0; i < 3; i++) {
      getline(ifst, waste, '\n');
    }
    return nullptr;
  }
  int m = stoi(temp);
  ifst.ignore();
  getline(ifst, temp, '\n');
  if ((temp) == "\0") {
    for (int i = 0; i < 2; i++) {
      getline(ifst, waste, '\n');
    }
    return nullptr;
  }
  string title = temp;
  getline(ifst, temp, '\n');
  if ((temp) == "\0") {
    for (int i = 0; i < 1; i++) {
      getline(ifst, waste, '\n');
    }
    return nullptr;
  }
  string country = temp;
  Movie* sp;
  switch (m) {
    case 1: {
      sp = new Movie;
      Fiction* temp;
      temp = InFiction(ifst);
      if (temp == nullptr) {
        return nullptr;
      } else {
        sp->k = Movie::key::FICTION;
        sp->fiction = *temp;
        sp->title = title;
        sp->country = country;
        return sp;
      }
      break;
    }
    case 2: {
      sp = new Movie;
      Cartoon* temp;
      temp = (InCartoon(ifst));
      if (temp == nullptr) {
        return nullptr;
      } else {
        sp->k = Movie::key::CARTOON;
        sp->cartoon = *temp;
        sp->title = title;
        sp->country = country;
        return sp;
      }
      break;
    }
    case 3: {
      sp = new Movie;
      Documentary* temp;
      temp = InDocumentary(ifst);
      if (temp == nullptr) {
        return nullptr;
      } else {
        sp->k = Movie::key::DOCUMENTARY;
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

void OutMovie(Movie& obj_movie, ofstream& fout) {
  if (&obj_movie == nullptr) {
    fout << "Incorrect data" << endl;
  } else {
    switch (obj_movie.k) {
      case Movie::key::CARTOON:
        OutCartoon(&(obj_movie.cartoon), fout);
        break;
      case Movie::key::FICTION:
        OutFiction(&(obj_movie.fiction), fout);
        break;
      case Movie::key::DOCUMENTARY:
        OutDocumentary(&(obj_movie.documentary), fout);
        break;
      default:
        return;
    }
    fout << "Title: " << obj_movie.title << endl;
    fout << "Country: " << obj_movie.country << endl;
  }
} 

int Count(Movie& obj_movie) {
  if (&obj_movie != nullptr) {
    int count = 0;
    string vowels = "óå¸ýîàûÿþèeyuoai";
    for (int i = 0; i < obj_movie.title.length(); i++) {
      for (int k = 0; k < vowels.length(); k++)
        if ((char)tolower(obj_movie.title[i]) == vowels[k]) {
          count++;
          break;
        }
    }
    return count;
  }
}

 bool Compare(Movie* first, Movie* second) {
  if (first == nullptr || second == nullptr) return false;
     return Count(*first) < Count(*second);
 }