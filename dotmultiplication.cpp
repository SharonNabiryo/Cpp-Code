#include <iostream>

using namespace std;

void printProduct(int** mat1, int** mat2, int r1, int c1, int r2, int c2, char example);

int main(){
    // Example a Matrices
    int r1a = 2, c1a = 2; 
    int r2a = 2, c2a = 4;

    int** mat1a = new int*[r1a];
    for (int i = 0; i < r1a; i++) {
        mat1a[i] = new int[c1a];
    }

    mat1a[0][0] = 2;     mat1a[0][1] = 5;
    mat1a[1][0] = 3;     mat1a[1][1] = 8; 


    int** mat2a = new int*[r2a];
    for (int i = 0; i < r2a; i++) {
        mat2a[i] = new int[c2a];
    }

    mat2a[0][0] = 6;     mat2a[0][1] = 9;   mat2a[0][2] = 11;     mat2a[0][3] = 13;
    mat2a[1][0] = 12;    mat2a[1][1] = 18;   mat2a[1][2] = 22;   mat2a[1][3] = 26;



    // example two
    int r1b = 3, c1b = 3; 
    int r2b = 3, c2b = 2;

    int** mat1b = new int*[r1b];
    for (int i = 0; i < r1b; i++) {
        mat1b[i] = new int[c1b];
    }

    mat1b[0][0] = 1;     mat1b[0][1] = 2;    mat1b[0][2] = 4;
    mat1b[1][0] = 8;     mat1b[1][1] = 16;   mat1b[1][2] = 32;
    mat1b[2][0] = 64;    mat1b[2][1] = 128;  mat1b[2][2] = 256;


    int** mat2b = new int*[r2b];
    for (int i = 0; i < r2b; i++) {
        mat2b[i] = new int[c2b];
    }

    mat2b[0][0] = 3;     mat2b[0][1] = 5;   
    mat2b[1][0] = 7;     mat2b[1][1] = 9;  
    mat2b[2][0] = 11;    mat2b[2][1] = 13;



    // Perform Multiplication for Both Examples
    printProduct(mat1a, mat2a, r1a, c1a, r2a, c2a, 'a');
    printProduct(mat1b, mat2b, r1b, c1b, r2b, c2b, 'b');

    return 0;
}


void printProduct(int** mat1, int** mat2, int r1, int c1, int r2, int c2, char example){

    if (c1 != r2){
        cout<<"Impossible: The number of columns in the first matrix is" << c1 << "and the number of rows in the second matrix is" << r2 << endl;

    }
    else {
        int rslt[r1][c2];
        cout<< "Multiplication of given two matrices is: \n";
        for (int i=0; i<r1; i++){
            for (int j=0; j<c2; j++){
                rslt[i][j] = 0;

            cout << "Computing R[" << i << "][" << j << "]:\n";  // Show which element is being calculated
            cout << "Dot product: [ ";

                for (int k=0; k<c1; k++){
                    cout << mat1[i][k] << " ";
                }
                cout << "] x [ ";

                for (int k=0; k<c1; k++){
                    cout << mat2[k][j] << " ";
                }
                cout << "] = ";

                for (int k=0; k<c1; k++){

                    rslt[i][j] += mat1[i][k] * mat2[k][j];
                     
                }
                cout << rslt[i][j]<<endl;
            }
            cout << endl;
        }
    }
}

