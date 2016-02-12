#include <iostream>
#include <vector>         // �ϥΦV�q�}�C�e���P���N��
#include <algorithm>      // �ϥαƧǺt��禡         

using namespace std ;

// (4) �w�q�@�禡�������O : �ΥH����ⵧ��ƪ��Ӧ�Ʀr�j�p
template <class T>
struct  Remainder {
    bool  operator() ( const T& a , const T& b ) const { 
        return  a%10 > b%10 ;
    }
} ;

// (5) �C�L�e��
template <class T>
void  print_container( const T& iter1 , const T& iter2 , char *sep ) {
    for ( T itr = iter1 ; itr != iter2 ; ++itr ) cout << *itr << sep ;
} 

int  main() {
    
    // (1) �w�q�@�ӥi�H�x�s 20 �Ӿ�ƪ��V�q�}�C�e��
    vector<int>  foo(20) ;          

    // (2) �w�q�@�Ӱw���ƦV�q�}�C��iter����
    vector<int>::iterator  itr ;   

    // �Q��iter����N��� 1 �� 20 �@�@���s�J���V�q�}�C��
    int  no = 1 ;
    for ( itr = foo.begin() ; itr != foo.end() ; ++itr ) *itr = no++ ;

    // (3) �Q�αƧǺt��禡�N�V�q�}�C�����̭Ӧ�ƪ��j�p�Ѥj�ܤp���@�Ƨ�
    sort( foo.begin() , foo.end() , Remainder<int>() ) ;

    // (5) �Q�Ψ禡�N�V�q�}�C�L�X�A�B���������H�@�ťդ��}
    print_container( foo.begin() , foo.end() , " " ) ;
    cout << endl ;

    return 0 ;
   
}
