#include <iostream>
#include <iterator>
#include <string>
#include <vector>

using namespace std ;

// ����r�����
bool  ssize( const string& a , const string& b ) {
    return  a.size() < b.size()  ;
}

int main() {
    
    const int S = 8 ;
    string  Picard[S] = { "I" ,  "am" ,  "Locutus" ,  "of" ,  
                          "Borg" ,  "Resistance" , "is" ,  "futile" } ;

    vector<string>  Locutus ;
    
    // �N Picard �r��}�C�̦r����ץѤp��j�ƦC�ƻs�� Locutus
    for ( int i = 1 ; i <= S ; ++i ) {
        // ���s�]�w Locutus ������
        Locutus.resize(i) ;
        partial_sort_copy( Picard , Picard+S , 
                           Locutus.begin() , Locutus.end() , ssize ) ;
        copy( Locutus.begin() , Locutus.begin()+i , 
              ostream_iterator<string>(cout," ") ) ;
        cout << endl ;
    }
    cout << "> ��l�r��}�C : " ;
    copy( Picard , Picard+S , ostream_iterator<string>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}

    
