#include <gtest/gtest.h>

#include <iostream>

#include "s21_matrix_oop.h"

#define fill_matrix(m, arr_values)          \
  for (int i = 0; i < m.GetRows(); i++) {   \
    for (int j = 0; j < m.GetCols(); j++) { \
      m(i, j) = arr_values[i][j];           \
    }                                       \
  }

using namespace std;

TEST(functions_suite, mult_matrix_function_test_1) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}, {4, 8, 2}};

  double expectedValues[3][3] = {{32, 44, 16}, {70, 96, 42}, {112, 156, 70}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(4, 3);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(3, 3);
  fill_matrix(expected_result, expectedValues);

  A.MulMatrix(B);

  EXPECT_TRUE(expected_result == A);
}

TEST(functions_suite, mult_matrix_function_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[4][2] = {{1, 2}, {5, 6}, {9, 10}, {4, 8}};

  double expectedValues[3][2] = {{32, 44}, {70, 96}, {112, 156}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(4, 2);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(3, 2);
  fill_matrix(expected_result, expectedValues);

  A.MulMatrix(B);

  EXPECT_TRUE(expected_result == A);
}

TEST(functions_suite, mult_matrix_function_test_3) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 4);
  fill_matrix(B, arr2);

  EXPECT_THROW(A.MulMatrix(B), std::invalid_argument);
}

TEST(constructors_suite, default_constructor_1) {
  S21Matrix matrix = S21Matrix();
  EXPECT_EQ(matrix.GetRows(), 1);
  EXPECT_EQ(matrix.GetCols(), 1);
}
TEST(constructors_suite, constructor_with_matrix_size_1) {
  S21Matrix matrix = S21Matrix(5, 6);
  EXPECT_EQ(matrix.GetRows(), 5);
  EXPECT_EQ(matrix.GetCols(), 6);
}
// TEST(constructors_suite, constructor_with_matrix_size_2) {
//   EXPECT_THROW(S21Matrix(-1, -3), std::out_of_range);
// }
TEST(constructors_suite, copy_constructor_1) {
  double arr[4][3] = {
      {1.52, 2.135, 3.315},
      {4.316316136, 5.136136, 6.31531},
      {7.136, 8.1614, 9.64314},
      {3.341134, 10.136133, 136.36136},

  };
  int rows = 4;
  int cols = 3;
  S21Matrix matrix = S21Matrix(rows, cols);
  fill_matrix(matrix, arr);

  S21Matrix expected_matrix = S21Matrix(rows, cols);
  fill_matrix(expected_matrix, arr);

  S21Matrix result = S21Matrix(matrix);

  EXPECT_TRUE(result == expected_matrix);
}

TEST(constructors_suite, move_constructor_1) {
  double arr[4][3] = {
      {1.52, 2.135, 3.315},
      {4.316316136, 5.136136, 6.31531},
      {7.136, 8.1614, 9.64314},
      {3.341134, 10.136133, 136.36136},

  };
  int rows = 4;
  int cols = 3;
  S21Matrix matrix = S21Matrix(rows, cols);
  fill_matrix(matrix, arr);

  S21Matrix expected_matrix = S21Matrix(rows, cols);
  fill_matrix(expected_matrix, arr);

  S21Matrix result = S21Matrix(std::move(matrix));

  EXPECT_TRUE(result == expected_matrix);
  EXPECT_EQ(matrix.GetRows(), 0);
  EXPECT_EQ(matrix.GetCols(), 0);
}

TEST(mutators_suite, set_row_test_1) {
  S21Matrix result;
  result.SetRows(5);
  EXPECT_TRUE(result.GetRows() == 5);
}

TEST(mutators_suite, set_row_test_2) {
  S21Matrix result = S21Matrix(3, 3);
  result.SetRows(5);
  EXPECT_TRUE(result.GetRows() == 5);
}

TEST(mutators_suite, set_row_test_3) {
  S21Matrix result = S21Matrix(3, 3);
  result.SetRows(5);
  EXPECT_TRUE(result.GetRows() == 5);
}

