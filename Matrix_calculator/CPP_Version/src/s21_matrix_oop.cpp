#include "s21_matrix_oop.h"

// MAIN FUNCTIONS

S21Matrix S21Matrix::InverseMatrix() {
  if (cols_ != rows_ && rows_ > 1)
    throw std::invalid_argument(
        "Rows != columns in Inverse Matrix calculation");
  if (rows_ == 1) {
    matrix_[0][0] = 1 / matrix_[0][0];
    return *this;
  }
  S21Matrix inverse = *this;
  double det = Determinant();

  if (det != 0) {
    inverse = CalcComplements();
    inverse = inverse.Transpose();
    inverse *= 1 / det;
  }
  return inverse;
}

S21Matrix S21Matrix::CalcComplements() {
  if (rows_ != cols_)
    throw std::invalid_argument("rows != cols in CalcComplements");
  if (rows_ == 1) return *this;
  S21Matrix result(rows_, cols_);
  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      S21Matrix minor = s21_minor(i, j);
      result.matrix_[i][j] = minor.Determinant() * pow(-1, (i + j));
    }
  }
  return result;
}

S21Matrix S21Matrix::s21_minor(int rows, int columns) {
  if (rows < 0 || columns < 0)
    throw std::invalid_argument("wromg minor number");
  S21Matrix minor = S21Matrix(rows_ - 1, cols_ - 1);
  int i = 0;
  int j = 0;
  for (int m = 0; m < rows_; m++) {
    for (int n = 0; n < cols_; n++) {
      if (n != columns && m != rows) {
        minor.matrix_[i][j] = matrix_[m][n];
        j++;
      }
    }
    if (m != rows) i++;
    j = 0;
  }
  return minor;
}

double S21Matrix::Determinant() {
  if (rows_ != cols_)
    throw std::invalid_argument("rows != columns when colculate determinant");
  if (cols_ == 2) {
    return (matrix_[0][0] * matrix_[1][1] - matrix_[0][1] * matrix_[1][0]);
  } else {
    double buf = 0;
    for (int j = 0; j < cols_; j++) {
      int exp = 1;
      S21Matrix minor = s21_minor(0, j);
      if (j % 2 != 0) exp = -1;
      buf += minor.Determinant() * exp * matrix_[0][j];
    }
    return buf;
  }
}

S21Matrix S21Matrix::Transpose() {
  S21Matrix copy(cols_, rows_);
  for (int m = 0; m < rows_; m++) {
    for (int n = 0; n < cols_; n++) {
      copy.matrix_[n][m] = matrix_[m][n];
    }
  }
  return copy;
}

void S21Matrix::MulMatrix(const S21Matrix &other) {
  S21Matrix result = S21Matrix(this->rows_, other.cols_);

  if (cols_ == other.rows_) {
    for (int m = 0; m < result.rows_; m++) {
      for (int n = 0; n < result.cols_; n++) {
        for (int i = 0; i < cols_; i++) {
          result.matrix_[m][n] += (matrix_[m][i] * other.matrix_[i][n]);
        }
      }
    }
    *this = result;
  } else {
    throw std::invalid_argument(
        "Number of colums in first matrix not equal to number of rows in "
        "second matrix");
  }
}

void S21Matrix::SumMatrix(const S21Matrix &other) {
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int m = 0; m < this->rows_; m++) {
      for (int n = 0; n < this->cols_; n++) {
        this->matrix_[m][n] += other.matrix_[m][n];
      }
    }
  } else {
    throw std::invalid_argument("different matrix sizes");
  }
}

void S21Matrix::SubMatrix(const S21Matrix &other) {
  if (this->rows_ == other.rows_ && this->cols_ == other.cols_) {
    for (int m = 0; m < this->rows_; m++) {
      for (int n = 0; n < this->cols_; n++) {
        this->matrix_[m][n] -= other.matrix_[m][n];
      }
    }
  } else {
    throw std::invalid_argument("different matrix sizes");
  }
}

bool S21Matrix::EqMatrix(const S21Matrix &other) {
  bool status =
      (this->rows_ == other.rows_ && this->cols_ == other.cols_) ? true : false;

  for (int x = 0; status && x < this->rows_; x += 1) {
    for (int y = 0; status && y < this->cols_; y += 1) {
      if (fabs(this->matrix_[x][y] - other.matrix_[x][y]) > 1e-07)
        status = false;
    }
  }
  return status;
}

void S21Matrix::MulNumber(const double num) {
  for (int m = 0; m < rows_; m++) {
    for (int n = 0; n < cols_; n++) {
      matrix_[m][n] = matrix_[m][n] * num;
    }
  }
}

S21Matrix &S21Matrix::operator=(const S21Matrix &o) {
  if (this != &o) {
    s21_remove_matrix();
    this->rows_ = o.rows_;
    this->cols_ = o.cols_;

    this->matrix_ = new double *[rows_];
    for (int i = 0; i < rows_; i++) this->matrix_[i] = new double[cols_];

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        matrix_[i][j] = o.matrix_[i][j];
      }
    }
  }
  return *this;
}

// OPERATORS

