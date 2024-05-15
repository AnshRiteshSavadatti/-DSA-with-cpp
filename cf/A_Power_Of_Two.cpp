#pragma GCC target("avx2")
#pragma GCC optimization("O3")
#pragma GCC optimization("unroll-loops")

/* anshsavadatti */
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

string decimalToBinary(int decimalNumber) {
    bitset<32> bits(decimalNumber);
    string binaryString = bits.to_string();
    size_t firstOne = binaryString.find('1');
    if (firstOne != string::npos) {
        binaryString.erase(0, firstOne);
    }
    return binaryString;
}

void swap(char &a, char &b) {
    char temp = a;
    a = b;
    b = temp;
}

void generatePermutations(vector<char> &arr, int start, int end) {
    if (start == end) {
        for (char element : arr) {
            cout << element << ' ';
        }
        cout << endl;
    } else {
        for (int i = start; i <= end; ++i) {
            swap(arr[start], arr[i]);
            generatePermutations(arr, start + 1, end);
            swap(arr[start], arr[i]);
        }
    }
}

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

int EuclidianGcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return EuclidianGcd(b, a % b);
}

int isCoprime(int a, int b) {
    return EuclidianGcd(a, b) == 1;
}

void solve() {
    unsigned ll n;
    cin >> n;

    long double f = log2(n);

    int k = int(f);

    if(f == k){
        cout <<"YES" << endl;
    }else{
        cout << "NO" << endl;
    } 
    return;
}

int main() {
    fast;
    ll t = 1;
    // cin >> t;
    while (t--) {
        solve();
    }
    return 0;
}