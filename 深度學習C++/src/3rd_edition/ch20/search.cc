#include <iostream>
#include <algorithm>

using namespace std ;

// ��ƬO�_�P���_�ƩΪ̬O����
bool  odd_even( int a , int b ) {  return a%2 == b%2 ; }

int  main() {

    const int S1 = 10 , S2 = 7 ;

    // �w�q ��Ʈw �P �˫~ �}�C
    int  databank[S1] = { 1 , 2 , 3 , 4 , 5 , 6 , 7 , 8 , 9 , 0 };
    int  sample[S2]    = { 8 , 6 , 7 , 8 , 9 , 0 , 3 };

    int   i , j , len , *p ;

    // �C�L��Ʈw
    cout << "> databank : " ;
    for ( i = 0 ; i < S1 ; ++i ) cout << databank[i] << " " ;
    cout << endl << endl ;

    // �b��Ʈw�ǦC����M��˫~���̪�����ƧǦC
    for ( len = S2 ; len > 0 ; --len ) {
        for ( i = 0 ; i+len <= S2 ; ++i ) {

            // �C�L�ҭn��M���˫~�l�ǦC
            cout << "> ��M�ǦC : " ;
            for ( j = i ; j < i+len ; ++j ) cout << sample[j] << " " ;
            cout << endl ;

            // �b��Ʈw�ǦC����M sample[i] �� sample[i+len-1] �l�ǦC
            p = search( databank , databank+S1 , sample+i , 
                        sample+i+len ) ;
            
            /*********************************************************
            // �b��Ʈw�ǦC����M sample[i] �� sample[i+len-1] �l�ǦC
            // ��M���󬰦P���_�Ʃΰ���
            // 
            p = search( databank , databank+S1 , sample+i , 
                        sample+i+len , odd_even ) ;
            **********************************************************/

            // �Y�w���, �h�C�L�������Ӱj��
            if ( p != databank+S1 ) {
                cout << "> �w�b��Ʈw�����˫~���̪��l�ǦC : " ;
                for ( j = 0 ; j < len ; ++j ) cout << *(p+j) << " " ;
                goto  NEXT ;
            }
        }
    }
    
    cout << "> ��Ʈw�ǦC�����]�t�˫~������l�ǦC ! "  ;
    
    NEXT :  
        cout << endl << endl ;
    
    // �b��Ʈw�ǦC����M�˫~���̪�����ƧǦC
    // �����P���_�Ʃΰ��ƪ�����
    for ( len = S2 ; len > 0 ; --len ) {
        for ( i = 0 ; i+len <= S2 ; ++i ) {

            // �C�L�ҭn��M���˫~�l�ǦC
            cout << "> ��M�ǦC : " ;
            for ( j = i ; j < i+len ; ++j ) cout << sample[j] << " " ;
            cout << endl ;

            // �b��Ʈw�ǦC����M sample[i] �� sample[i+len-1] �l�ǦC
            // ��M���󬰦P���_�Ʃΰ���
            p = search( databank , databank+S1 , sample+i , 
                        sample+i+len , odd_even ) ;

            if ( p != databank+S1 ) {
                cout << "> �w�b��Ʈw�����˫~���̪��l�ǦC : " ;
                for ( j = 0 ; j < len ; ++j ) cout << *(p+j) << " " ;
                cout << endl ;
                return 0 ;
            }
        }
    }
    
    cout << "> ��Ʈw�ǦC�����]�t�˫~������l�ǦC ! "  ;
    cout << endl ;

    return 0 ;
    
}

    
    
    
    
