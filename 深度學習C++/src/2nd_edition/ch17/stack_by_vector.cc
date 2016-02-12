#include <iostream>
#include <vector>
#include <cassert>

using  namespace  std ;

// ���|���O
template  <class  T> 
class  Stack {
    
  private :

    vector<T>   data  ;  // �����}�C

  public :

    void pop() ;                               // �q���|�����X����
    void push( const T& item ) ;               // �N������J���|��
    T    top() const { return  data.back() ; } // �i���̤W�@�Ӥ���
    int  size() const { return data.size() ; } // �i�����|�����j�p
        
    template <class S> 
    friend  ostream&  operator << ( ostream&  , const Stack<S>& ) ;
    
} ;

// �q���|�����X����
template <class T>
void  Stack<T>::pop() {
    assert( data.size() > 0 ) ;
    data.pop_back() ;
}

// �N������J���|��
template <class T>
void  Stack<T>::push( const T& item ) { data.push_back(item) ; }
    
// �C�L���|����
template <class T>
ostream&  operator << ( ostream& out , const Stack<T>& foo ) {

    out << "> ���|�@�� " << foo.size() << " �Ӥ���" << endl ;
    out << "  ���� [ "  ;
    for ( int i = foo.size()-1 ; i >=0 ; --i ) 
        out << foo.data[i] << ' ' ;
    
    return  out << "] ����" << endl ;

}

int main() {

    Stack<int>  foo ;
    
    // �[�J 1 , 2 , 3 , 8 �� ���|
    foo.push(1) ;  foo.push(2) ;  foo.push(3) ;  foo.push(8) ;
    cout << "> �̳��ݤ����� : " << foo.top() << endl ;
    cout << "> �����ӼƬ�   : " << foo.size() << endl << endl ;
    
    // ���X��Ӥ�����, �[�J 9 , 7 , 5 
    foo.pop() ;  foo.pop() ;  foo.push(9) ;  foo.push(7) ;  
    foo.push(5) ;
    cout << foo  ;

    return 0 ;
    
}

   
