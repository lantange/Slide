#include  <iostream>
#include  <string>
#include  <sstream>
#include  <iomanip>

using namespace std ;

int main() {
    
    string         line ;
    istringstream  math_string ;
    
    int      no , sum ;
    char     op ;
    
    // ���ư���, �����J�ťզ欰��
    while ( 1 ) {

        cout << "> " ;
        
        // Ū�J�@���ƫ�s�J�r���Ʀ�y����
        getline( cin , line ) ;
        if ( line == "" ) break ;
        
        math_string.str( line ) ;

        // Ū�J�Ĥ@�ӼƦr
        math_string >> sum ;

        // �Ѧr���Ʀ�y����Ū�J�@�ӹB��r���P�Ʀr
        while ( math_string >> op >> no ) {

            cout << setw(3) << sum << ' ' ;
            ( op == '+' ) ? ( sum += no ) : ( sum -= no ) ;

            cout << op << ' ' << setw(3) << no << " = " 
                 << setw(3) << sum << endl ;
            
        }

        cout << endl ;

        // �M�����e����J���~�X�m, �H�Q�����ƪ�Ū��
        math_string.clear() ;

    }

    return 0 ;
    
}
