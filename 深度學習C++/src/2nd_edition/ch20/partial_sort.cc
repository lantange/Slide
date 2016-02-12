#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std ;

// ����Q��ƪ��j�p
bool  big10 ( int a , int b ) {  return  a/10 < b/10 ; }

int main() {
    
    const int S = 6 ;
    int         old_no[S] = { 16 , 9 , 36 , 4 , 25 , 1 } ;
    deque<int>  no(S) ;
    
    cout << "> �Ƨǫe                    : " ;
    copy( old_no , old_no+S , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �N old_no �ƻs�� no ��� partial_sort �@�ӭӨ̦��Ƨ�
    for ( int  i = 1 ; i <= no.size() ; ++i ) {
        copy( old_no , old_no+S , no.begin() ) ;
        partial_sort( no.begin() , no.begin()+i , no.end() ) ;
        cout << "> partial sort        ( " << i << " ) : " ;
        copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
        cout << endl ;
    }
    
    cout << endl ;
    
    // �N old_no �ƻs�� no ��H����Q��ƪ��覡
    // �ϥ� partial_sort �@�ӭӨ̦��Ƨ�
    for ( int  i = 1 ; i <= no.size() ; ++i ) {
        copy( old_no , old_no+S , no.begin() ) ;
        partial_sort( no.begin() , no.begin()+i , no.end() , big10 ) ;
        cout << "> parital sort �Q��� ( " << i << " ) : " ;
        copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
        cout << endl ;
    }

    return 0 ;
    
}

