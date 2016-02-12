#include <iostream>
#include <vector>
#include <cmath>
#include <string>

using  namespace  std ;

// �N�e�@�d�Ҭ����{���X�[�J���{���ϥ�
#include "transformation.h"   

// �򥻴X��ϧ�
class  Basic_Geometric_Entity {

    public :

        // (1) �X���ഫ : �Ψӥ���, ����, ��g����
        virtual Basic_Geometric_Entity*  transformation( 
                 const vector<GT*>& geotrs ) const = 0 ;

        // (2) �ƻs����
        virtual Basic_Geometric_Entity* clone() const = 0 ;

        // (3) �C�L����
        virtual ostream& print(ostream& out) const = 0 ;

        // (4) �����Ѻc�禡
        virtual  ~Basic_Geometric_Entity() {}

        // (5) �и���X�B��l
        friend  ostream&  operator<< ( 
            ostream& out , const Basic_Geometric_Entity& bge ) {
             return  bge.print(out) ;
        }

} ;


// �u�q���O
class  Line : public  Basic_Geometric_Entity {

  private :

    Point  p , q ;   // �u�q����Ӻ��I

  public :
 
    // �غc�禡
    Line( const Point& a , const Point& b ) : p(a) , q(b) {}

    // �h�ʽu�q
    virtual Line*  transformation( 
        const vector<GT*>& geotrs ) const {
        return  new  Line( p.transformation(geotrs),
                           q.transformation(geotrs)) ;
    }

    // �ƻs����, �æ^�Ǩ����
    virtual  Line*  clone() const { return  new  Line(*this) ; }

    // �C�L�u�q
    virtual  ostream&  print( ostream& out ) const {
        return  out << "> Line : " << p << " --> " << q  ;
    } 

} ;   


// ��
class  Circle : public  Basic_Geometric_Entity {
    
  private :
    
    Point    center ;   // ���
    Length   radius ;   // �b�|
    
  public :

    // �غc�禡
    Circle( const Point& c , Length r ) : center(c) , radius(r) {}

    // �h�ʶ�
    virtual  Circle*  transformation( 
        const vector<GT*>& geotrs ) const {
        return new Circle(center.transformation(geotrs),radius) ;
    }

    // �ƻs����, �æ^�Ǩ����
    virtual  Circle* clone() const { return new Circle(*this) ; }

    // �C�L��
    virtual  ostream&  print( ostream& out ) const {
        return  out << "> Circle : center = " 
                    <<  center << " , radius = " << radius  ;
    } 

} ;   
    

typedef  Basic_Geometric_Entity  BGE ;

int main() {
    
    int  i ;

    // ���ͨ�ӦV�q�}�C�Ψ��x�s�X�����O�[�c���ʺA���󪺫���
    vector<BGE*>  bge1 , bge2 ;

    // �ʺA���ͤT�ӴX�󪫥�

    // (1) �� : ��� (1,1) �b�| 1 
    bge1.push_back( new Circle(Point(1,1),1) ) ;         

    // (2) ���u : ����I (1,1) (2,1) 
    bge1.push_back( new Line(Point(1,1),Point(2,1)) ) ;  

    // (3) �� : ��� (1,0) �b�| 3
    bge1.push_back( new Circle(Point(1,0),3) ) ;         

    // �C�L�Ҧ����X�󪫥�
    cout << "�h�ʫe���ϧ�" << endl ;
    for ( i = 0 ; i < bge1.size() ; ++i ) 
        cout << *bge1[i] << endl ;

    cout << endl ;

    // �x�s�X���ഫ���
    vector<GT*> gt ;

    // �h�ʴX��ϧ�, ���f�ɰw���� 90 ��, �� 45 �ת��u�@��g, 
    // �A���k�� 1 ���
    gt.push_back( new Rotation(90) ) ;
    gt.push_back( new Reflection(45) ) ;
    gt.push_back( new Translation(1,0) ) ;
    
    // ���ͷh�ʫ᪺�ϧ�
    for ( i = 0 ; i < bge1.size() ; ++i ) 
        bge2.push_back( bge1[i]->transformation( gt ) ) ;

    // �C�L�h�ʫ᪺�Ҧ��X��ϧ�
    cout << "�h�ʫ᪺�ϧ� : " 
         << "(1) �f�ɰw���� 90 �� (2) 45 �׽u��g (3) �k�� 1"
         << endl ;

    for ( i = 0 ; i < bge2.size() ; ++i ) 
        cout << *bge2[i] << endl ;

    cout << endl ;

    // �ƻs bge2 �X��ϧ�
    vector<BGE*>  bge3 ;
    for ( i = 0 ; i < bge2.size() ; ++i ) {
        bge3.push_back( bge2[i]->clone() ) ;
    }

    cout << "�ƻs�ϧ�" << endl ;
    for ( i = 0 ; i < bge3.size() ; ++i ) 
        cout << *bge3[i] << endl ;
    
    
    // �R���Ҧ����ʺA����
    for ( i = 0 ; i < bge1.size() ; ++i ) {
        delete  bge1[i] ;        
        delete  bge2[i] ;
        delete  bge3[i] ;
    }
    
    // �R���Ҧ����ʺA����
    for ( i = 0 ; i < gt.size() ; ++i )  delete gt[i] ;

    return 0 ;
    
}
