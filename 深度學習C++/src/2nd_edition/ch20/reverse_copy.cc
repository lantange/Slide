#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>
#include <string>

using namespace std ;

int main() {
    
    char   p[] =  "�׭�¶�|��  �q�۱a�s�s  ��l������  �ƱK������" ;

    // �p�� p �r�ꪺ��r����
    int  size = sizeof(p)/sizeof(char)-1 ;

    vector<string>  poem , new_poem ;

    // �H�C��Ӧr�����@�Ӧr��Ū�J
    for ( int i = 0 ; i < size ; i+=2 ) 
        poem.push_back( string(p+i,p+i+2) ) ;

    // �C�L�֥y
    copy(poem.begin(),poem.end(),ostream_iterator<string>(cout,"") ) ;
    cout << endl ;

    // ���Ͱj���
    reverse_copy( poem.begin() , poem.end() , back_inserter(new_poem) ) ;

    // �C�L�j��֥y
    copy(new_poem.begin(),new_poem.end(),ostream_iterator<string>(cout,"") ) ;
    cout << endl ;
    
    return 0 ;
    
}

    
