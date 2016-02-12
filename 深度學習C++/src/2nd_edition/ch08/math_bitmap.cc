#include <iostream>
#include <string>

using namespace std ;

// �C�ӼƦr�� 5 x 5 ���I�x�}
const int ROW = 5 , COL = 5 ;

// �غc�I�x�}
void  build_bitmap( const string& , string * ) ;

// �C�L�I�x�}
void  print_bitmap( const string * ) ;

// �M���I�x�}
void  clear_bitmap( string * ) ;
    

int main() {
    
    // no     : ����J���Ʀr�r�� 
    // bitmap : �}�C���C�@�C�Һc�����I�x�}�r�����
    string  no , bitmap[ROW] ;

    while( 1 ) {
        cout << "> ��J����Ʀr�� : " ;
        cin >> no ;
        if ( no == "0" ) break ;           // ����
        build_bitmap( no , bitmap ) ;      // �غc�I�x�}���
        print_bitmap( bitmap ) ;           // �C�L�Ʀr���I�x�}
        clear_bitmap( bitmap ) ;           // �M���I�x�}
        cout << endl ;
    }

}
              
// �غc��J�Ʀr�r�ꪺ�I�x�}
void  build_bitmap( const string& no , string bitmap[] ) {

    // �I�x�}�Ʀr : �@�Q�ӼƦr 0 , 1 , 2 , ... , 9
    static unsigned char no_bitmap[10][ROW] = 
        { {14,17,17,17,14} , {4,12,4,4,14} , {14,17,2,4,31}   ,
          {30,1,14,1,30}   , {2,6,10,31,2} , {31,16,30,1,30}  ,
          {15,16,30,17,14} , {31,1,2,4,8}  , {14,17,14,17,14} ,
          {14,17,15,1,30}   };

    int i , n , r , c ;
    for ( r = 0 ; r < ROW ; ++r ) {
        for ( i = 0 ; i < no.size() ; ++i ) {

            // �p��C�@�C�ҹ������I�x�}���
            n = no_bitmap[ no[i] - '0' ][r] ;

            // �C���I�x�}�Ʀr���Y���Ʀr  �h�H�P���N��, �_�h�[�W�ť�
            for ( c = COL-1 ; c >= 0 ; --c ) {
                bitmap[r] += ( n & ( 1 << c ) ? '*' : ' ' ) ;
            }
            
            // �C�ӼƦr�����Ψ�Ӫťչj�}
            bitmap[r] += "  " ;
        }
    }
}

// �C�L�I�x�}
void  print_bitmap( const string * bitmap ) {
    for ( int i = 0 ; i < ROW ; ++i ) cout << bitmap[i] << endl ;
}

// �M���I�x�}
void  clear_bitmap( string bitmap[] ) {
    for ( int i = 0 ; i < ROW ; ++i ) bitmap[i] = "" ;
}
              
              
              
              
              
                
            
    
