#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>

using namespace std ;

// �ˬd��ƬO�_�P���_�ƩΪ̬O����
bool  odd_even( int a , int b ) { return  a % 2 == b % 2 ; }

int main() {
    
    const int S = 10 ;
    int no[S] = { 23 , 55 , 55 , 98 , 12 , 34 , 34 , 34 , 73 , 43 };

    vector<int>            foo(no,no+S) ;
    vector<int>::iterator  iter ;

    cout << "> ��l�ǦC����   : " ;
    copy( foo.begin() , foo.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �h���۾F�B�ۦP����
    iter = unique( foo.begin() , foo.end() ) ;

    cout << "> ��@��(����)   : " ;
    copy( foo.begin() , iter , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    cout << "> ��@��(���)   : " ;
    copy( foo.begin() , foo.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    vector<int>  bar ;
    copy( no , no+S , foo.begin() ) ;
    unique_copy( foo.begin() , foo.end() , back_inserter(bar) ) ;
    
    cout << "> ��@�ƻs       : " ;
    copy( bar.begin() , bar.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // ���s�]�w foo 
    copy( no , no+S , foo.begin() ) ;

    // �_�ư��Ƴ�@��
    iter = unique( foo.begin() , foo.end() , odd_even ) ;
    
    cout << "> �_���Ƴ�@��   : " ;
    copy( foo.begin() , iter , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // ���s�]�w foo , bar 
    copy( no , no+S , foo.begin() ) ;
    bar.resize(0) ;
    
    // �_�ư��Ƴ�@�ƻs
    iter = unique_copy( foo.begin() , foo.end() , bar.begin() , odd_even ) ;
    
    cout << "> �_���Ƴ�@�ƻs : " ;
    copy( bar.begin() , iter , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}