TEST(mutators_suite, set_cols_test_1) {
  S21Matrix result;
  result.SetCols(5);
  EXPECT_TRUE(result.GetCols() == 5);
}

TEST(mutators_suite, set_cols_test_2) {
  S21Matrix result = S21Matrix(3, 3);
  result.SetCols(5);
  EXPECT_TRUE(result.GetCols() == 5);
}

TEST(mutators_suite, set_cols_test_3) {
  S21Matrix result = S21Matrix(5, 5);
  result.SetCols(3);
  EXPECT_TRUE(result.GetCols() == 3);
}

TEST(operators_suite, mult_matrix_assignment_operator_test_1) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}, {4, 8, 2}};

  double expectedValues[3][3] = {{32, 44, 16}, {70, 96, 42}, {112, 156, 70}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(4, 3);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(3, 3);
  fill_matrix(expected_result, expectedValues);

  EXPECT_TRUE((A *= B) == A);
  EXPECT_TRUE(expected_result == A);
}

TEST(operators_suite, mult_matrix_assignment_operator_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[4][2] = {{1, 2}, {5, 6}, {9, 10}, {4, 8}};

  double expectedValues[3][2] = {{32, 44}, {70, 96}, {112, 156}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(4, 2);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(3, 2);
  fill_matrix(expected_result, expectedValues);

  EXPECT_TRUE((A *= B) == A);
  EXPECT_TRUE(expected_result == A);
}

TEST(operators_suite, mult_matrix_assignment_operator_test_3) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 4);
  fill_matrix(B, arr2);

  EXPECT_THROW(A *= B, std::invalid_argument);
}

TEST(operators_suite, mult_matrix_operator_test_1) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[4][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}, {4, 8, 2}};

  double expectedValues[3][3] = {{32, 44, 16}, {70, 96, 42}, {112, 156, 70}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(4, 3);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(3, 3);
  fill_matrix(expected_result, expectedValues);

  S21Matrix result = A * B;
  EXPECT_TRUE(expected_result == result);
}
TEST(operators_suite, mult_matrix_operator_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[4][2] = {{1, 2}, {5, 6}, {9, 10}, {4, 8}};

  double expectedValues[3][2] = {{32, 44}, {70, 96}, {112, 156}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(4, 2);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(3, 2);
  fill_matrix(expected_result, expectedValues);

  S21Matrix result = A * B;
  EXPECT_TRUE(expected_result == result);
}

TEST(operators_suite, mult_matrix_operator_test_3) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 4);
  fill_matrix(B, arr2);

  EXPECT_THROW(A * B, std::invalid_argument);
}

TEST(operators_suite, mult_number_assignment_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};

  double expectedValues[3][4] = {
      {-3, -3, -6, -6}, {-9, -9, -12, -12}, {-15, -15, -18, -21}};
  double number = -3;

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  EXPECT_TRUE((A *= number) == A);
  EXPECT_TRUE(expected_result == A);
}

TEST(operators_suite, mult_number_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};

  double expectedValues[3][4] = {
      {-3, -3, -6, -6}, {-9, -9, -12, -12}, {-15, -15, -18, -21}};
  double number = -3;

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  S21Matrix result = A * number;
  EXPECT_TRUE(expected_result == result);
}

TEST(operators_suite, mult_number_operator_test_2) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};

  double expectedValues[3][4] = {
      {-3, -3, -6, -6}, {-9, -9, -12, -12}, {-15, -15, -18, -21}};
  double number = -3;

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  S21Matrix result = number * A;
  EXPECT_TRUE(expected_result == result);
}

TEST(operators_suite, parentheses_operators_test_1) {
  S21Matrix matrix(1, 1);
  matrix(0, 0) = 10.123;
  EXPECT_DOUBLE_EQ(((const S21Matrix)matrix)(0, 0), 10.123);
}

