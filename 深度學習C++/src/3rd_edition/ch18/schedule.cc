#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <queue>

using namespace std ;

typedef  string  Course  ;
typedef  int     Section ;

enum  Weekday  { Sun , Mon , Tue , Wed , Thu , Fri , Sat };

// �ҵ{���c
struct  Schedule { 

    Course    name ;  // �ҵ{�W��
    Weekday   day  ;  // �½Ҥ��
    Section   sct  ;  // �½Үɶ�

    // ��ӫغc�禡
    Schedule(){} ;
    Schedule( Course n , Weekday d , Section s ) 
        : name(n) , day(d) , sct(s) {}
};


// �]�w Schedule ���c������, �`�Ƥp���u��, �Y�۵�, �h�½Ҥ�p���u��
bool  operator< ( const Schedule& a , const Schedule& b ) {
    return ( a.sct == b.sct ? b.day < a.day : b.sct < a.sct ) ;
}


class  Course_Schedule{

  private :

    // �� �ҵ{ Schedule ������, �x�s�ҵ{���
    priority_queue<Schedule>  courses ;   

  public :

    // �غc�禡, Ū�����
    Course_Schedule( char* datafile ) {

        ifstream        infile(datafile) ;
        string          line ;
        istringstream   strline ;

        Course   cname ;
        Weekday  wday ;
        Section  sct ;
        string   day ;
        char     colon ;
        
        // Ū�J�@����, �N�C�@�½Үɶ��s�J courses �u���ǦC
        while ( getline( infile , line ) ) {

            strline.str(line) ;
            strline >> cname ;

            // Ū�J�ҵ{���½Ҥ��
            while ( strline >> day ) {

                // �]�w�½Ҥ��ܼ�
                if ( day == "Mon" )       wday = Mon ;
                else if ( day == "Tue" )  wday = Tue ;
                else if ( day == "Wed" )  wday = Wed ;
                else if ( day == "Thu" )  wday = Thu ;
                else if ( day == "Fri" )  wday = Fri ;
                else if ( day == "Sat" )  wday = Sat ;
                
                // Ū���_��
                strline >> colon ;

                // Ū�J�ҵ{���½Үɶ�, ����o��Ū�J���~����
                while ( strline >> sct ) 
                    courses.push( Schedule(cname,wday,sct) ) ;

                // �M��Ū�J���~�X�m
                strline.clear() ;
            }

            // �M��Ū�J���~�X�m
            strline.clear() ;

        }

    }

    // �C�L�ҵ{��
    void  print_schedule() const {

        char*  weekday[] = { "Sun" , "Mon" , "Tue" , "Wed" , "Thu" , 
                             "Fri" , "Sat" };

        priority_queue<Schedule>  course = courses ;
        Schedule  foo ;
        int       i , s , d ;

        // �a���C�L
        cout.setf(ios::adjustfield,ios::left) ;

        // �C�L�D�g������Y
        cout << setw(5) << " " ;
        for ( d = 1 ; d <= 5 ; ++d ) cout << setw(14) << weekday[d] ;
        cout << endl ;

        // ���X���u�����ҵ{
        foo = course.top() ;

        // �C�L�Ҫ�, �ĥξ�Ƹ`��, ���Ƥ��
        for ( s = 1 ; s <= 8 ; ++s ) {
            cout << setw(3) << s << "  ";

            for ( d = 1 ; d <= 5 ; ++d ) {

                // �p�G���馹�`����, �h�b�C�L��, 
                // �A���u����C���X�@�����
                if ( foo.day == d && foo.sct == s ) {
                    cout << setw(14) << foo.name.c_str() ;
                    course.pop() ;
                    if ( ! course.empty() ) foo = course.top() ;
                }
                else 
                    cout << setw(14) << " " ;
            }
            cout << endl ;
        }
        
    }
    
};

// �D�禡
int  main() {

    Course_Schedule  courses("class.db") ;

    // �C�L�Ҫ�
    courses.print_schedule() ;

    return 0 ;
    
}

