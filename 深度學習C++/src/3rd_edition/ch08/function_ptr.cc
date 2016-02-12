#include <iostream>
#include <iomanip>

using  namespace  std ;

// fn(x) = x * x
double  square( double x ) { return  x * x ; }

// fn(x) = ( x - 1 ) ( x - 1 )
double  f     ( double x ) { return  x * x - 2. * x + 1. ; }

// �H c ��C�L �禡 fn �b�϶� [a,b] ����, �϶��N���Φ� division ����
void  print_function( double (*fn)(double) , double a , double b , 
                      int division = 20 , int c = 3 ) {

    int     i , j ;
    
    // �C�L���Y
    for ( i = 0 ; i < c ; ++i ) 
        cout << setw(6) << " X  " << setw(7) << "F(X)" 
             << setw(4) << " " ;
    cout << endl ;

    for ( i = 0 ; i < c ; ++i ) 
        cout << setw(6) << "====" << setw(7) << "====" 
             << setw(4) << " " ;
    cout << endl ;

    // n ���禡���I��
    int     n = division + 1 ;

    // x ���禡�����ܼ�, dx ���C�@�������j�p
    double  x = a ;
    double  dx = ( b - a ) / division ;

    // �p��ֶ̤��n����ܪ��C�� r (row) 
    int  r = n / c ;
    if ( r * c < n ) r++ ;   
    
    // �̫�@��Ҷ��n��ܪ��C��
    int  s =  n - r * (c-1) ;

    // �B�I�ƪ��p�Ʀ�ƥH 2 ���X, �B�p�Ʀ�Ƥ����������ɤW 0 
    cout << fixed << setprecision(2) ;
    
    // �C�L r �C (row)
    for ( j = 1 ; j <= r ; ++j , x += dx ) {

        // �C�L�e c-1 �� (column)
        for ( i = 0 ; i < c-1 ; ++i ) 
            cout << setw(6) << x+(r*i)*dx << setw(7) << fn(x+(r*i)*dx) 
                 << setw(4) << " " ;

        // �C�L�̫�@��
        if ( j <= s ) cout << setw(6) << x+(r*(c-1))*dx 
                           << setw(7) << fn(x+(r*(c-1))*dx) ;

        cout << endl ;

    }
}

int main() {

    // �C�L  x*x �b [0,1] ���ƭ�, �H�w�w�� 20 ��������, �� 3 ��C�L
    cout << "> X*X : " << endl ;
    print_function( square , 0 , 1 ) ;
    cout << endl ;
    
    // �C�L (x-1)(x-1) �b [0,3] ���ƭ�, �H 30 ��������, �B 4 ��C�L
    cout << "> (X-1)(X-1) : " << endl ;
    print_function( f , 0 , 3 , 30 , 4 ) ;
    
    return 0 ;
    
}

