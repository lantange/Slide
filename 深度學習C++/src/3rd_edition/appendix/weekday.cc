#include <iostream>
#include <string>

using namespace std ;

// �w�q Weekday �C�|���O
enum  Weekday { Sun , Mon , Tue , Wed , Thu , Fri , Sat } ;

// �榡�B�z���O
class  Alpha_Weekday {
  private :

    static const string  weekday[7] ;   // �x�s�C�|���O�������r��
    istream  *inptr ;                   // ���Ы��V istream ����
    ostream  *outptr ;                  // ���Ы��V ostream ����

  public :

    // �B�z��ƪ���J
    friend Alpha_Weekday operator>> ( istream& , Alpha_Weekday ) ;
    friend istream&    operator>> ( Alpha_Weekday , Weekday& ) ;

    // �B�z��ƪ���X
    friend Alpha_Weekday operator<< ( ostream& , Alpha_Weekday ) ;
    friend ostream&    operator<< ( Alpha_Weekday , Weekday ) ;
    
} ;

const string Alpha_Weekday::weekday[7] = { "Sun" , "Mon" , "Tue" , 
                                           "Wed" , "Thu" , "Fri" , 
                                           "Sat" } ;


Alpha_Weekday  operator >> ( istream& in , Alpha_Weekday foo ) {
    foo.inptr = &in ;
    return  foo ;
}


istream&  operator >> ( Alpha_Weekday foo , Weekday& weekday ) {

    string  str ;
    *(foo.inptr) >> str ;
    
    for ( int i = 0 ; i < 7 ; ++i ) {
        if ( str == foo.weekday[i] ) {
            weekday = static_cast<Weekday>(i) ;
            break ;
        }
    }

    return  *(foo.inptr) ;
}


Alpha_Weekday  operator << ( ostream& out , Alpha_Weekday foo ) {
    foo.outptr = &out ;
    return  foo ;
}


ostream&  operator<< ( Alpha_Weekday foo , Weekday  weekday ) {
    *(foo.outptr) << foo.weekday[static_cast<int>(weekday)] ;
    return  *(foo.outptr) ;
}

// �w�q�榡�B�z��
Alpha_Weekday  alphaweekday ;

int main() {

    Weekday  weekday ;

    while ( 1 ) {
        cout << "��J�G" ;
        cin >> alphaweekday >> weekday ;
        cout << "��X�G" << weekday << endl ;
        cout << "��X�G" << alphaweekday << weekday << endl ;
    }
    
    return 0 ;
    
}

