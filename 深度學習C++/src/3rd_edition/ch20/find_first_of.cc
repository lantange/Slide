#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std ;

int main() {

    // �T�w���]�w�ֳz�}�����X : 32 24 38 42 12 19
    int  lottery[6] = { 32 , 24 , 38 , 42 , 12, 19 } ;
    
    // �C�L�ֳz�}�����X
    cout << "> �ֳz�}�����X : " ;
    copy( lottery , lottery+6 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �H�u��J�m�鸹�X
    vector<int>  no ;
    cout << "> �m���ʶR���X : " ;
    copy( istream_iterator<int>(cin) , istream_iterator<int>() ,
          back_inserter(no) ) ;

    // �ֺ⤤�������X����`��
    vector<int>::iterator  iter = no.begin() ;
    vector<int>            matched_no ;
    
    while( ( iter = find_first_of( iter , no.end() , lottery ,
                                   lottery+6 ) ) != no.end() ) {
        matched_no.push_back( *iter++ ) ;
    }
    
    // �C�L�m�餤�����X
    cout << "> �m�餤�����X : " ;
    copy( matched_no.begin() , matched_no.end() , 
          ostream_iterator<int>(cout," ") ) ;
    cout << " , �@ " <<  matched_no.size() << " �Ӹ��X" << endl ;

    return 0 ;
    
}

    
    
