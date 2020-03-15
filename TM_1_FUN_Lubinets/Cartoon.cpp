
#include "cartoon.h"
#include "string.h"

cartoon* In_cartoon( ifstream& ifst)
{
       cartoon* r=new cartoon;  

       int cartoon_type = 0;
       ifst >> cartoon_type;
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
           cout << "Incorrect way to create of cartoon";
           exit(1);
       }

       return r;
}


    void Out_cartoon(cartoon *r, ofstream& ofst)
    {
        ofst << "It is a cartoon " << endl;
     
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
