#include <iostream>
#include <algorithm>
#include <iterator>

using namespace std ;

int main() {

    const  int  S = 7 ;
    int         no[S] ;

    // �N no �}�C�� 1, ��C�L 
    fill(no,no+S,1) ;
    copy(no,no+S,ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    // �ϥ� fill_n �񺡭Y�z�ӼƦr
    int  i = 1 , size = S - 2 ;
    for ( ; size > 0 ; ++i , size -= 2 ) {
        fill_n(no+i,size,i+1) ;
        copy(no,no+S,ostream_iterator<int>(cout," ")) ;
        cout << endl ;
    }
    
    return 0 ;

}

            
