#include <iostream>
#include <sstream>
#include <fstream>
#include <string>
#include <ctime>
#include <cstdlib>
#include <iomanip>

using namespace std ;

const int MAX_NO = 42 ;

// ���ͤ@���� [a,b] �������ü�
inline  int  random_no( int a , int b ) {

    return  rand()%(b-a+1) + a ;   

    // �Ϊ̨ϥΥH�U�����T���覡���Ͷü�
    // return  a+static_cast<int>((b-a+1.)/(RAND_MAX+1.)*rand()) ;

}

// ��� a �P b �⤸������
inline  void  swap( int& a , int& b ) {
    int  tmp = a ;
    a = b ;
    b = tmp ;
}


// ���� 7 �Ӥ��� [1,42] �������ֳz���X, �̫�@�Ӭ��S�O���X
void  generate_lottery_number( int no[] , int n = 7 ) {

    int  i , j , tmp ;
    for ( i = 0 ; i < MAX_NO ; ++i ) no[i] = i+1 ;

    // �ϥΦ�m��դ覡���ͫe n �Ӽֳz���X 
    for ( i = 0 ; i < n ; ++i ) {
        
        // �H�����ͤ@����դ������U�Ф��� [i,MAX_NO-1] ����
        j = random_no(i,MAX_NO-1) ;

        // �p�G i �P j �U�Ф��P, �h��� no[i] �P no[j] ����
        if ( i != j ) swap( no[i] , no[j] ) ;
        
    }

}

int main() {

    int i , j , n = 10 ;
    int no[MAX_NO] ;

    ofstream        outfile ;    
    ostringstream   outstring ;    

    // �]�w�üƪ��
    srand( static_cast<unsigned>( time(NULL) ) ) ;

    // �̦���X n ���ɮ�
    for ( i = 1 ; i <= n ; ++i ) {

        // �غc�C����X���ɮצW��
        outstring << "lottery" << setfill('0') << setw(3) << i ;

        // �}���ɮ׷ǳƿ�X
        outfile.open( outstring.str().c_str() ) ;

        // ���ͼֳz���X
        generate_lottery_number(no) ;

        // ��X�������X���ɮ�
        for ( j = 0 ; j < 7 ; ++j ) outfile << setw(4) << no[j] ;
        outfile << endl ;

        // �����ɮ�
        outfile.close() ;

        // �N�r���y���� sout ���s�]���Ŧr��
        outstring.str("") ;
    }

    return 0 ;
    
}

