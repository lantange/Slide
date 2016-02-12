#include <iostream>

using namespace std ;

// �w�q���X�̦h���x�s�h�֤���
const  int  SIZE = 10 ;

// �]�w�O�_���X�����}�C���x�s���A
enum   Status  { empty , occupied } ;

// �w�q���X��´��ƫ��O
class  Set {
  private :
    int     element[SIZE] ;    // �x�s���X����
    Status  status[SIZE]  ;    // �C�Ӷ��X��m�����A
    int     element_no    ;    // ���X�������Ӽ�
  public :
    // ���X��ȳ]�w
    void  initialization( void ) {
        for ( int i = 0 ; i < SIZE ; ++i ) status[i] = empty ;
        element_no = 0 ;
    }

    // �[�J�����ܶ��X
    bool  insert_element( int data ) ;
    
    // �R�����X����
    int  delete_element( int data ) ;

    // �C�L���X
    void  print_set( void ) ;
    
} ;


// �D�禡
int  main() {
    
    // �w�q���X�ܼ�
    Set   myset ;  
    
    // �]�w���X�ܼƪ��
    myset.initialization() ;  

    // �[�J����
    myset.insert_element(3) ;  myset.insert_element(5) ;
    myset.insert_element(1) ;  myset.insert_element(4) ;
    myset.insert_element(1) ;  myset.insert_element(7) ;
    myset.insert_element(1) ;  myset.insert_element(5) ;
    myset.print_set() ;

    // �R������
    myset.delete_element(1) ;  myset.delete_element(3) ;
    myset.print_set() ;

    return 0 ;
    
}

// �[�J�����ܶ��X
bool  Set::insert_element( int data ) { 

    // �Y���X�w���F, �h�T��[�J���󤸯�
    if ( element_no == SIZE ) return false ;

    // �M��Ĥ@�Ӫŵ۪�����
    for ( int i = 0 ; i < SIZE ; ++i ) {
        if ( status[i] == empty ) {
            element[i] = data ;
            status[i] = occupied ;
            ++element_no ;
            return  true ;
        }
    }
}

// �R�����X����
int  Set::delete_element( int data ) {

    // �w�q�ܼƪ�ܬO�_�������Q�h��
    int  no_element_deleted = 0 ;

    for ( int i = 0 ; i < SIZE ; ++i ) {
        // ��춰�X����, �P�ɨ�ȻP�h���������ۦP
        if ( status[i] == occupied  &&  element[i] == data ) {
            status[i] = empty ;
            --element_no ;
            ++no_element_deleted ;
        }
    }
    return  no_element_deleted ;
}

// �C�L���X
void  Set::print_set( void ) {

    cout << "���X�� " << element_no << " ���� : " ;
    for ( int i = 0 ; i < SIZE ; ++i ) {
        if ( status[i] == occupied )
            cout << element[i] << ' ' ;
    }
    cout << endl ;
}
