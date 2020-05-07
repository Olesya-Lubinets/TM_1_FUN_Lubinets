
#include "cartoon.h"
#include "string.h"
#include <string>

cartoon* In_cartoon( ifstream& ifst)
{
       cartoon* r=new cartoon;  
       string temp;
       ifst >> temp;
       if (temp.length() != 1)
       {
           return NULL;
       }
       if(isdigit(temp[0])==0)
       {
           return NULL;
       }
       
       int cartoon_type = std::stoi(temp);
       switch (cartoon_type)
       {
       case 1:
           r->way = cartoon::DRAWN;
           break;
       case 2:
           r->way =cartoon::PUPPET ;
           break;
       case 3:
           r->way = cartoon::PLASTICINE;
           break;
       default:
           return NULL;
       }

       return r;
}


    void Out_cartoon(cartoon *r, ofstream& ofst)
    {
        ofst << "It is a cartoon" << endl;
      if(r==NULL)
          ofst << "Incorrect data" << endl;
      else {
          switch (r->way)
          {
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
