#include  <iostream>
#include  <fstream>
#include  <string>

using namespace std ;

int main() {

    // ��X�᪺�C�@���r���Ƴ̦h�� 45 �Ӧr��
    const int     max_char_per_line = 45 ;

    // ��X��r���_�l�r��
    char          starting_char     = ' ' ;

    int           i , no , total_char  ;
    unsigned int  a , num[4] ;
    string        infile , line ;

    cout << "> ��J�G�줸�ɦW : " ;
    cin  >> infile ;
    cout << "\n> encoded  output :" << endl ;

    // �}�ҤG�줸�����    
    ifstream  in( infile.c_str() , ios::in | ios::binary ) ;

    // num ���w�w�줸�}�C�Ω�@�줸�B��
    // num[3] = 111111              
    // num[2] = 111111000000
    // num[1] = 111111000000000000  
    // num[0] = 111111000000000000000000

    num[3] = 63                 ;   num[2] = ( num[3] << 6 ) ;
    num[1] = ( num[3] << 12 )   ;   num[0] = ( num[3] << 18 ) ;

    while ( 1 ) {
        
        line = "" ;
        total_char = 0 ;
        
        do {

            // Ū�� 3 �줸�ո�ƨ�@��� a
            a = 0 ;
            in.read( reinterpret_cast<char*>(&a) , 3 ) ;

            // �p�G�ϥ� MOTOROLA �������B�z�� :  
            // �ѩ�uŪ�F�T�Ӧ줸�ժ����, �BŪ�J����ƳQ��b
            // ��ƥ���T�Ӧ줸�ժ���m, �]��������Ƹ�ƦV��
            // �k���K�Ӧ줸��m
            // a >>= 8  ;

            // �p�G�ϥέ^�N�� (INTEL) �������B�z�� :
            // �h���N�W�@��{���X�H�U��{���X���N, 
            // �ت��b�NŪ�J���� 1 �ӻP�� 3 �Ӧ줸�ո�ƹ��
            a = ( ( ( a & 255 ) << 16 ) | ( a & (255<<8) ) | 
                  ( a >> 16 ) ) ;
            
            if ( in.gcount() == 0 ) 

                break ;         // �p�G�SŪ�������, �h���}

            else {

                // �p��Ū�J���r���Ƭ۷��h�֤��Ӧ줸�����γ��
                no = in.gcount() + 1 ;
                
                // �H���줸���@���, �}�l��X
                for ( i = 0 ; i < no ; ++i ) 
                    line  += ( ( a & num[i] ) >> ((3-i)*6) ) + 
                             starting_char ;

                // �p���Ū�J���r����
                total_char += in.gcount() ;
        
            }
            
        } while ( total_char < max_char_per_line ) ;

        // �C�L�`�r���Ƥ���X��r��
        cout << static_cast<char>(total_char+starting_char) 
             << line.c_str() << endl ;

        // �ɮץ���
        if ( in.gcount() == 0 ) break ;
            
    }

    in.close() ;

    return 0 ;

}