S21Matrix &S21Matrix::operator+=(const S21Matrix &o) {
  SumMatrix(o);
  return *this;
}
S21Matrix &S21Matrix::operator-=(const S21Matrix &o) {
  SubMatrix(o);
  return *this;
}
S21Matrix &S21Matrix::operator*=(const S21Matrix &o) {
  MulMatrix(o);
  return *this;
}
S21Matrix &S21Matrix::operator*=(const double &o) {
  MulNumber(o);
  return *this;
}

double &S21Matrix::operator()(int row, int col) {
  if (row < 0 || col < 0 || col > cols_)
    throw std::out_of_range("The index is out of range!");
  return matrix_[row][col];
}

double S21Matrix::operator()(int row, int col) const {
  if (row < 0 || col < 0 || col > cols_)
    throw std::out_of_range("The index is out of range!");
  return matrix_[row][col];
}

S21Matrix operator+(const S21Matrix &m1, const S21Matrix &m2) {
  S21Matrix result = S21Matrix(m1);
  result.SumMatrix(m2);
  return result;
}
S21Matrix operator-(const S21Matrix &m1, const S21Matrix &m2) {
  S21Matrix result = S21Matrix(m1);
  result.SubMatrix(m2);
  return result;
}
S21Matrix operator*(const S21Matrix &m1, const S21Matrix &m2) {
  S21Matrix result = S21Matrix(m1);
  result.MulMatrix(m2);
  return result;
}

S21Matrix operator*(const S21Matrix &m1, const double &number) {
  S21Matrix result = S21Matrix(m1);
  result.MulNumber(number);
  return result;
}

S21Matrix operator*(const double &number, const S21Matrix &m1) {
  S21Matrix result = S21Matrix(m1);
  result.MulNumber(number);
  return result;
}

void S21Matrix::s21_create_matrix() {
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) {
    matrix_[i] = new double[cols_];
  }
  for (int m = 0; m < rows_; m++) {
    for (int n = 0; n < cols_; n++) {
      matrix_[m][n] = 0;
    }
  }
}

void S21Matrix::s21_remove_matrix() {
  for (int i = 0; i < rows_; i++) {
    delete[] matrix_[i];
  }
  delete[] matrix_;
}

// CONSTRUCTORS AND DECONSTRUCTORS

S21Matrix::~S21Matrix() { s21_remove_matrix(); }

S21Matrix::S21Matrix() {
  rows_ = 1;
  cols_ = 1;
  s21_create_matrix();
}

S21Matrix::S21Matrix(int rows_, int cols_) {
  if (rows_ >= 1 && cols_ >= 1) {
    this->rows_ = rows_;
    this->cols_ = cols_;
    s21_create_matrix();
  } else
    throw std::out_of_range("Incorrect matrix size!");
}

S21Matrix::S21Matrix(const S21Matrix &o) {
  rows_ = o.rows_;
  cols_ = o.cols_;
  matrix_ = new double *[rows_];
  for (int i = 0; i < rows_; i++) matrix_[i] = new double[cols_];

  for (int i = 0; i < rows_; i++) {
    for (int j = 0; j < cols_; j++) {
      matrix_[i][j] = o.matrix_[i][j];
    }
  }
}

S21Matrix::S21Matrix(S21Matrix &&o) {
  this->rows_ = o.rows_;
  this->cols_ = o.cols_;
  this->matrix_ = o.matrix_;
  o.rows_ = 0;
  o.cols_ = 0;
  o.matrix_ = nullptr;
}

// ACCESOR  AND  MUTATOR

int S21Matrix::GetRows() { return rows_; }  // Getter Setter

void S21Matrix::SetRows(int rows_) {
  if (rows_ == this->rows_)
    return;
  else if (rows_ < 1)
    throw std::invalid_argument("wrong number");
  else {
    S21Matrix prew = *this;
    s21_remove_matrix();
    cols_ = prew.cols_;
    this->rows_ = rows_;
    s21_create_matrix();

    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (i >= prew.rows_)
          matrix_[i][j] = 0;
        else
          matrix_[i][j] = prew.matrix_[i][j];
      }
    }
  }
}

int S21Matrix::GetCols() { return cols_; }

void S21Matrix::SetCols(int cols_) {
  if (cols_ == this->cols_)
    return;
  else if (cols_ < 1)
    throw std::invalid_argument("wrong number");
  else {
    S21Matrix prew = *this;
    s21_remove_matrix();
    rows_ = prew.rows_;
    this->cols_ = cols_;
    s21_create_matrix();
    for (int i = 0; i < rows_; i++) {
      for (int j = 0; j < cols_; j++) {
        if (j >= prew.cols_)
          matrix_[i][j] = 0;
        else
          matrix_[i][j] = prew.matrix_[i][j];
      }
    }
  }
}

// void S21Matrix::print_matrix(){
//     for (int m = 0; m < rows_; m++) {
//         for (int n = 0; n < cols_; n++) {
//             cout << matrix_[m][n] << "   ";
//         }
//         cout << "\n" << endl;
//     }
//     cout << "------------------------------------------------------" << endl;
// }
