#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std ;

int main() {
    
    const  int  S1 = 8 , S2 = 6 ;
    int  no1[S1] = { 73 , 44 , 23 , 19 , 37 , 65 , 44 , 44 };
    int  no2[S2] = { 25 , 23 , 44 , 20 , 10 , 87 };

    // �̼Ʀr�j�p�Ѥp��j���s�Ƨ�
    sort(no1,no1+S1) ;    
    sort(no2,no2+S2) ;
    
    cout << "> �Ҷ��X   : " ;
    copy( no1 , no1+S1 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;
    cout << "> �A���X   : " ;
    copy( no2 , no2+S2 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    vector<int>  no ;

    // �p��涰, �ñN���G���J�V�q no
    set_intersection( no1 , no1+S1 , no2 , no2+S2 , back_inserter(no) ) ;
    
    cout << "> �涰     : " ;
    copy( no.begin() , no.end(), ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // ���]�}�C���׬� 0
    no.resize(0) ;
    
    // �p���p��, �ñN���G���J�V�q no
    set_union( no1 , no1+S1 , no2 , no2+S2 , back_inserter(no) ) ;
    cout << "> �p��     : " ;
    copy( no.begin() , no.end(), ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // ���]�}�C���׬� 0
    no.resize(0) ;

    // �p��t��, �ñN���G���J�V�q no
    set_difference( no1 , no1+S1 , no2 , no2+S2 , back_inserter(no) ) ;
    cout << "> �t��     : " ;
    copy( no.begin() , no.end(), ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // ���]�}�C���׬� 0
    no.resize(0) ;

    // �p���ٮt��, �ñN���G���J�V�q no
    set_symmetric_difference( no1 , no1+S1 , no2 , no2+S2 , 
                              back_inserter(no) ) ;
    cout << "> ��ٮt�� : " ;
    copy( no.begin() , no.end(), ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

    
