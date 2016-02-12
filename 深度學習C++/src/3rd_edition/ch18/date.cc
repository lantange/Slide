class  Date {
    
  private :

    // ���O�R�A��� : �D�|�~���C���`�Ѽ�
    static  const  int  Days[12] ;
    
    // �~ , �� , ��
    int  year , mon , day ;

    // �ˬd�Y�~�O�_���|��
    bool  leap_year ( int y ) const {
        return ( y % 400 == 0 || ( y % 4 == 0 && y % 100 != 0 ) ? 
                 true : false ) ;
    }

  public :
    
    // �غc�禡
    Date () {}
    Date ( int y , int m , int d ) : year(y) , mon(m) , day(d) {}

    // �p��X�j�@�Ѫ����
    Date  next_date() const ;
    
    // �ˬd�O�_��Ѭ��P�@��
    bool  operator == ( const Date& date ) const {
        return ( year == date.year && mon == date.mon && 
                 day == date.day ) ;
    }

    // �ˬd�O�_��Ӥ�������P�@��
    bool  operator != ( const Date& date ) const { 
        return ! ( *this == date ) ;
    }

    // �ˬd��Ѯɶ����e�ᦸ�ǬO�_�����T
    bool  operator < ( const Date& date ) const ;

    bool  operator <= ( const Date& date ) const { 
        return  *this == date || *this < date ;
    }
    
    // �٦�禡 : �p���Ӥ���ۮt���Ѽ�
    friend  int  operator - ( const Date& , const Date& ) ;
    
    // �٦�禡 : ��J�P��X���
    friend  ostream& operator << ( ostream& , const Date& ) ;
    friend  istream& operator >> ( istream& ,       Date& ) ;

    // �٦����O : �]�w���O Account �� Date ���٦����O
    friend  class  Account ;

};

// �D�|�~���C���`�Ѽ�
const int  Date::Days[12] = { 31 , 28 , 31 , 30 , 31 , 30 , 
                              31 , 31 , 30 , 31 , 30 , 31 } ;

// �p��X�j�@�Ѫ����
Date  Date::next_date() const {

    // �������`�Ѽ�
    int  days_of_month = ( mon == 2 && leap_year( year ) ? 
                           Days[mon-1]+1 : Days[mon-1] ) ;

    int  y = year , m = mon , d = day ;

    // �ˬd�O�_���멳�̫�@��
    if ( day == days_of_month ) {
        d = 1 ;  ++m ;
        // �Y���~��, �h���鬰�j�~�Ĥ@��
        if ( m > 12 ) {  m = 1 ;  y += 1 ; } 
    } else 
        d++ ;

    return  Date( y , m , d ) ;

}

// �ˬd��Ѯɶ����e�ᦸ�ǬO�_�����T
bool  Date::operator < ( const Date& date ) const {

    if ( year == date.year ) {

        if ( mon == date.mon ) 
            return ( day < date.day ? true : false ) ;
        else 
            return ( mon < date.mon ? true : false ) ;

    } else 

        return ( year < date.year ? true : false ) ;

}

// �p���Ѭۮt���Ѽ�
int   operator - ( const Date& date1 , const Date& date2 )  {

    int  c = 0 ;
    Date date ;

    if ( date1 < date2 ) {
        
        for ( date = date1 ;  date != date2 ; ++c ) 
            date = date.next_date() ;

        return -c ;
        
    } else {
        
        for ( date = date2 ;  date != date1 ; ++c ) 
            date = date.next_date() ;
        return c ;

    }
    
}
    
// �������X�B��l
ostream& operator << ( ostream& out , const Date& date ) {
    return out << date.year << '-' 
               << setw(2) << setfill('0') << date.mon << '-' 
               << setw(2) << date.day << setfill(' ') ;
}

// �������J�B��l
istream& operator >> ( istream& in , Date& date ) {
    char  sep ;
    return  in >> date.year >> sep >> date.mon >> sep >> date.day ;
}
