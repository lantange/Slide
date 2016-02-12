#include <iostream>
#include <string>
#include <queue>

using  namespace  std ;

struct  Record {
    string        name ;
    int          score ;
    Record( const string& n , int s ) : name(n) , score(s) {}
};

// �w�q Record ���Z���P�_��
bool  operator< ( const Record& a , const Record& b ) {
    return  a.score < b.score ;
}

// ��X�B��l
ostream&  operator<< ( ostream& out , const Record& foo ) {
    return  out << foo.name << " : " << foo.score ;
}

int main() {

    // �ϥιw�]�� less<Record> ���P�_�u�����ǼзǡA
    // ���ƧC���u�����Ǥ]�p
    priority_queue<Record>  contestant ;

    // ��J���ɰO������ɪ��u����C��
    contestant.push( Record("���@��" , 7 ) ) ;  
    contestant.push( Record("���G��" , 5 ) ) ;
    contestant.push( Record("�]�T��" , 9 ) ) ;
    contestant.push( Record("���|�R" , 8 ) ) ;
    
    // �C�L���G�A�̦��L�X
    while ( ! contestant.empty() ) {
        cout << contestant.top() << "   " ;
        contestant.pop() ;
    }
    cout << endl ;
    
    return 0 ;
}
