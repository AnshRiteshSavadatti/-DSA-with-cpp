#include<bits/stdc++.h>
using namespace std;

int N = 1000000;
vector<bool>sieve(N+1);

void create_sieve(){
    for(int i = 2; i < N; i++)
        sieve[i] = true;

    for(int i = 2; i*i <= N; i++){
        if(sieve[i]){
            for(int j = i*i; j <= N; j++){
                sieve[j] = false;
            }
        }
    }
    return;
}

vector<int> generate(int n){
    vector<int> ds;
    for(int i=0; i<n; i++){
        if(sieve[i]){
            ds.push_back(i);
        }
    }
    return ds;
}

int main(){
    create_sieve();
    int l, r;
    cin >> l >> r;

    // Step 1 : genereate all primes till sqrt(r)
    vector<int> primes = generate(sqrt(r));


    // Step 2 : create a dummy array of size r- l + 1 and make everyone as one 
    int dummy[r-l+1];
    for(int i=0; i<r-l+1; i++){
        dummy[i] = 1;
    }


    // Step 3 : mark all multiples of primes in dummy as false
    for(auto it : primes){
        int firstMultiple = (l/it) * it;
        if(firstMultiple < l){
            firstMultiple += it;
        }
        for(int j = max(firstMultiple, it*it); j <= r; j += it){
            dummy[j-l] = 0;
        }
    }

    // Step 4 : get all the primes
    for(int i = l; i <= r; i++){
        if(dummy[i - l]){
            cout << dummy[i-l] << " ";
        }
    }
    return 0;
}