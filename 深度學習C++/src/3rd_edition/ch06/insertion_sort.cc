#include <iostream>
#include <vector>

using namespace std ;

int main() {

    int  i , j , no , tmp ;
    
    cout << "> ��J��ƭӼ� : "  ;
    cin >> no ;

    // �w�q�@ no ����ƪ��V�q�}�C
    vector<int>  data(no) ;
    
    cout << "> �п�J " << no << " �ӼƦr : " ;
    for ( i = 0 ; i < data.size() ; ++i ) cin >> data[i]  ;

    // ���洡�J�Ƨ�
    for ( i = 1 ; i < data.size() ; ++i ) {
    
        // ���e��ժ���Ʀr�����e�������j����
        for ( j = i ; j > 0 ; --j ) {

            if ( data[j] >= data[j-1] ) 
                break ;
            else {
                // �Y�񤧫e�������p�h�P�����
                tmp       = data[j] ;
                data[j]   = data[j-1] ;
                data[j-1] = tmp ;
            } 

        }

    }

    // ��X�Ƨǫ᪺���G
    cout << "\n> �Ƨǫᵲ�G : " ;
    for ( i = 0 ; i < data.size() ; ++i ) cout << data[i] << " " ;
    cout << endl ;

    return 0 ;
    
}

