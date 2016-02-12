#include <iostream>
#include <algorithm>
#include <iterator>
using namespace std ;

int main() {

    // �@�Ӥw�Ƨǧ�������ư}�C
    const int S = 10 ;
    char  str[S] = { 'a' , 'c' , 'e' , 'e' , 'm' , 
                     'm' , 'm' , 'u' , 'u' , 'v' } ;
    
    // �C�L���}�C
    copy(str,str+S,ostream_iterator<char>(cout," ")) ;
    cout << endl ;
    
    char  *lower , *upper ;
    
    for ( char i = 'a' ; i <= 'z' ; i += 4 ) {

        cout << i << " : [ " ;
        lower = lower_bound( str , str+S , i ) ;
        upper = upper_bound( str , str+S , i ) ;
        
        cout << ( lower != str+S ? *lower : '-' ) ;
        cout << " , " ;

        cout << ( upper != str+S ? *upper : '-' );
        
        cout << " ]" << endl ;
        
    }
    
}

    