TEST(operators_suite, parentheses_operator_test_2) {
  S21Matrix matrix(3, 4);
  EXPECT_THROW(matrix(0, 5) = 10.132, std::out_of_range);

  const S21Matrix const_matrix = S21Matrix(4, 3);
  EXPECT_THROW(const_matrix(0, 4), std::out_of_range);
}

TEST(operators_suite, sub_assignment_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 1, 2}};

  double expectedValues[3][4] = {
      {0, -1, -1, -2}, {-2, -3, -3, -4}, {-4, -5, 5, 5}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(rowsCount, columnsCount);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  EXPECT_TRUE((A -= B) == A);
  EXPECT_TRUE(expected_result == A);
}

TEST(operators_suite, sub_assignment_operator_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 3);
  fill_matrix(B, arr2);

  EXPECT_THROW(A -= B, std::invalid_argument);
}

TEST(operators_suite, sub_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 1, 2}};

  double expectedValues[3][4] = {
      {0, -1, -1, -2}, {-2, -3, -3, -4}, {-4, -5, 5, 5}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(rowsCount, columnsCount);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  S21Matrix result = A - B;
  EXPECT_TRUE(expected_result == result);
}

TEST(operators_suite, sub_operator_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 3);
  fill_matrix(B, arr2);

  EXPECT_THROW(A - B, std::invalid_argument);
}

TEST(operators_suite, sum_assignment_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 1, 2}};

  double expectedValues[3][4] = {{2, 3, 5, 6}, {8, 9, 11, 12}, {14, 15, 7, 9}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(rowsCount, columnsCount);
  fill_matrix(B, arr2);

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  EXPECT_TRUE((A += B) == A);
  EXPECT_TRUE(expected_result == A);
}

TEST(operators_suite, sum_assignment_operator_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 3);
  fill_matrix(B, arr2);

  EXPECT_THROW(A += B, std::invalid_argument);
}

TEST(operators_suite, sum_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 1, 2}};

  double expectedValues[3][4] = {{2, 3, 5, 6}, {8, 9, 11, 12}, {14, 15, 7, 9}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(rowsCount, columnsCount);
  fill_matrix(B, arr2);

  S21Matrix result;

  S21Matrix expected_result = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expected_result, expectedValues);

  result = A + B;
  EXPECT_TRUE(result == expected_result);
}

TEST(operators_suite, EqMatrix_operator_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 1, 2}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(rowsCount, columnsCount);
  fill_matrix(B, arr2);

  EXPECT_FALSE(A.EqMatrix(B));
}

