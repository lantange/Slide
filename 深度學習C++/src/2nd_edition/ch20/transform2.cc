#include <iostream>
#include <iterator>
#include <algorithm>
#include <fstream>
#include <functional>

using namespace std ;

int main() {
    

    // data1 : 2 7 3 9 4 5 ,  data2 : 2 0 3 8 4 3
    ifstream  file1("data1") , file2("data2") ;
    ofstream  file3("data3") ;
 
    // ���X data1 �P data2 �ɮפ����, �����N�ۭ���Ʀr�s�J�ɮ� data3
    transform( istream_iterator<int>(file1) , istream_iterator<int>() ,
               istream_iterator<int>(file2) , 
               ostream_iterator<int>(file3," ") , multiplies<int>() ) ;
    
    return 0 ;
    
}

