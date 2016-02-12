#include <iostream>
#include <numeric>
#include <vector>
#include <iterator>
#include <algorithm>

using namespace std ;

// �禡�Ȧb b ���j��s�ɤ~�@�[�k�B��
int positive_sum ( int a , int b ) { return ( b > 0 ? a + b : a ) ; }


int main() {
    
    const  int   S = 5 ;
    int          no[S] = { 2 , 4 , -3 , 1 , 4 };
    vector<int>  s(S) ;
    
    // �C�L no �}�C
    cout << "> ��ư}�C   : " ;
    copy( no , no+S , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �N�����M�����G�s�J�V�q�}�C s ��L�X
    partial_sum( no , no+S , s.begin() ) ;
    cout << "> �}�C�����M : " ;
    copy( s.begin() , s.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �u�[�����
    partial_sum( no , no+S , s.begin() , positive_sum ) ;
    cout << "> ���Ƴ����M : " ;
    copy( s.begin() , s.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    // �p�⭼�n
    partial_sum( no , no+S , s.begin() , multiplies<int>() ) ;
    cout << "> �������n�� : " ;
    copy( s.begin() , s.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

