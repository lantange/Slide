#include <iostream>
#include <vector>
#include <string>

using namespace std ;

// �C�|���O : �i�઺�ǰ|
enum  Colleges  { Sci , Eng , Mgt , Ife , Eth };

typedef  string  Name ;

// �ǰ| : ��H��¦���O
class  College {
    
  protected :
    
    Name              name  ;        // �ǰ|�W��
    vector<Name>      depts ;        // �ǰ|�����Ǩt
    
  public :

    // �C�L�ǰ|�@�P���� : �µ����禡
    virtual  void  list_common_subjects() const = 0 ;
    
    // �C�L�ǰ|���Ҧ����Ǩt
    void  list_all_departments() const {
        cout << "> " << name << " :  "  ;
        for ( int i = 0 ; i < depts.size() ; ++i ) 
            cout << depts[i] << "  "  ;
        cout << endl ;
    }

    // �ǰ|�W��
    Name get_college_name() const { return name ;  }
    
    // �ǰ|�����Ǩt�`��
    int  get_dept_no() const { return depts.size()  ; }

    // �����Ѻc�禡
    virtual  ~College() {}

};


// �C�L�w�]���@�P����
void  College::list_common_subjects() const {
    cout << "  " << name << "�@�P���׬�� : �L" << endl ;
}



// �z�ǰ|
class  Science : public  College {
    
  public :

    // �غc�禡
    Science() {
        name = "�z�ǰ|" ; 
        depts.push_back( "�ƾǨt" ) ;   
        depts.push_back( "�ƾǨt" ) ;
        depts.push_back( "���z�t" ) ;   
        depts.push_back( "�ͩR��Ǩt" ) ;
    }

    // �C�L�@�P���׬��
    void  list_common_subjects() const {
        cout << "  " << name << "�@�P���׬�� : �L�n��, ���z" 
             << endl ;
    }

        
};

// �u�ǰ|
class  Engineering : public  College {
    
  public :

    // �غc�禡
    Engineering() {
        name = "�u�ǰ|"  ; 
        depts.push_back( "�g��t" ) ; depts.push_back( "����t" ) ;
        depts.push_back( "�Ƥu�t" ) ;
    }

    // �C�L�@�P���׬�� : �ϥιw�]��
    void  list_common_subjects() const { 
        College::list_common_subjects() ; 
    }

    
};


// �j�����O
class  University {

  private :

    Name               name ;            // �j�ǦW��
    vector<College*>   colleges ;        // �j�Ǥ����ǰ|
    
  public :
  
    // �w�]�غc�禡
    University() : name("�p���P�ڤj��") {
        colleges.push_back( new Science ) ; 
        colleges.push_back( new Engineering ) ;
    }

    // �Ѻc�禡 
    ~University() {  
        for ( int i = 0 ; i < colleges.size() ; ++i ) 
            delete colleges[i] ; 
    }
    
    // �C�L�Ҧ��ǰ|�W��
    void  list_all_colleges() const {
        cout << "> " << name << "���ǰ| : "  ;
        for ( int i = 0 ; i < colleges.size() ; ++i ) 
            cout << colleges[i]->get_college_name() << "  " ;
        cout << endl ;
    }
    
    // �C�L�Ǯդ����Ҧ��Ǩt�W��
    void  list_all_departments() const {
        cout << "> " << name << "���Ǩt :\n" ;
        for ( int i = 0 ; i < colleges.size() ; ++i ) {
            cout << "<" << i+1 ;
            colleges[i]->list_all_departments() ;
        }
        cout << endl ;
    }

    // �ǮզW��
    inline  Name  get_name() const { return name ;  }

    // �C�L���w�ǰ|���Ҧ��Ǩt�W��
    void  list_departments_in_college( const Colleges& college ) 
        const {
        colleges[college]->list_all_departments() ;
    }

    // �p��j�Ǥ��Ҧ��Ǩt���`��
    int  total_no_of_departments() const {
        int no = 0 ;
        for( int i = 0 ; i < colleges.size() ; ++i ) {
            no += colleges[i]->get_dept_no() ;
        }
        return no ;
    }
    
};


int  main() {

    Science  sci ;                  // �z�ǰ|����                
    sci.list_all_departments() ;    // �C�L�z�ǰ|�����Ҧ��Ǩt�W��
    sci.list_common_subjects() ;    // �C�L�z�ǰ|�����@�P���׬��
    cout << endl ;

    Engineering  eng ;              // �u�ǰ|����                
    eng.list_all_departments() ;    // �C�L�u�ǰ|�����Ҧ��Ǩt�W��
    eng.list_common_subjects() ;    // �C�L�u�ǰ|�����@�P���׬��
    cout << endl ;

    University  fed ;               // �j�Ǫ���
    fed.list_all_colleges() ;       // �C�L�j�Ǥ����Ҧ��ǰ|�W��
    fed.list_all_departments() ;    // �C�L�j�Ǥ����Ҧ��Ǩt�W��

    // �C�L�Ǩt�`��
    cout << "> " << fed.get_name() << "�Ǩt�`�� = "           
         << fed.total_no_of_departments() << "\n\n" ;

    // �C�L�����j�ǲz�ǰ|�����Ҧ��Ǩt
    fed.list_departments_in_college( Sci ) ;

    return 0 ;
    
}
