#include <iostream>
#include <algorithm>
#include <iterator>
#include <string>

using namespace std ;

// �ˬd�r���O�_������
bool  vowel ( char c ) {
    return ( c == 'a' || c == 'e' || c == 'i' ||
             c == 'o' || c == 'u' ) ? true : false ;
}

int main() {

    string  enterprise = "To boldly go where no one has gone before" ;
    string  startrek , tng ;

    startrek = enterprise ;

    // �ξ�u���N�Ҧ����Ů�
    replace( startrek.begin() , startrek.end() , ' ' , '-' ) ;
    cout << "1 > " << startrek << endl ;

    startrek = enterprise ;

    // �ξ�u���N�Ҧ����Ů�  �����G���J��s�r��
    replace_copy( startrek.begin() , startrek.end() , back_inserter(tng) , 
                  ' ' , '-' ) ;
    cout << "2 > " << startrek << endl << "--> " << tng << endl ;

    startrek = enterprise ;

    // �N�Ҧ��������άP�����N
    replace_if( startrek.begin() , startrek.end() , vowel , '*' ) ;
    cout << "3 > " << startrek << endl ;

    tng = "" ;
    startrek = enterprise ;

    // �N�Ҧ��������άP�����N  ���G���J��s�r��
    replace_copy_if( startrek.begin() , startrek.end() , back_inserter(tng) , 
                     vowel , '*' ) ;
    cout << "4 > " << startrek << endl << "--> " << tng << endl ;

    return 0 ;
    
}
