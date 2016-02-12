#include <iostream>
#include <fstream>
#include <iterator>

using namespace std ;

struct  to_upper {
    char  operator() ( char c ) const {
        return ( c >= 'a' && c <= 'z' ? c - 'a' + 'A' : c ) ;
    }
};

// S �P T �����N�����O, Fn ���禡�������O
template <class S , class T , class Fn>
void  convert( S i1 , S i2 , T i3 , Fn fn ) {
    for ( S i = i1 ; i != i2 ; i++ , i3++ )  *i3 = fn( *i ) ;
}

int main() {

    ifstream                   infile("episodes.db",ios::in) ;
    ofstream                   outfile("EPISODES.db",ios::out) ;
    
    istreambuf_iterator<char>  in(infile) ;
    ostreambuf_iterator<char>  out(outfile) ;
    
    // �N episodes �ɮפ��Ҧ��^��r���ন�j�g��s�J EPISODES ��
    convert( in , istreambuf_iterator<char>() , out , to_upper() ) ;

    return 0 ;

}

