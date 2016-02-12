#include <iostream>
#include <cmath>
#include <functional>

using namespace std ;

// �w�q X ����, �ߤ�P Sin ���
struct  Square {
    double  operator()( double x ) const { return x * x ; }
};

template <typename T>
T  Cubic ( T x ) { return x * x * x ; }

template <typename T>
double Sin( T x ) { return sin(x) ; }


// �p���� fn �b [a,b] �϶����w�n��, 
// �n���H���ά� n �ӥ��������������έ��n�p��
//
template <typename Function>
double  integral( Function fn , double a , double b , 
                  int n = 1000000 ) {

    double  area = 0.  ;
    double  dx = ( b - a ) / n ;

    for ( int i = 0 ; i < n ; ++i ) area += fn(a+dx*i) ;
    
    return  dx * area ;
}


// �p���� fn �b [a,b] �϶��B��ƭȺ����Y�ӳ]�w���󪺩w�n��, 
// �n���H���ά� n �ӥ��������������έ��n�p��
//
template < typename Fn1 , typename Fn2 >
double  integral( Fn1 fn , double a , double b , 
                  const Fn2& fn2 , int n = 1000000 ) {

    double  area = 0. , tmp ;
    double  dx = ( b - a ) / n ;

    for ( int i = 0 ; i < n ; ++i ) {
        tmp = fn(a+dx*i) ;
        if ( fn2(tmp) ) area += tmp ;
    }
    
    return  dx * area ;
}

    
int main() {
    
    const double PI = 3.141592654 ;
    
    // �p�⥭���Ʀb [0,1] �϶����w�n��
    cout << "> �����Ʀb [0,1] �϶����w�n�� = "
         << integral( Square() , 0 , 1 ) << endl ;

    // �p�⥭���Ʀb [0,1] �B��ƭȶ��p�� 0.25 ���w�n��
    cout << "> �����Ʀb [0,1] �B��ƭȶ��p�� 0.25 ���w�n�� = " 
         << integral( Square() , 0 ,  1, 
                      bind2nd( less<double>() , 0.25 ) ) << endl ;

    // �p��ߤ��Ʀb [0,1] �϶����w�n��
    cout << "> �ߤ��Ʀb [0,1] �϶����w�n�� = "
         << integral( Cubic<double> , 0 , 1 ) << endl ;

    // �p�� sin ��Ʀb [0,PI] �϶����w�n��
    cout << "> sin(x) �b [0,PI] �϶����w�n�� = "
         << integral( Sin<double> , 0 , PI ) << endl ;

    // �p�� sin ��Ʀb [0,PI] �B sin(x) ���j��s���w�n��
    cout << "> sin(x) �b [0,PI] �B sin(x) ���j��s���w�n�� = " 
         << integral( Sin<double> , 0 , 2*PI , 
                      bind2nd( greater<double>() , 0. ) ) << endl ;

    return 0 ;

}
