#include <iostream>
#include <cmath>

using namespace std ;

int main() {

    //  a X^2 + b X + c = 0 
    double  a , b , c ;
    double  delta ;

    cout << "> �Ш̦���J�@���G����{�����T�ӫY�� : " ;

    cin >> a >> b >> c ;
    delta = b * b - 4. * a * c ;

    if ( delta >= 0. ) {

        // ��Ʈ�
        double  root1 , root2 ;
        root1 = ( -b + sqrt(delta) ) / ( 2. * a ) ;
        root2 = ( -b - sqrt(delta) ) / ( 2. * a ) ;
        cout << "root 1 : " << root1 << '\n' ;
        cout << "root 2 : " << root2 << '\n' ;

    } else {

        // ��Ʈ�
        double  re , im ;
        re = -b / ( 2. * a ) ;
        im = sqrt(-delta) / ( 2. *a ) ;
        cout << "root 1 : " << re << " + " << im << " i" << endl ;
        cout << "root 2 : " << re << " - " << im << " i" << endl ;

    }

    return 0 ;
    
}