TEST(operators_suite, sum_operator_test_2) {
  double arr1[3][4] = {{1, 1, 2, 2}, {3, 3, 4, 4}, {5, 5, 6, 7}};
  double arr2[3][3] = {{1, 2, 3}, {5, 6, 7}, {9, 10, 1}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix B = S21Matrix(3, 3);
  fill_matrix(B, arr2);

  EXPECT_THROW(A + B, std::invalid_argument);
}

TEST(functions_suite, transpose_function_test_1) {
  double arr1[3][4] = {{1, 2, 3, 4}, {5, 6, 7, 8}, {9, 10, 11, 12}};

  double expectedValues[4][3] = {{1, 5, 9}, {2, 6, 10}, {3, 7, 11}, {4, 8, 12}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  S21Matrix expected_result = S21Matrix(4, 3);
  fill_matrix(expected_result, expectedValues);

  S21Matrix result = A.Transpose();
  EXPECT_TRUE(expected_result == result);
}

TEST(functions_suite, minor_function_test_2) {
  double arr1[2][2] = {{10, 7}, {4, -2}};

  S21Matrix A(2, 2);
  fill_matrix(A, arr1);

  EXPECT_THROW(A.s21_minor(-2, 2), std::invalid_argument);
}

TEST(functions_suite, create_function_test_2) {
  EXPECT_THROW(S21Matrix A(-2, 2), std::out_of_range);
}

TEST(functions_suite, Rows_accesor_function_test_2) {
  S21Matrix A(2, 2);
  A.SetRows(2);

  EXPECT_THROW(A.SetRows(0), std::invalid_argument);
}

TEST(functions_suite, Cols_accesor_function_test_2) {
  S21Matrix A(2, 2);
  A.SetCols(2);

  EXPECT_THROW(A.SetCols(0), std::invalid_argument);
}

TEST(functions_suite, determinant_function_test_2) {
  double arr1[2][2] = {{10, 7}, {4, -2}};

  double expectedDeterminant = -48;

  S21Matrix A = S21Matrix(2, 2);
  fill_matrix(A, arr1);

  EXPECT_DOUBLE_EQ(A.Determinant(), expectedDeterminant);
}

TEST(functions_suite, determinant_function_test_3) {
  double arr1[3][3] = {
      {10.4, 8.53, -9.321}, {3.0, -10.6, 5.6}, {55, -53.7, 123}};

  double expectedDeterminant = -14884.8919;

  S21Matrix A = S21Matrix(3, 3);
  fill_matrix(A, arr1);

  EXPECT_DOUBLE_EQ(A.Determinant(), expectedDeterminant);
}

TEST(functions_suite, determinant_function_test_4) {
  double arr1[3][4] = {
      {10.4, 8.53, -9.321, 0}, {3.0, -10.6, 5.6, 0}, {55, -53.7, 123, 0}};

  S21Matrix A = S21Matrix(3, 4);
  fill_matrix(A, arr1);

  EXPECT_THROW(A.Determinant(), std::logic_error);
}

TEST(functions_suite, calc_complements_function_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 3;
  double arr1[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};

  double expectedValues[3][3] = {{0, 10, -20}, {4, -14, 8}, {-8, -2, 4}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expectedResult = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expectedResult, expectedValues);

  S21Matrix result = A.CalcComplements();
  EXPECT_TRUE(expectedResult == result);
}

TEST(functions_suite, calc_complements_function_test_2) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {
      {10.4, 8.53, -9.321, 0}, {3.0, -10.6, 5.6, 0}, {55, -53.7, 123, 0}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  EXPECT_THROW(A.CalcComplements(), std::logic_error);
}

TEST(functions_suite, calc_complements_function_test_3) {
  const int rowsCount = 1;
  const int columnsCount = 1;
  double arr1[1][1] = {{3.235153}};

  double expectedValues[1][1] = {{3.235153}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expectedResult = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expectedResult, expectedValues);

  S21Matrix result = A.CalcComplements();
  EXPECT_TRUE(expectedResult == result);
}

TEST(functions_suite, inverse_function_test_1) {
  const int rowsCount = 3;
  const int columnsCount = 3;
  double arr1[3][3] = {{1, 2, 3}, {0, 4, 2}, {5, 2, 1}};

  double expectedValues[3][3] = {
      {0, -0.1, 0.2}, {-0.25, 0.35, 0.05}, {0.5, -0.2, -0.1}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expectedResult = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expectedResult, expectedValues);

  S21Matrix result = A.InverseMatrix();

  EXPECT_TRUE(result == expectedResult);
}

TEST(functions_suite, inverse_function_test_2) {
  const int rowsCount = 1;
  const int columnsCount = 1;
  double arr1[1][1] = {{52}};

  double expectedValues[1][1] = {{1.0 / 52}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  S21Matrix expectedResult = S21Matrix(rowsCount, columnsCount);
  fill_matrix(expectedResult, expectedValues);

  S21Matrix result = A.InverseMatrix();

  EXPECT_TRUE(result == expectedResult);
}

TEST(functions_suite, inverse_function_test_3) {
  const int rowsCount = 3;
  const int columnsCount = 4;
  double arr1[3][4] = {{1, 2, 3, 4}, {0, 4, 2, 5}, {5, 2, 1, 6}};

  S21Matrix A = S21Matrix(rowsCount, columnsCount);
  fill_matrix(A, arr1);

  EXPECT_THROW(A.InverseMatrix(), std::logic_error);
}

int main(int argc, char **argv) {
  testing::InitGoogleTest(&argc, argv);

  return RUN_ALL_TESTS();
}
