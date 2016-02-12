#include <iostream>
#include <string>

using namespace std ;

// �r���Ƭۥ[
string  bigint_addition( string a , string b ) {

    int  i , tmp ;
    
    // �p���Ʀr�r����׮t��
    int  size_difference = a.length() - b.length() ;

    if ( size_difference < 0 ) size_difference *= -1 ;

    // �N���u���Ʀr�r�ꤧ�e�ɤW�r�� 0 , �ϱo�̫��r�굥��
    if ( a.length() > b.length() ) 
        for ( i = 0 ; i < size_difference ; ++i ) b = '0' + b ;
    else
        for ( i = 0 ; i < size_difference ; ++i ) a = '0' + a ;
    
    string    sum = "" ;    // �r��Ʀr�M
    int     carry = 0  ;    // �[�k���i���

    // �Ѧr�ꪺ�̧��r�����e�[, �N�i�쪺�Ʀr�s�J carry �ܼƤ�
    for ( i = a.length()-1 ; i >= 0 ; --i ) {
        tmp = ( b[i] - '0' ) + ( a[i] - '0' ) + carry ;
        sum = static_cast<char>(( tmp % 10 + '0' )) + sum ;
        carry =  tmp / 10 ;
    }

    // �B�z�̫�ѤU�i��Ʀr
    if ( carry ) sum = static_cast<char>( carry + '0' ) + sum ;
    
    return sum ;

}

int  main() {
    
    string  a , b ;
    
    cout << "> ��J��ӥ���� : " ;
    cin  >> a >> b ;
    
    cout << '\n' << a << " + " << b << " = " 
         << bigint_addition(a,b) << endl ;

    return 0 ;
    
}
