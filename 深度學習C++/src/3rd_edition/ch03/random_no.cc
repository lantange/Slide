#include <iostream>
#include <cstdlib>   // �H���禡 rand �P�]�w�H���禡��Ȫ��禡 srand
#include <ctime>     // �{���b����ɪ��ɨ��� time

using namespace std ;

int main() {

    // �H�{�����檺�ɶ��ӳ]�w�H���禡����l��
    srand( static_cast<unsigned int>(time(NULL)) ) ;
  
    // ���ͤQ�� 0 �� 9 �������H�����
    for ( int i = 0 ; i < 10 ; ++i ) cout << rand()%10 << ' ' ;
    cout << '\n' ;

    return 0 ;
    
}
