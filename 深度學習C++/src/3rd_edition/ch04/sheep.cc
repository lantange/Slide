#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std ;

int main() {
    
    int  right_choice = 0 , total_no = 1000000 ;
    int  i , j , car_door , guest_door , sheep_door , last_door ;

    // �ήɶ��]�w�üƨ�ƪ����
    srand( static_cast<unsigned int>( time(NULL) ) ) ;

    // ���� 1000000 ��
    for ( i = 0 ; i < total_no ; ++i ) {
        
        // �ζüƳ]�w���l����m : 1 �� 3 ����
        car_door = rand() % 3 + 1 ;
        
        // �ӻ��ҿ�ܪ�����m
        guest_door = rand() % 3 + 1 ;

        // �D���H��X���O�ӻ��ҿ�ܪ��B���Ϫ���
        do {
            j = rand()%3 + 1 ;
        } while ( j == guest_door || j == car_door ) ;
        sheep_door = j ;

        // ��X�̫�@����, �]�N�O�i�H�󴫪���
        do {
            j = rand()%3 + 1 ;
        } while ( j == guest_door || j == sheep_door ) ;
        last_door = j ;
        
        // �ˬd�󴫪�����O�_���T��, �p�G�O�h�O���U��
        if ( last_door == car_door ) {
            right_choice += 1 ;
        }

    }

    // �L�X�󴫫�q�諸���v
    cout << ( right_choice * 1.0 / total_no ) << endl ;

    return 0 ;
    
}
