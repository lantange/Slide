#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>

using  namespace  std ;

typedef  int  Node ;

// �y���I���O
class  Point {

  private :
    
    double  x , y ;   // x , y �y��

  public :
    
    // �غc�禡
    Point( double a = 0. , double b = 0. ) : x(a) , y(b) {}

    double  getx () const {  return x ;  }
    double  gety () const {  return y ;  }

    // ��X�B��l
    friend ostream& operator<< ( ostream& out , const Point& pt ) {
        out.setf(ios::fixed,ios::floatfield) ;
        out.precision(2) ;
        return  out << "(" << pt.x << "," << pt.y << ")" ;
    }

};

// �����l��¦���O
class  Geometrical_Cell {
    
  public :
    
    // ��l�W��
    virtual  string  cell_name() const = 0 ;
    
    // ��l���I���s��
    virtual  void  get_nodes( Node node[] ) const = 0 ;

    // ��l�����I�ƥ�
    virtual  int   node_no() const = 0 ;

    // �C�L��l���
    virtual  ostream&  print( ostream& out ) const = 0 ;

    // �ƻs��l
    virtual  Geometrical_Cell*  clone() const = 0 ;

    // �����Ѻc�禡
    virtual  ~Geometrical_Cell() {}
    
} ;

// �и������X�B��l
ostream&  operator << ( ostream& out , 
                        const Geometrical_Cell& cell ) {
    return  cell.print( out ) ;
};
    

// �T���ή�l
class  Triangular_Cell : public Geometrical_Cell {
    
  private :

    // ��l���I�s��
    Node     nodes[3] ;
    
  public :

    // �T�ӫغc�禡
    Triangular_Cell() {}

    Triangular_Cell( const Node& node1 , const Node& node2 , 
                     const Node& node3 ) {
        nodes[0] = node1 ;     nodes[1] = node2 ;
        nodes[2] = node3 ;
    }

    Triangular_Cell( const Node n[3] ) {
        for ( int i = 0 ; i < 3 ; ++i ) nodes[i] = n[i] ;
    }

    // ��X��l���I���s��
    void  get_nodes( Node  n[3] ) const {
        for ( int i = 0 ; i < 3 ; ++i ) n[i] = nodes[i] ;
    }

    // �^�Ǯ�l���I��
    int   node_no() const {    return 3 ;    }

    // ��l�W��
    string  cell_name() const {  return  string("�T���ή�l") ;  }

    // �C�L��l���
    ostream&  print(ostream& out) const {
        return  out << "��l�s�� : " << nodes[0] 
                    << " " << nodes[1] << " " << nodes[2] ;
    }

    // �ƻs��l
    Triangular_Cell*  clone() const { 
        return  new Triangular_Cell(nodes) ; 
    }

};

// ���ͺ����ϰ� [0,1]x[0,1] ����
class  Mesh_Generator {
    
  private :
  
    int                         division ;    // ���ε���
    vector<Point>               points   ;    // ���I�V�q�}�C
    vector<Geometrical_Cell*>   cells    ;    // ��l�V�q�}�C

    // �M������ : ����ʺA��l�O�ЪŶ�
    void  delete_mesh() {
        int i ;
        for ( i = 0 ; i < cells.size() ; ++i ) delete cells[i] ;
        cells.resize(0) ;
        points.resize(0) ;
    }
    
  public :
    
    // �w�]�غc�禡
    Mesh_Generator( int d = 3 ) : division(d) {};
    
    // �ƻs�غc�禡
    Mesh_Generator( const Mesh_Generator& mesh ) {

        int i ;
        division = mesh.division ;

        for ( i = 0 ; i < mesh.points.size() ; ++i ) 
            points.push_back(mesh.points[i]) ;
        
        for ( i = 0 ; i < mesh.cells.size() ; ++i ) 
            cells.push_back( mesh.cells[i]->clone() ) ;

    }
    
    // �Ѻc�禡
    ~Mesh_Generator() {  delete_mesh() ;  }

