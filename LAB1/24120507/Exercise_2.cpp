#include<iostream>
#include<stdio.h>
#include<fstream>
#include<vector>

using namespace std;

const char matrix_a[] = {"matrix_a.txt"};
const char matrix_b[] = {"matrix_b.txt"};
const char matrix_c[] = {"matrix_c.txt"};
const char matrix_TC[] = {"matrix_c_transposed.txt"};

bool readMatrix(const char *filename , int **&matrix , int &rows , int &cols) {
    FILE * file = fopen(filename , "r");
    if(!file) return false;
    rows = cols = 0;
    char line[10000];
    while(fgets(line , sizeof(line) , file)) rows++;
    fclose(file);
    ifstream f(filename);
    vector<int>val;
    val.clear();
    int x;
    while(f >> x) val.push_back(x);
    cols = (int) val.size() / rows;
    matrix = new int*[rows];
    x = 0;
    for (int i = 0; i < rows; i++) {
        matrix[i] = new int[cols];
        for (int j = 0; j < cols; j++)
            matrix[i][j] = val[x++];
    }
    return true;
}

void printMatrix(const char * filename , int **matrix , int rows , int cols) {
    ofstream f(filename);
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols ; j++)
            f << matrix[i][j] << " ";
        f << "\n";
    }
}

bool multiplyMatrices(int **a , int aRows , int aCols , int **b , int bRows , int bCols , int **&res , int &resRows , int &resCols) {
    if(aCols != bRows) return false;
    resRows = aRows , resCols = bCols;
    res = new int *[resRows];
    for (int i = 0; i < resRows; i++) {
        res[i] = new int[resCols];
        for (int j = 0; j < resCols; j++) {
            res[i][j] = 0;
            for (int k = 0; k < bRows; k++)
                res[i][j] += a[i][k] * b[k][j];
        }
    }
    return true;
}

void transposeMatrix(int **matrix , int rows , int cols , int **&res , int &resRows , int &resCols) {
    resRows = cols , resCols = rows;
    res = new int*[resRows];
    for (int i = 0; i < resRows; i++)
        res[i] = new int[resCols];
    for (int i = 0; i < rows; i++)
    for (int j = 0; j < cols; j++)
        res[j][i] = matrix[i][j];
}

int main() {
    int rowA , rowB , rowC , rowTC;
    int colA , colB , colC , colTC;
    int **matrixA = nullptr , **matrixB = nullptr, **matrixC = nullptr , **matrixTC = nullptr;
    if(readMatrix(matrix_a , matrixA , rowA , colA))
        cout << "Read Successfully" << "\n";
        else cout << "Cannot Read File" << "\n";
    if(readMatrix(matrix_b, matrixB , rowB , colB))
        cout << "Read Successfully" << "\n";
        else cout << "Cannot Read File" << "\n";
    if(multiplyMatrices(matrixA , rowA , colA , matrixB , rowB , colB , matrixC , rowC , colC))
        printMatrix(matrix_c , matrixC , rowC , colC);
    transposeMatrix(matrixC , rowC , colC , matrixTC , rowTC , colTC);
    printMatrix(matrix_TC , matrixTC , rowTC , colTC);
    return 0;
}
