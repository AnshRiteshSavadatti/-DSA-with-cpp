
#include<iostream>
using namespace std;
int square_root(int M)
{   int ans;
    int start=1;
    int end=M;
    int mid ;
    while(start<=end){
    mid = start+(end-start)/2;
       if((mid*mid)==M)
         {
          return mid;

         }
         else if((mid*mid)>M)
          {
            end=mid-1;
          }
          else{
            ans = mid;
            start=mid+1;
          }

    }
    return ans;
}

double precise_ans(double ans, int prc, int m ){
  double a = 1;
  for(int i=0; i<prc; i++){
    a /= 10.0;
    while( (ans + a) * (ans + a)<= m){
      ans += a;
    }
    ans -= a; 
  }
  return ans;
}

int main()
{   
    int M;
    cout<<"the number whose square root has to be found is:"<<endl;
    cin>>M;
  int answer;
  answer=square_root(M);
  int prc;
  cout << "Enter the precision " << endl;
  cin >> prc;
  cout << "The answer is  " <<  answer << endl;
  double final_ans = precise_ans(answer, prc, M);
  cout << final_ans << endl;

  return 0;

}