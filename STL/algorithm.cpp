#include<bits\stdc++.h>
using namespace std;

int main(){

    // sorting 
    int arr[10];
    for(int i=0; i<10; i++) cin >> arr[i];
    
    // n logn ---> complexity
    sort(arr, arr + 10);  // in increasing order

    vector < int > vec;
    for(int i=0; i<10; i++) cin >> vec[i];
    sort(vec.begin(), vec.end());

    // to sort the indexes one two and three
    sort(vec.begin() + 1, vec.begin() + 4); // [1, 4)



    // reverse
    reverse(arr, arr+10);
    reverse(vec.begin(), vec.end());
    reverse(vec.begin() +1, vec.begin() +4);


    // to find maximum element

    int elementMax = *max_element(arr, arr + 10);
    int elementMin = *min_element(arr, arr + 10);
    elementMax = *max_element(vec.begin(), vec.end());
    elementMin = *max_element(vec.begin(), vec.end());


    // for sum
    // accumulate(startIterator, endIterator, initialSum);
    int sum = accumulate(arr, arr+10, 0);



    // to count the number of times x appeares 
    // will return the number of times 10 is present
    // count(startIterator, endIterator, elemnet to be counted);
    int cnt = count(vec.begin(), vec.end(), 10);


    // to find a element 
    // will return an ***iterator*** at first occurance or else will point at end or vec ie vec.end()
    auto it = find(vec.begin(), vec.end(), 2);
    // to get index subtract vec.begin();



    // binary search
    // this algorithm on sorted arrays
    // binary_search(firstIterator, lastIterator, element)  will return  true or false
    // log n complexity
    bool flag = binary_search(vec.begin(), vec.end(), 2);
    bool flag1 = binary_search(arr, arr+10, 2);


    // lower_bound funtion returnes iterator to the first element which is not less than x
    // arr --> [ 1,4,6,8,9,9,10]
    // if x = 9   will point at 4th index
    // if x = 3    will point at 0th index
    // binary search is implemented in lower bound function
    it = lower_bound(vec.begin(), vec.end(), 1);
    int index = it - vec.begin();




    // upper_bound will return an iterator which points to element just greater than x
    // arr --> [ 1,4,6,8,9,9,10]
    // if x = 9   will point at 6th index
    // if x = 3    will point at 2nd index
    it = upper_bound(vec.begin(), vec.end(), 1);
    index = it - vec.begin();




    // next permutation    time conplexity --- > O(n)
    // string "abc"
    // lexiographycally sorted
    // "abc"
    // "acb"
    // "bac"
    // "bca"
    // "cab"
    // "cba"
    // there is n! permutations

    string s = " bac";
    flag = next_permutation(s.begin(), s.end());
    // now string s will be "bca"


    // how to print all the permutations of s 
    sort(s.begin(),s.end());
    do{
        cout << s << " ";
    }while (next_permutation(s.begin(),s.end())); 


    // prev_permutation
    flag = prev_permutation(s.begin(), s.end());
    // now string s will be "acb"




    // comparator
    // greater<int> is a inbuilt comparator

    sort(arr, arr+10, greater<int>());
    
    // or we can write a function for comparator
    // sort(vec.begin(), vec.end(), comp())
    
    



    
    return 0;
}