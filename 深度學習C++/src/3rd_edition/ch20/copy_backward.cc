#include <iostream>
#include <algorithm>
#include <iterator>
#include <deque>

using namespace std ;

int main() {
    
    int          no[8] = { 2 , 1 , 8 , 7 , 4 , 3 , 5 , 9 };
    deque<int>   foo(10,0) ;   // 10 �� 0 

    // �N no[1] .. no[3] �T�Ӥ����л\�b foo ��C, 
    // �B��k��ɬ� foo.end()-2, �Y�˼ƲĤG�Ӥ���
    //
    copy_backward( no+1 , no+4 , foo.end()-1 ) ;

    // �ϥ� ostream_iterator �N foo ����ƥ�����X��ù�
    copy( foo.begin() , foo.end() , ostream_iterator<int>(cout," ") ) ;
    cout << endl ;

    return 0 ;

}

            
