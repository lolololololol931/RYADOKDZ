#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

void printArray(int** arr, int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
}

void printVectorArray(const vector<vector<int>>& arr) {
    for (const auto& row : arr) {
        for (int val : row) {
            cout << val << " ";
        }
        cout << endl;
    }
}

//n1
void addRow(int**& arr, int& rows, int cols, int pos, int* newRow) {
    if (pos < 0 || pos > rows) return;
    int** newArr = new int* [rows + 1];
    for (int i = 0, j = 0; i < rows + 1; i++) {
        if (i == pos)
            newArr[i] = newRow;
        else
            newArr[i] = arr[j++];
    }
    delete[] arr;
    arr = newArr;
    rows++;
}

//n2
void removeRow(vector<vector<int>>& arr, int pos) {
    if (pos < 0 || pos >= arr.size()) return;
    arr.erase(arr.begin() + pos);
}

//n3
vector<vector<int>> converter(const vector<int>& arr, int rows, int cols) {
    vector<vector<int>> result(rows, vector<int>(cols));
    for (int i = 0; i < rows; i++)
        for (int j = 0; j < cols; j++)
            result[i][j] = arr[i * cols + j];
    return result;
}
vector<int> convertTo1D(const vector<vector<int>>& arr) {
    vector<int> result;
    for (const auto& row : arr)
        result.insert(result.end(), row.begin(), row.end());
    return result;
}

int main() {
    system("chcp 1251>nul");
    //n1

    int rows = 2, cols = 3;
    int** arr = new int* [rows];
    for (int i = 0; i < rows; i++) {
        arr[i] = new int[cols] {i* cols + 1, i* cols + 2, i* cols + 3};
    }
    cout << "вигляд:" << endl;
    printArray(arr, rows, cols);
    int* newRow = new int[cols] {7, 8, 9};
    int choice;
    cout << "куди додати (від 0 до " << rows << "): ";
    cin >> choice;
    addRow(arr, rows, cols, choice, newRow);
    cout << "результат:" << endl;
    printArray(arr, rows, cols);
    //n2

    vector<vector<int>> vectorar = { {1, 2, 3}, {4, 5, 6}, {7, 8, 9} };
    cout << "вигляд:" << endl;
    printVectorArray(vectorar);
    int choice1;
    cout << "який рядок видалити: ";
    cin >> choice1;
    removeRow(vectorar, choice1);
    cout << "результат:" << endl;
    printVectorArray(vectorar);
    //n3

    vector<int> Done = { 1, 2, 3, 4, 5, 6 };
    vector<vector<int>> Dtwo = converter(Done, 2, 3);
    vector<int> res = convertTo1D(Dtwo);

    cout << "з 1д до 2д:" << endl;
    printVectorArray(Dtwo);

    cout << "до 1д:" << endl;
    for (int num : res) {
        cout << num << " ";
    }
    cout << endl;

    return 0;
}
