#include <iostream>
#include <fstream>
#include <iterator>
#include <algorithm>
#include <list>

using namespace std ;

int main() {
    
    list<int>  foo ;
    ifstream   infile("data.db") ;
    istream_iterator<int>  in(infile) ;

    // �� data.db ��Ū�J��Ƥ@���@�����J��C foo ���e�ݫ�L�X
    copy( in , istream_iterator<int>() , front_inserter(foo) ) ;
    copy( foo.begin() , foo.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;
    
}







