#include <iostream>
#include <iomanip>
#include <vector>

using namespace std ;

// �N�b�P�ؿ�������ɮ׵{���X�[�J
#include "date.cc" 

// �ӤH�b�����
class  Account {

  private :

    static  double  interest_rate            ;   // �~�Q�v
    
    int             transaction_no           ;   // �������
    vector<bool>    is_interest              ;   // �O�_�����
                                                 // �Q�����J
    vector<double>  balance                  ;   // �l�B
    vector<double>  transaction              ;   // ������B
    vector<Date>    transaction_date         ;   // ������
    
    // �p��Y�~���ĴX�����ұo�Q��
    void  add_interest( int year , int time ) {

        // �C��Q��
        double daily_interest_rate = interest_rate / 365 ;
        
        int i , index ;
        int day_count ;
        
        // �ѩҦ�����Ƥ�, ��M�s���Y�~�ĴX�����Ĥ@����ƤU��
        for ( i = 0 ; i < transaction_no ; ++i ) {
            if ( transaction_date[i].year == year ) {
                if ( time == 1 ) {
                    if ( transaction_date[i].mon <= 6 ) index = i ;
                } else {
                    if ( transaction_date[i].mon > 6 )  index = i ;
                }
            }
        }

        // �O���Q�������J���
        if ( time == 1 ) 
            transaction_date.push_back( Date(year,7,1) ) ;
        else
            transaction_date.push_back( Date(year+1,1,1) ) ;

        
        // �p��ѼƻP�Q��
        double  interest = 0 ;
        for ( i = index ; i < transaction_no ; ++i ) {
            day_count = transaction_date[i+1] - transaction_date[i] ;
            interest += balance[i] * day_count * daily_interest_rate;
        }

        // ��s���
        is_interest.push_back( true ) ;
        transaction.push_back( interest ) ;
        balance.push_back( balance.back() + interest ) ;
        transaction_no = transaction.size() ;

    }
    
    // �C�L������Y
    void  print_transaction_header() const {
        cout << setw(6) << "���" << setw(14) << "����" 
             << setw(15) << "�s��" << setw(15) << "����" 
             << setw(15) << "�l�B" << '\n' ;
    }

    // �C�L�浧����ӥ�
    void  print_single_transaction( int i ) const {

        cout << transaction_date[i] 
             << setw(10) << ( is_interest[i] ? "�Q��" : " " ) ;

        cout.setf(ios::fixed,ios::floatfield) ;
        
        if ( transaction[i] >= 0. ) 
            cout << setw(15) << setprecision(2) << transaction[i] 
                 << setw(15) << " " ;
        else
            cout << setw(15) << " " << setw(15) << setprecision(2) 
                 << transaction[i] ;
        
        cout << setw(15) << balance[i] << setprecision(0) << '\n' ;

        cout.unsetf(ios::fixed) ;

    }
    

  public :

    // �]�w����    
    Account() : transaction_no(0) {}
    
    // �C�L�Ҧ�����ӥ�
    void  print_all_transactions() const {
        print_transaction_header() ;
        for ( int i = 0 ; i < transaction_no ; ++i ) {
            print_single_transaction(i) ;
        }
    }

    // ����B�z    
    bool  make_transaction( const Date& today , double amount ) {

        // �p�G�w�g������O��
        if ( transaction_no ) {

            // �W������ɶ�
            Date  date = transaction_date.back() ;

            if ( today < date ) {
                cout << "> ��J������w�g�L��\n" ;
                return false ;
            }

            print_transaction_header() ;

            // �p��Q��
            bool  first_day = true ;
            while ( date <= today ) {

                if ( ( date.mon ==  7 && date.day == 1 ) ||
                     ( date.mon ==  1 && date.day == 1 ) ) {
                    if ( ! first_day ) {
                        if ( date.mon ==  7 ) 
                            add_interest( date.year , 1 ) ;
                        else 
                            add_interest( date.year-1 , 2 ) ;

                        print_single_transaction(transaction_no-1) ;
                    }
                }

                date = date.next_date() ;
                first_day = false ;
            }

            // �s�ڤ���
            if ( -amount > balance.back() ) return false ;

            balance.push_back( balance.back() + amount ) ;

        } else {

            // �Ĥ@�����, ���ണ��
            if ( amount < 0. ) return false ;

            print_transaction_header() ;
            balance.push_back( amount ) ;
            
        }
        
        // ��s���
        is_interest.push_back( false ) ;
        transaction_date.push_back( today ) ;
        transaction.push_back( amount ) ;

        // �C�L����������
        print_single_transaction(transaction_no) ;
        transaction_no = transaction.size() ;
        return true ;
        
    }

    // �C�L����T��
    void  print_transaction_message() const {
        cout << "> �w��ϥέӤH�M�ε����l��, �п�ܥH�U�A�ȶ���\n" 
             << "  [1] �s�ڥ��    [2] ���ڥ��  " 
             << "  [3] �C�L����    [4] ���}\n" ;
    }

};

// �]�w�Q��
double  Account::interest_rate = 0.1 ;

int main() {
    
    int      option ;
    
    Account  foo    ;
    Date     date   ;
    double   amount ;
    
    while ( 1 ) {
        
        foo.print_transaction_message() ;
        cout << "> " ;
        cin >> option ;
        
        if ( option == 1 || option == 2 ) {

            // �s�� �P ����
            cout << "> ��J����P���B : " ;
            cin >> date >> amount ;

            // �����ڪ����B���t��
            if ( option == 2 && amount > 0. ) amount *= -1 ;

            foo.make_transaction(date,amount) ;

        } else if ( option == 3 ) {

            // �C�L�Ҧ��������
            foo.print_all_transactions() ;

        } else {

            // ����
            break ;

        }

        cout << endl ;
        
    }

    return 0 ;
    
}

