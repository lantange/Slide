#include <iostream>
#include <vector>

using namespace std ;

template  <class T>
class   Matrix {

  private :

    vector< vector<T> >  mat ;            // �����V�q�}�C
    int                  row , col ;      // �C�ƻP���   

  public :

    // �w�]�غc�禡
    Matrix() : row(0) , col(0) {}

    // �غc�禡
    Matrix( int r , int c , const T& val = 0 ) : row(r) , col(c) {
        mat = vector< vector<T> >(r,vector<T>(c,val)) ;
    }

    // �^�ǯx�}�C�ƻP���
    inline  int  rows() const {  return row ;  }
    inline  int  cols() const {  return col ;  }
    
    // �^�ǯx�}���� i �C���V�q�}�C�Ѧ�
    inline vector<T>&        operator [] ( int i )       { 
        return  mat[i] ; 
    }

    inline const vector<T>&  operator [] ( int i ) const { 
        return  mat[i] ; 
    }

    // ���� += �B��l
    Matrix<T>&   operator += ( const Matrix<T>& rhs ) {
        int  i , j ;
        for ( i = 0 ; i < row ; ++i ) {
            for ( j = 0 ; j < col ; ++j ) mat[i][j] += rhs[i][j] ;
        }
        return  *this ;
    }
    
};


// �w�q�x�}����X�B��l
template <class S>
ostream&  operator << ( ostream& out , const Matrix<S>& m ) {

    int  i , j ;
    for ( i = 0 ; i < m.rows() ; ++i ) {
        out << '\n' ;
        for ( j = 0 ; j < m.cols() ; ++j ) {
            out << m[i][j] << "  " ;
        }
    }
    return  out << '\n' ;
}

// �����x�}���k�B��l
template  <class T>
Matrix<T>  operator * ( const Matrix<T>& m1 , 
                        const Matrix<T>& m2 ) {

    T          sum ;
    int        i , j , k ;
    Matrix<T>  m(m1.rows(),m2.cols()) ;
 
    for ( i = 0 ; i < m1.rows() ; ++i ) {
        for ( j = 0 ; j < m2.cols() ; ++j ) {
            sum = 0 ;
            for ( k = 0 ; k < m1.cols() ; ++k ) 
                sum += m1[i][k] * m2[k][j] ;
            m[i][j] = sum ;
        }
    }
    return  m ;
}

// �����x�}�[�k�B��l
template  <class T>
Matrix<T>  operator + ( const Matrix<T>& m1 , 
                        const Matrix<T>& m2 ) {
    Matrix<T>  m = m1 ;
    return  m += m2 ;
}

int  main() {

    // A �� 2 x 3 �x�},  B �� 3 x 2 �x�}
    Matrix<int>  A(2,3,1) , B(3,2,2) ;
    
    cout << "A = "       << A << '\n' ;
    cout << "B = "       << B << '\n' ;
    cout << "A * B = "   << A * B << '\n' ;
    cout << "A + A = "   << A + A << '\n' ; 
    cout << "A[1][2] = " << A[1][2] << '\n' ;

    return 0 ;
    
}
