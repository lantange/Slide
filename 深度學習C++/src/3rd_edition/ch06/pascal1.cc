#include <iostream>
#include <iomanip>           

using namespace std ;

int main() {
    
    int  i , j , no ;
    
    // a , b ���O���ڴ��d�T���Ϊ��W�@�C�P�U�@�C�}�C
    int  a[20] , b[20] ;
    
    cout << "> ��J�ڴ��d�T���Ϊ����� : " ;
    cin >> no ;
        
    a[0] = 1 ;
        
    for ( i = 0 ; i < no ; ++i ) {

        // �C�L�ڴ��d�� i �C�}�C
        cout << setw(3*(no-i)) << " " ;
        for ( j = 0 ; j <= i ; ++j ) cout << setw(6) << a[j] ;
        cout << endl ;
            
        // �p��U�@�C�}�C��
        b[0] = 1 ;
        for ( j = 1 ; j <= i ; ++j ) b[j] = a[j-1] + a[j] ;
        b[i+1] = 1 ;
            
        // ���s�]�w�W�@�C���}�C
        for ( j = 0 ; j <= i+1 ; ++j ) a[j] = b[j] ;
            
    }
        
    return 0 ;
    
}
