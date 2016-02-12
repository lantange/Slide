#include <iostream>
#include <cassert>

using namespace std ;

class  Vector {

  private :
    int  *data ;  // �V�q����
    int   size ;  // �V�q�����Ӽ�

  public :
    // ���w�غc�禡
    Vector() : data(NULL) , size(0) {};

    // �غc�禡
    Vector( unsigned int s , int v = 0 ) ;

    // �ƻs�غc�禡
    Vector( const Vector& foo ) ;

    // ���w�B��l
    Vector&  operator = ( const Vector& foo ) ;

    // �Ѻc�禡
    ~Vector() {  delete [] data ;  }

    // �V�q����
    int  length() const { return size ;  }
        
    // �U�Ш禡
    int&        operator [] ( int i )       { return data[i] ; }
    const int&  operator [] ( int i ) const { return data[i] ; }

    // ��J�B��l
    friend istream& operator >> ( istream& in  , Vector& foo ) ;

    // ��X�B��l
    friend ostream& operator << ( ostream& out , 
                                  const Vector& foo ) ;
    
};

// �غc�禡 : �Яd�N v ��Ʀb�����g�w�]��
Vector::Vector( unsigned int s , int v ) : size(s) {
    data = new int[size] ;
    for ( int i = 0 ; i < size ; ++i ) data[i] = v ;
}

// �ƻs�غc�禡
Vector::Vector( const Vector& foo ) : size(foo.size) {
    data = new int[size] ;
    for ( int i = 0 ; i < size ; ++i ) data[i] = foo.data[i] ;
}

// ���w�B��l
Vector&  Vector::operator=( const Vector& foo ) {
    if ( this == &foo ) return  *this ;
    if ( foo.size != size ) { 
        delete [] data ; 
        size = foo.size ; 
        data = new int[size] ;
    }
    for ( int i = 0 ; i < size ; ++i ) data[i] = foo.data[i] ;
    return  *this ;
}

// �[�k
Vector  operator+( const Vector& foo , const Vector& bar ) {
    Vector  tmp(foo.length()) ;
    for ( int i = 0 ; i < tmp.length() ; ++i ) 
        tmp[i] = foo[i] + bar[i] ;
    return tmp ;
}

// ���n
int  operator*( const Vector& foo , const Vector& bar ) {
    int  sum = 0 ;
    for ( int i = 0 ; i < foo.length() ; ++i ) 
        sum += foo[i] * bar[i] ;
    return sum ;
}

// ��J�B��l
istream&  operator>> ( istream& in , Vector &foo ) {
    for ( int i = 0 ; i < foo.size ; ++i ) in >> foo[i] ;
    return  in ;
}

// ��X�B��l
ostream&  operator<< ( ostream& out , const Vector &foo ) {
    out << '(' << ' ' ;
    for ( int i = 0 ; i < foo.size ; ++i ) out << foo[i] << ' ' ;
    out << ')' ;
    return  out ;
}

int  main() {
    
    // �غc�禡
    Vector  a(3,1) , b(3,4) , c(3) ;
    
    // ��X�B��l
    cout << "> a = " << a << " , b = " << b << endl ;
    
    // �[�k �P ���n
    cout << ">  a + b = " << a + b << " ,"
         << "  a * b = " << a * b << endl << endl ;

    // �V�q��J�B��l
    cout << "> ��J 3 ����Ƹ�� : " ;
    cin  >> c ;
    cout << "> c = " << c << endl << endl ;

    // �ƻs�غc�禡
    Vector  d(c) ;
    cout << "> d(c)  ==>  d = " << d << endl ;

    // �[�k�P���w�禡
    d = a + b + c ;
    cout << "> d = a + b + c  ==>  d = " << d << endl << endl ;

    // �V�q�}�C
    Vector  foo[3] ;    // �I�s���w�غc�禡

    foo[0] = a ;    foo[1] = b ;    foo[2] = c ;
    
    int  i ;
    cout << "> " ;
    for ( i = 0 ; i < 3 ; ++i ) 
        cout << "[" << i << "] = " << foo[i] << "  " ;

    // �N foo[2] ���C�Ӥ����[�W foo[1] ���⭿
    for ( i = 0 ; i < 3 ; ++i ) foo[2][i] += 2 * foo[1][i] ;
    
    cout << "\n> foo[2][i] += 2 * foo[1][i]  ==>  foo[2] = " 
         << foo[2] << endl ;

    return 0 ;
    
}
