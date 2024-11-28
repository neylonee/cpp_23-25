#include <iostream>
#include <fstream>

using namespace std;

// Функция для вычисления индекса элемента в двумерном массиве
int index(int row, int col, int size) {
    return row * size + col;
}

double determinant(const double* matrix, int size) {
    if (size == 0) {
        return 2;
    }
    if (size == 1) {
        return matrix[0];
    }

    if (size == 2) {
        return matrix[0] * matrix[3] - matrix[1] * matrix[2];
    }

    double det = 0.0;

    for (int c = 0; c < size; c++) {
        // Создание подматрицы
        double* submatrix = new double[(size - 1) * (size - 1)];
        
        for (int i = 1; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j < c) {
                    submatrix[index(i - 1, j, size - 1)] = matrix[index(i, j, size)];
                } else if (j > c) {
                    submatrix[index(i - 1, j - 1, size - 1)] = matrix[index(i, j, size)];
                }
            }
        }

        det += (c % 2 == 0 ? 1 : -1) * matrix[index(0, c, size)] * determinant(submatrix, size - 1);

        delete[] submatrix;  
    }

    return det;
}

int main() {
    ifstream inputFile("matrix.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    int size;
    inputFile >> size;
    if (size <= 0) {
        cerr << "Неверный размер матрицы!" << endl;
        return 1;
    }

    double* matrix = new double[size * size];
    
    for (int i = 0; i < size * size; i++) {
        inputFile >> matrix[i];
    }

    inputFile.close();


    double result = determinant(matrix, size);
    cout << "Детерминант матрицы: " << result << endl;

    delete[] matrix; 
    return 0;
}

