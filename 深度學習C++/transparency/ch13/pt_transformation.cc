#include <iostream>
#include <vector>
#include <cmath>
#include <sstream>
#include <string>

using  namespace  std ;

// �w�q����, ����, �P�Z��������
typedef  double  Angle ;
typedef  double  Length ;
typedef  double  Distance ;

// �]�w PI
const  double  PI = 3.14159265358979 ;

// �]�w�ഫ���O : ���� ���� ��g
enum  Transformation_Type { TRA , ROT , REF } ;

// �X��y���ഫ : ��H��¦���O
class  Geometric_Transformation {

  protected :
    
    double  m[2][3] ;  // �ഫ�x�}
    
  public :

    // �p��s���ഫ�x�} A = M A : ���ഫ�x�}���n
    void  update_transformation_matrix( double a[2][3] ) {

        int i , j ;
        
        static  double tmp[2][3] ;
        for ( i = 0 ; i < 2 ; ++i ) 
            for ( j = 0 ; j < 2 ; ++j ) 
                tmp[i][j] = m[i][0] * a[0][j] + m[i][1] * a[1][j] ;

        tmp[0][2] = m[0][0]*a[0][2] + m[0][1]*a[1][2] + m[0][2] ;
        tmp[1][2] = m[1][0]*a[0][2] + m[1][1]*a[1][2] + m[1][2] ;
        
        for ( i = 0 ; i < 2 ; ++i ) 
            for ( j = 0 ; j < 3 ; ++j ) a[i][j] = tmp[i][j] ;
    
    }
    
    // �^���ഫ������
    virtual Transformation_Type  get_transformation_type() 
        const = 0 ;

    // �����Ѻc�禡
    virtual ~Geometric_Transformation() {}

} ;


typedef  Geometric_Transformation  GT ;


// �������O
class  Translation : public GT {

  private :

    Distance  dx , dy ;   // �x�s�� X �P Y �������Z��
    
  public :

    // �]�w�ഫ�x�}
    Translation( Distance x , Distance y ) : dx(x) , dy(y) {
        m[0][0] = 1. ;  m[0][1] =  0. ; m[0][2] = dx ;
        m[1][0] = 0. ;  m[1][1] =  1. ; m[1][2] = dy ;
    }

    Transformation_Type get_transformation_type() const {
        return Transformation_Type( TRA ) ;
    }

} ;

// �������O
class  Rotation : public GT {

  private :

    Angle  angle ;

  public :

    // �]�w�ഫ�x�}, ��J���ת���쬰��
    Rotation( Angle a ) : angle(PI*a/180.)  { 
        double  c = cos(angle) , s = sin(angle) ;
        m[0][0] = c  ;  m[0][1] = -s  ; m[0][2] = 0. ;
        m[1][0] = s  ;  m[1][1] =  c  ; m[1][2] = 0. ;
    };

    Transformation_Type get_transformation_type() const {
        return Transformation_Type( ROT ) ;
    }

};

// ��g���O
class  Reflection : public GT {

  private :

    Angle  angle ;

  public :

    // �]�w�ഫ�x�}, ��J���ת���쬰��
    Reflection( Angle a ) : angle(PI*a/180.) {
        double  c = cos(2.*angle) , s = sin(2.*angle) ;
        m[0][0] = c  ;  m[0][1] =  s  ; m[0][2] = 0. ;
        m[1][0] = s  ;  m[1][1] = -c  ; m[1][2] = 0. ;
    };

    Transformation_Type get_transformation_type() const {
        return Transformation_Type( REF ) ;
    }

};


// �����I
class  Point {

  private :

        double   x , y ;   // �����I���y��

  public :

    // �غc�禡
    Point() {}
    Point( double a , double b ) : x(a) , y(b) {}

    // �^���I�g�L�@�s�ꪺ�X���ഫ�᪺�y��
    Point  transformation( const vector<GT*>& gt ) const ;

    // �и���J�P��X�B��l
    friend  istream&  operator>> ( istream& in , Point& pt ) {
        return  in >> pt.x >> pt.y ;
    }

    friend  ostream&  operator<< ( ostream& out , 
                                   const Point& pt ) {
        return  out << "( " << pt.x << " , " << pt.y << " )" ;
    }
    
} ;

// �^���I�g�L�@�s�ꪺ�X���ഫ�᪺�y��
Point  Point::transformation( const vector<GT*>& gt ) const {

    // �]�w��l���ഫ�x�}�����x�}
    double  m[2][3] = { {1,0,0},{0,1,0} } ;
     
    // ���ƭp��C���X���ഫ�᪺�ഫ�x�} m
    for ( int i = 0 ; i < gt.size() ; ++i ) {
        gt[i]->update_transformation_matrix(m) ;
    }

    // �N�ഫ�x�}���W��l�I�y�Ц�m��  ���ͷs�I��X
    return  Point( m[0][0] * x + m[0][1] * y + m[0][2] ,
                   m[1][0] * x + m[1][1] * y + m[1][2] ) ;
    
} ;


int  main() {
    
    // �����I
    Point  point ;

    // �V�q�}�C�x�s�ഫ���O���󪺫���
    vector<GT*>  gt ;

    int       i , no ;
    Distance  dx , dy ;  
    Angle     angle   ;  // �ϥΨ���, �D�|��
    
    // Ū�����
    string         line , transformation ;
    istringstream  istr ;

    do {
        
        cout 
        << "> ��J�����I�y��, �ഫ����, �ӧO�ഫ�覡�P������� :"
        << endl ;
    
        // Ū���C�@��, �s�J�r��y����
        getline(cin,line) ;
        istr.str(line) ;

        // Ū�J�I�y�лP���n�ഫ������
        istr >> point >> no ;
        
        // �B�z�C�����ഫ
        for ( i = 0 ; i < no ; ++i ) {

            istr >> transformation ;

            if ( transformation == "TRA" ) {             // ����
                istr >> dx >> dy ;
                gt.push_back( new Translation(dx,dy) ) ;
            } else if ( transformation == "ROT" ) {      // ����
                istr >> angle ;
                gt.push_back( new Rotation(angle) ) ;
            } else if ( transformation == "REF" ) {      // ��g
                istr >> angle ;
                gt.push_back( new Reflection(angle) ) ;
            }
                
        }

        // �M���X�m
        istr.clear() ;
        
        // �C�L
        cout << "  " << point << "  -->  " 
             << point.transformation(gt) << "\n\n" ;

        // �M�� gt �ҫ���Ҧ��ഫ����, ����N gt �V�q�}�C������
        // �զ��s
        for ( i = 0 ; i < gt.size() ; ++i ) delete  gt[i] ;
        gt.resize(0)  ;
        
    } while ( no != 0 ) ;      // �p�G�S�������ഫ�ʧ@�h�����j��

    return 0 ;
    
}