    // �w�q���w�B��l
    Mesh_Generator&  operator = ( const Mesh_Generator& mesh ) {

        // �B�z�ۧګ��w
        if ( this == &mesh ) return  *this ;

        int i ;

        // �h���w�������
        if ( cells.size() != 0 ) delete_mesh() ;
        
        // �]�w�s���
        division = mesh.division ;

        for ( i = 0 ; i < mesh.points.size() ; ++i ) 
            points.push_back(mesh.points[i]) ;
        
        for ( i = 0 ; i < mesh.cells.size() ; ++i ) 
            cells.push_back( mesh.cells[i]->clone() ) ;

        return  *this ;

    }

    // �]�w�P���o���ΰϰ�
    void  set_division( int d ) {  division = d ;         }
    int   get_division() const { return  division  ; }
    
    // ���ͤT���κ���
    void  generate_triangular_mesh() {

        int    i , j , c1 , c2 , c3 , c4 ;
        int    line_point_no = division+1 ;
        double  ds =  1. / division ;

        if ( cells.size() != 0 )  delete_mesh() ;
        
        // �x�s��l�I�s��
        for ( j = 0 ; j < line_point_no ; ++j ) {
            for ( i = 0 ; i < line_point_no ; ++i ) {
                points.push_back( Point( i * ds , j * ds ) ) ;
            }
        }

        // �x�s�T���ή�l
        for ( j = 0 ; j < division ; ++j ) {
            for ( i = 0 ; i < division ; ++i ) {
                c1 = i  + j * line_point_no ;
                c2 = c1 + 1 ;
                c3 = c2 + line_point_no ;
                c4 = c1 + line_point_no ;
                cells.push_back( new Triangular_Cell(c1,c2,c4) ) ;
                cells.push_back( new Triangular_Cell(c2,c3,c4) ) ;
            }
        }
        
    }

    // �ϥ� gnuplot ���榡��X������
    void  output_mesh( const string&  filename = "mesh" ) const {

        int       i , j ;
        Node      nodes[4] ;
        ofstream  fout( filename.c_str() , ios::out ) ;
        
        fout.setf(ios::fixed,ios::floatfield) ;
        fout.precision(3) ;
        
        for ( i  = 0 ; i < cells.size() ; ++i ) {

            cells[i]->get_nodes(nodes) ;

            fout << "# " << i << " : " << cells[i]->cell_name() 
                 << " --- " ;

            for ( j = 0 ; j < cells[i]->node_no() ; ++j ) 
                fout << setw(3) << nodes[j] << " " ;
            fout << endl ;
            
            for ( j = 0 ; j < cells[i]->node_no() ; ++j ) {
                fout << setw(5) << points[nodes[j]].getx() 
                     << " " << setw(5) << points[nodes[j]].gety() 
                     << "\n" ;
            }
            fout << setw(5) << points[nodes[0]].getx() 
                 << " " << setw(5) << points[nodes[0]].gety() 
                 << "\n\n" ;
        }

        fout.close() ;

    }
    

    // �и���X�B��l
    friend  ostream& operator << ( ostream& out , 
                                   const Mesh_Generator& mesh ) {

        int    i , j ;
        Node   nodes[4]  ;
        
        out << "> �����`�@�� " << mesh.cells.size() << " ��l�P " 
            << mesh.points.size() << " ��l�I" << "\n\n" ;
        
        for ( i  = 0 ; i < mesh.cells.size() ; ++i ) {

            mesh.cells[i]->get_nodes(nodes) ;
            out << mesh.cells[i]->cell_name() << " : "  
                << i << "\n" ;

            for ( j = 0 ; j < mesh.cells[i]->node_no() ; ++j ) {
                out << "[" << setw(2) << nodes[j] << "] : " 
                    << mesh.points[nodes[j]] << "   " ;
            }
            out << "\n\n" ;

        }

        return out ;
        
    }
    
};

int  main() {

    // ���ͺ���, �C�@������ⵥ��
    Mesh_Generator  mesh(2) ;

    // ���ͤT���κ���
    mesh.generate_triangular_mesh() ;

    // ��X������
    cout << mesh << endl ;

    // �N�����ƿ�X�� gnuplot �榡��
    mesh.output_mesh() ;

    return 0 ;
    
}
