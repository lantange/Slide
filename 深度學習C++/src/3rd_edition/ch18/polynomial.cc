#include <iostream>
#include <vector>
#include <list>

using namespace std ;

// �h�������C�@�� 
template <class T>
struct  Item {
    int     deg ;    // X �������
    T       coeff ;  // X ���Y��

    Item( int d = 0 , T c = 1 ) : deg(d) , coeff(c) {}

    // ��X�������
    friend  ostream&  operator<< ( ostream& out , 
                                   const Item<T>& foo ) {
        return  out << ( foo.coeff > 0 ? " + " : " - " ) 
                    << ( foo.coeff > 0 ? foo.coeff : -foo.coeff )
                    << " X^" << foo.deg ;
    }

};

// �h�����P�_�� : ����Ƥp���u��
template <class T>
struct  small_degree {
    bool  operator() ( const Item<T>& a , const Item<T>& b ) const {
        return  a.deg < b.deg ;
    }
};

// �h�������O
template <class T>
class  Polynomial {
    
  private :
    
    list< Item<T> >       items ;        // �x�s�h�������C�@��
    
  public :

    // �w�]�غc�禡
    Polynomial<T>() {}
    
    // �@��غc�禡
    template<class Iter>
    Polynomial<T>( Iter first , Iter last ) 
        : items(first,last) {
        typename  list< Item<T> >::iterator   iter ;

        // �h���s�Y�ƪ�����
        for ( iter = items.begin() ; iter != items.end() ; 
              ++iter ) {
            if ( iter->coeff == 0 ) {
                // �^�Ǫ����N�����V�U�@�����
                iter = items.erase(iter) ;  

                // ���N�����^��W�@�����
                --iter ;                    
            }
        }

        // �Ѧ���Ƥp�̱Ƨ�
        items.sort( small_degree<T>() ) ;
    }
        
    // ���J�@����h������
    void  insert( const Item<T>& item ) {

        // �Y�Y�Ƭ��s, �h�������X
        if ( item.coeff == 0 ) return ;

        // �p�G�h�������Ŧh���� �άO ��J������Ƥj��h������
        // �̰������, �h�����[�W����
        if ( items.size() == 0 || item.deg > items.back().deg ) {

            items.push_back( item ) ;

        } else {

            // �w�q�@��C���N������
            typename  list< Item<T> >::iterator   iter ;

            // ��X�O�_�w���P����ƪ� X ��, �Y���h������ȥ[�J�䤺
            for ( iter = items.begin() ; iter != items.end() ; 
                  ++iter ) {

                if ( item.deg < (*iter).deg ) {
                    items.insert( iter , item ) ;
                    return ;
                } else if ( item.deg == (*iter).deg ) {
                    iter->coeff += item.coeff ;
                    // �p�G�Y�Ƴ̫ᬰ 0, �h�h������
                    if ( iter->coeff == 0 ) items.erase( iter ) ;
                    return ;
                }

            }

        }
    }

    // �C�L�h���� 
    friend  ostream& operator<< ( ostream& out , 
                                  const Polynomial<T>& foo ) {

        typename  list< Item<T> >::const_iterator   iter ;
        for ( iter = foo.items.begin() ; 
              iter != foo.items.end() ;  ++iter )  out << *iter ;
        return out ;

    }

};

int main() {
    
    Polynomial<int>  foo  ;
    
    // ����N�U���s�J�h����,  foo = X - 2 X^1 + 3 X^2 - 4 X^3
    for ( int i = 3 ; i >= 0 ; --i ) {  
        if ( i % 2 == 0 ) 
            foo.insert( Item<int>(i,i+1) ) ;
        else
            foo.insert( Item<int>(i,-(i+1)) ) ;

    }

    // foo = + 1 X^0 - 2 X^1 + 3 X^2 - 4 X^3
    cout << "foo = " << foo << endl ;

    // �[�J  4 X^2 + 4 X^3 + 4 X^4 + 4 X^5
    for ( int i = 2 ; i <= 5 ; ++i ) foo.insert( Item<int>(i,4) ) ;
    
    // foo =  + 1 X^0 - 2 X^1 + 7 X^2 + 4 X^4 + 4 X^5
    cout << "foo = " << foo << endl ;


    // �ϥΦV�q�}�C�x�s�h�������@�Ƕ���
    vector< Item<int> >   items ;

    for ( int i = 10 ; i >= 0 ; i -= 2 )
       items.push_back( Item<int>(i,i) ) ;

    // �N�V�q�}�C����Ʀs�J�h�������O
    Polynomial<int>  bar(items.begin(),items.end()) ;
    
    cout << "bar = " << bar << endl ;

    return 0 ;
    
}

