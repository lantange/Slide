#include <iostream>
#include <climits>

using namespace std ;

int main() {

    // int ��ƪ��̤j�ȻP�̤p��
    cout << "> �̤j��� int \t\t\t: " 
         << numeric_limits<int>::max() 
         << "\n> �̤p��� int \t\t\t: " 
         << numeric_limits<int>::min() ;
    
    // unsigned int �L����ƪ��̤p�ȻP�̤j��
    cout << "\n\n> �̤j�L����� unsigned int \t: " 
         << numeric_limits<unsigned int>::max() 
         << "\n> �̤p�L����� unsigned int \t: " 
         << numeric_limits<unsigned int>::min() ;
    
    // long long int ������ƪ��̤j�ȻP�̤p��
    cout << "\n\n> �̤j������� long long int \t: " 
         << numeric_limits<long long int>::max() 
         << "\n> �̤p������� long long int \t: " 
         << numeric_limits<long long int >::min() ;

    // float ���T�ׯB�I�ƪ��̤p�ȻP�̤j��
    cout << "\n\n> �̤j���T�ׯB�I�� float\t: " 
         << numeric_limits<float>::max() 
         << "\n> �̤p���T�ׯB�I�� float\t: " 
         << numeric_limits<float>::min() ;

    // double ����T�ׯB�I�ƪ��̤j�ȻP�̤p��
    cout << "\n\n> �̤j����T�ׯB�I�� double\t: " 
         << numeric_limits<double>::max() 
         << "\n> �̤p����T�ׯB�I�� double\t: " 
         << numeric_limits<double>::min() << '\n' ;

    return 0 ;
    
}
