#include <iostream>
#include <iterator>
#include <list>
#include <vector>

using namespace std ;

// 泛型函式
template <class Iter1, class Iter2>
void   insert( Iter1 from , Iter1 to , Iter2 i3 ) {
    for ( Iter1 i = from ; i != to ; ++i , ++i3 ) *i3 = *i ;
}

int main() {

    // 產生一空串列 , 4 個 1 的向量陣列, 8 個元素的整數陣列
    list<int>     foo ;
    vector<int>   bar(4,1) ;
    int           no[8] = { 2 , 1 , 3 , 8 , 6 , 4 , 9 , 1 } ;

    // 將 no[2] 到 no[4] 共 3 個元素由串列的前端一一插入
    insert( no+2 , no+5 , front_inserter(foo) ) ;

    // 將全部的向量陣列元素由串列的末尾加入
    insert( bar.begin() , bar.end() , back_inserter(foo) ) ;

    list<int>::iterator  i ;
    for ( i = foo.begin() ; i != foo.end() ; ++i ) cout << *i << " " ;
    cout << endl ;

    return 0 ;
    
}
