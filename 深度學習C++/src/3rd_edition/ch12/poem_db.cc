#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <iomanip>
#include <vector>

using  namespace  std ;

typedef  string  Poet    ;   // �֤H
typedef  string  Name    ;   // �֪��W��
typedef  string  Content ;   // �֪����e

// �֪���Ƶ��c
struct  Poem {
    Poet     poet ;
    Name     name ;
    Content  content ;
};

// �и� Poem ��J�B��l
istream&  operator>> ( istream& in , Poem& poem ) {
    string  content ;
    in >> poem.poet >> poem.name >> poem.content ;
    while ( in >> content ) poem.content += "  " + content ;
    return in ;
}

// �и� Poem ��X�B��l
ostream&  operator<< ( ostream& out , const Poem& poem ) {
    return  out << poem.poet 
                << setw(poem.content.size()-poem.poet.size()-
                        poem.name.size())
                << " "
                << poem.name << "\n" << poem.content  ;
}

// ������O
class  Tang_Poem {

  private :

    vector<Poem>   five  ;   // �������y
    vector<Poem>   seven ;   // �C�����y

  public :

    // �غc�禡 : ���OŪ�J�����P�C�����y�����
    Tang_Poem( const char* poem5 , const char* poem7 ) {

        ifstream  infile1(poem5) , infile2(poem7) ;
        string    line ;

        Poem            poem ;
        istringstream   poem_entry ;
    
        // Ū�J�������y�����
        while ( getline( infile1 , line ) ) {
            poem_entry.str(line) ;
            poem_entry >> poem ;
            five.push_back( poem ) ;
            poem_entry.clear() ;
        }

        // Ū�J�C�����y�����
        while ( getline( infile2 , line ) ) {
            poem_entry.str(line) ;
            poem_entry >> poem ;
            seven.push_back( poem ) ;
            poem_entry.clear() ;
        }
   
    }
    
    // ��M�֤H�b��Ʈw���Ҧ����֫�^��
    vector<Poem>  search_poet( const Poet& poet ) const {

        int i ;
        vector<Poem>  poems ;
        
        for ( i = 0 ; i < five.size() ; ++i ) 
            if ( five[i].poet == poet ) poems.push_back(five[i]) ;

        for ( i = 0 ; i < seven.size() ; ++i ) 
            if ( seven[i].poet == poet ) poems.push_back(seven[i]);

        return poems ;
    }
    
};


int  main() {
    
    // ��ָ�Ʈw����
    Tang_Poem  poem_db( "five_poem.db" , "seven_poem.db" ) ;
    
    Poet          poet  ;   // �֤H
    vector<Poem>  poems ;   // ��

    int i ;

    // �H Ctrl-c ������j��
    while ( 1 ) {
        cout << "> ��J�֤H�W�r : " ;
        cin >> poet ;

        // ��M�֤H�b��ָ�Ʈw�������Ҧ���
        poems = poem_db.search_poet( poet ) ;

        for ( i = 0 ; i < poems.size() ; ++i ) 
            cout << "\n" << poems[i] << "\n" ;

        cout << endl ;
        
    }

    return 0 ;
    
}
