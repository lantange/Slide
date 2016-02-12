#include <iostream>
#include <iomanip>
#include <fstream>
#include <sstream>
#include <string>
#include <set>

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


// �]�w�p�����禡, �H�`�Ƥp�̪���Ƹ��p, �Y�۵�, �h�½Ҥ�p�̸��p
bool  operator< ( const Schedule& a , const Schedule& b ) {
    return ( a.sct == b.sct ? a.day < b.day : a.sct < b.sct ) ;
}


class  Course_Schedule{

  private :

    // �� �ҵ{ Schedule ������, �x�s�ҵ{���
    set<Schedule>  courses ;   

  public :

    // �غc�禡, Ū�����
    Course_Schedule( char* datafile ) {

        ifstream        infile(datafile) ;
        string          line ;
        istringstream   strline(line) ;

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
                    courses.insert( Schedule(cname,wday,sct) ) ;

                // �M��Ū�J���~�X�m
                strline.clear() ;
            }

            strline.clear() ;

        }

    }

    // �C�L�ҵ{��
    void  print_html_schedule() const {

        char*  weekday[] = { "�P����" , "�P���@" , "�P���G" , 
                             "�P���T" , "�P���|" , "�P����" , 
                             "�P����" };

        int   s , d ;


        // ���� HTML �}�l, �����W��, �κ������D�鳡�����аO
        cout << "<html><head><title>�ҵ{��</title></head>\n" 
             << "<body>" ;
        
        // ���ͽҵ{����Ĥ@�C���Y
        cout << "<table border=1 cellpadding=3>\n" 
             << "<tr><th bgcolor=white width=5%><br></th>\n" ;

        for ( d = 1 ; d <= 5 ; ++d ) 
            cout << "<th width=16% bgcolor=cyan>" 
                 << weekday[d] << "</th>\n" ;
                 

        cout << "</tr>" ;
        
        // ���X���u�����ҵ{
        set<Schedule>::const_iterator  iter = courses.begin() ;

        // �C�L�Ҫ�, �ĥξ�Ƹ`��, ���Ƥ��
        for ( s = 1 ; s <= 8 ; ++s ) {

            // �}�l�s���@�C, �P�ɸ`�����βL�Ŧ�I��, �m��������
            cout << "<tr><td bgcolor=cyan align=center>" 
                 << s << "</td>\n";

            for ( d = 1 ; d <= 5 ; ++d ) {

                // �ҵ{�W�٪��C�@��Υզ�I��, �m��������
                cout << "<td bgcolor=white align=center>" ;

                // �p�G���馹�`����, �h�H����r�C�L��, 
                // ���N���H�Y���V�U�@�Ӥ���
                if ( iter->day == d && iter->sct == s ) {
                    cout << "<font color=red>" 
                         << iter->name.c_str() << "</font>" ;
                    if ( iter != courses.end() ) ++iter ;
                }
                cout << "<br></td>\n" ;

            }

            // �׵��@�C
            cout << "</tr>\n" ;
        }

        // �[�W HTML �����аO
        cout << "</table></body></html>" ;
        
    }
    
};

// �D�禡
int  main() {

    Course_Schedule  courses("class.db") ;

    // �C�L HTML �Ҫ�
    courses.print_html_schedule() ;
    
    return 0 ;
    
}

