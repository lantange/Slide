#include <iostream>

using namespace std ;

int main() {
    
    // �Q�Τ��y���N�k�p��ڸ� x ����, �p��~�t�� 1.0E-6
    // 
    const double  SMALL = 1.0E-6 ;
    double  a , b , n , error ;
    
    cout << "> ��J�ƭ� : " ;
    cin  >> n ;

    // �]�w�_�l�� a    
    a = 10. ;
    do {
        b  = 0.5 * ( a + n / a ) ;  // ���y���N����
        error =  a - b ;
        if ( error < 0 ) error = -error ;
        a = b ;
    } while ( error > SMALL ) ;
    
    cout << "> �ڸ� " << n << "  = " << b << endl ;

    return 0 ;
    
}
