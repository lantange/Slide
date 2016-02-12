#include <iostream>
#include <map>
#include <string>
#include <sstream>

using namespace std ;

int main() {

    // �@���a�W��r��
    string   famous_composers = 
       "Vivaldi Handel Bach Haydn Mozart Beethoven Paganini "
       "Schubert Berlioz Weber Mendelssohn Chopin Schumann Liszt "
       "Bramhs Bruch Tchaikovsky Dvorak Sibelius Strawinsky "
       "Shostakovitch" ;
    
    // �ƹ�M�e��
    multimap<char,string>  collection ;
    string                 composer ;
    
    istringstream  istring(famous_composers) ;
    
    // �N�@���a�@�@���X��, �[�J�ƹ�M�e����
    while( istring >> composer ) 
        collection.insert( make_pair(composer[0],composer) ) ;
    
    typedef  multimap<char,string>::iterator  mmiter ;

    char                 letter ;
    mmiter               iter ;

    pair<mmiter,mmiter>  piter ;
    
    while ( 1 ) {
        cout << "> ��J�@���a�W�r���Ĥ@�Ӧr�� : " ;
        cin >> letter ;

        // �Y�O�p�g�r���h�令�j�g, �Y�D�j�g�r���h����Ū�J
        if ( letter >= 'a' && letter <= 'z' ) letter = letter - 'a' + 'A' ;
        if ( letter < 'A' || letter > 'Z' ) break ;

        // �ϥΦr��, �j�M�i�઺�@���a�W��
        piter = collection.equal_range( letter ) ;

        // �C�L���G
        for ( iter = piter.first ; iter != piter.second ; ++iter ) 
            cout << iter->second << "   " ;

        cout << endl ;
    }

    return 0 ;
    
}
