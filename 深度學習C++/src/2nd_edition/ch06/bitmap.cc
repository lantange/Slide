#include <iostream>
#include <vector>

using namespace std ;

// �I�x�}��r
int  main() {
    
    int  i , j  , n  ;
    cout << "> ��J����r�ҹ����� 8 ���I�x�Ʀr : " ;

    vector<int>    no(8) ;
    vector<bool>   bitmap(8) ;
    
    // �x�s��r�I�x�}���
    for ( i = 0 ; i < 8 ; ++i ) cin >> no[i] ;

    cout << endl ;
    
    // �j�魫�ƨC�@��
    for ( i = 0 ; i < 8 ; ++i ) {
        
        n = no[i] ;

        // �N�C�@�C���U�Ӯ�l�Ȧs�J bitmap �x�}��
        for ( j = 7 ; j >= 0 ; --j ) {
            bitmap[j] = n % 2 ;
            n /= 2 ;
        }
    
        // �C�L�C�@�C
        for ( j = 0 ; j < 8 ; ++j ) 
            cout << ( bitmap[j] ? " *" : "  " ) ;
        
        cout << endl ;
        
    }

    return 0 ;
    
}

                                 
