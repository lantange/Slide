#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

bool  case_insensitive( char a , char b ) {
    if ( a >= 'a' ) a = a - 'a' + 'A' ;
    if ( b >= 'a' ) b = b - 'a' + 'A' ;
    return  a < b ;
}

int main() {
    
    string  borg = "You Too Will Be Assimilated" ;
    
    cout << "> �Ƨǫe : " << borg << endl ;

    sort( borg.begin() , borg.end() ) ;
    cout << "> �Ƨǫ� : " << borg << " (�r���j�p�g���O)" << endl ;

    sort( borg.begin() , borg.end() , case_insensitive ) ;
    cout << "> �Ƨǫ� : " << borg << " (�r���j�p�g�L��)" << endl ;
}

