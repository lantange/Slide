#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std ;

int main() {
    
    int          no[8] = { 2 , 1 , 8 , 7 , 4 , 3 , 5 , 9 };
    deque<int>   foo(10,0) ;   // 10 �� 0 

    // �ƻs no �e���Ӥ����� foo ���ĥ|�Ӧ�m����
    copy( no , no+5 , foo.begin()+3 ) ;

    // �N no[4] .. no[6] �� foo ���e�ݤ@�@���J
    copy( no+4 , no+7 , front_inserter(foo) ) ;

    // �ϥ� ostream_iterator �N foo ����ƥ�����X��ù�
    copy( foo.begin() , foo.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;

}

            
