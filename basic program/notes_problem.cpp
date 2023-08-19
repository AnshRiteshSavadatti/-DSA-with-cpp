#include<bits\stdc++.h>
using namespace std;

 void value(float val){
    int hun;
    hun = val / 100;
    val -= hun * 100;
    int fifty;
    fifty = val / 50;
    val -= fifty * 50;
    int ten = val / 10;
    val -= ten * 10;
    int one = val;
    cout << "The number of hundred rupee note is " << hun << endl <<" value of 10 rupee note is "<< ten << endl << " value of 50 rupee note is "<<fifty<< endl << " value of one rupee note is "<< one << endl; 
}

int main(){
    float val;
    cout << " Enter the vallue of money "<< endl;
    cin >> val;
     value(val);
     return 0;
}