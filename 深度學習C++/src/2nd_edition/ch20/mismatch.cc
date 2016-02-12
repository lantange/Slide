#include <iostream>
#include <algorithm>

using namespace std ;

int main() {
    
    const int S = 10 ;
    int  foo[S] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 };
    int  bar[S] = { 0 , 1 , 2 , 3 , 4 , 5 , 6 , 3 , 8 , 9 };

    pair<int*,int*>   ptr_pair ;

    // �b��}�C�����O��M���줣�ۦP��������}
    ptr_pair = mismatch( foo , foo+S , bar ) ;

    if ( ptr_pair.first == foo+S ) {
        cout << "> �b foo �}�C���䤣�줣�@�˪����� " << endl ;
    } else {
        cout << *(ptr_pair.first) << endl ;
    }

    if ( ptr_pair.second == bar+S ) {
        cout << "> �b bar �}�C���䤣�줣�@�˪����� " << endl ;
    } else {
        cout << *(ptr_pair.second) << endl ;
    }

    return 0 ;
    
}
