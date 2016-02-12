#include <iostream>
#include <set>

using  namespace  std ;

template <class T>
class  Set {

  private :

    set<T>  data ;
    
  public :
 
    // ��ثغc�禡
    Set() {}

    Set( const T a[] , int s ) {
        for ( int i = 0 ; i < s ; ++i ) data.insert(a[i]) ;
    }

    // ���X�����Ӽ�
    inline  int  size() const { return data.size() ; }

    // �[�J����
    inline  void  insert( const T& a ) { data.insert(a) ; }

    // �h������, �^�ǥh�����Ӽ�
    inline  int  erase( const T& a ) { return  data.erase(a) ; }
    
    // �涰
    template <class S>
    friend  Set<S>  operator * ( const Set<S>& a , 
                                 const Set<S>& b ) ;

    // �p��
    template <class S>
    friend  Set<S>  operator + ( const Set<S>& a , 
                                 const Set<S>& b ) ;

    // �t�� : a ���X�h�����P b ���X�ۦP������
    template <class S>
    friend  Set<S>  operator - ( const Set<S>& a , 
                                 const Set<S>& b ) ;
    
    // �C�L
    template <class S>
    friend  ostream&  operator<< ( ostream& out , 
                                   const Set<S>& foo ) ;
    
};

// �涰
template <class S>
Set<S>  operator * ( const Set<S>& a , const Set<S>& b ) {

    Set<S>                      foo  ;
    typename  set<S>::iterator  iter ;   // �o�̶��n typename

    for ( iter = a.data.begin() ; iter != a.data.end() ; ++iter ) {
        if ( b.data.count(*iter) ) foo.insert(*iter) ;
    }
    return  foo ;

}

// �p��
template <class S>
Set<S>  operator + ( const Set<S>& a , const Set<S>& b ) {

    Set<S>  foo(a) ;
    foo.data.insert(b.data.begin(),b.data.end()) ;
    return  foo ;

}

// �t��
template <class S>
Set<S>  operator - ( const Set<S>& a , const Set<S>& b ) {

    Set<S>                      foo(a) ;
    typename  set<S>::iterator  iter   ;    // �o�̶��n typename

    for ( iter = a.data.begin() ; iter != a.data.end() ; ++iter ) {
        if ( b.data.count(*iter) ) foo.erase(*iter) ;
    }
    return  foo ;
    
}

// �C�L
template <class S>
ostream&  operator<< ( ostream& out , const Set<S>& foo ) {
    
    // �o�̶��n typename
    typename  set<S>::const_iterator  iter ;  

    out << "{  " ;
    for ( iter = foo.data.begin() ; iter != foo.data.end() ; 
          ++iter ) out << *iter << "  " ;
    return  out << "}" ;

}

int main() {
    
    int  a[10] = { 3 , 2 , 2 , 3 , 7 , 3 , 2 , 9 , 8 , 5 } ;
    int  b[10] = { 1 , 2 , 6 , 2 , 5 , 5 , 7 , 3 , 4 , 1 } ;
    
    Set<int>  m(a,10) , n(b,10) ;
    
    cout << "> m = " << m << '\n' 
         << "> n = " << n << endl ;

    cout << "m * n = " << m * n << endl ;
    cout << "m + n = " << m + n << endl ;
    cout << "m - n = " << m - n << endl ;

    cout << endl ;
    
    char  c[8]  = { 's' , 't' , 'a' , 'r' , 't' , 'r' , 'e' , 'k' };
    char  d[10] = { 'e' , 'n' , 't' , 'e' , 'r' , 'p' , 'r' , 'i' , 
                    's' , 'e' };

    Set<char>  s(c,8) , t(d,10) ;

    cout << "> s = " << s << '\n' 
         << "> t = " << t << endl ;

    cout << "s * t = " << s * t << endl ;
    cout << "s + t = " << s + t << endl ;
    cout << "s - t = " << s - t << endl ;

    cout << endl ;
    
    return 0 ;
    
}

            
        
