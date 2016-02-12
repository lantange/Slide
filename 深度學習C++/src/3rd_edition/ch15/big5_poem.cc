#include <iostream>
#include <fstream>
#include <sstream>
#include <locale>
#include <string>
#include <iomanip>

using namespace std ;


int main() {
  
    setlocale( LC_ALL , "zh_TW.UTF-8") ;

    // �]�wŪ�J�������r���׻P�e��
    const int MAX_H = 24 ;
    const int MAX_W = 80 ;

    wstring          line ;
    wifstream        poem("utf8_poem.db") ;

    // �w�q�r���Ƭy����}�C
    wostringstream   poemstring[MAX_W]  ;

    locale  utf8("zh_TW.UTF-8");     

    // �N utf8 locale ����[�J poem ��y����
    poem.imbue(utf8) ;  

    // �O���bŪ�J���Ҧ���Ƥ��̦h�r�����Ӽ�
    int no = 0 , max = 0 ;
    int i , j ;

    // Ū�J��椤��, �ä@�@�s�J�r���Ƭy����}�C
    while ( getline( poem , line ) ) {
        if ( max < line.length() ) max = line.length() ;
        poemstring[no++] << line ;
    }

    // �����ɤW�Y�z�Ӫťռe�r���A�ϨC�� poemstring ���������e�r��
    for ( i = 0 ; i < no ; ++i ) {
        j = poemstring[i].str().size() ;
        if ( j < max ) poemstring[i] << wstring(max-j,L'�@' ) ;
    }
    
    // �C�L
    for ( j = 0 ; j < max ; ++j ) {
        for ( i = no-1 ; i >= 0 ; --i ) {
            wcout << poemstring[i].str()[j] << L'�@' ;
        }
        wcout << endl ;
    }

    return 0 ;
    
}






