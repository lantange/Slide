#include <iostream>
#include <sstream>
#include <iomanip>
#include <vector>

using namespace std ;


// �������O
class  Fraction {
  private :

    // ���l �P ����
    int  num , den ;

    // �p��̤j���]��
    int  gcd( int a , int b ) const {
        if ( a >= b ) 
            return ( a % b == 0 ? b : gcd(b,a%b) ) ;
        else 
            return ( b % a == 0 ? a : gcd(a,b%a) ) ;
    }

    
  public :

    // (1) �������غc�禡
    Fraction( int n = 0 , int d = 1 ) : num(n) , den(d) {
        if ( num != 0 ) {
            int g = gcd(num,den) ;
            num /= g ;
            den /= g ;
        }
    }

    // (2) ���������غc�禡
    Fraction( int n , int d , int j ) : num(n) , den(d) {}

    // �^�Ǥ��l
    int  get_num() const { return  num ; }

    // �^�Ǥ���
    int  get_den() const { return  den ; }
    
    // �^�ǭ˼�
    Fraction  inverse() const { return  Fraction(den,num) ; }

    // �p��s���ƪ�ܼƦC
    vector<int>  continued_fraction_list() const {

        vector<int>  no ;

        Fraction  foo = *this ;


        do  {
            no.push_back( foo.num/foo.den ) ;
            foo = foo - no.back() ;
            foo = foo.inverse() ;
        } while ( foo.den != 1 ) ;
        
        no.push_back( foo.num ) ;
        
        return  no ;
    }

    // �p��Ҧ�������Ƥ���
    vector<Fraction>  generate_convergents() const {
        
        vector<int>       no = continued_fraction_list() ;
        vector<Fraction>  flist(no.size()) ;

        int       i , j ;
        Fraction  sum ;

        flist.front() = Fraction(no[0]) ;
        
        for ( i = 1 ; i < no.size()-1 ; ++i ) {
            sum = Fraction(no[i])  ;
            for ( j = i ; j > 0 ; --j ) 
                sum = no[j-1] + sum.inverse() ;
            flist[i] = sum ;
        }
        
        flist.back() = *this ;
        
        return  flist ;
        
    }

    // �٦�禡�G��X�B��l
    friend  ostream& operator<< ( ostream& out , 
                                  const Fraction& foo ) {
        ostringstream  ostr ;
        if ( foo.num == 0 ) 
            ostr << "0" ;
        else 
            ostr << foo.num << "/" << foo.den ;
        
        return  out << ostr.str() ;
    }

    // �٦�禡�G�[�k�B��l
    friend  Fraction  operator+( const Fraction& a , 
                                 const Fraction& b ) {
        return  Fraction(a.num*b.den+a.den*b.num,a.den*b.den) ;
    }

    // �٦�禡�G��k�B��l
    friend  Fraction  operator-( const Fraction& a , 
                                 const Fraction& b ) {
        return  Fraction(a.num*b.den-a.den*b.num,a.den*b.den) ;
    }


};

int main() {
    
    int  i ;
    
    const int MDAYS = 295306 ;
    const int YDAYS = 3652422 ;
    const int SCALE = 10000 ;

    Fraction   foo(YDAYS,MDAYS,0) ;

    vector<int>  no = foo.continued_fraction_list() ;
    vector<Fraction>  cno = foo.generate_convergents() ;

    cout << "> " << foo << " = [" ;
    for ( i = 0 ; i < no.size()-1 ; ++i ) 
        cout << no[i] << ( i == 0 ? ";" : "," ) ;
    cout << no.back() << "] ��������� : \n" ;

    for ( i = 0 ; i < cno.size() ; ++i ) {
        cout << "[" << setw(2) << i+1 << "] " 
             << setw(14) << cno[i] << "    " ;
        if ( (i+1)%3 == 0 ) cout << endl ;
    }
    cout << "\n\n" ;


    int  M , Y ;
    double         min ;
    
    cout << "> ������ƩҲ��ͪ��|��� : \n" ;
    for ( i = 0 ; i < cno.size() ; ++i ) {
        M = cno[i].get_num() ;
        Y = cno[i].get_den() ;
        min = ( 1. * MDAYS * M - 1. * YDAYS * Y )*1440/SCALE/Y ;
        
        cout << "[" << setw(2) << i+1 << "] �C " 
             << setw(6) <<  Y << " �~ " << setw(6) << M - 12 * Y
             << " �Ӷ|��A���䥭���C�~�񶧾�"
             << ( min > 0 ? "�h" : "��") 
             << setprecision(6) << fixed << setw(13) 
             << ( min >= 0 ? min : -min ) << " ����\n" ;
    }

    return 0 ;
    
}

