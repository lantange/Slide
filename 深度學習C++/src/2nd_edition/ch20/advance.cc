#include <iostream>
#include <iterator>
#include <list>
#include <string>

using namespace std ;

int main() {

    string                Q = "Must you be so linear, Jean-Luc" ;
    list<char>            startrek(Q.begin(),Q.end()) ;
    list<char>::iterator  itr1 , itr2 ;
 
    // itr1 �P itr2 �����V��l����m
    itr1 = itr2 = startrek.begin() ;

    // itr1 �P itr2 ���O����e�i 5 �P 12 �Ӧr����L�X
    advance(itr1,5) ;
    advance(itr2,12) ;
    cout << *itr1 << " "  << *itr2 << endl ;
    
    // �p���̤������r����
    cout << distance(itr1,itr2) << endl ;

    return 0 ;
    
}

    
    
