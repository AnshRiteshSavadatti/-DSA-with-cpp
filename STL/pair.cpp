#include <iostream>
#include<bits\stdc++.h>
using namespace std;

int main(){
    pair<int, int> pr = {1,2};
    pair< pair<int,int> , int> p = {{1,2}, 3} ;
    cout << p.first.second << endl;
    pair<pair <int, int> , pair<int, int> > pa = {{1,2}, {3,4}};
    cout << pa.first.first << endl;
    cout << pa.second.second << endl;
    vector <pair<int,int>> vec;
    set< pair<int,int>> s;
    map< pair<int,int> ,int> m;
    // we cannot use unordered map for pairs

    return 0;

}

