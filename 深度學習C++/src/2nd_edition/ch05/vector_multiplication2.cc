#include <iostream>
#include <iomanip>

using namespace std ;

int  main() {
    
    int  i , j , n ;
    
    cout << "> ��J�V�q���� : " ;
    cin >> n ;

    int  *a , *b , **M ;
    
    a = new int[n] ;
    b = new int[n] ;

    M = new int*[n] ;
    for ( i = 0 ; i < n ; ++i )  M[i] = new int[n] ;
    
    cout << "> ��J�Ĥ@�ӦV�q�Ҧ������� : " ;
    for ( i = 0 ; i < n ; ++i ) cin >> *(a+i) ;
    
    cout << "> ��J�ĤG�ӦV�q�Ҧ������� : " ;
    for ( i = 0 ; i < n ; ++i ) cin >> *(b+i) ;

    // �p��x�} M[i][j] = a[i] * b[j]
    for ( i = 0 ; i < n ; ++i ) {
        for ( j = 0 ; j < n ; ++j ) M[i][j] = *(a+i) * *(b+j) ;
    }
    
    // �C�L a b = M 
    for ( i = 0 ; i < n ; ++i ) {

        cout << setw(2) << *(a+i) ;

        if ( i == static_cast<int>(n/2) ) {
            cout << "  * " ;
            for ( j = 0 ; j < n ; ++j ) cout << setw(2) << *(b+j) ;
            cout << "  = " ;
        } else {
            cout << setw(8+2*n) << " " ;
        }
        for ( j = 0 ; j < n ; ++j ) 
            cout << setw(3) << M[i][j] << " " ;
        
        cout << endl ;
    }

    // �N a , b , M ���O�ЪŶ��e�^�t��
    delete [] a ;   delete [] b ;   

    for ( i = 0 ; i < n ; ++i ) delete [] M[i] ;
    delete [] M ;
    

    return 0 ;
    
}


