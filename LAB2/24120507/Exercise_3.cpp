#include<iostream>
#include<math.h>

using namespace std;

int a , b;

int GCD(int a , int b) {
    int r = a % b;
    if(r == 0) return b;
    else return GCD(b , r);
}

int main() {
    cin >> a >> b;
    if(a < b) swap(a ,  b);
    cout << GCD(a , b) << "\n";
}