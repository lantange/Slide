#include <iostream>
#include <cstdlib>
#include <string>

using  namespace  std ;

// �w�q���~�ҥ󸹽X�B�z���O
class  ID_ERR {

  private :

    int  kind ;

  public :

    // �غc�禡
    ID_ERR( int i ) : kind(i) {} ;

    // ���~�T��
    char*  error_msg() const {
        switch ( kind ) {
          case 0 : return "�ҥ�r�����פ���" ;
          case 1 : return "�Ĥ@�Ӧr�������^��r��" ;
          case 2 : return "�Ĥ@�ӼƦr���n�O 1 �� 2" ;
          case 3 : return "�ĤG�ӼƦr�H�ᶷ�n�b 0 �� 9 ����" ;
          case 4 : return "�ˬd�X���~" ;
        }
    }

} ;

// �ˬd��J���ҥ󸹽X�O�_���T
bool  correct_id ( string id ) throw(ID_ERR) {

    // �]�w�[�v�Ƭ�����S�ͦ~ (1756), ��~ (1791) �P�ɦ~ (35)
    static const int mozart[10] = { 1 , 7 , 5 , 6 , 1 , 7 , 9 , 
                                    1 , 3 , 5 };

    int  no[10] , i , tmp , sum ;  

    // �p�G���פ���, �h�Y�X�Ĺs�����~
    if ( id.size() != 10 ) throw  ID_ERR(0) ;

    for ( i = 0 ; i < 9 ; ++i ) {
        
        if ( i == 0 ) {

            // �N�Ĥ@�Ӧr���Ѥp�g�ন�j�g
            if ( ( id[0] >= 'a' ) && ( id[0] <= 'z' ) )  
                id[0] += 'A' - 'a' ;

            // �p�G�Ĥ@�Ӧr�����O�^��r��, �h�Y�X�Ĥ@�����~
            if ( ( id[0] < 'A' ) || ( id[0] > 'Z' ) )  
                throw  ID_ERR(1) ;

            // �N�r���������Ʀr 1 �� 26
            tmp = id[0] - 'A' + 1 ;
            no[0] = tmp / 10 ;
            no[1] = tmp % 10 ;

        } else if ( i == 1 ) {

            // �p�G�Ĥ@�ӼƦr���O 1 �Ϊ� 2, �h�Y�X�ĤG�����~
            if ( ! ( id[1] == '1' || id[1] == '2' ) ) 
                throw  ID_ERR(2) ;

            no[2] = id[1] - '0' ;
            
        } else {

            // �p�G�䥦���r�������Ʀr, �h�Y�X�ĤT�����~
            if ( id[i] < '0' || id[i] > '9' ) throw  ID_ERR(3) ;
            no[i+1] = id[i] - '0' ;

        }

    }

    // �p��X���T���ˬd���X
    sum = no[0] ;
    for ( i = 1 ; i < 10 ; ++i ) sum += no[i] * mozart[i]  ;
    sum = sum % 10  ;
    
    // �p�G�ˬd�X�����T, �h�Y�X�ĥ|�����~
    if ( sum != ( id[9] - '0' ) ) throw  ID_ERR(4) ;
    
    return  true ;
    
}

int  main() {

    string  id ;

    while ( 1 ) {
        
        cout << "> �п�J�ҥ󸹽X : " ;
        cin  >> id ;

        try {  
            if ( correct_id(id) ) cout << "> ���T�r��\n\n" ;
            return 0 ;
        }

        catch ( const ID_ERR& e ) { 
            cout << "> ���~ : " << e.error_msg() << "\n\n" ; 
        }
    }

    return 0 ;
    
}
