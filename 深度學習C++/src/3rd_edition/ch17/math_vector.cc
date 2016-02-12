#include <iostream>
#include <sstream>
#include <vector>
#include <cassert>

using namespace std ;

template <class T>
class Vec {
    
  private :
    
    vector<T>  dat ;     // �ΦV�q�}�C�x�s�V�q������
    
  public :

    Vec() {}
    
    Vec( const vector<T>& foo ) : dat(foo) {}

    // �V�q�����Ӽ�
    int size() const { return dat.size() ; }

    // �U�йB��l
    T&          operator[] ( int i )       {  return dat[i] ; }
    const  T&   operator[] ( int i ) const {  return dat[i] ; }

    // �w�q += �B��l
    Vec&  operator-= ( const Vec& a ) {
        assert( dat.size() == a.size() ) ;
        for ( int i = 0 ; i < dat.size() ; ++i ) dat[i] -= a.dat[i] ;
        return  *this ;
    }

    // �w�q Vec �M�Ϊ���J�B��l
    template <class S>
    friend  istream&  operator>> ( istream& in , Vec<S>& foo ) {
        string  line ;
        getline( in , line ) ;
        istringstream  istr(line) ;
        S  tmp ;
        while ( istr >> tmp ) foo.dat.push_back(tmp) ;
        return  in ;
    }

};

// �w�q Vec �M�Ϊ���X�B��l
template <class S>
ostream&  operator<< ( ostream& out , const Vec<S>& foo ) {
    out << "( " ;
    for ( int i = 0 ; i < foo.size() ; ++i ) out << foo[i] << ' ' ;
    return  out << ")" ;
}

// �p���V�q���[�k
template <class T>
Vec<T>  operator+ ( const Vec<T>& a , const Vec<T>& b ) {
    assert( a.size() == b.size() ) ;

    // �w�q�@�V�q�}�C  ��N��V�q���󪺤����X����V�q�}�C��
    vector<T>  foo(a.size()) ;
    for ( int i = 0 ; i < foo.size() ; ++i ) foo[i] = a[i] + b[i] ;
    return  Vec<T>(foo) ;
}

// �p���V�q�����n�M
template <class T>
T  operator* ( const Vec<T>& a , const Vec<T>& b ) {
    assert( a.size() == b.size() ) ;
    T  sum = static_cast<T>(0.) ;
    for ( int i = 0 ; i < a.size() ; ++i ) sum += a[i] * b[i] ;
    return  sum ;
}
        
int  main() {
    
    Vec<int>  a , b ;
    cout << "> ���O��J��ӦV�q (�����ӼƬۦP) : \n" ;
    cout << "a = " ;    cin  >> a ;
    cout << "b = " ;    cin  >> b ;
    
    cout << "a + b  => " << a + b  << endl ;
    cout << "a * b  => " << a * b  << endl ;
    cout << "a -= b => " << (a -= b) << endl ;

    return 0 ;
    
}

        
    
