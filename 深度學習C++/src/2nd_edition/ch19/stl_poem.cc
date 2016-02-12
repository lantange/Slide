#include <iostream>
#include <iomanip>
#include <string>
#include <sstream>
#include <fstream>
#include <vector>
#include <map>

using namespace std ;

typedef  string  Poet ;

// �w�q�@�~���c
struct  Poem {
    Poet    poet ;
    string  name ;
    string  content ;
};

// �w�� Poem �w�q��J�B��l
istream&  operator>> ( istream& in , Poem& poem ) {
    string  content ;
    in >> poem.poet >> poem.name >> poem.content ;
    while ( in >> content ) poem.content += "  " + content ;
    return in ;
}

// �w�� Poem �w�q��X�B��l
ostream&  operator<< ( ostream& out , const Poem& poem ) {
    return  out << poem.poet 
                << setw(poem.content.size()-poem.poet.size()-
                        poem.name.size()) << " " 
                << poem.name << "\n" << poem.content  ;
}

// ��Ʈw���O
class  Poem_db {

  private :
    
    // �ھڸ֤H�x�s��@�~
    multimap<Poet,Poem>  poem_db ;

    // Ū�������
    void  read_datafile ( char* datafile ) {
    
        // �}���ɮ�
        ifstream  infile(datafile) ;
        string    line ;

        Poem            poem ;
        istringstream   data_line ;
    
        // �C��Ū���@���, �ন Poem �����A�t�J poem_db 
        // �ƹ�M�e����
        while ( getline( infile , line ) ) {
            data_line.str(line) ;
            data_line >> poem ;
            poem_db.insert( make_pair( poem.poet , poem ) ) ;
            data_line.clear() ;
        }
        
    }
    
  public :

    typedef  multimap<Poet,Poem>::const_iterator   Pciter ;

    // �غc�禡 : Ū�������
    Poem_db( char* datafile ) {  read_datafile( datafile ) ;   }

    // �j�M�֤H�b����ɤ����Ҧ��@�~
    vector<Poem>  find( const Poet& poet ) const ;
    
};

// �j�M�֤H�b����ɤ����Ҧ��@�~
vector<Poem>  Poem_db::find( const Poet&  poet ) const {
    
    Pciter               iter ;
    pair<Pciter,Pciter>  piter ;

    // �j�M�֤H
    piter = poem_db.equal_range(poet) ;

    vector<Poem>   poems ;
    for ( iter = piter.first ; iter != piter.second ; ++iter ) {
        poems.push_back(iter->second) ;
    }
    
    return  poems ;
    
}

// �D�禡
int  main() {

    Poem_db       poem_database("poem.db") ;
    
    int           i     ;
    Poet          poet  ;
    vector<Poem>  poems ;
    
    while ( 1 ) {
        cout << "> ��J�֤H�W�r : " ;
        cin >> poet ;
        poems = poem_database.find( poet ) ;
        for ( i = 0 ; i < poems.size() ; ++i ) {
            cout << "[" << i+1 << "]\n" 
                 << poems[i] << "\n\n" ;
        }
        if ( poems.empty() ) {
            cout << "> ��ָ�Ʈw���d�L���֤H\n" ;
            break ;
        }
    }

    return 0 ;
    
}

