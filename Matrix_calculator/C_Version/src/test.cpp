#include <iostream>
#include <vector>

using namespace std;

// Функция для нахождения минора матрицы
int findMinor(vector<vector<int>>& matrix, int row, int col) {
    vector<vector <int> > minorMatrix;
    int n = matrix.size();

    for (int i = 0; i < n; i++) {
        if (i != row) {
            vector<int> tempRow;
            for (int j = 0; j < n; j++) {
                if (j != col) {
                    tempRow.push_back(matrix[i][j]);
                }
            }
            minorMatrix.push_back(tempRow);
        }
    }

    // Вывод минора матрицы
    cout << "Минор матрицы " << row << ", " << col << ":" << endl;
    for (int i = 0; i < n - 1; i++) {
        for (int j = 0; j < n - 1; j++) {
            cout << minorMatrix[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}

int main() {
    vector<vector<int>> matrix = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    int row = 1;
    int col = 1;

    findMinor(matrix, row, col);

    return 0;
}
