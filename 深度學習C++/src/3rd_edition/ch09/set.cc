#include <iostream>

using namespace std ;

// �w�q���X�̦h���x�s�h�֤���
const  int  SIZE = 10 ;

// �]�w�O�_���X�����}�C���x�s���A
enum   Status  { empty , occupied } ;

// �w�q���X��´��ƫ��O
struct  Set {
    int     element[SIZE] ;    // �x�s���X����
    Status  status[SIZE]  ;    // �C�Ӷ��X��m�����A
    int     element_no    ;    // ���X�������Ӽ�
} ;

// ���X��ȳ]�w
void  set_initialization( Set&  set ) ;

// �[�J�����ܶ��X
bool  insert_element( Set& set , int data ) ;

// �R�����X����
int  delete_element( Set& set , int data ) ;

// �C�L���X
void  print_set( const Set& set ) ;

// �D�禡
int  main() {
    
    // �w�q���X�ܼ�
    Set   myset ;  
    
    // �]�w���X�ܼƪ��
    set_initialization( myset ) ;  

    // �[�J����
    insert_element( myset , 3 ) ; insert_element( myset , 5 ) ;
    insert_element( myset , 1 ) ; insert_element( myset , 4 ) ;
    insert_element( myset , 1 ) ; insert_element( myset , 7 ) ;
    insert_element( myset , 1 ) ; insert_element( myset , 5 ) ;
    print_set( myset ) ;

    // �R������
    delete_element( myset , 1 ) ;  delete_element( myset , 3 ) ;
    print_set( myset ) ;

    return 0 ;
}


// ���X��ȳ]�w
void  set_initialization( Set&  set ) {
    for ( int i = 0 ; i < SIZE ; ++i ) set.status[i] = empty ;
    set.element_no = 0 ;
}

// �[�J�����ܶ��X
bool  insert_element( Set& set , int data ) { 

    // �Y���X�w���F, �h�T��[�J���󤸯�
    if ( set.element_no == SIZE ) return false ;

    // �M��Ĥ@�Ӫŵ۪�����
    for ( int i = 0 ; i < SIZE ; ++i ) {
        if ( set.status[i] == empty ) {
            set.element[i] = data ;
            set.status[i] = occupied ;
            ++set.element_no ;
            return  true ;
        }
    }
}

// �R�����X����
int  delete_element( Set& set , int data ) {

    // �w�q�ܼƪ�ܬO�_�������Q�h��
    int  no_element_deleted = 0 ;

    for ( int i = 0 ; i < SIZE ; ++i ) {
        // ��춰�X����, �P�ɨ�ȻP�h���������ۦP
        if ( set.status[i]  == occupied  &&  
             set.element[i] == data ) {
            set.status[i] = empty ;
            --set.element_no ;
            ++no_element_deleted ;
        }
    }
    return  no_element_deleted ;
}

// �C�L���X
void  print_set( const Set& set ) {

    cout << "���X�� " << set.element_no << " ���� : " ;
    for ( int i = 0 ; i < SIZE ; ++i ) {
        if ( set.status[i] == occupied )
            cout << set.element[i] << ' ' ;
    }
    cout << endl ;

}
