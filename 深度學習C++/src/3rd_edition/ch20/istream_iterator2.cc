#include <iostream>
#include <iterator>

using namespace std ;

int main() {

    istream_iterator<int>  iter(cin) ;
    
    int  sum ;
    // �s�򰵥[�k�ʧ@  �����J�ɮײ׵��r������
    for ( sum = 0  ; iter != istream_iterator<int>() ; iter++ )
        sum += *iter ;

    cout << "��J����`�M = " << sum << endl ;

    return 0 ;
    
}
