#include <iostream>

using namespace std ;

int main() {

    int  i , n , sqrtn ;
    bool is_prime_number ;

    while ( 1 ) {
        
        cout << "> �п�J�@����� ( ��J�t�Ƶ����{�� ) : " ;
        cin >> n ;

        if ( n < 0 ) {
            // ��J�t�ƴ������} while �j��
            break ;
        } else if ( n <= 1 ) {
            // ��J���Ʀr <= 1
            cout << "> ��J���Ʀr�������j�� 1 ���۵M��\n\n" ;
            continue ;
        } else if ( n == 2 ) {
            // ��J���Ʀr�� 2, 2 �����
            is_prime_number = true ;
        } else if ( n % 2 == 0 ) {
            // ��J���Ʀr������, �h���Ƥ��O���
            is_prime_number = false ;
        } else {
            // ��J���Ʀr���j�� 2 ���_��
            is_prime_number = true ;
            
            for ( i = 3 ; i * i <= n ; i = i + 2 ) {
                if ( n % i == 0 ) {
                    // �Y i �� n ���]��, �h n ���O���, 
                    // �ϥ� break ���������j��
                    is_prime_number = false ;
                    break ;         
                }
            }
        }
        cout << "> " << n << ( is_prime_number ? " �O" : " ���O" ) 
             << "���\n\n" ;

    }

    return 0 ;
    
}
