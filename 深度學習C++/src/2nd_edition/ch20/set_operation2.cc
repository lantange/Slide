#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std ;

// ����Ӧ�Ƥj�p
bool  cmp_last_digit( int a , int b ) {   return  a % 10 < b % 10 ;  }

int main() {
    
    const  int  S1 = 8 , S2 = 6 ;
    int  no1[S1] = { 73 , 44 , 23 , 19 , 37 , 65 , 44 , 44 };
    int  no2[S2] = { 25 , 23 , 44 , 20 , 10 , 87 };

    vector<int>  no ;

    // �H�Ӧ�Ƥj�p���s�Ƨ�
    sort(no1,no1+S1,cmp_last_digit) ;
    sort(no2,no2+S2,cmp_last_digit) ;

    cout << "> �Ҷ��X     : " ;
    copy( no1 , no1+S1 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;
    cout << "> �A���X     : " ;
    copy( no2 , no2+S2 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;
    
    // �p��涰, �ñN���G���J�V�q no, ���ä��ϥέӦ�Ƥ���Ʀr�j�p
    set_intersection( no1 , no1+S1 , no2 , no2+S2 , back_inserter(no) ) ;
    
    cout << "> �涰(���~) : " ;
    copy( no.begin() , no.end(), ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    no.resize(0) ;
    
    // �p��涰, �ñN���G���J�V�q no, �ϥέӦ�Ƥ覡����j�p
    set_intersection( no1 , no1+S1 , no2 , no2+S2 , back_inserter(no) , 
                      cmp_last_digit ) ;
    
    cout << "> �涰(���T) : " ;
    copy( no.begin() , no.end(), ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

    
