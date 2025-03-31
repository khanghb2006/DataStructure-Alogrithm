#include<iostream>
#include<math.h>

using namespace std;

int n;
int a[105];

bool check(int id) {
    if(id == n) return true;
    return (a[id] < a[id + 1]) * check(id + 1);
}    

int main() {
    cin >> n; 
    for (int i = 1; i <= n; i++)  
        cin >> a[i];
    if(check(1)) cout << "Yes" << "\n";
    else cout << "No" << "\n";
}