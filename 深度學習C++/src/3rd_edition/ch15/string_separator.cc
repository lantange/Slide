#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>

using namespace std ;

// ��ѰO���r�� foo ���ӥئr��}�C bar, �O���������аO�� sep
void  split_string( const string& foo , const string& sep ,
                    string  bar[] ) {
    
    // i , j ���U��, n ���ӥؤU��
    int  i = 0 , j , n = 0 ;

    while ( 1 ) {

        // foo �ѤU�� i ������аO sep
        j = foo.find(sep,i) ;

        // �Y�w�g�䤣������аO, �h�s�J�̫�@���ӥث����}
        if ( j == string::npos ) {
            bar[n] = foo.substr(i,(foo.length()-i)) ;
            return ;
        }
        
        // �x�s�O�����ӥ�
        bar[n] = foo.substr(i,(j-i)) ;
        ++n ;

        // �p��U����M���U�Э�
        i = j + sep.length() ;
        
    }
    
}


// �C�L�O�����ӥظ��
void  print_student_record( const string field[] ) {

    cout << "> �m�W : " << field[0] << "  "
         << setw(10) << "�ʧO : " << field[1] << "  "
         << setw(10) << "�X�� : " << field[2] << '\n' 
         << "  �Ǹ� : " << setw(6) << setfill('0') 
         << field[3].c_str() << setfill(' ') << "  " 
         << setw(10) << "�J�� : " << field[4] << '\n'
         << "  ��} : " 
         << ( field[5] == "*" ? "��" : field[5] ) << '\n'
         << "  �q�� : " 
         << ( field[6] == "*" ? "��" : field[6] ) << "\n\n" ;

}


int  main() {
    
    const int FIELD_NO = 7 ;

    // �}�Ҹ���ɮ�
    ifstream  infile( "student.db" ) ;
    
    string  record ;
    string  field[FIELD_NO]  ;

    // �C���Ѹ���ɤ�Ū���@���ƫ����, �C�L
    while ( getline( infile , record ) ) {
        if ( record == "" ) break ;
        split_string( record , "::" , field ) ;
        print_student_record( field ) ;
    }

    infile.close() ;
    
    return 0 ;
    
}
