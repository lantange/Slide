#include <iostream>
#include <iomanip>

using namespace std ;

int main() {
    
    int   i , n ;
    
    char  a[] = " " ;
    char  b[] = "123456" ;

    cout << "> ��J�����μƦr�L�j�p : " ;
    cin  >> n ;
    cout << endl ;

    // �C�L�����μƦr�L���W�b��
    for ( i = 0 ; i < n ; ++i ) {

        cout << setfill(' ') << setw(n-i+2) << " " ;

        a[0] = b[0] ;            
        cout << setfill(b[0]) << setw(2*i+1) << a << ' ' ;

        a[0] = b[1] ;            
        cout << setfill(b[1]) << setw(2*(n-i)-1) << a << ' ' ;

        a[0] = b[2] ;            
        cout << setfill(b[2]) << setw(2*i+1) << a << '\n' ;
        
    }

    cout << endl ;
    
    // �C�L�����μƦr�L���U�b��
    for ( i = 0 ; i < n ; ++i ) {

        cout << setfill(' ') << setw(3+i) << " " ;

        a[0] = b[5] ;            
        cout << setfill(b[5]) << setw(2*(n-i)-1) << a << ' ' ;

        a[0] = b[4] ;            
        cout << setfill(b[4]) << setw(2*i+1) << a << ' ' ;

        a[0] = b[3] ;            
        cout << setfill(b[3]) << setw(2*(n-i)-1) << a << '\n' ;
        
    }

    return 0 ;
    
}
