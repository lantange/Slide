#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std ;

// ������H n ��l�ƪ��j�p
struct big_n {
    int n ;
    big_n( int a ) : n(a) {}
    bool  operator() ( int a , int b ) const {
        return a % n < b % n ;
    }
};

int main() {
    
    const int S = 10 ;
    int no[S] = { 3 , 4 , 5 , 7 , 8 , 1 , 9 , 3 , 4 , 1 };
    
    // �C�L�}�C�ç�X�̤p�P�̤j������
    cout << "> �}�C : " ;
    copy( no , no+S , ostream_iterator<int>(cout," ") ) ;
    cout << endl 
         << "> �̤p�� : " << *min_element(no,no+S) << endl 
         << "> �̤j�� : " << *max_element(no,no+S) << endl 
         << "> �Q 3 ���l�ƪ��̤p�� : " 
         << *min_element(no,no+S,big_n(3)) << endl 
         << "> �Q 3 ���l�ƪ��̤j�� : " 
         << *max_element(no,no+S,big_n(3)) << endl 
         << "> �Q 5 ���l�ƪ��̤p�� : " 
         << *min_element(no,no+S,big_n(5)) << endl 
         << "> �Q 5 ���l�ƪ��̤j�� : " 
         << *max_element(no,no+S,big_n(5)) << endl ;

    return 0 ;
    
}
