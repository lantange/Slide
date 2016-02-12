#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std ;

// �j�p�g�L��
bool  case_insensitive ( char a , char b ) {
    if ( 'a' <= a && a <= 'z' ) a = a - 'a' + 'A' ;
    if ( 'a' <= b && b <= 'z' ) b = b - 'a' + 'A' ;
    return  a == b ;
}

int main() {
    
    string  pwd = "ratoxtigerrabbitdragonoxoxrat" ;
    string  code ;
    string::iterator  iter , iter2 ;
    
    int  n ;
    cout << pwd << endl ;

    // ���Ƨ�M  �� ctrl-c ���}
    while ( 1 ) {
        
        // ��J����M�r��
        cin >> code ;

        iter = pwd.end() ;
        n = 0 ;
        
        while( 1 )  {

            // �b [pwd.begin(),iter) ����M�̫�@���r�� code
            iter2 = find_end( pwd.begin() , iter , 
                              code.begin() , code.end() ,
                              case_insensitive ) ;

            // �S���h����
            if ( iter2 == iter ) break ;

            // ���, �h�p�ƥ[�@, ���w�j�M����
            ++n ; iter = iter2 ;
        }
        cout << "> count : " << n << endl ;
    }

    return 0 ;
    
}
