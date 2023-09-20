// bitset -- > 1 bit

#include<bits/stdc++.h>
using namespace std;

int main(){
    bitset< 5 >bt ;
    cin >> bt; // 01010
    // all
    cout << bt.all(); // --> return true or false /// will return true if all the bits are set ie 1 will return false if all the bits are not set ie if any one is zero wil return 0;
    // if bt.all() == 0101 -- > returnes false    if (bt.all()) == 11111 -- > returnes false

    // any
    cout << bt.any();  // --> returnes true or false  ,,, will return true of any of the one set is 1  and will return false if all are 0;;
    
    // count
    // bt = 01010 
    // prints 2;
    cout << bt.count();   // ---> will return the number of set bits

    // flip
    // bt = 01010
    bt.flip(2); // bt will be 01110  bit at second index is flipped


    // none
    // if none is set will return true
    // bt = 00000  ,,, will return true

    // set
    // bt.set();
    // will set entire space of bit  ---> 11111
    // for only one index 
    // bt.set(2);  // sets the second index as one ;
    // but if we specify 0 then it will set as 0
    // bt.set(2, 0);  // sets the second index to 0


    // reset
    // bt.reset();  // will turn all the indexes to zero
    // bt.retset(2); // will turn the element at second as 0
    // bt.reset(2,1);  // this is not possible *****

    // size
    // bt.size(); ---> will result size


    // test
    // bt.test(2);  // will check the element at second index will return true if it is 1 and false if it is 0
    return 0;
}