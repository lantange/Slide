#include  <iostream>
#include  <fstream>
#include  <sstream>
#include  <string>
#include  <iomanip>

using namespace std ;

int main( int argc , char *argv[]) {

    // �p�G�ѤF�b�R�O���[�J���B�z�������ɮצW��, �h�{������
    if ( argc == 1 ) return 1 ;

    // �]�wŪ�J�������r���׻P�e��
    const int MAX_H = 24*2 ;
    const int MAX_W = 80   ;

    string          line ;
    ifstream        poem( argv[1] ) ;

    // �w�q�r���Ƭy����}�C
    ostringstream   poemstring[MAX_W]  ;

    // �O���bŪ�J���Ҧ���Ƥ��̦h�r�����Ӽ�
    int  no = 0 , max = 0 ;

    // Ū�J��椤��, �ä@�@�s�J�r���Ƭy����}�C
    while ( getline( poem , line ) ) {
        
        if ( max < line.length() ) max = line.length() ;
        poemstring[no++] << setw(MAX_H) << setiosflags(ios::left) 
                         << line.c_str() ;
        
    }

    // ��Ө�Ӧr����X, �æb�C�@�椧���t�~�[�J�@�ťզ�
    int i , j ;
    for ( j = 0 ; j < max ; j += 2 ) {
        for ( i = no-1 ; i >= 0 ; --i ) {
            cout << poemstring[i].str()[j] << poemstring[i].str()[j+1]
                 << "  " ;
        }
        cout << endl ;
    }

    return 0 ;
    
}

