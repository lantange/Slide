#include <iostream>
#include <string>
#include <unistd.h>   

// �p�G�O�ϥ� visual C++ �sĶ��  �h�ϥΥH�U���Y��
// #include <cstdlib>    

using namespace std ;

int main() {

    // �]���O�W����r
    string  foo = "�u�u�����F�u���A����^�ɭ^���C"
                  "�O�D�������Y�šG�C�s���¦b�A�X�פi�����C" ;
    
    int  i ;

    // �C�L���_�l��m
    int  p = 0 ;
    
    while ( 1 ) {
    
        // �� p ��m�_�`���C�L���
        for ( i = 0  ; i < foo.size() ; i+=2 ) {
            cout << foo[(p+i)%foo.size()] << foo[(p+i+1)%foo.size()] 
                 << flush ;
        }

        // �{���𮧤@��
        sleep(1) ;          

        // _sleep(1000) ;  // �p�G�ϥ� visual C++, �h���Φ��ԭz

        // �N��L��Э���歺
        cout << "\r" ;
    
        p+=2 ;
        
    }

    return 0 ;
    
}
