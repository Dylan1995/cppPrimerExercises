#include <iostream>
#include <vector>

using namespace std;

bool search_vec(vector<int>::iterator beg, vector<int>::iterator end, int val){
    while( beg != end ) {
        if(*beg == val)
            return true;
        beg++;
    }
    return false;
}

int main( int argc, char **argv )
{
    std::vector<int> vec = {1, 2, 3, 4, 5};
    cout << search_vec(vec.begin(), vec.end(), 3) << endl;
    cout << search_vec(vec.begin(), vec.end(), 9) << endl;
    return 0;
}
