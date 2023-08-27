#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
    vector<int>vec;
    for(int i=0; i<10; i++)
        vec.push_back(i);
    cout << binary_search( vec.begin(), vec.end(),11) << endl;
    cout << binary_search(vec.begin(), vec.end(), 4) << endl;

    cout << "lower bound --> " << lower_bound(vec.begin(), vec.end(), 5)- vec.begin()  << endl;
    cout << "uppper bound --> " << upper_bound(vec.begin(), vec.end(), 5) - vec.begin() << endl;
    
    int a = 5, b = 9;
    cout << max(a,b) << endl;
    cout << min(a,b) << endl;
    string s = "DSA ";
    reverse(s.begin(),s.end());
    cout << s << endl;
    rotate(vec.begin(), vec.begin() + 2, vec.end());
    cout << "After rotating " << endl;
    for(auto it : vec)
        cout << it << " ";
    sort(vec.begin(),vec.end());
    // intro sort; quick sort, heap sort, insertion sort;


}
