#include <iostream>

using  namespace  std ;

// �w�q�B�z���X������~���O
class  Set_Error {

  public :

    // �]�w��Ӷ��X�����~�������κA
    enum  error_type  { under_set , over_set } ;  

  private:

    // ���~����
    error_type  kind ;
 
  public :

    // �غc�禡
    Set_Error(error_type type) : kind(type) {} ;

    // ���C�L���~�T��
    friend  ostream& operator << ( ostream& out , 
                                   const Set_Error& err ) ;

};


// �w�q�ҪO���X���O
template < class T , int Set_Size = 5 >
class Set {

  private :

    int    count              ;  // �w�������X�����Ӽ�
    T      data[Set_Size]     ;  // �x�s�������}�C
    bool   occupied[Set_Size] ;  // �O�_�}�C���Y�Ӧ�m�w�x�s����

  public:

    // ���w�غc�禡
    Set() throw() : count(0) {
        for( int i = 0 ; i < Set_Size ; ++i ) occupied[i] = false ;
    }

    // ��������
    bool  remove( const T& item ) throw(Set_Error) ;

    // �[�J����
    bool  insert( const T& item ) throw(Set_Error) ;

    // �C�L���X�Ҧ�������
    template <class S, int size>
    friend  ostream&  operator << 
          ( ostream& out , const Set<S,size>& foo ) throw() ;

} ;

// �w�� Set_Error ���O���s�w�q��X�B��l
ostream&  operator << ( ostream& out , const Set_Error& err ) {
    
    if ( err.kind == Set_Error::under_set ) {
        out << "> ���X������~ : �L�k�Ѥ@�Ŷ��X����������" ;
    } else if ( err.kind == Set_Error::over_set ) {
        out << "> ���X������~ : ���X�Ŷ��w��, �L�k�[�J����" ;
    }
    return out ;
      
}

// �Ѷ��X���R������
template <class T , int Set_Size>
bool Set<T,Set_Size>::remove(const T& item) throw(Set_Error) {

    // ���X�w��, �Y�X���~����
    if ( count == 0 ) throw  Set_Error( Set_Error::under_set ) ;

    for ( int i = 0 ; i < Set_Size ; ++i ) {
        if ( occupied[i] && data[i] == item ) {
            occupied[i] = false ;
            --count ;
            return true ;
        }
    }

    // �p�G�S��줸��, �h�^�ǰ���
    return  false ;
    
}

// �[�J�����춰�X��
template <class T, int Set_Size>
bool Set<T,Set_Size>::insert( const T& item ) throw(Set_Error) {

    // ���X�w��, �Y�X���~����
    if ( count == Set_Size ) 
        throw Set_Error( Set_Error::over_set ) ;

    for ( int i = 0 ; i < Set_Size ; ++i ) {
        if ( ! occupied[i] ) {
            occupied[i] = true ;
            data[i] = item ;
            ++count ;
            return true ;
        }
    }

}

// �C�L���X 
template <class T, int Set_Size>
ostream& operator << ( ostream& out , 
                       const Set<T,Set_Size>& foo ) throw() {
 
    out << "> ���X [ �i�x�s�����Ӽ� = " << Set_Size 
        << " ] �@�� " << foo.count << " �Ӥ���\n" << " ( " ;

    if ( foo.count != 0 ) {

        bool first_item = true ;
        for ( int i = 0 ; i < Set_Size ; ++i ) {

            if ( ! foo.occupied[i] ) continue ;

            if ( first_item ) {
                out << foo.data[i] ;
                first_item = false ;
            } else 
                out << " , " << foo.data[i] ;

        }

    } 

    return  out << " )\n" ;

}

int main() {

    Set<int,20>  foo1 , foo2 ;
    Set<double>  foo3 , foo4 ;

    // ���� ��ƶ��X foo1, �i�H�x�s�� 20 �Ӥ���
    try {
        foo1.insert(6) ; foo1.insert(8) ; foo1.insert(7) ;
        foo1.remove(8) ; foo1.remove(6) ; foo1.remove(9) ;
        foo1.remove(7) ; foo1.remove(5) ;

        cout << "[���T] foo1 : \n" << foo1 << endl ;
    }

    catch ( const Set_Error& error ) {
        cout << "[���~] foo1 : \n" << error << "\n" << foo1 << endl ;
    }

    // ���� ��ƶ��X foo1, �i�H�x�s�� 20 �Ӥ���
    try {
        foo2.insert(1) ; foo2.insert(2) ; foo2.insert(3) ; 
        foo2.insert(9) ; foo2.remove(4) ; foo2.insert(5) ; 
        foo2.remove(3) ; foo2.insert(6) ; foo2.remove(4) ;

        cout << "[���T] foo2 : \n" << foo2<< endl ;
    }

    catch ( const Set_Error& error ) {
        cout << "[���~] foo2 : \n" << error << "\n" << foo2 << endl ;
    }

    // ���� ����ׯB�I�ƶ��X foo3, �i�H�x�s 5 �Ӥ���
    try {
        foo3.insert(1.1) ; foo3.insert(2.2) ; foo3.insert(3.3) ; 
        foo3.insert(4.4) ; foo3.insert(5.5) ; foo3.insert(6.6) ; 
        foo3.insert(7.7) ; foo3.insert(8.8) ; foo3.insert(9.9) ;

        cout << "[���T] foo3 : \n" << foo3 << endl ;
    }

    catch ( const Set_Error& error ) {
        cout << "[���~] foo3 : \n" << error << "\n" << foo3 << endl ;
    }

    // ���� ����ׯB�I�ƶ��X foo4, �i�H�x�s 5 �Ӥ���
    try {
        foo4.remove(1.9) ; 
        foo4.insert(1.1) ; foo4.insert(2.2) ; foo4.insert(3.3) ; 
        foo4.insert(4.4) ; foo4.insert(5.5) ; 

        cout << "[���T] foo4 : \n" << foo4 << endl ;
    }

    catch( const Set_Error& error ) {
        cout << "[���~] foo4 : \n" << error << "\n" << foo4 << endl ;
    }

    return 0 ;
    
}
