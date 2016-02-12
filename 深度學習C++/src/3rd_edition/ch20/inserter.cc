#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std ;

// �x���禡
template <class Iter1, class Iter2>
void   insert( Iter1 from , Iter1 to , Iter2 i3 ) {
    for ( Iter1 i = from ; i != to ; ++i , ++i3 ) *i3 = *i ;
}

int main() {

    // ���ͤ@�Ŧ�C , 4 �� 1 ���V�q�}�C, 8 �Ӥ�������ư}�C
    list<int>     foo ;
    vector<int>   bar(4,1) ;
    int           no[8] = { 2 , 1 , 3 , 8 , 6 , 4 , 9 , 1 } ;

    // �N bar �������������J foo ��C���e��
    insert( bar.begin() , bar.end() , inserter(foo,foo.begin()) ) ;

    // �N no[2] �� no[4] �@ 3 �Ӥ����� foo ��C�������B���J 
    insert( no+2 , no+5 , inserter(foo,foo.end()) ) ;

    list<int>::iterator  i ;
    for ( i = foo.begin() ; i != foo.end() ; ++i ) cout << *i << " " ;
    cout << endl ;

    return 0 ;
    
}
