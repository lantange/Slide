#include <iostream>

using namespace std ;

int main() {

    int   i , j ;
    
    char  a[30] = "��~����A�����v�v�a�C" ;
    char  b[30] = "�ʤ��ն�A�p���p�p�ѡC" ;
    
    char  c[60] ;

    // �ƻs�Ĥ@�Ӧr��, �B�O�d�Ŧr���U��    
    for ( i = 0 ; a[i] != '\0' ; ++i )  c[i] = a[i] ;
    
    // �ѲĤ@�Ӧr�ꪺ�Ŧr���U�ж}�l�ƻs
    for ( j = 0 ; b[j] != '\0' ; ++j )  c[i+j] = b[j] ;
    
    // �ɤW�Ŧr��
    c[i+j] = '\0' ;
    
    cout << c << endl ;

    return 0 ;
    
}
