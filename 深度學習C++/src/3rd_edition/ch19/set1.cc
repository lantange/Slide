#include <iostream>
#include <set>

using  namespace  std ;

// ������ i ���Ӧ�ƬO�_�� j ���Ӧ�Ƥp
struct  myless {
    bool operator() ( int i , int j ) { return ( i%10 < j%10 ) ; }
};

int main() {
    int  n ; 
    int no[10] = { 13 , 52 , 27 , 19 , 9 , 87 , 45 , 2 , 7 , 23 } ;

    // �N�ƶ��X�P��iter��W�H²�ƦW��
    typedef   multiset<int,myless>  settype ;
    typedef   settype::iterator     setiter ;   

    // �w�q�ƶ��X�P����iter
    settype  foo(no,no+10)     ;             
    setiter  i ;
    pair<setiter,setiter>  iter ;
    
    // �C�L�ƶ��X�Ҧ�����
    for ( i = foo.begin() ; i != foo.end() ; ++i ) cout << *i << ' ' ;
    cout << "\n> "  ;
    
    // �j�M�����A�æL�X�Ҧ��۷��Ʀr
    while ( 1 ) {
        cin >> n ;
        iter = foo.equal_range(n) ;  
        cout << "--> " ;

        if ( iter.first != iter.second ) 
            for ( i = iter.first ; i != iter.second ; ++i ) 
                cout << *i << ' ' ;
        else 
            cout << "�S���۷�����" ;
        
        cout << "\n> " ;
    }
    return 0 ;
}
