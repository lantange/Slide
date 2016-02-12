#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <iomanip>
#include <iterator>

using namespace std ;

// �p��r��r���� 
int  char_count( const string& s ) { 
    return s.size() ; 
}

// �N�C�Ӧr���b�r�������Ǳ���r����׭Ӧ�m
string  rotate_char( string s , int no ) {

        for ( int i = 0 ; i < s.size() ; ++i ) 
            
            if ( 'a' <= s[i] && s[i] <= 'z' ) {
                s[i] +=  s.size() ;
                if ( s[i] > 'z' ) s[i] -= 26 ;
            } else if ( 'A' <= s[i] && s[i] <= 'Z' ) {
                s[i] +=  s.size() ;
                if ( s[i] > 'Z' ) s[i] -= 26 ;
            }
    
    return s ;
}

int main() {
    
    const  int  S = 11 ;
    string  Q[S] = { "I" , "believed" ,  "that" , "my" ,  
                      "exact" , "words" , "were" , "dangerous" , 
                      "savage" , "child" , "race" } ;

    vector<int>     chars(S) ;
    vector<string>  code ;

    int  i  ;
    for ( i = 0 ; i < S ; ++i ) cout << Q[i] << " " ;
    cout << endl ;

    // �p��C�ӳ�r���������Ӽƫ�N���G�s��V�q�}�C��
    transform( Q , Q+S , chars.begin() , char_count ) ;

    for ( i = 0 ; i < S ; ++i ) 
        cout << left << setw(Q[i].size()) << chars[i] << " " ;
    cout << endl ;

    // �N Q �����r��r���̳�r���ױ���r��, �ഫ�᪺���
    // �ѥ��ݴ��J code �r��}�C��
    transform( Q , Q+S , chars.begin() , 
               back_inserter(code) , rotate_char ) ;

    for ( i = 0 ; i < S ; ++i ) cout << code[i] << " " ;
    cout << endl ;

    return 0 ;
    
}

        
            
