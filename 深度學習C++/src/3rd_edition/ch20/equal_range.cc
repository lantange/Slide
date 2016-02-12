#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std ;

// �r������禡����, �����j�p�g
struct case_insensitive {
    bool  operator() ( char a , char b ) const {
        if ( a >= 'a' ) a = a - 'a' + 'A' ;
        if ( b >= 'a' ) b = b - 'a' + 'A' ;
        return  a < b ;
    }
};

int main() {

    // �@�Ӥw�ƧǪ��r���}�C
    const int S = 10 ;
    char  str[S] = { 'a' , 'c' , 'e' , 'e' , 'm' , 
                     'm' , 'm' , 'u' , 'u' , 'v' } ;
    
    // �C�L�r���}�C
    copy(str,str+S,ostream_iterator<char>(cout," ")) ;
    cout << endl ;

    char  *lower , *upper ;

    // 'a' �� 'z' �C�|�Ӧr������@��
    for ( char c = 'a' ; c <= 'z' ; c += 4 ) {

        lower = lower_bound( str , str+S , c ) ;
        upper = upper_bound( str , str+S , c ) ;
        
        cout << c << " : [ " 
             << ( lower != str+S ? *lower : '-' ) << " , " 
             << ( upper != str+S ? *upper : '-' ) << " )" << endl ;

    }
    cout << endl ;
    
    // �w�q�@���磌��, ���t��Ӧr������
    pair<char*,char*>  range ;

    // �Y�O�j�g�r��, �h�ϥΤ���禡�����r���j�p�g
    for ( char c = 'A' ; c <= 'Z' ; c += 4 ) {

        range = equal_range( str , str+S , c , case_insensitive() ) ;
        cout << c << " : [ " 
             << ( range.first  != str+S ? *(range.first) : '*' ) 
             << " , " 
             << ( range.second != str+S ? *(range.second) : '*' )
             << " )" << endl ;

    }

    return 0 ;
    
}

    
