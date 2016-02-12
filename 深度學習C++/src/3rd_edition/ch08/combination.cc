#include <iostream>
#include <vector>
#include <iomanip>

using namespace std ;

// �ֳz�]�P�{��
void print_combination( const vector<int>& number , 
                        vector<int>& chosen_no , 
                        int depth , int start_index ) {

    int i ;
    static  int  count = 0 ;

    // ���j���`�׻P��쪺���X�ƬۦP
    if ( depth == chosen_no.size() ) {

        // ��X�Ʀr�զX
        cout << setw(3) << ++count << " : " ;
        for ( i = 0 ; i < chosen_no.size() ; ++i ) 
            cout << setw(4) << chosen_no[i] ;
        cout << endl ;

    } else {

        // ���j���j��, �`�@�h�����j��l�U�Эȷ|�۰ʥ[�@
        for ( i = start_index ; i < number.size() ; ++i ) {
            chosen_no[depth] = number[i] ;
            print_combination( number , chosen_no , depth+1 , i+1 ) ;
        }
        
    }
    
}

int main() {
    
    int  no ;
    cout << "> ��J�`���X�ƶq : " ;
    cin  >> no ;

    // number  : �x�s�Ҧ������X
    vector<int>  number(no)  ;

    cout << "> ��J " << no << " �Ӹ��X : " ;
    for ( int i = 0 ; i < no ; ++i ) cin >> number[i] ;

    cout << "> ��J�]�P�X�ƶq : " ;
    cin  >> no ;

    // chosen_no  : �w��쪺���X
    vector<int>  chosen_no(no) ;

    // depth       : ���j�`��
    // start_index : ���j�j�餤����l�U�Э�
    int  depth = 0 , start_index = 0 , count = 0 ;
    print_combination( number , chosen_no , depth , start_index ) ;

    return 0 ;
    
}
        
