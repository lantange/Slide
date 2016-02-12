#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std ;

const char*  esc    = "\x1b[" ;
const char*  sep    = ";" ;
const char*  clr    = "\x1b[2J" ;

int main() {
    
    // �ù����C�ƻP���
    const int ROW    = 24 ;
    const int COL    = 80 ;

    int  i , row , col , color ;

    // �]�w�ü�
    srand( static_cast<unsigned>(time(NULL)) ) ;

    // �M���e��
    cout << clr << flush ;

    // �L�a�j��, �ХH���_�� (ctrl-C) ���}
    while ( 1 ) {

        // �ζüƨM�w row �P col ����m
        row   = rand() % ROW + 1 ;  
        col   = rand() % COL + 1 ;  
        color = rand() % 8 ;
        
        // �b ( row , col ) ����y�гB�L�X�m����
        cout << esc << row << sep << col  << "H"
             << esc << 4 << color << "m" << " " << flush ;

        // ����@�q�ɶ� : 50000000 ���[�k�ɶ�
        for ( i = 0 ; i < 50000000 ; ++i ) ;

    }

    return 0 ;
    
}
