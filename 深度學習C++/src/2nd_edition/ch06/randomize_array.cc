#include <iostream>
#include <cstdlib>   // �����H���禡 rand �P�]�w�H���禡
                     // ��Ȫ��禡 srand
#include <ctime>     // ���ѵ{���b����ɪ��ɨ��� time

using namespace std ;

int main() {

    int  foo[] = { 2 , 4 , 6 , 8 , 10 };
    int  i , j , tmp ;

    // �H�ɶ��]�w�H���禡��l��
    srand( static_cast<unsigned>( time(NULL) ) ) ;

    // �p���ư}�C������
    int  size = sizeof(foo) / sizeof(int) ;
    
    // �}�C�����ѫ᩹�e�̦��P��e���t�@���H����m��ռƭ�
    for ( i = size-1 ; i > 0 ; --i ) {
        j      = rand() % (i+1) ;
        if ( i == j ) continue ;  // �p�G i �P j ���m�۵��h�����
        tmp    = foo[i] ;
        foo[i] = foo[j] ;
        foo[j] = tmp ;
    }
    
    for ( i = 0 ; i < size ; ++i )  cout << foo[i] << " " ;
    cout << '\n' ;
    
    return 0 ;
    
}
