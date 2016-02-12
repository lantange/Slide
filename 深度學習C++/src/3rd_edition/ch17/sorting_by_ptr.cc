#include <iostream>
#include <iomanip>
#include <string>
#include <functional>           // ���� : less  greater
#include <algorithm>            // ���� : sort

using  namespace  std ;

// �w�q �m�W �~��  �ʧO ��ƫ��O
typedef  string    NAME ;
typedef  unsigned  AGE  ;
enum     GENDER    { female , male } ;

// �ǥ����O
class  Student {

  private :
    
    NAME    name   ;  // �m�W
    AGE     age    ;  // �~��
    GENDER  gender ;  // �ʧO
    
  public :

    Student( NAME n , AGE a ,GENDER g ) 
        : name(n) , age(a) , gender(g) {}
    
    AGE     get_age()    const {  return age ;    }

    friend  ostream& operator << ( ostream& out , 
                                   const Student& foo ) ;

};

// ��X�ǥ͸��
ostream& operator << ( ostream& out , const Student& foo ) {
    return  out << "�m�W : " << setw(6) << foo.name.c_str() 
                << " [" << ( foo.gender == female ? 'F' : 'M' ) 
                << "]"  << setw(5) << " �~�� : " << foo.age  ;
}

// �禡���O : ����~�� (������˪O���O�ѼƤ��w�� less<AGE>)
template <class  Compare = less<AGE> >
struct  by_age {
    bool operator() ( const Student* a , const Student* b ) const {
        return  Compare()( a->get_age() , b->get_age() ) ;
    }
};

int  main() {

    int i ;
    const  int  Student_No = 5 ;
    
    // �ǥͰ}�C
    Student  foo[Student_No] = { 
        Student("John" ,13,male) , Student("Mary" ,10,female) ,
        Student("Tony" ,17,male) , Student("Amy"  ,10,female) ,
        Student("Grace",18,female) } ;

    // ���а}�C
    Student  *ptrs[Student_No] ;
    for ( i = 0 ; i < Student_No ; ++i ) ptrs[i] = &foo[i] ;

    // �ϥΫ��бƧ�
    cout << "> �̦~�ֱƧ� [�j->�p] " << endl ;
    sort( ptrs , ptrs+Student_No , by_age< greater<AGE> >() ) ;
    for ( i = 0 ; i < Student_No ; ++i ) cout << *ptrs[i] << '\n' ;
    cout << endl ;

    cout << "> ��l�}�C���� " << endl ;
    for ( i = 0 ; i < Student_No ; ++i ) cout << foo[i] << '\n' ;
    cout << endl ;

    return 0 ;
    
}
