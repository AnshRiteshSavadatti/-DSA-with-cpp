// #pragma GCC target("avx2")
// #pragma GCC optimization("O3")
// #pragma GCC optimization("unroll-loops")

/* anshsavadattti */

#include<bits/stdc++.h>
using namespace std;
#define pb push_back
#define ll long long
#define vi vector<int>
#define vll vector<long long>
#define mll map<long, long>

#define fl(s, e) for(long long int i=s;i<e;i++)
#define rfl(s, e) for(long long int i = s; i >= e; i--)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)

#define modulo 1000000007

/*
        decimal to binary
*/

string decimalToBinary(int decimalNumber) {
    // Use bitset to convert integer to binary string
    bitset<32> bits(decimalNumber);

    // Convert to binary string
    string binaryString = bits.to_string();

    // Find the position of the first '1' in the binary string
    size_t firstOne = binaryString.find('1');

    // Erase leading zeros
    if (firstOne != string::npos) {
        binaryString.erase(0, firstOne);
    }

    return binaryString;
}

/*
  Generating next permutation 
*/
void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void generatePermutations(vector<char> &arr, int start, int end) {
    if (start == end) {
        for (char element : arr) {
            cout << element << " ";
        }
            cout << endl;
    } else {
        for (int i = start; i <= end; ++i) {
            swap(arr[start], arr[i]);
            generatePermutations(arr, start + 1, end);
            swap(arr[start], arr[i]);  // Backtrack to restore the original order
        }
    }
    return;
}

/*
    sieve
*/
bool prime[1000002];  
void SieveOfEratosthenes() {
     memset(prime, 1, sizeof(prime));
  for (int p = 2; p * p <= 1000001; p++) {
    if (prime[p] == true) {
      for (int i = p * p; i <= 1000001; i += p) 
        prime[i] = false;
    }
  }
}


/*
    Euclidian algorithm
*/

int EuclidianGcd(int a, int b){
    if(b == 0){
        return a;
    }
    return EuclidianGcd(b, a % b);
}

int isCoprime(int a, int b){
    return EuclidianGcd(a, b) == 1;
}

int sum(int n){
    return (n*(n-1))/2;
}

void popElementAtPosition(std::vector<int>& vec, int position) {
    if (position >= 0 && position < vec.size()) {
        vec.erase(vec.begin() + position);
    } else {
    }
    return;
}

void solve() {
    int n;
    cin >> n;

    vector<vector<int>>a(n,vector<int>(n));

    for(int i=0; i<n; i++){
        for(int j =0; j<n; j++){
            cin >> a[i][j];
        }
    }

    int cnt = 0;
    for(int i=0; i<n; i++){
        int temp = 0;
        for(int j=0; j<n; j++){
            if(a[i][j] == 1){
                temp ++;
            }
        }
        if(cnt == 0){
            cnt = temp;
        }else{
            if(temp < cnt || temp > cnt){
                cout << "TRIANGLE" << endl;
                return;
            }else{
                cout << "SQUARE" << endl;
                return;
            }
        }
    }
    return;
}



int main(){
    fast;
    ll t = 1; 
    cin >> t;
    while(t--){
        solve();
    }
    return 0;
}

