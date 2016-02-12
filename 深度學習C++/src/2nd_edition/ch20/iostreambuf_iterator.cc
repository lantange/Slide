#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>

using namespace std ;

int main() {

    const int  S = 5 ;
    double     no[S] = { 3.5 , -2 , 5.75 , -4 , 8.25 };

    // �}���ɮ׷ǳƿ�X
    ofstream                   outfile("number.db",ios::out) ;
    ostreambuf_iterator<char>  out(outfile) ;

    // �r������ p ���V no �}�C���_�l
    char *p = reinterpret_cast<char*>(no) ;

    // �H�r�����覡�����N no �}�C��X���ɮ� number.db
    // number.db ���G�i����
    copy( p , p + S * sizeof(double) , ostreambuf_iterator<char>(out) ) ;

    outfile.close() ;


    // �}���ɮ׷ǳ�Ū�J
    ifstream                   infile("number.db",ios::in) ;
    istreambuf_iterator<char>  in(infile) ;

    double  no2[S] ;
    
    // �r������ p ���V no2 �}�C���_�l
    p = reinterpret_cast<char*>(no2) ;

    // �H�r�����覡�����N�ɮ� number.db ����Ʀs�J no2 �}�C��
    copy( in , istreambuf_iterator<char>() , p ) ;

    // �C�L no2 �}�C
    copy( no2 , no2+S , ostream_iterator<double>(cout,"  ") ) ;
    cout << endl ;

    return 0 ;

}

