#include <iostream>
#include <cmath>
using namespace std;

class S21Matrix {
private:
    int rows_, cols_;                 // attributes                  // rows_ and columns attributes
    double **matrix_;                                                // pointer to the memorcols_ where the matrix_ will be allocated

public:

    S21Matrix();                                                // default constructor
    S21Matrix(int rows_, int cols_);                              // parameterized constructor
    S21Matrix(const S21Matrix& o);                              // copcols_ cnstructor
    S21Matrix(S21Matrix&& o);                               // move cnstructor
    ~S21Matrix();                                               // destructor    
    
    bool EqMatrix(const S21Matrix& other);                       // some public methods
    void SumMatrix(const S21Matrix& other);
    void SubMatrix(const S21Matrix& other);
    void MulNumber(const double num);
    void MulMatrix(const S21Matrix& other);
    S21Matrix Transpose();
    S21Matrix CalcComplements();
    double Determinant();
    S21Matrix InverseMatrix();


    int GetRows();                                     //Getter Setter
    void SetRows(int rows_);

    int GetCols();
    void SetCols(int val);

    void s21_create_matrix();
    void s21_remove_matrix();
    S21Matrix s21_minor(int rows, int columns);
    void print_matrix();
    void write_num(double (&array)[3][3]);

    bool operator==(const S21Matrix& o) {return EqMatrix(o);}
    S21Matrix& operator=(const S21Matrix& o);                   // assignment operator overload
    S21Matrix& operator+=(const S21Matrix& o);
    S21Matrix& operator-=(const S21Matrix& o);
    S21Matrix& operator*=(const S21Matrix& o);
    S21Matrix& operator*=(const double &o);
    double& operator()(int row, int col);                          // index operator overload
    double operator()(int row, int col) const;
};

S21Matrix operator+(const S21Matrix& m1, const S21Matrix& m2);                            // some operators overloads
S21Matrix operator-(const S21Matrix& m1, const S21Matrix& m2);
S21Matrix operator*(const S21Matrix& m1, const S21Matrix& m2);
S21Matrix operator*(const S21Matrix &m1, const double &number);
S21Matrix operator*(const double &number, const S21Matrix &m1);