#include<iostream>

using namespace std;

int n;
bool chess[15][15];

bool can_place(int X , int Y) {
    if(chess[X][X]) return false;
    int x = X , y = Y;
    while(x > 0 && y > 0) {
        if(chess[x][y]) return false;
        x-- , y--;
    }
    x = X , y = Y;
    while(x <= n && y <= n) {
        if(chess[x][y]) return false;
        x++ , y++;
    }
    x = X , y = Y;
    while(x > 0) {
        if(chess[x][y]) return false;
        x--;
    }
    x = X , y = Y;
    while(x <= n) {
        if(chess[x][y]) return false;
        x++;
    }
    x = X , y = Y;
    while(y > 0) {
        if(chess[x][y]) return false;
        y--;
    }
    x = X , y = Y;
    while(y <= n) {
        if(chess[x][y]) return false;
        y++;
    }
    x = X , y = Y;
    while(x && y <= n) {
        if(chess[x][y]) return false;
        x--;
        y++;
    }
    x = X , y = Y;
    while(x <= n && y) {
        if(chess[x][y]) return false;
        x++;
        y--;
    }
    return true;
}

void queen(int id) {
    if(id == n) {
        cout << '[';
        bool ok = true;
        for (int i = 1; i <= n; i++)
            for (int j = 1; j <= n; j++)
                if(chess[i][j]) {
                    if(!ok) cout << ',';
                    ok = false;
                    cout << j;
                    break;
                }
        cout << ']' << "\n";
        return;
    }
    for (int i = 1; i <= n; i++)
        if(can_place(id + 1 , i)) {
            chess[id + 1][i] = true;
            queen(id + 1);
            chess[id + 1][i] = false;
        }
}

int main() {
    cin >> n;
    queen(0);
}
