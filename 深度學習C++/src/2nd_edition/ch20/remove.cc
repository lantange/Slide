#include <iostream>
#include <algorithm>
#include <iterator>
#include <list>
#include <vector>

using namespace std ;

// �ˬd�O�_������
bool  even( int a ) { return a % 2 == 0 ; }

int main() {
    
    const int S = 8 ;
    int n[S] = { 23 , 45 , 24 , 87 , 76 , 10 , 24 , 55 };

    list<int>                no(n,n+S) ;
    list<int>::iterator      iter1 ;
    
    vector<int>              foo ;
    vector<int>::iterator    iter2 ;

    // �C�L��l��C
    cout << "> ��l���� : " ;
    copy(no.begin(),no.end(),ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    // �h�� 24
    iter1 = remove( no.begin() , no.end() , 24 ) ;
    
    // �C�L�Ѿl����
    cout << "> �h�� 24  : " ;
    copy(no.begin(),iter1,ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    // ���s�]�w no 
    copy(n,n+S,no.begin()) ;

    // �N���Ʒh��
    cout << "> �h������ : " ;
    iter1 = remove_if( no.begin() , no.end() , even ) ;

    // �C�L�Ѿl����
    copy(no.begin(),iter1,ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    // ���s�]�w no 
    copy(n,n+S,no.begin()) ;

    // �h�� 24  �ñN�Ѿl�����ƻs�� foo
    remove_copy( no.begin() , no.end() , back_inserter(foo) , 24 ) ;
    
    // �C�L foo
    cout << "> �h�� 24  : " ;
    copy(foo.begin(),foo.end(),ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    // ���s�]�w foo �P no
    copy(n,n+S,no.begin()) ;
    foo.resize(no.size()) ;

    // �N���Ʒh�� �ñN�Ѿl�����ƻs�� foo
    iter2 = remove_copy_if( no.begin() , no.end() , foo.begin() , even ) ;
    
    // �C�L foo
    cout << "> �h������ : " ;
    copy(foo.begin(),iter2,ostream_iterator<int>(cout," ")) ;
    cout << endl ;

    return 0 ;
    
}

    
