#include <iostream>
#include <iterator>

using namespace std ;

int main() {

    // �w�� cin ���ͤ@��J�w�İϭ��N��
    istream_iterator<int>  iter(cin) ;
    
    int  sum ;

    // �s�򰵥[�k�ʧ@  �����J���Ʀr�� 1 �p����
    for ( sum = 0  ; *iter >= 0 ; iter++ ) sum += *iter ;
    cout << sum << endl ;

    return 0 ;
    
}
