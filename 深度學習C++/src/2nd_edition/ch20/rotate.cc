#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std ;

int main() {

    // �~���s���� : �@
    string  tea_poem[5] = { "�M" , "��" , "�]" , "�i" , "�H" };
    string  new_poem[5] ;
    int     i ;
    
    for ( int i = 0 ; i < 5 ; ++i ) {
        rotate_copy( tea_poem , tea_poem+i , tea_poem+5 , new_poem ) ;
        copy( new_poem , new_poem+5 , ostream_iterator<string>(cout,"") ) ;
        cout << endl ;
    }
    cout << endl ;
    
    /******************************************************************

    // �~���s���� : �G
    string  tea_poem2 = "�M�ߤ]�i�H" ;
    
    for ( int i = 0 ; i < 5 ; ++i ) {
        cout << tea_poem2 << endl ;
        rotate( tea_poem2.begin() , tea_poem2.begin()+2 , tea_poem2.end() ) ;
    }        
    cout << endl ;

    // �~���s���� : �T
    char  tea_poem3[] = "�M�ߤ]�i�H" ;
    
    for ( int i = 0 ; i < 5 ; ++i ) {
        cout << tea_poem3 << endl ;
        rotate( tea_poem3 , tea_poem3+2 , tea__poem+10 ) ;
    }        
    cout << endl ;

    ******************************************************************/
    
    // Ĭ�p�f : �s���� 
    string  poem[14] = { "��","��","�k","�h","��","�p","��",
                         "�s","�O","�L","��","��","�w","��" };

    int     d[4] = { 0 , 3 , 4 , 3 };
    
    // �C���H d[i] ���r�Ʈt�Z�`�����ͤC���֥y
    for ( int i = 0 ; i < 4 ; ++i ) {
        rotate( poem , poem+d[i] , poem+14 ) ;
        copy( poem , poem+7 , ostream_iterator<string>(cout,"") ) ;
        cout << endl ;
    }

    return 0 ;
    
}

    
    
