#include <iostream>
#include <algorithm>
#include <string>

using namespace std ;

int main() {
    
    string  foo = "TREK" ;
    string  bar = "startrek" ;
    
    cout << "��իe : " << foo << " " << bar << endl ;
    swap_ranges( foo.begin() , foo.end() , bar.begin()+4 ) ;
    cout << "��ի� : " << foo << " " << bar << endl ;

    return 0 ;
    
}

    
