#include <iostream>
#include <queue>
#include <string>
#include <cstdlib>
#include <ctime>

using namespace std ;

int main() {

    int           i ;
    const int     NO = 4 ;
    string  contestant[NO] = { "���@��" , "���G��" , "�]�T��" , 
                               "���|�R" };
    
    // �x�s���Z����
    queue<int>  score ;

    // �]�w�üƺؤl���
    srand( static_cast<unsigned>(time(NULL)) ) ;

    // �H�N���ͼƦr�A�s�J score 
    for ( i = 0 ; i < NO ; ++i )  score.push(rand()%11) ;

    // �� score ���X����
    i = 0 ;
    while ( ! score.empty() ) {
        cout << score.front() << " : " << contestant[i++] << "    " ;     
        score.pop() ;
    }
    cout << endl ;
    
    return 0 ;
}
