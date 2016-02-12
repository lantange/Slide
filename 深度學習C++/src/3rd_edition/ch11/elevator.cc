#include  <iostream>
#include  <sstream>
#include  <iomanip>
#include  <string>

// �Ӽh�h��
const int MAX_FLOOR = 10 ;          

// �ɭ���ɭ���V
enum  DIRECTION  { up   , down } ;  

// �ɭ���b�Y�Ӽh�O�_���L�����Ϊ̰���
enum  STATUS     { skip , stop } ;  

using  namespace  std ;

int  main() {
    
    int        i  , no ;

    // �]�w���w���ɭ���{�b�Ҧb���Ӽh, �ɭ���V, ������Ӽh
    int        current_floor       = 1         ;
    DIRECTION  direction           = up        ;
    STATUS     floor[MAX_FLOOR+1]  = { skip }  ;
    
    string         line           ;
    istringstream  stops( line )  ;
    
    // �ɭ��謰�s��B��, �ϥ� Ctrl-c �����{��
    while ( 1 ) {
        
        cout << "[" << setw(2) << current_floor << "] : " ;

        // Ū�J�ɭ��谱��Ӽh
        getline( cin , line ) ;
        stops.str( line ) ;

        // �]�w�ɭ��谱��Ӽh
        while ( stops >> no ) {
            if ( ( no >= 1 ) && ( no <= MAX_FLOOR ) ) 
                floor[no] = stop ;
        }
        
        floor[current_floor] = skip ;

        // �ھڿ�J���Ӽh���, �M�w�ɭ��豵�U�Ӫ��ɭ���V
        if ( direction == up || current_floor == MAX_FLOOR ) {

            direction = down ;
            for ( i = current_floor+1 ; i <= MAX_FLOOR ; ++i ) 
                if ( floor[i] == stop ) direction = up ;

        } else {

            direction = up ;
            for ( i = 1 ; i < current_floor ; ++i ) 
                if ( floor[i] == stop ) direction = down ;

        }

        // �ھڤɭ���V, ��X�ɭ���U�@�Ӷ��n����Ӽh
        if ( direction == up ) {

            for ( i = current_floor+1 ; i <= MAX_FLOOR ; ++i ) {
                if ( floor[i] == stop ) {
                    current_floor = i ;
                    break ;
                }
            }
            
        } else {
            
            for ( i = current_floor-1 ; i >= 1 ; --i ) {
                if ( floor[i] == stop ) {
                    current_floor = i ;
                    break ;
                }
            }

        }

        stops.clear() ;    // �M�����~�X�m
        
    }

    return 0 ;
    
}
