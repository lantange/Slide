#include <iostream>
#include <numeric>
#include <iterator>
#include <algorithm>

using namespace std ;

// �Y�t�Z�p��s, �h�]���s. 
// �Яd�N : b �ѼƩҥN�������b a �ѼƩҥN��������@��
int  positive_difference( int b , int a ) {
    int  d = b - a ;
    return  ( d < 0 ? 0 : d ) ;
}

int main() {
    
    int x[5] = { 4 , 2 , 2 , 5 , 2 };
    int dx[5] ;
    
    cout << "> �}�C   = " ;
    copy( x , x+5 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    adjacent_difference( x , x+5 , dx ) ;
    
    cout << "> �t�Z   = " ;
    copy( dx , dx+5 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    adjacent_difference( x , x+5 , dx , positive_difference ) ;
    
    cout << "> ���t�Z = " ;
    copy( dx , dx+5 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

