#include <iostream>
#include <algorithm>
#include <vector>

using namespace std ;

// �ˬd�O�_��������
struct  even {
    bool operator() ( int a , int b ) const { 
        return ( a % 2 == 0 && b % 2 == 0 ) ? true : false ; 
    }
};


int main() {
    
    int          foo[5] = { 2 , 2 , 4 , 6 , 8 };
    vector<int>  bar(5,2) ;   // 5 �� 2 

    // �ϥΤ�r true �P false �ӥN��u���Ȫ���X
    cout << boolalpha ;

    cout << equal(foo,foo+5,bar.begin()) << endl ;
    cout << equal(foo,foo+5,bar.begin(),even()) << endl ;

    return 0 ;
    
}

            
