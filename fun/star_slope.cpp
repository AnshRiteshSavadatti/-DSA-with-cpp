#include <iostream>
#include <thread>
#include <chrono>

using namespace std;

int main() {
    int n = 40;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < i; j++)
            cout << " ";
        cout << "*" << endl;
        // this_thread::sleep_for(chrono::milliseconds(1000));
    }
    return 0;
}
