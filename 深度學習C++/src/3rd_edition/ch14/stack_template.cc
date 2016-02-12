#include <iostream>
#include <cassert>

using namespace std ;

// ���|���O : ���|�������w�ӼƬ� 10 �� 
template  < class  T , int Stack_Size = 10 >
class  Stack {
    
  private :
    int  count ;             // ���|�w�x�s�����Ӽ�
    T    data[Stack_Size] ;  // �����}�C

  public :
    Stack<T,Stack_Size>() : count(0) {} ;
    
    T     pop() ;                  // �q���|�����X����
    bool  push( const T& item ) ;  // �N������J���|��
    
    template <class S, int size> 
    friend  ostream&  operator << ( ostream&  , 
                                    const Stack<S,size>& ) ;
    
} ;

// �q���|�����X����
template <class T, int Stack_Size>
T  Stack<T,Stack_Size>::pop() {
    assert( count > 0 ) ;
    return data[--count] ;
}

// �N������J���|��
template <class T, int Stack_Size>
bool Stack<T,Stack_Size>::push( const T& item ) {
    if ( count >= Stack_Size ) return false ;
    data[count++] = item ;
    return true ;
}
    
// �C�L���|����
template <class T, int Stack_Size>
ostream&  operator << ( ostream& out , 
                        const Stack<T,Stack_Size>& foo ) {

    out << "> The stack ( size = " << Stack_Size << " ) has " 
        << foo.count << " items" << endl ;
    out << "  top [ "  ;
    for ( int  i = foo.count-1 ; i >= 0 ; --i ) {
        out << foo.data[i] ;
        if ( i != 0 ) out << " , " ;
    }
    return  out << "  ] bottom" << endl ;

}

main() {

    // �w�q�i�H�x�s�T�Ӿ�ƪ����|
    Stack<int,3>  foo ;
    
    foo.push(1) ;   foo.push(2) ;   foo.push(3) ;   foo.push(4) ;
    foo.pop()   ;   foo.push(5) ;   foo.pop()   ;   foo.push(6) ;
    cout << foo << endl ;    

    // �w�q�i�H�x�s�Q�Ӧr�������|
    Stack<char>  bar ;

    bar.push('a') ;   bar.push('b') ;   bar.push('c') ;   
    bar.push('d') ;   bar.push('e') ;   bar.pop()     ;   
    bar.push('f') ;
    cout << bar << endl ;    

    // �w�q�i�H�x�s�Q�ӳ��T�ׯB�I�ƪ����|
    Stack<float>  fbar ;

    fbar.push(1.1) ;    fbar.push(2.2) ;    fbar.push(3.3) ;    
    fbar.pop()     ;    fbar.push(4.4) ;    fbar.pop()     ;    
    fbar.push(5.5) ;
    cout << fbar << endl ;    

    return 0 ;
    
}

   
