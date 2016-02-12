#include <iostream>
#include <set>

using  namespace  std ;

// ������ i ���Ӧ�ƬO�_�� j ���Ӧ�Ƥp
template <class T>
struct  myless {
    bool operator() ( T i , T j ) const { return ( i%10 < j%10 ) ; }
};

int main() {

    int no[10] = { 13 , 52 , 27 , 19 , 9 , 87 , 45 , 2 , 7 , 23 } ;

    multiset<int,myless<int> >  foo(no,no+10) ;

    cout << foo.key_comp()(24,33) << endl ;    // �L�X : 0
    cout << foo.key_comp()(24,74) << endl ;    // �L�X : 0
    cout << foo.key_comp()(24,15) << endl ;    // �L�X : 1

    return 0 ;
}
