#include <iostream>
#include <cstring>

using namespace std;

int main(){
     char s1[] = "c++";
     char s2[] = "stl";
     char res[strlen(s1) + strlen(s2) - 1];

     strcpy(res, s1);
     strcat(res, s2);

     cout << "1: " << s1 << endl;
     cout << "2: " << s2 << endl;
     cout << "res: " << res << endl;

     return 0;
}
