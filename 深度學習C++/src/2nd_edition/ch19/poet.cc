#include <iostream>
#include <string>
#include <sstream>
#include <map>

using namespace std ;

int main() {

    string   foo[4] = { "����    �]�� �象"  ,  "����    �e�O �۫�" , 
                        "����    �M��"       ,  "���j    �K�}��"   } ;
    
    typedef  string  POET ;   // �֤H
    typedef  string  POEM ;   // �֦W
    
    multimap<POET,POEM>  collection ;
    string               poet , poem ;
    istringstream  istring(poem) ;    
    
    for ( int  i = 0 ; i < 4 ; ++i ) { 
        // �N�C�Ӧr��e�J�r���Ƭy����, ���X�֤H�W�r
        istring.str( foo[i] ) ;
        istring >> poet ;
        
        // �̦��N�֨��X, ���ͦ��磌��, �ᴡ�J�ƹ�M����
        while ( istring >> poem ) collection.insert( make_pair(poet,poem) ) ;

        // �h�� failbit 
        istring.clear() ;
        
    }

    // �̦��C�L��ӽƹ�M����    
    multimap< POET , POEM >::iterator  iter1 ;
    for ( iter1 = collection.begin() ; iter1 != collection.end() ; ++iter1 )
        cout << iter1->first << " : " << iter1->second << endl ;
    cout << endl ;
    
    // �N�ƹ�M�e����ƴ��J���M����, ���ۦP�����ޤ��@���J�ʧ@
    map<POET,POEM>  single ;
    single.insert( collection.begin() , collection.end() ) ;
    
    // �̦��C�L��ӹ�M����    
    map< string , string >::iterator  iter2 ;
    for ( iter2 = single.begin() ; iter2 != single.end() ; ++iter2 )
        cout << iter2->first << " : " << iter2->second << endl ;

    return 0 ;
    
}
