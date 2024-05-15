/*
    We want to calculate the total marks of each student of a class in Physics,Chemistry and 
    Mathematics and the average marks of the class. The number of students in the class are 
    entered by the user. Create a class named Marks with data members for roll number, name 
    and marks. Create three other classes inheriting the Marks class, namely Physics, 
    Chemistry and Mathematics, which are used to define marks in individual subject of each 
    student. Roll number of each student will be generated automatically.

*/

/*
INPUT
3
100 ansh 47
11 aaaa 45
12 4444 56

12 ansh 47
13 aaaa 45
14 4444 56

15 ansh 47
12 aaaa 45
11 4444 56

EXPECTED OUTPUT
127 36 37 
42 12 12
*/

#include <bits/stdc++.h>
using namespace std;

class Marks{
    public:
        int rollNo;
        string name;
        float marks;
};

class Physics: public Marks{
    public:
    Physics(){}

    Physics(int rollNo, string name, float marks){
        this->rollNo = rollNo;
        this->marks = marks;
        this->name = name;
    }
};


class Chemistry: public Marks{
    public:
    Chemistry(){}

    Chemistry(int rollNo, string name, float marks){
        this->rollNo = rollNo;
        this->marks = marks;
        this->name = name;
    }
};

class Mathematics: public Marks{
    public:
    Mathematics(){}

    Mathematics(int rollNo, string name, float marks){
        this->rollNo = rollNo;
        this->marks = marks;
        this->name = name;
    }
};

vector<int> sum(int n, vector<Physics> &a, vector<Chemistry> &b, vector<Mathematics>& c){
    vector<int>sum(n, 0);

    for(int i=0; i<n; i++){
        sum[i] = a[i].marks + b[i].marks + c[i].marks;
    }
    return sum;
}

void average(vector<float>& avg, vector<int>& sum, int n){
    
    for(int i =0; i<n; i++){
        avg[i] = (sum[i]/3);
    }
    return;
}

int main(){
    int n;
    cin >> n;
    vector<Physics> a(n);
    vector<Chemistry> b(n);
    vector<Mathematics> c(n);

    for(int i =0; i<n; i++){
        cin >> a[i].marks >> a[i].name >> a[i].rollNo;
    }

    for(int i =0; i<n; i++){
        cin >> b[i].marks >> b[i].name >> b[i].rollNo;
    }
    
    for(int i =0; i<n; i++){
        cin >> c[i].marks >> c[i].name >> c[i].rollNo;
    }

    vector<int>summ(n);

    summ = sum(n, a, b, c);

    vector<float>avg(n, 0);

    average(avg, summ, n);

    for(auto it: summ){
        cout << it << " ";
    }
    cout << endl;

    for(auto it: avg){
        cout << it << " "; 
    }
    cout << endl;


}
