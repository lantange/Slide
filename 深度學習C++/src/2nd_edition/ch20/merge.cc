#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std ;

// ������ƪ��Ӧ�Ƥj�p
bool  cmp_last_digit( int a , int b ) { return a%10 < b%10 ; }

int main() {

    const int S1 = 4 , S2 = 5 ;
    
    int no1[S1] = { 42 ,  4 , 27 ,  8 };
    int no2[S2] = { 20 , 91 , 12 , 55 , 39 };

    vector<int>  no ;
    
    // �N��}�C�̭Ӧ�ƥѤp��j�X�֥[�J no �V�q�}�C
    merge( no1 , no1+S1 , no2 , no2+S2 , back_inserter(no) , 
           cmp_last_digit ) ;
    
    // �C�L
    copy( no.begin() , no.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}
