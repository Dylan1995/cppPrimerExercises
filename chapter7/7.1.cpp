#include "Sales_data.h"
#include <iostream>

using namespace std;

int main( int argc, char **argv )
{
    Sales_data total;
    if( cin >> total )
    {
        Sales_data trans;
        while( cin >> trans ) {
            if( total.isbn() )
            {
                total += trans;
            }
            else
            {
                cout << total << endl;
                total = trans;
            }
        }
    }
    else
    {
        cerr << "no data" << endl;
        return -1;
    }
    return 0;
}
