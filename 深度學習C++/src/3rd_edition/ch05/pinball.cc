#include <iostream>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std ;

int main() {

    int i , j , n ;
    
    // ��J�u���`�h��
    cout << "> n : " ;
    cin >> n ;
    
    // �x�s�C�@�Ӧ�m���u�]�ƶq
    int  *ball = new int[n+1] ;

    // �C�Ӧ�m���_�l�u�]�Ƭ� 0
    for ( i = 0 ; i < n+1 ; ++i ) ball[i] = 0 ;

    // ���ժ��u�]�`�ƶq
    const int M = 100000 ;

    srand( static_cast<unsigned int>(time(NULL)) ) ;

    int  position ;
    // ���� M ��
    for ( i = 0 ; i < M ; ++i ) {

        // �p��u�]�b�g�L n �h�u���᪺��m
        position = 0 ;
        for ( j = 0 ; j < n ; ++j ) {
            // �Y�üƬ� 1 �h�y����u���᩹�k, �_�h����
            if ( rand()%2 ) ++position ;
        }

        // �b position �B�x�s�W�[�@�Ӽu�]
        ++ball[position] ;

    }

    // �H���Ƥ�覡�C�L���G, ���� s �� 2 �� n ����
    int s = 1 ;
    for ( i = 0 ; i < n ; ++i ) s*=2 ;

    cout << "\n" ;
    for ( i = 0 ; i < n + 1 ; ++i )
        cout << "| " << static_cast<char>('A'+i) << " " ;
    cout << "|" << "\n\n" ;

    // �̤��� s ���j�p, ���s�վ�C�Ӭ}���y��, ��X�|�ˤ��J�᪺�Ʀr
    for ( i = 0 ; i < n + 1 ; ++i )
        cout << setw(3)
             << static_cast<unsigned>(1.*ball[i]*s/M+0.5) << " " ;
    cout << endl ;

    for ( i = 0 ; i < n + 1 ; ++i )  cout << setw(3) << " -- " ;
    cout << endl ;

    for ( i = 0 ; i < n + 1 ; ++i )  cout << setw(3) << s << " " ;
    cout << endl ;


    delete [] ball ;

    return 0 ;

}

