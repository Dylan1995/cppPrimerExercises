#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    if( cin >> total )
    {
        Sales_data trans;
        while( cin >> trans ) {
            if( total.isbn() == trans.isbn() )
            {
                total.combine(trans);
            }
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
        cout << total << endl;

    }
    else
    {
        cerr << "no data" << endl;
        return -1;
    }
}
