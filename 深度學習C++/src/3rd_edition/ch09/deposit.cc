#include <iostream>

using namespace std ;

typedef  double  Dollar ;

class  Deposit {

  private :

    // �Ҧ��s�ڱb�����Q�v
    static  double  interest_rate ;

    // �s��
    Dollar      amount ;

  public :

    // �غc�����禡
    Deposit( Dollar money = 0 ) { amount = money ; }

    // �]�w�Ҧ��s�ڱb�����s�Q�v
    static  void  set_rate( double rate ) { 
        interest_rate = rate ; 
    }

    // ��X�s��
    Dollar  deposit() const { return  amount ; }

    // ��X�Q��
    Dollar  interest() const { return  amount * interest_rate ; } 

} ;

// �]�w�s�ڱb�����O�����w�R�A��ƪ�� (�]�i�H�����]���, 
// �������w�q)
double  Deposit::interest_rate = 0.05 ;

int  main() {

    const int no = 5 ;

    // �]�w�s�ڱb��
    Deposit  account[no] = { 100 , 300 , 200 , 350 , 50 } ;

    double  interest_rate ;
     
    cout << "> ��J�Q�v : " ;
    cin >> interest_rate ;
    
    // �]�w�s�ڱb�����s�Q�v 
    Deposit::set_rate(interest_rate) ;

    // �p���`�s�ڻP�`�Q��
    double  total_deposit = 0. , total_interest = 0. ;
    for ( int i = 0 ; i < no ; ++i ) {
        total_deposit  += account[i].deposit() ;
        total_interest += account[i].interest() ;
    }

    cout << "> �`�s�ڬ� : " << total_deposit  << endl ;
    cout << "> �`�Q���� : " << total_interest << endl ;

    return 0 ;
    
}


