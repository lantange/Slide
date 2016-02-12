#include <iostream>
#include <string>
#include <cstdlib> 

using namespace std ;

int  string_number_sum( const string& line ) {
    
    const  string  number = "0123456789" ;
    
    int j = 0 , i , sum = 0 ;

    while ( 1 ) {
            
        // �ѤU�� j �_��M�Ĥ@�ӼƦr���U�� i, �Y�S���, �����j��
        i = line.find_first_of(number,j) ;
        if ( i == string::npos ) break   ;    

        // �ѲĤ@�ӼƦr�U�� i �_��M�Ĥ@�ӫD�Ʀr���U�� j
        j = line.find_first_not_of(number,i) ;

        // �p�G j �w�g�쥽��, �h�I���̫�@�ӼƦr������j��
        if ( j == string::npos ) {

            // �p�G���Ʀr�q�Ĥ@��}�l�Ϊ̬O�b�Ů椧��  �~�I���Ʀr
            if ( i == 0 || ( i > 0 && line[i-1] == ' ' ) )
                sum += 
                    atoi( line.substr(i,line.length()-i).c_str() ) ;

            break ;
        }

        // �p�G���Ʀr�q�Ĥ@��}�l�Ϊ̬O�b�Ů椧��  �~�I���Ʀr
        if ( i == 0 || ( i > 0 && line[i-1] == ' ' ) ) 
            sum += atoi( line.substr(i,j-i).c_str() ) ; 
        
    }

    return  sum ;
        
}

int main() {

    string  line ;

    while ( 1 ) {
        cout << "> " ;
        getline( cin , line ) ;

        // �p�G���Ŧ� �h�����j�鵲��
        if ( line.empty() ) break ;
        cout << "> " << string_number_sum( line ) << "\n\n" ;
    } 

    return 0 ;
    
}

