#include <iostream>
#include <cassert>

using namespace std ;

// �����
int abs( int a ) { return a > 0 ? a : -a ;  }
    
class  Fraction {

  private :

    // ���l�P����  ( ���� > 0 )
    int  num , den ;  

    // �̤j���]��
    int  gcd( int a , int b ) const {
        assert( a > 0 && b > 0 ) ;
        if ( a > b ) 
            return  ( a % b == 0 ? b : gcd( b , a % b ) ) ; 
        else 
            return  ( b % a == 0 ? a : gcd( a , b % a ) ) ; 
    }

  public :

    // ���w�غc�禡
    Fraction() {};

    // �غc�禡 : ����������s
    Fraction( int n , int d = 1 ) : num(n) , den(d) {
        assert( d != 0 ) ;
        if ( den < 0 ) { num *= -1 ; den *= -1 ; }
    }
    
    // �a���ƫغc�禡 : ���l�j�󵥩�s, �����j��s
    Fraction( int a , int n , int d ) : den(d) {
        assert( d > 0 && n >= 0 ) ;
        num = ( a > 0 ? a * d + n : a * d - n ) ;
    }

    // �e�X���l�P����
    int  get_den() const { return den ; }
    int  get_num() const { return num ; }

    // �����禡 : �t��
    Fraction  operator-() {  return  Fraction(-num,den) ; }

    // �����禡 : += , -= , *= , /=
    Fraction& operator+= ( const Fraction& a ) ;
    Fraction& operator-= ( const Fraction& a ) ;
    Fraction& operator*= ( const Fraction& a ) ;
    Fraction& operator/= ( const Fraction& a ) ;

    // ��J�B��l  : ���� ���l / ���� ����
    friend istream& operator >> ( istream& in , Fraction& foo ) {
        char  slash ;
        in >> foo.num >> slash  >> foo.den ;
        if ( foo.den < 0 ) { foo.num *= -1 ;  foo.den *= -1 ; }
        return in ;
    }
    
    // ��X�B��l  : ��X���������
    friend ostream& operator << ( ostream& out , 
                                  const Fraction& foo ) {
        int  num = ( foo.num > 0 ? foo.num : -foo.num ) ;
        int  den = foo.den ;
        int  divisor = ( num == 0 ? 1 : foo.gcd(num,den) ) ;
        return  out << foo.num/divisor << "/" << den/divisor ;
    }
    
} ;

// ����禡 + 
Fraction  operator+ ( const Fraction& a , const Fraction& b ) {
    return  
      Fraction( a.get_num()*b.get_den() + a.get_den()*b.get_num() ,
                a.get_den()*b.get_den() ) ;
}

// ����禡 - 
Fraction  operator- ( const Fraction& a , const Fraction& b ) {
    return  
      Fraction( a.get_num()*b.get_den() - a.get_den()*b.get_num() ,
                a.get_den()*b.get_den() ) ;
}

// ����禡 * 
Fraction  operator* ( const Fraction& a , const Fraction& b ) {
    return  Fraction( a.get_num() * b.get_num() , 
                      a.get_den() * b.get_den() ) ;
}

// ����禡 /
Fraction  operator/ ( const Fraction& a , const Fraction& b ) {
    return  Fraction( a.get_num() * b.get_den() , 
                      a.get_den() * b.get_num() ) ;
}

// �����禡 += : �i�H�Q�Τw���� operator +
Fraction&  Fraction::operator+= ( const Fraction& a ) { 
    return *this = *this + a ; 
}

// �����禡 -= : �i�H�Q�Τw���� operator -
Fraction&  Fraction::operator-= ( const Fraction& a ) { 
    return *this = *this - a ; 
}

// �����禡 *= : �Ϊ̦ۦ�]�p
Fraction&  Fraction::operator*= ( const Fraction& a ) { 
    num = num * a.num ;  den = den * a.den ;  
    return *this ;
}

// �����禡 /= : �Ϊ̦ۦ�]�p
Fraction&  Fraction::operator/= ( const Fraction& a ) { 
    num = num * a.den ;  den = den * a.num ;  
    if ( den < 0 ) { num *= -1 ; den *= -1 ; }
    return *this ;
}

// ����禡 : �e�m���W
Fraction&  operator++( Fraction& a ) {
    return  a += 1 ;
}

// ����禡 : �p��
bool  operator< ( const Fraction& a , const Fraction& b ) { 
    return  a.get_num()*b.get_den() < b.get_num()*a.get_den() ;
}
        
int main() {
        
    Fraction  a(2,3) , b(-1,3,2) , c(10,-6) ;
    
    cout << "> a = " << a << " , b = " << b 
         << " , c = " << c << endl ;

    cout << "> 2 + a * -b - c * b / 2 = " 
         << 2 + a * -b - c * b / 2 << "\n\n" ;

    a += b -= c + 2 ;
    cout << "> a += b -= c + 2 : " << '\n' 
         << "  a = " << a << " , b = " << b 
         << " , c = " << c << "\n\n" ;

    for ( Fraction d(0,1) ; d < 5 ; ++d ) cout << d << " " ;
    cout << "\n\n" ;
    
    cout << "> ��J ���l/���� �Φ� : " ;
    cin >> a ;
    cout << "> ��X : " << a << endl ;

    return 0 ;
    
}

