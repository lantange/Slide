#include <iostream>
#include <string>

using namespace std ;

// �r�꭫�� n ��
string  operator* ( const string& foo , unsigned int n ) {
    string  tmp = foo ;
    for ( int i = 1 ; i < n ; ++i ) tmp += foo ;
    return  tmp ;
}

// �r�꭫�� n ��
string&  operator*= ( string& foo , unsigned int n ) {
    return  foo = foo * n ;
}

// �Ѧr�� foo ���h�� str
string  operator- ( const string& foo , const string& str ) {

    string  tmp = foo ;
    int i = 0 ;

    while ( i < tmp.length() ) {           
        i = tmp.find( str , i ) ;          // ��M�r��
        if ( i == string::npos ) break ;   // �Y�䤣��r��h�����j��
        tmp.erase( i , str.length() ) ;    // �R���r��
    }
    return  tmp ;
}

// �Ѧr�� foo ���h�� str
string&  operator-= ( string& foo , const string& str ) {
    return  foo = foo - str ;
}

int main() {
    
    string  DNA = "TGCA" ;
    
    DNA *= 2 ;
    DNA = DNA + "TT" + DNA + "TT" ;
    cout << "DNA : " << DNA << "\n\n" ;
    
    DNA -= "CAT" ;
    cout << "DAN : " << DNA << endl ;

    return 0 ;
    
}
