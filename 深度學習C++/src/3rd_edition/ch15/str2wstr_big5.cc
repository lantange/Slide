#include <iostream>
#include <cstdlib>
#include <string>

using namespace std ;

// string �r���� wstring �r��
wstring  str2wstr( const string& from ) {

    // �����[�W 1 �ӪŦr������
    int  wcsize = from.size()+1 ;
    wchar_t  *to = new wchar_t[wcsize] ;

    // �h�줸�նǲΦr���ର�e�r���r��
    mbstowcs(to,from.c_str(),wcsize) ;

    wstring  wstr = to ;
    delete [] to ;

    return wstr ;

}


// wstring �r���� string �r��
string  wstr2str( const wstring& from ) {

    // �����[�W 1 �ӪŦr������
    int  csize = sizeof(wchar_t)*from.size()+1 ;
    char *to = new char[csize] ;

    // �e�r���r���ର�h�줸�նǲΦr��
    wcstombs(to,from.c_str(),csize) ;
    
    string  str = to ;
    delete [] to ;

    return str ;

}


int main() {

    setlocale( LC_ALL , "zh_TW.UTF-8" ) ;
    
    // �r�� 
    string  a = "=== �s����p  �����ۥX ===" , b ;

    b = wstr2str( str2wstr(a) ) ;

    // �e�r��
    wstring  c = L"=== �s����p  �����ۥX ===" , d ;

    d = str2wstr( wstr2str(c) ) ;


    // �H�U��̫h�@�C�L

    // (1) 
    if ( a == b ) cout << "(1) string : " << b << endl ;
    
    // (2) 
    // if ( c == d ) wcout << "(2) wstring : " << d << endl ;

    return 0 ;

}
