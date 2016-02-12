#include <iostream>
#include <string>
#include <vector>
#include <stack>

using namespace std ;

int main() {

    char  p[] =  "�׭�¶�|��  �q�۱a�s�s  ��l������  �ƱK������" ;

    // �p��r��}�C������
    int    size = sizeof(p) / sizeof(char) ;

    // c++ �r����|
    stack< string , vector<string> >  poem ;

    // �C��Ӧr�����@�Ӧr��e�J���|
    for ( int i = 0 ; i < size ; i+=2 ) 
        poem.push( string(p+i,p+i+2) ) ;
    
    // �N���|�����@�@�L�X�Ჾ��
    while ( ! poem.empty() ) {
        cout << poem.top() ;
        poem.pop() ;
    }
    cout << endl ;
    return 0 ;

}
