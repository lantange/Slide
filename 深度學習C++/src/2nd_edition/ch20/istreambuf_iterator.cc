#include <iostream>
#include <iterator>

using namespace std ;

struct  to_upper {
    char  operator() ( char c ) const {
        return ( c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c ) ;
    }
};

// S �P T ��\iter���O, Fn ���禡�������O
template <class S , class T , class Fn>
void  convert( S i1 , S i2 , T i3 , Fn fn ) {
    for ( S i = i1 ; i != i2 ; i++ , i3++ )  *i3 = fn( *i ) ;
}

int main() {

    istreambuf_iterator<char>  in(cin) ;
    ostream_iterator<char>     out(cout) ;
    
    // �N��J���^��y�l�����Ҧ��^��r���ন�j�g���X
    convert( in , istreambuf_iterator<char>() , out , to_upper() ) ;

    return 0 ;

}

