#include <iostream>
#include <algorithm>

using namespace std ;

struct  Equal {
    int  n ;
    Equal( int i ) : n(i) {}
    bool  operator() ( int a , int b ) { return  a%n == b%n ; }
};


int main() {
    
    int  no[8] = { 3 , 5 , 9 , 8 , 7 , 1 , 2 , 5 };
    int  *p = adjacent_find(no,no+8) ;
   
    if ( p == no+8 ) 
        cout << "> �S���۾F�������O�ۦP��" << endl ;
    else
        cout << "> �ۦP���۾F���� : " << *p << endl ;
    
    p = adjacent_find(no,no+8,Equal(4)) ;
    
    if ( p == no+8 ) 
        cout << "> �S���Q 4 �ᰣ�᪺�l�ƬO�ۦP�B�۾F������" << endl ;
    else
        cout << "> �Q 4 �ᰣ�᪺�l�ƬO�ۦP�B�۾F������ : " 
             << *p << endl ;

    return 0 ;

}

    
