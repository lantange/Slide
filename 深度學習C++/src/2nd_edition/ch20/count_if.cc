#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

// �P�_�r���O�_���j�g�r��
struct  upper_case {
    bool  operator() ( char c ) const {
        return ( c >= 'A' && c <= 'Z' ) ? true : false ;
    }
};


int main() {
    
    string   Q = "Must you be so linear, Jean-Luc" ;

    // �p�� o �r�����Ӽ�
    cout << count( Q.begin() , Q.end() , 'o' ) << endl ;

    // �p��j�g�r�����Ӽ�
    cout << count_if( Q.begin() , Q.end() , upper_case() ) << endl ;

    return 0 ;
    
}

            
