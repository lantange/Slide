#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <ctime>

using namespace std ;

void  swap( int& a , int& b ) {
    int t = a ;  a = b ;  b = t ;
}


int main() {

    // �H�ɶ��]�w�üƪ��
    srand( time(NULL) ) ;
    
    // �q�����ͼֳz�������X
    int  i , no[42] ;
    for ( i = 0 ; i < 42 ; ++i ) no[i] = i+1 ;
    for ( i = 0 ; i < 6 ; ++i ) swap(no[i], no[rand()%42])  ;

    vector<int>  lottery(6) ;
    copy( no , no+6 , lottery.begin() ) ;
    
    cout << "> �ֳz�}�����X : " ;
    copy( lottery.begin() , lottery.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �H�u��J�m�鸹�X
    vector<int>  foo ;
    cout << "> �m���ʶR���X : " ;
    copy( istream_iterator<int>(cin) , istream_iterator<int>() ,
          back_inserter(foo) ) ;

    // �ֺ⤤�������X����`��
    vector<int>::iterator  iter = foo.begin() ;
    vector<int>            matched_no ;
    
    while( ( iter = find_first_of( iter , foo.end() , lottery.begin() ,
                                   lottery.end() ) ) != foo.end() ) {
        matched_no.push_back( *iter++ ) ;
    }
    
    cout << "> �m�餤�����X : " ;
    copy( matched_no.begin() , matched_no.end() , 
          ostream_iterator<int>(cout," ") ) ;
    cout << " , �@ " <<  matched_no.size() << " �Ӹ��X" << endl ;
    
    
}

    
    
