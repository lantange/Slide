#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

// �O�_�P������
bool  vowel ( char a , char b ) {
    return ( ( a == 'a' || a == 'e' || a == 'i' ||
               a == 'o' || a == 'u' ) &&
             ( b == 'a' || b == 'e' || b == 'i' ||
               b == 'o' || b == 'u' ) ? true : false ) ;
}

int main() {

    string            code = "dafskjafskjsfbiaouakkkmasljkasafsd" ;
    string::iterator  p ;
    
    char  ch ;
    int   i , j ;
    
    // ��M�̪������Ʀr��
    for ( i = code.size() ; i > 0 ; --i ) {
        for ( ch = 'a' ; ch <= 'z' ; ++ch ) {
            p = search_n(code.begin(),code.end(),i,ch) ;
            if ( p != code.end() ) { 
                cout << "> ��� " << i << " �� " << ch  ;
                goto NEXT ;
            }
        }
    }

    NEXT :  cout << endl ;
    
    // ��M�̪������ƥ���
    for ( i = code.size() ; i > 0 ; --i ) {
        p = search_n(code.begin(),code.end(),i,'a',vowel) ;
        if ( p != code.end() ) {
            cout << "> " << 'a' << " �@���  " << i << " ��  " ;
            for ( j = 0 ; j < i ; ++j ) cout << *(p+j) ;
            cout << endl ;
            return 0 ;
        }
    }

    return 0 ;
    
}


    
    
