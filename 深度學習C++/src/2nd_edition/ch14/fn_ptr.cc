#include <iostream>
#include <iomanip>

using namespace std ;

// ����禡
template <class T>
T square( const T& i ) {  return ( i * i  ) ;  }

// �ߤ�禡
template <class T>
T cubic( const T& i ) {  return ( i * i * i ) ; }

// �����禡
int factorial( int n ) {
    int  p = 1 ;
    for ( int i = 2 ; i <= n ; i++ )  p *= i ;
    return  p ;
}

// �ܸ�
template <class T>
T  negative( const T& i ) { return  -i ; }

// �ƻs�}�C : �N a �}�C���e S �Ӥ����ƻs�� b �}�C
template <class T>
void  copy_array( const T a[] , T  b[] , int S ) {
    for ( int i = 0 ; i < S ; ++i ) b[i] = a[i] ;
}

// �ഫ�禡
template <class Function , class T>
void  transform ( Function f , T foo[] , int size ) { 
    for ( int i = 0 ; i < size ; ++i )  foo[i] = f( foo[i] ) ;
}

// �C�L�}�C : 
template <class T>
void  print_array( T array[] , int size , char *header = "" ) {
    cout << setw(8) << header << " :" ;
    for ( int i = 0 ; i < size ; ++i ) cout << setw(5) << array[i] ;
    cout << endl ;
}

int  main() {
    
    const int     S = 5 ;
    int        a[S] = { 1 , 2 , 3 , 4 , 5 } , b[S] ;

    print_array( a , S ,"��l�}�C" ) ;

    // ���� b �}�C���C�Ӥ���
    copy_array( a , b , S ) ;
    transform( square<int> , b , S ) ;
    print_array( b , S ,"����" ) ;

    // �ߤ� b �}�C���C�Ӥ���
    copy_array( a , b , S ) ;
    transform( cubic<int> , b , S ) ;
    print_array( b , S , "�ߤ�" ) ;

    // �N b �}�C�C�Ӥ����ܴ����t��
    copy_array( a , b , S ) ;
    transform( negative<int> , b , S ) ;
    print_array( b , S , "�ܸ�" ) ;

    // �N b �}�C���C�Ӥ����ﴫ���䶥����
    copy_array( a , b , S ) ;
    transform( factorial , b , S ) ;
    print_array( b , S , "����" ) ;

    return 0 ;
    
}

