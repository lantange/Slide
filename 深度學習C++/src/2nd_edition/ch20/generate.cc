#include <iostream>
#include <algorithm>
#include <iterator>
#include <vector>

using namespace std ;

// �ƦC�禡�������O
struct  Sequence {

    // �ƦC�_�l�ȻP���W��
    int  no , step ;  

    Sequence( int a = 0 , int s = 1 ) : no(a) , step(s) {}

    int  operator() ()  {
        int s = no ;
        no += step ;
        return s ;
    }

};


int main() {

    // a �� 5 �ӥ��w���
    vector<int>  a(5) ;

    // �N a �ǦC�]�w�� : 1 2 3 4 5 
    generate(a.begin(),a.end(),Sequence(1,1)) ;

    // �C�L a �ǦC
    copy(a.begin(),a.end(),ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    // �N a �ǦC�����[�W 4 3 2 1 ���|�Ӽ�
    generate_n(back_inserter(a),4,Sequence(4,-1)) ;

    // �C�L a �ǦC
    copy(a.begin(),a.end(),ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    return 0 ;
}

