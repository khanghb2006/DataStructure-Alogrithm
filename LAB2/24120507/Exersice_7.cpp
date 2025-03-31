#include<iostream>

using namespace std;

int n;
int a[15];
bool vis[15];
int permu[15];

void permutation(int id) {
    if(id == n) {
        for (int i = 0; i < n; i++)
            cout << permu[i] << " ";
        cout << "\n";
        return;
    }
    for (int i = 0; i < n; i++)
        if(!vis[a[i]]) {
            vis[a[i]] = true;
            permu[id] = a[i];
            permutation(id + 1);
            vis[a[i]] = false;
        }
    return;
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++)
        cin >> a[i];
    for (int i = 0 ; i < n ;i++)
        for (int j = i + 1; j < n; j++)
            if(a[i] > a[j]) swap(a[i] , a[j]);
    permutation(0);
}
