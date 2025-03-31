#include<iostream>
#include<math.h>

using namespace std;

int n;

long long frac(int i) {
    if(!i) return 1;
    return i * frac(i - 1);
}

int main() {
    cin >> n;
    cout << frac(n);
}