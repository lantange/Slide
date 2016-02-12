#include <iostream>

using namespace std ;

// ���X�����x�s���A
enum  Status  { empty , occupied };

// ���X���O
class  Set {

  private :

    // Default_Size : �w�]�����X�̤p�i�x�s�������Ӽ� 
    // Inc_Size     : �C���W�[�������Ӽ�
    enum { Default_Size = 10 , Inc_Size = 20 } ;
    
    int     *element       ;    // ����
    Status  *status        ;    // �����x�s���A
    int     element_no     ;    // �w�x�s�������Ӽ�
    int     max_element_no ;    // �i�x�s�������Ӽ�

  public :
    
    // �w�]�غc�禡
    Set() : element_no(0) , max_element_no(Default_Size) {
        element = new int[Default_Size] ;
        status  = new Status[Default_Size] ;
        for ( int i = 0 ; i < Default_Size ; ++i ) 
            status[i] = empty ;
    }

    // �Ѻc�禡
    ~Set() {  delete [] element ;  delete [] status  ;   }
    
    // �ƻs�غc�禡
    Set( const Set& set ) ;
    
    // ���w�B��l : �o�̼ȥ��]�����^�ǥ�����
    void  operator=( const Set& set ) ;

    // �[�J����
    void  insert_element( int data ) ;
    
    // �R������
    int   delete_element( int data ) ;
    
    // �C�L����
    void  print_set() const ;
    
};

int  main() {
    
    // �ϥΤ��w�غc�禡
    Set  set1 ;

    // �x�s 20 �ӭӦ�Ƥ���
    for( int i = 0 ; i < 20 ; ++i ) set1.insert_element( i%10 ) ;
    set1.print_set() ;

    // ���սƻs�غc�禡
    Set  set2(set1) ;
    set2.print_set() ;

    // �W��X����
    set2.insert_element(5) ;  set2.insert_element(9) ;
    set2.delete_element(3) ;  set2.delete_element(0) ;
    set2.print_set() ;

    // ���ի��w�B��l
    set1 = set2 ;
    set1.print_set() ;

    return 0 ;
    
}

// �W�[����
void  Set::insert_element ( int data ) {

    int  i ;

    // �p�G�{���������ӼƤw�g���F, �h���t�M�Ŷ��x�s
    if ( element_no == max_element_no ) {

        int    *tmp_element = new    int[max_element_no+Inc_Size] ;
        Status *tmp_status  = new Status[max_element_no+Inc_Size] ;
        
        // �ƻs�{��������s���O�ЪŶ�
        for ( i = 0 ; i < max_element_no ; ++i ) {
            tmp_element[i] = element[i] ;
            tmp_status[i]  = status[i] ;
        }
        
        // �x�s�s����
        tmp_element[max_element_no] = data ;
        tmp_status[max_element_no]  = occupied ;

        for ( i = 1 ; i < Inc_Size ; ++i ) {
            tmp_status[max_element_no+i] = empty ;
        }
        
        // �����°O�ЪŶ�
        delete [] element ;    delete [] status  ;
        
        element = tmp_element ;
        status  = tmp_status  ;
        
        max_element_no += Inc_Size ;
        ++element_no ;
        
    } else {

        // �즳�Ŷ��w����, �����W�[�@�Ӥ���
        for ( i = 0 ; i < max_element_no ; ++i ) {
            if ( status[i] == empty ) {
                element[i] = data ;
                status[i]  = occupied ;
                ++element_no ;
                return ;
            }
        }
        
    }
    
}

// �R������
int  Set::delete_element( int data ) {

    // �w�q�ܼƪ�ܧR���������Ӽ�
    int  no_element_deleted = 0 ;

    for ( int i = 0 ; i < max_element_no ; ++i ) {

        // �M��줸����R��
        if ( status[i] == occupied  &&  element[i] == data ) {
            status[i] = empty ;
            --element_no ;
            ++no_element_deleted ;
        }

    }
    return  no_element_deleted ;
}

// �C�L����
void  Set::print_set( void ) const {

    cout << "���X�� " << element_no << " ���� : " ;

    for ( int i = 0 ; i < max_element_no ; ++i ) 
        if ( status[i] == occupied ) cout << element[i] << ' ' ;

    cout << endl ;

}

// �ƻs�غc�禡
Set::Set( const Set& set ) {

    element_no     = set.element_no ;
    max_element_no = set.max_element_no ;
        
    element = new int[max_element_no] ;
    status  = new Status[max_element_no] ;
        
    for ( int i = 0 ; i < max_element_no ; ++i ) {
        element[i] = set.element[i] ;
        status[i]  = set.status[i]  ;
    }

}

// ���w�B��l
void  Set::operator=( const Set& set ) {

    // �p�G�ұ��ƻs�����X���O���������{�����Ŷ��h, 
    // �h���n���s���t�Ŷ�, �_�h�Q�β{�����Ŷ��Y�i
    if( set.element_no > max_element_no ) {
        
        element_no     = set.element_no ;
        max_element_no = set.max_element_no ;
        
        int     *tmp_element = new int[max_element_no] ;
        Status  *tmp_status  = new Status[max_element_no] ;
        
        for ( int i = 0 ; i < max_element_no ; ++i ) {
            tmp_element[i] = set.element[i] ;
            tmp_status[i]  = set.status[i]  ;
        }

        // ����{�����O�ЪŶ�
        delete [] element ;        delete [] status ;

        // �ϥηs�O�ЪŶ�
        element = tmp_element ;
        status  = tmp_status ;

    } else {

        int i , c = 0 ;
        element_no  = set.element_no ;

        // ���s���t����
        for ( i = 0 ; i < set.max_element_no ; ++i ) {
            if ( set.status[i] == occupied ) {
                element[c] = set.element[i] ;
                status[c]  = occupied ;
                ++c ;
            }
        }

        for ( i = c ; i < max_element_no ; ++i )
            status[i] = empty ;

    }

}
