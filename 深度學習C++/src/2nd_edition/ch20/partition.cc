#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

// �ˬd�r���O�_������
bool  vowel ( char c ) {
    return  ( c == 'a' || c == 'e' || c == 'i' || 
              c == 'o' || c == 'u' ) ? true : false ;
}

int main() {

    string  Picard  = "sleep, Data. sleep" ;

    cout << "�즳�r��         > " << Picard << endl ;

    // �N����������r�ꪺ�e��
    partition( Picard.begin() , Picard.end() , vowel ) ;

    cout << "partition        > " << Picard << endl ;

    // ���s�]�w
    Picard = "sleep, Data. sleep" ;

    // �N����������r�ꪺ�e��, ���������즳�e�ᦸ�ǫO������
    stable_partition( Picard.begin() , Picard.end() , vowel ) ;

    cout << "stable partition > " << Picard << endl ;

    return 0 ;
    
}
