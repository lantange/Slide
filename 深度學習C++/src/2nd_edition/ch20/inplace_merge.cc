#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std ;

// ����Ӧ�Ƥj�p
bool  cmp_last_digit( int a , int b ) {
    return  a%10 < b%10 ;
}
    
int main() {
 
    const int S = 8 ;
    int  no[S] = { 23 , 15 , 28 , 11 , 44 , 26 , 17 , 9 };
    
    // �C�L
    cout << "> �e���q�X�֫e : " ;
    copy( no , no+S , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �e���q�X��
    inplace_merge( no , no+3 , no+S , cmp_last_digit ) ;

    // �C�L
    cout << "> �e���q�X�֫� : " ;
    copy( no , no+S , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

    
