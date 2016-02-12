#include <iostream>
#include <cmath>
#include <numeric>

using namespace std ;

// ���[���B��Ϊ̬O�����[�B��, �w�]�����[���B��
template <class T>
struct  plus_minus {
    int  sign ;
    plus_minus( int s = 1 ) : sign(s) {}
    T  operator() ( const T& a , const T& b ) {
        T  sum = ( sign > 0 ? ( a + b ) : ( a - b ) ) ;
        sign *= -1 ;
        return  sum ;
    }
};

// �����[�B��
template <class T>
T  minus_plus( const T& a , const T& b ) {
    static int sign = 1 ;
    T  sum = ( sign > 0 ? a + b : a - b ) ;
    sign *= -1 ;
    return  sum ;
}

int main() {

    int a[5] = { 2 , 2 , 1 , 1 , 1 };
    int b[5] = { 1 , 2 , 0 , 1 , 2 };
    
    // �p��  0 + a[0]b[0] + a[1]b[1] + ... + a[4]b[4] ����
    cout << inner_product(a,a+5,b,0) << endl ;

    // �p��  v + a[0]b[0] - a[1]b[1] + ... - a[4]b[4] ����
    int  v = 10 ;
    cout << inner_product(a,a+5,b,v,plus_minus<int>(),multiplies<int>()) 
         << endl ;
    
    // �p��  0 - a[0]b[0] + a[1]b[1] - ... + a[4]b[4] ����
    cout << inner_product(a,a+5,b,0,plus_minus<int>(-1),multiplies<int>())
         << endl ;
    
    // �p��  8 - a[0]b[0] + a[1]b[1] - ... + a[4]b[4] ����
    cout << inner_product(a,a+5,b,8,minus_plus<int>,multiplies<int>()) 
         << endl ;    

    // �p��  a �V�q������
    // sqrt( 0 + a[0]a[0] + a[1]a[1] + ... + a[4]a[4] )
    cout << sqrt(static_cast<double>(inner_product(a,a+5,a,0))) << endl ;

    return 0 ;
    
}
