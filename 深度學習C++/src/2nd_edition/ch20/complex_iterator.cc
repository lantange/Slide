#include <iostream>
#include <complex>     // �ϥνƼƼҪO���O
#include <iterator>

using namespace std ;

int main() {

    complex<double>  c , sum = 0 ;

    cout << "��J : " ;

    istream_iterator< complex<double> >  iter(cin) ;

    // ����[�J�ƼƸ��  ���즬��׵��r������
    for ( ; iter != istream_iterator< complex<double> >() ; iter++ ) 
        sum += *iter ;
    
    cout << "�`�M : " << sum << endl ;
    
}

