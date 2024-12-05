#include <stdio.h>
#include <stdlib.h>

// Function to dynamically allocate a 2D array
int** allocateMatrix(int rows, int cols) {
    int** matrix = (int**)malloc(rows * sizeof(int*));
    for (int i = 0; i < rows; i++) {
        matrix[i] = (int*)malloc(cols * sizeof(int));
    }
    return matrix;
}

// Function to free a 2D array
void freeMatrix(int** matrix, int rows) {
    for (int i = 0; i < rows; i++) {
        free(matrix[i]);
    }
    free(matrix);
}

// Main function
int main() {
    int cols, rows = 0, **originalMatrix, **resultMatrix;

    // Read the number of columns
    printf("Enter the number of columns: ");
    scanf("%d", &cols);

    // Allocate space for the original matrix (initially max possible size)
    originalMatrix = allocateMatrix(100, cols);  // Assuming a maximum of 100 rows for simplicity

    // Read rows of the matrix
    printf("Enter rows (terminate with -1):\n");
    while (1) {
        int stopFlag = 0;
        for (int j = 0; j < cols; j++) {
            scanf("%d", &originalMatrix[rows][j]);
            if (originalMatrix[rows][j] == -1) {
                stopFlag = 1;
                break;
            }
        }
        if (stopFlag) break;
        rows++;
    }

    // Adjust matrix size if needed
    originalMatrix = realloc(originalMatrix, rows * sizeof(int*));

    // Check if matrix size is valid for a 3x3 calculation
    if (rows < 3 || cols < 3) {
        printf("Matrix is too small for 3x3 submatrix calculations.\n");
        freeMatrix(originalMatrix, rows);
        return 0;
    }

    // Allocate space for the resultant matrix
    int resultRows = rows - 2;
    int resultCols = cols - 2;
    resultMatrix = allocateMatrix(resultRows, resultCols);

    // Fill the resultant matrix with 3x3 submatrix sums
    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            int sum = 0;
            for (int x = 0; x < 3; x++) {
                for (int y = 0; y < 3; y++) {
                    sum += originalMatrix[i + x][j + y];
                }
            }
            resultMatrix[i][j] = sum;
        }
    }

    // Print the resultant matrix and its dimensions
    printf("Resultant matrix dimension = %dx%d\n", resultRows, resultCols);
    for (int i = 0; i < resultRows; i++) {
        for (int j = 0; j < resultCols; j++) {
            printf("%d ", resultMatrix[i][j]);
        }
        printf("\n");
    }

    // Free allocated memory
    freeMatrix(originalMatrix, rows);
    freeMatrix(resultMatrix, resultRows);

    return 0;
}
