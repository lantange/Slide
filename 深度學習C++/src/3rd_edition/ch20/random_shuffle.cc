#include <iostream>
#include <algorithm>
#include <iterator>
#include <cstdlib>
#include <ctime>

using namespace std ;

// ���ͤ@ [0,n) ���ü�
int  random_number ( int n ) { return rand() % n ; }

int main() {
    
    // �N 1 �� 42 �Ӿ�ƨ̦��s�J no �}�C��
    const int S = 42 ;
    int   no[S] ;
    for ( int i = 0 ; i < S ; ++i ) no[i] = i+1 ;

    // �]�w�üƺؤl���
    srand( static_cast<unsigned>(time(NULL)) ) ;
    
    // �N���}�C�������s���t��m
    random_shuffle( no , no+S , random_number ) ;

    // ��X�e���Ӥ���
    copy( no , no+6 , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;

}


            
