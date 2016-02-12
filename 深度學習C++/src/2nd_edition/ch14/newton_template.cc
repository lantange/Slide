#include <iostream>
#include <complex>     // �ϥνƼƼҪO���O
#include <cmath>       // ���ѵ���Ȩ禡 abs(x)

using namespace std ;

// ��ƨ禡 : F(X) = X^3 - X^2 + X - 1
template <class T>
T  f( const T& x ) {  return x * x * x - x * x + x - 1. ; }

// ��ƷL���禡 : 3 X^2 - 2 X + 1
template <class T>
T  df( const T& x ) { return  3. * x * x - 2. * x + 1. ;  }

// �ϥΤ��y�k�D��
template < class T >
T  find_root( T x1 ) {

    const double TOL = 1.0e-7 ;

    T       x2 ;
    double  dx ; 

    do {
        x2 = x1 - f(x1) / df(x1) ;     // ���y���N����
        dx = abs(x2-x1) ;              // �p��s�­Ȯt�Z
        x1 = x2 ;                      // ��s�ƭ�
    } while ( dx > TOL ) ;
    
    return x2 ;

}

int main() {

    double  x ;
    cout << "> ��J��ư_�l�� : " ;
    cin >> x ;
    cout << "> ��Ʈڬ� : " << find_root(x) << endl ;

    double  re , im ;
    cout << "> ��J�Ƽư_�l�� : " ;
    cin >> re >> im ;

    // �w�q��ƻP��Ƴ����Ҭ�����T�ׯB�I�ƪ��Ƽƪ���
    complex<double> c(re,im) ;
    cout << "> �ƼƮڬ� : " << find_root(c) << endl ;

    return 0 ;
    
}

