#include <iostream>
#include <complex>    
#include <cmath>      
#include <fstream>

using namespace std ;

// ��ƨ禡     :  z^3 - 1
template <class T>  
T  f( const T& z ) {  return z * z * z - 1. ; }

// ��ƷL���禡 :  3 z^2 
template <class T>
T  df( const T& z ) { return  3. * z * z ;  }


// �ϥΤ��y�k�D��
template < class T >
T  find_root( T a ) {

    T       b ;
    double  dz ; 
    const double TOL  = 1.0e-10 ;

    do {
        b = a - f(a) / df(a) ;       // ���y���N����
        dz = abs(b-a) ;              // �p��s�­Ȯt�Z
        a = b ;                      // ��s�ƭ�
    } while ( dz > TOL ) ;
    
    return a ;

}


int main() {

    const double  TOL2 = 1.0e-7 ;
    const double  PI = 4. * atan(1) ;
    const int     N = 3 ;

    int     i , j , k ;
    double  x , y , dx , dy , norm ;
    double  n , a , b , c , d ;

    complex<double>  z , rt ;

    // F(z) = z^3 - 1 ���T�Ӯ�
    complex<double>  root[N] = { 
            complex<double>(1,0) , 
            complex<double>(cos(2.*PI/3),sin(2.*PI/3)) ,
            complex<double>(cos(4.*PI/3),sin(4.*PI/3)) } ;

    // �̾ڭ��N�k�����ĭ��x�s�_�l��m
    ofstream  rt1("rt1") , rt2("rt2") , rt3("rt3") ;
    
    // �_�l��m������d�� : (a,b) ���U���y��   (c,d) �k�W���y��
    a = b = -1 ;   
    c = d = 1 ;

    // ���������
    n = 100 ;                 

    // x �P y �����Z
    dx = (c-a)/n ;           
    dy = (d-b)/n ;           

    
    // �����d�򤺪��C���I���N
    for ( i = 0 ; i <= n ; ++i ) {
        for ( j = 0 ; j <= n ; ++j ) {

            // �p��_�l�I�y��
            x = a + i * dx ;
            y = b + j * dy ;
            
            // �ন�Ƽ��I
            z = complex<double>(x,y) ;

            // �H���y�k�D��
            rt = find_root(z) ;

            // �P�_�ƭȮڬ����@�Ӯ�
            for ( k = 0 ; k < N ; ++k ) {

                norm = abs(rt-root[k]) ;

                if ( norm <= TOL2 ) {
                    if ( k == 0 ) 
                        rt1 << x << "  " << y << "\n" ;
                    else if ( k == 1 ) 
                        rt2 << x << "  " << y << "\n" ;
                    else 
                        rt3 << x << "  " << y << "\n" ;
                    break ;
                }
            }

        }

    }

    return 0 ;
    
}
