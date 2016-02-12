#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
#include <iomanip>

using namespace std ;

// �]�w���
double  g( double x ) {  return  sin(x)/x ; }

// �w�q��m�C�|���O
enum  Position { upperleft , upperright , lowerleft , lowerright };

// �w�q�禡ø�ϼ˪O���O
template <int row = 21 , int col = 75>
class  Plot_Function {

  private :

    // �x�s�I�x�}�ϧ�
    string  bitmap[row+2] ;
    
    // �Ϧ���ܦ�m
    Position  caption_location ;
    
    // �x�s�禡
    double  (*fn)(double) ;
    string   fn_name ;
    
    // X ���̤j�ȻP�̤p��   f(X) ���̤j�ȻP�̤p��
    double  xmax , xmin ;
    double  ymax , ymin ;

    // �����I�x�}�ϧ�
    void  plot_bitmap() ;
    
    // �]�w X �P Y ���̤j�ȻP�̤p��
    void  setup_caption() ;

  public :
    
    // �غc�禡
    Plot_Function( double (*f)(double) , string name , 
                   double a , double b , 
                   Position loc = upperleft ) ;

    // ���s�]�w X ���̤p�ȻP�̤j��, �Y X �b [a,b] ����, 
    // �P�ɤ]�i�H�]�w��X����m
    void assign( double a , double b , Position loc = upperleft ) ;
    
    // �и���X�B��l
    template <int r, int c>
    friend ostream& operator << ( ostream& out , 
                                  const Plot_Function<r,c>& foo ) ;

};


int main() {

    // �b 17 �C 61 �檺���I�W�e�X��� g(x) = sin(x)/x �b [-10,10] 
    // �������ϧ�
    Plot_Function<17,61>  plot( g , "sin(x)/x" , -10 , 10 ) ;

    // ø��
    cout << plot << endl ;

    // �]�w X �b [-3,20] ����, �B�N�ϥܩ�b���W��
    plot.assign(-3,20,upperright) ;

    // ø��
    cout << plot << endl ;

    return 0 ;

}

// �غc�禡
template <int row , int col>
Plot_Function<row,col>::Plot_Function( double (*f)(double) , 
              string name , double a , double b , Position loc ) 
    : fn(f) , xmin(a) , xmax(b) , caption_location(loc) {

    // �ন�j�g
    for ( int i = 0 ; i < name.size() ; ++i ) 
        if ( name[i] >= 'a' && name[i] <= 'z' ) 
            name[i] = name[i] - 'a' + 'A' ;
    
    fn_name = "F(X)  =  " + name ;
    
    // �����I�x�ι�
    plot_bitmap() ;

    // ���͹ϥ�
    setup_caption() ;

}

// ���s�]�w X ���̤p�ȻP�̤j��, �Y X �b [a,b] ����, �P�ɤ]�i�H
// �]�w��X����m
template <int row , int col>
void  Plot_Function<row,col>::assign( double a , double b , 
                                      Position loc ) {
    xmin = a ;
    xmax = b ;
    caption_location = loc ;
    plot_bitmap() ;
    setup_caption() ;
}


// �����I�x�}�ϧ�
template<int row, int col>
void  Plot_Function<row,col>::plot_bitmap() {

    int  i , r , c ;

    // �_�l�]�w bitmap �r��}�C
    for ( r = 0 ; r < row+2 ; ++r ) bitmap[r].assign(col+2,' ') ;

    // nx , ny : x �P y �b���϶���
    int     nx = col-1 , ny = row-1 ;

    // dx : x �b�W���C�@�Ӱ϶��j�p
    double  dx = (xmax-xmin)/nx ;

    double  x , y[col] ;

    ymin = 1.e20 ;
    ymax = -ymin ;

    // �p���ƭȨç�X��ƪ��̤j�ȻP�̤p��
    for ( i = 0 ; i < col ; ++i ) {
        x    = xmin+i*dx ;
        y[i] = fn(x) ;
        if ( y[i] > ymax ) ymax = y[i] ;
        if ( y[i] < ymin ) ymin = y[i] ;
    }

    // dy : y �b�W���C�@�Ӱ϶����j�p
    double dy = (ymax-ymin)/ny ;

    // ic : y �b���U�Э�
    // ir : x �b���U�Э�
    int  ic = static_cast<int>(-xmin/dx+0.5) ; 
    int  ir = static_cast<int>(-ymin/dy+0.5) ; 

    // �e�X x �b
    if ( 0 <= ir && ir < row ) {
        for ( c = 0 ; c < col ; ++c ) bitmap[ir][c] = '-' ;
        bitmap[ir][col] = '>' ;
        bitmap[ir][col+1] = 'X' ;
    }
        
    // �e�X y �b
    if ( 0 <= ic && ic < col ) {
        for ( r = 0 ; r < row ; ++r ) bitmap[r][ic] = '|' ;
        bitmap[row][ic] = '^' ;
        bitmap[row+1][ic] = 'Y' ;
        if ( 0 <= ic && ic < col ) bitmap[ir][ic] = '+' ;
    }
        
    // ���ͨ���I
    for ( int  c = 0 ; c < col ; ++c ) {
        bitmap[static_cast<int>((y[c]-ymin)/dy+0.5)][c] = '*' ;
    }

}


// �]�w X �P Y ���̤j�ȻP�̤p��
template<int row, int col>
void  Plot_Function<row,col>::setup_caption() {

    int r , c ;
    if ( caption_location == upperleft ) {
        r = row ;
        c = 2 ;
    } else if ( caption_location == upperright ) {
        r = row ;
        c = col-18 ;
    } else if ( caption_location == lowerleft ) {
        r = 4 ;
        c = 2 ;
    } else {
        r = 4 ;
        c = col-18 ;
    }

        
    bitmap[r+1].replace( c , fn_name.size() , fn_name ) ;

    ostringstream  ostr ;

    ostr << "Max Y = " << setw(10) << setprecision(3) 
         << right << scientific << ymax ;
    bitmap[r].replace(c,ostr.str().size(),ostr.str()) ;
    
    ostr.str("") ;
    ostr << "Min Y = " << setw(10) << setprecision(3) 
         << right << scientific << ymin ;
    bitmap[r-1].replace(c,ostr.str().size(),ostr.str()) ;
    
    ostr.str("") ;
    ostr << "Max X = " << setw(10) << setprecision(3) 
         << right << fixed << xmax ;
    bitmap[r-2].replace(c,ostr.str().size(),ostr.str()) ;

    ostr.str("") ;
    ostr << "Min X = " << setw(10) << setprecision(3) 
         << right << fixed << xmin ;
    bitmap[r-3].replace(c,ostr.str().size(),ostr.str()) ;
}
    
// �и���X�B��l
template <int row, int col>
ostream& operator << ( ostream& out , 
                       const Plot_Function<row,col>& foo ) {

    out << string(col+6,'=') << "\n" ;
    for ( int j = row+1 ; j >= 0 ; --j ) 
        out << "I " << foo.bitmap[j] << " I" << "\n" ;
    out << string(col+6,'=') << "\n" ;

    return out ;
    
}
