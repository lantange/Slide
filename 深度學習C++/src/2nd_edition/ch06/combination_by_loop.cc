#include <iostream>
#include <vector>

using namespace std ;

//  ²��]�P�{�� : �� m �ӼƦr��, �C�L�Ҧ��ѤT�ӼƦr���զX
int main() {
    
    int  i , j , k , m , c = 1 ;
    
    cout << "> �Ʀr�Ӽ� : " ;
    cin  >> m ;
    vector<int>  number(m) ;

    cout << "> �̦���J " << m << " �ӼƦr : " ;
    for ( i = 0 ; i < m ; ++i ) cin >> number[i] ;

    cout << endl ;

    // �� i , j , k �û����|�۵�    
    for ( i = 0 ; i < m ; ++i ) {
        for ( j = i + 1 ; j < m ; ++j ) {
            for ( k = j + 1 ; k < m ; ++k ) {
                cout << c++ << " : " << number[i] << " " 
                     << number[j] << " " << number[k] << endl ;
            }
        }
    }

    return 0 ;
    
}

        
