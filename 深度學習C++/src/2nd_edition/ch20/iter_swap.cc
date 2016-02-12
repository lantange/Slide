#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

int main() {

    int          no[3] = { 10 , 20 , 30 };

    vector<int>  foo(2)  ;
    foo[0] = 40 ;  foo[1] = 50 ;
    
    vector<int>::iterator  iter = foo.begin() ;

    cout << "��իe : " << endl 
         << "> no  = " << no[0] << " " << no[1] << " " << no[2] << endl 
         << "> foo = " << foo[0] << " " << foo[1] << endl ;

    // ��� no[1] �P *iter ���ƭ�
    iter_swap( no+1 , iter ) ;
    
    // ��� no[2] �P foo[1] 
    swap( no[2] , foo[1] ) ;
    
    cout << "��ի� : " << endl 
         << "> no  = " << no[0] << " " << no[1] << " " << no[2] << endl
         << "> foo = " << foo[0] << " " << foo[1] << endl ;

    return 0 ;

}

    
