#include <iostream>
#include <map>

using namespace std ;

int main() {

    map< char , int >            no ;
    map< char , int >::iterator  iter ;

    char * dna = "ACGTAAGTCCGAGTAATAGA" ;
    
    // �p��U���Q�򪺦���
    for ( int i = 0 ; i < 20 ; ++i ) no[ dna[i] ] += 1 ;

    // �C�L�U���Q���`����
    for ( iter = no.begin() ; iter != no.end() ; ++iter )
        cout << iter->first << " : " << iter->second << endl ;

    return 0 ;
}
