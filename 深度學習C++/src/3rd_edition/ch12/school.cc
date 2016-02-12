#include <iostream>
#include <iomanip>
#include <string>

using  namespace  std ;

const  int  MAX_CLASS  = 3  ;   // �Z�O�̤j�ƥ�
const  int  MAX_STUDENT = 10 ;  // �C�ӯZ�O�ǥͳ̤j�ƥ�

// �ǥ͸�Ƶ��c : �m�W�P�Ǹ�
struct  Student {
    string  name ;
    int     id   ;
};

// �и��ǥ͸�ƫ��O����J�B��l
istream&  operator>> ( istream& in  , Student& s ) {
    return  in >> s.name >> s.id ;
}

// �и���ƫ��O����X�B��l
ostream&  operator<< ( ostream& out , const Student& s ) {
    return  out << setw(6) << s.name.c_str() << " [" <<  s.id 
                << "]" ;
}

// �Z�O���O
class  Class {
  private :
    
    // �Z�O�����ǥͦW��P�H��
    Student   student[MAX_STUDENT] ;
    int       student_no ;
    
  public :
    
    // �غc�禡
    Class() : student_no(0) {}
    
    // �[�J�@�Ӿǥͨ�Z�O��
    bool  insert_student( const Student& s ) { 
        if ( student_no == MAX_STUDENT )
            return  false ;
        else {
            student[student_no++] = s ;  
            return  true ;
        }
    }

    // �Z�O�{�b���ǥͤH��
    int  current_student_no() const { return student_no ; }
    
    // �и��Z�O���O����X�B��l
    friend ostream& operator<< ( ostream& out , const Class& foo ){
        for ( int i = 0 ; i < foo.student_no ; ++i ) {
            out << i+1 << " : " << foo.student[i] << "\n" ;
        }
        return out ;
    }
    
};

// �ҵ{���O
class  Course {

  private :

    // �C�@�ҵ{���Z�O�}�C
    Class  classes[MAX_CLASS] ;

  public :

    // �[�J�@�Ӿǥ͹�Y�@�ӯZ�O
    bool  add_student( int c , const Student& s ) {
        if ( c < 1 || c > MAX_CLASS ) return false ;
        return ( classes[c-1].insert_student(s) ? true : false ) ; 
    }

    // �и��ҵ{����X�B��l
    friend  ostream&  operator<< ( ostream& out , 
                                   const Course& foo ) {

        int  total_student_no = 0 ;

        for ( int i = 0 ; i < MAX_CLASS ; ++i ) {
            total_student_no += foo.classes[i].current_student_no() ;
            out << "�� " << i+1 << " �Z" << " : \n"
                << left << foo.classes[i] << "\n" ;
        }
        out << "�`�׽ҤH�� : " << total_student_no << endl ;
        
        return out ;
    }

};


int  main() {

    Course   foo ;  // �ҵ{����
    int      c ;    // �Z�O
    Student  s ;    // �ǥ�

    // ��J�Z�O�P�ǥ͸�ƨ�ҵ{����, ��J 0 ������J
    cout << "> ��J�Z�O, �m�W, �Ǹ� : \n" ;
    while ( 1 ) {
        cin >> c ;
        if ( c == 0 ) break ;
        cin >> s ;
        foo.add_student(c,s) ;
    }

    // �C�L�����׽үZ�O�ǥ�
    cout << "\n" << foo << endl ;

    return 0 ;
    
}

        
    
    
