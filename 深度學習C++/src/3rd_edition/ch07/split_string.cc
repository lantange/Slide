#include <iostream>
#include <string>

using namespace std ;

// �q�^��y�l�����X�^���r

int main() {
    
    int  i  ;
    
    string  Q = "Must you be so linear, Jean-Luc" ;
    
    int     count = 0 ;    // �r���
    string  word      ;    // �x�s�ȮɨϥΪ��^���r
    string  words[20] ;    // �r��}�C�Ψ��x�s�^���r
    
    for ( i = 0 ; i < Q.size() ; ++i ) {

        // �p�G���O�^��r��, �h�����i�J�U�Ӱj��
        if ( ! ( ( Q[i] >= 'a' && Q[i] <= 'z' ) ||
                 ( Q[i] >= 'A' && Q[i] <= 'Z' ) ) ) continue ;
        
        // ����r�k�s
        word = "" ;

        // ���ƱN�^��r���[�W��r����, ����D�^��r������
        do {
            word += Q[i] ;
            ++i ;
        } while (  ( Q[i] >= 'a' && Q[i] <= 'z' ) ||
                   ( Q[i] >= 'A' && Q[i] <= 'Z' ) ) ;

        words[count] = word ;
        
        // ��r�ƥضi�@
        ++count ;

    }
    
    // �C�L�Ҧ��^���r
    for ( i = 0 ; i < count ; ++i ) {
        cout << i+1 << " : [" << words[i] << "]\n" ;
    }

    return 0 ;
    
}

