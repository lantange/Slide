#include <iostream>
#include <iomanip>

using namespace std ;

int main() {
    
    // a : �Q���� , b : ����
    int  a , b , c , i , no ;

    cout << "> �п�J�⥿�� : " ;

    // ��J a , b 
    cin >> a >> b ;
    
    // �C�L a X b ����������
    cout << "\n" 
         << setw(10) << a << endl 
         << setw(3)  << "x" << setw(7) << b << endl
         << setw(10) << "--------" << endl ;
    
    // �p�� b �ѭӦ�ư_���C�@���(�s�Jc), ���O���H a ����
    // i  : �����X����m
    // no : �x�s���� b ���ư��H 10 �᪺��

    i = 0 ;
    no = b ;
    while ( no ) {
        c  = no % 10 ;
        no = no / 10 ;
        cout << setw(10-i) << c * a << endl ;
        ++i ;
    }
    
    // �C�L�̫᪺�ۭ����G
    cout << setw(10) << "--------" << endl 
         << setw(10) << a * b << endl ;

    return 0 ;
    
}

        
