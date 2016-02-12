#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std ;

// ����Q��ƪ��j�p
bool  big10 ( int a , int b ) {  return  a/10 < b/10 ; }


int main() {
    
    const int S = 18 ;
    int         old_no[S] ;
    deque<int>  no(S) ;
    
    // ���� 18 �ӭӦ��
    for ( int i = 0 ; i < S ; ++i ) old_no[i] = 4-(2*i)/10 ;
    
    cout << "> �Ƨǫe      : " ;
    copy( old_no , old_no+S , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �N old_no �ƻs�� no ��� sort �Ƨ�
    copy( old_no , old_no+S , no.begin() ) ;
    sort( no.begin() , no.end() ) ;
    cout << "> sort        : " ;
    copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �N old_no �ƻs�� no ��� stable_sort �Ƨ�
    copy( old_no , old_no+S , no.begin() ) ;
    stable_sort( no.begin() , no.end() ) ;
    cout << "> stable_sort : " ;
    copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl << endl ;

    // �N old_no �ƻs�� no ��H����Q��ƪ��覡�ϥ� sort �Ƨ�
    copy( old_no , old_no+S , no.begin() ) ;
    sort( no.begin() , no.end() , big10 ) ;
    cout << "> sort        �Q��� : " ;
    copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �N old_no �ƻs�� no ��H����Q��ƪ��覡�ϥ� stable_sort �Ƨ�
    copy( old_no , old_no+S , no.begin() ) ;
    stable_sort( no.begin() , no.end() , big10 ) ;
    cout << "> stable_sort �Q��� : " ;
    copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

