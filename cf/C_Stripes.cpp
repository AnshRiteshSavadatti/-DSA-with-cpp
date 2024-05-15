#include <bits/stdc++.h>
using namespace std;

int main() {
    int t;
    cin>>t;
    while(t--){
        vector<vector<char>>v(8,vector<char>(8)); 
        for (int i=0;i<8;i++) {
            for (int j=0; j < 8; j++) {
                    cin>>v[i][j];   
            }
        }

        char output;
        
        for (int i=0;i<8;i++) {
            char c=v[i][0];
            int cnt = 0;
            for (int j=0;j<8;j++) {
                if (v[i][j] != c) {
                    break;
                } else {
                    cnt++;
                }
            }
            if (cnt == 8 && c!='.') {
                output = c;
                break;
            }
        }
      
        for (int j=0;j<8;j++) {
            char c = v[0][j];
            int cnt = 0;
            for (int i=0;i<8;i++) {
                if (v[i][j] != c) {
                    break;
                } else {
                    cnt++;
                }
            }
            if (cnt == 8 && c!='.') {
                output = c;
                break;
            }
        }

        cout << output << endl;
    }
    return 0;
}