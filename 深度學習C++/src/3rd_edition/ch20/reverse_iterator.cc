#include <iostream>
#include <iterator>
#include <vector>

using namespace std ;

int main() {
    
    // �w�q foo �V�q�}�C�s�J 1 �� 10 ���Q�Ӿ��
    vector<int>  foo ;
    for ( int i = 0 ; i < 10 ; ++i ) foo.push_back(i+1) ;
    
    // �]�w�@�f�V���N�վ㾹����, �B�_�l��}�b��������@��
    reverse_iterator< vector<int>::iterator >   riter(foo.end()) ;

    // ���ưf�V���e, �C���L�X��ƫ���e��Ӥ���
    for( ; riter.base() > foo.begin() ; riter += 2 ) cout << *riter << " " ;
    cout << endl ;

    return 0 ;
    
}
