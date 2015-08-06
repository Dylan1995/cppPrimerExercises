#include <iostream>
#include "Sales_data.h"

using namespace std;

int main()
{
    Sales_data total;
    if( read(cin, toal) )
    {
        Sales_data trans;
        while( read(cin, trans) ) {
            if( total.isbn() == trans.isbn() )
            {
                total += add(total, trans);
            }
            else
            {
                print(cout, total);
                cout << endl;
                total = trans;
            }
        }
        print(cout, total);
        cout << endl;
    }
    else
    {
        cerr << "no data" << endl;
        return -1;
    }
    return 0;
}
