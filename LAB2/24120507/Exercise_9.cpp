#include<iostream>

using namespace std;

int n;
bool bit[15];

void binary(int id) {
    if(id == n) {
        for (int i = 0; i < n; i++) cout << bit[i];
        cout << "\n";
        return;
    }
    bit[id] = 0;
    binary(id + 1);
    bit[id] = 1;
    binary(id + 1);
    return;
}

int main() {
    cin >> n;
    binary(0);
}
