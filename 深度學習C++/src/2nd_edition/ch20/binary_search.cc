#include <iostream>
#include <algorithm>

using namespace std ;

// ����Ӧ�Ƥj�p
bool  cmp_last_digit( int a , int b ) {  return  a%10 < b%10 ; }

int main() {
    
    const int S = 10 ;

    // �̼Ʀr�j�p�Ƨ�
    int  no1[S] = { 3 , 4 , 9 , 14 , 23 , 29 , 39 , 44 , 54 , 63 };
    
    int i ;

    cout << "�п�J�j�M���Ʀr : " ;
    
    // �j�M��J���Ʀr�O�_�b�}�C��, �p�G���O, �h���sŪ�����
    while( cin >> i ) {
        if ( binary_search( no1 , no1+S , i ) ) break ;
        cout << "> " << i << " ���b�}�C��" << endl
             << "> �ЦA��J�s�Ʀr : " ;
    }
    cout << "> " << i << " �w��� -- �Ʀr�ۦP" << endl << endl ;

    // �̭Ӧ�Ƥj�p�Ƨ�, �ϥ� cmp_last_digit ����禡�Ӥ����Ƥj�p

    cout << "�п�J�j�M���Ʀr : " ;

    int  no2[S] = { 3 , 23 , 63 , 4 , 14 , 44 , 54 , 9 , 29 , 39 };
    while( cin >> i ) {
        if ( binary_search( no2 , no2+S , i , cmp_last_digit ) ) break ;
        cout << "> " << i << " ���b�}�C��" << endl
             << "> �ЦA��J�s�Ʀr : " ;
    }
    cout << "> " << i << " �w��� -- �Ӧ�ƬۦP" << endl ;

    return 0 ;
    
}
