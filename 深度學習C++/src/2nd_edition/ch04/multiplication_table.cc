#include <iostream>
#include <iomanip>

using namespace std ;

int main() {

   int  i , j ;

   for ( i = 1 ; i < 10 ; ++i ) {
      for ( j = 1 ; j < 10 ; ++j ) {
         // setw(2) ��ܺ򱵦b�᪺��ƥ� 2 �檺�e�צL�X  
         cout << j << 'x' << i << "=" << setw(2) << i*j << " " ;
      }
      cout << '\n' ;
   }

   return 0 ;
   
}

