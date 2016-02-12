#include <iostream>
#include <iomanip>
#include <string>
#include <functional>
#include <algorithm>

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
    
    NAME    get_name()   const {  return name ;   }
    AGE     get_age()    const {  return age ;    }
    GENDER  get_gender() const {  return gender ; }

    friend  ostream& operator << ( ostream& out , 
                                   const Student& foo ) ;

};

// ��X�ǥ͸��
ostream& operator << ( ostream& out , const Student& foo ) {
    return  out << "�m�W : " << setw(6) << foo.name.c_str() 
                << " [" << ( foo.gender == female ? 'F' : 'M' )
                << "]"  << setw(5) << " �~�� : " << foo.age  ;
}

// �禡���O : ����W��  (������覡�]�w���˪O���O�Ѽ�)
template <class Compare>
struct  by_name {
    bool operator() ( const Student& a , const Student& b ) const {
        return  Compare()( a.get_name() , b.get_name() ) ;
    }
};

// �禡���O : ����~�� (������˪O���O�ѼƤ��w�� less<AGE>)
template <class  Compare = less<AGE> >
struct  by_age {
    bool operator() ( const Student& a , const Student& b ) const {
        return  Compare()( a.get_age() , b.get_age() ) ;
    }
};

// �˪O�禡 : ����ʧO  (������覡�]�w���˪O���O�Ѽ�)
template <class Compare>
bool  by_gender ( const Student& a , const Student& b ) {
    return  Compare()( a.get_gender() , b.get_gender() ) ;
}

// �禡���O : ������ʧO, �A����~��, �̫����m�W
template <class Compare_g , class Compare_a , class Compare_n>
struct  my_rule {
    bool operator() ( const Student& a , const Student& b ) const {
        if ( a.get_gender() == b.get_gender() ) {
            
            if ( a.get_age() ==  b.get_age() ) 
                return  Compare_n()( a.get_name() , b.get_name() ) ;
            else 
                return  Compare_a()( a.get_age() , b.get_age() ) ;

        } else 
            return Compare_g()( a.get_gender() , b.get_gender() ) ;
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

    cout << "> �̩m�W�Ƨ� [�p->�j] " << endl ;
    sort( foo , foo+Student_No , by_name< less<NAME> >() ) ;
    for ( i = 0 ; i < Student_No ; ++i )  cout << foo[i] << '\n' ;
    cout << endl ;

    cout << "> �̦~�ֱƧ� (�ϥΤ��w�ƧǤ覡[�p->�j]) " << endl ;
    sort( foo , foo+Student_No , by_age<>() ) ;
    for ( i = 0 ; i < Student_No ; ++i )  cout << foo[i] << '\n' ;
    cout << endl ;

    cout << "> �̩ʧO�Ƨ� [�j->�p] " << endl ;
    sort( foo , foo+Student_No , by_gender< greater<GENDER> > ) ;
    for ( i = 0 ; i < Student_No ; ++i )  cout << foo[i] << '\n' ;
    cout << endl ;

    cout << "> �̤U�C�覡���ǱƧ�\n"
         << "  (1) �ʧO [�p->�j] (2) �~�� [�j->�p] " 
         << "(3) �m�W [�p->�j]\n";    
    sort( foo , foo+Student_No ,
          my_rule< less<GENDER>, greater<AGE> , less<NAME> >() ) ;
    for ( i = 0 ; i < Student_No ; ++i )  cout << foo[i] << '\n' ;
    cout << endl ;

    return 0 ;
    
}
