#include <iostream>

using namespace std ;

int main() {
    
    // ���r��
    char  str[] = "AGACCGGTATTACGGTTACCTCCACTCGTTACCCTGTCCCATTTAG" ;
    char  substr[100] ;
    
    bool  found ;
    int   count = 0; 
    int   i , j ;
    int   len , len1 , len2 ;
    
    cout << "> ��J�r�� : " ;
    cin >> substr ;

    // �ҭn��諸�r�����, ���]�t�Ŧr��
    len1 = 0 ;
    while( str[len1] != '\0' ) ++len1 ;

    // �ҭn��M���r�����, ���]�t�Ŧr��
    len2 = 0 ;
    while( substr[len2] != '\0' ) ++len2 ;

    // �C�L���r��
    cout << str << endl ;

    // �p��̦h�j��`������
    len = len1 - len2 + 1 ;

    // �j��}�l
    for ( i = 0 ; i < len ; ++i ) {

        // ���r��
        found = true ;
        for ( j = 0 ; j < len2 ; ++j ) {
            if ( str[i+j] != substr[j] ) {
                found = false ;
                break ;
            }
        }

        // �p���쪺����        
        if ( found ) ++count ;

        // �C�L��쪺�_�l��m
        cout << ( found ? "^" : " " ) ;
        
    }

    cout << "\n> ��즸�� : " << count << endl ;

    return 0 ;
    
}
