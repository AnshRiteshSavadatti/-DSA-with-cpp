#include<bits\stdc++.h>
using namespace std;
int nearestNo(int x){
    int s = 0;
    int e = x-1;
    long long int ans;
    while(s < e){
        int mid = s + (e-s)/2;
        long long int sqr = mid * mid;
        if(sqr > x)
            e = mid -1;
        else if(sqr < x){
            ans = mid;
            s = mid + 1;
        }
        if(sqr == x)
            return mid;
    }
    return ans;
}

float sqrt(float x, int k){
    double ans;
    for(int i=0;;i++){
        x +=0.1;
        double temp = x * x;
        if(temp == k)
            return x;
        if(temp > k){
            ans = x - 0.1;
            return ans;
        }
    }
}

float sqrt1(float x, int k){
    double ans;
    for(int i=0;;i++){
        x +=0.01;
        double temp = x * x;
        if(temp == k)
            return x;
        if(temp > k){
            ans = x - 0.01;
            return ans;
        }
    }
}

float sqrt2(float x, int k){
    double ans;
    for(int i=0;;i++){
        x +=0.001;
        double temp = x * x;
        if(temp == k)
            return x;
        if(temp > k){
            ans = x - 0.001;
            return ans;
        }
    }
}

int main(){

    int n;
    cout << "Enter the number whose square is to be done " << endl;
    cin >> n;
    long long int ans1 = nearestNo(n);
    float ans2 = sqrt(ans1,n);
    float ans3 = sqrt1(ans2,n);
    cout << "The ans is " << sqrt2(ans2, n) << endl;
    return 0;
}