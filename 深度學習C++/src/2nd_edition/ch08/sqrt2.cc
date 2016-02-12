#include <iostream>
#include <vector>
#include <cmath>             // �ڸ��禡 
#include <iomanip>

using namespace std ;

double  r( const vector<int>& a , int i ) {

    int  n = a.size()-1 ;

    if ( i == 0 )
        return  a[n] ;
    else 
        return  a[n-i] + 1./r(a,i-1) ;

}

int main() {

    double  approx ;                     // �x�s�����
    double  sqrt2 = sqrt(2.) ;           // �p��ڸ� 2
    
    cout << "> �s���Ʀ��� sqrt(2) : \n" ;
    
    for ( int i = 0 ; i <= 15 ; ++i ) {

        vector<int>  a(i+1,2) ;          // �]�w�s���ƫY��
        a[0] = 1 ;                       // �Ĥ@�Ӥ����אּ 1

        approx = r(a,i) ;                // �s���Ʀ��� 

        cout << "c_" << left << setw(2) << i << " : " 
             << fixed << setw(10) << approx 
             << "  �~�t : " << right << scientific 
             << setw(14) << sqrt2-approx << endl ;

    }
    
    return 0 ;
    
}
