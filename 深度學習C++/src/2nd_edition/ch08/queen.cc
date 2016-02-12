#include <iostream>
#include <iomanip>

using namespace std ;

// �ϥΥ����ܼ�

// S : �ѽL�j�p , queen : �ӦZ��m
const int  S = 8 ;
bool  queen[S][S] = { { false }, { false }, { false }, { false },
                      { false }, { false }, { false }, { false } };

// �p�⵴���
int  abs( int x ) { return x > 0 ? x : -x ; }

// �ˬd�s���ӦZ�Y�\��b (r,c) ��m�O�_�A��
bool  valid_position(int r , int c ) {

    int i , j , dx , dy ;

    // �ˬd�O�_�P�w�����ӦZ�b�P�@��, �P�@�C�Φb�﨤�u�W
    for ( j = 0 ; j < c ; ++j ) 
        for ( i = 0 ; i < S ; ++i ) {
            if ( queen[i][j] ) {
                dx = abs(r-i) ;
                dy = c - j ;
                if ( dx == 0 || dy == 0 || dx == dy ) return false ;
            }
        }
    return true ;

}

// �C�L�Ҧ����ӦZ��m
void  print_queen(int counter) {
    int i , j ;
    cout << "\n" << setw(7) << "[" << setw(3) << counter << "]\n" ;
    for ( i = 0 ; i < S ; ++i ) {
        for ( j = 0 ; j < S ; ++j ) 
            cout << setw(2) << ( queen[i][j] ? "Q" : "+" ) ;
        cout << endl ;
    }
}


// ���j��M�ӦZ��m
void  locate_queen( int col ) {

    int  row ;
    static int  counter = 0 ;

    if ( col == S ) {

        print_queen(++counter) ;

    } else {

        for ( row = 0 ; row < S ; ++row ) {
            if ( valid_position(row,col) ) {
                queen[row][col] = true ;
                locate_queen(col+1) ;
                queen[row][col] = false ;
            }
        }

    }
}

// �D�禡
int  main() {

    int  col = 0 ;

    locate_queen(col) ;

    return 0 ;
    
}		 
