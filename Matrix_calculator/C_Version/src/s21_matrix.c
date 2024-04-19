#include "s21_matrix.h"

int s21_inverse_matrix(matrix_t *A, matrix_t *result) {
  int res = 2;

  if (s21_is_bad_matrix(A) == SUCCESS) return 1;
  if (A->columns != A->rows) return 2;

  if (A->columns == A->rows && A->rows > 0) {
    s21_create_matrix(A->columns, A->rows, result);
    double det = 0;
    s21_determinant(A, &det);
    if (det != 0) {
      res = 0;
      matrix_t minor;
      matrix_t transp;
      s21_create_matrix(A->rows, A->columns, &minor);
      s21_create_matrix(A->rows, A->columns, &transp);

      s21_calc_complements(A, &minor);
      s21_transpose(&minor, &transp);
      s21_mult_number(&transp, 1 / det, result);

      s21_remove_matrix(&minor);
      s21_remove_matrix(&transp);
    }
  }
  return res;
}

int s21_calc_complements(matrix_t *A, matrix_t *result) {
  int res = 2;
  double det = 0;
  s21_create_matrix(A->columns, A->rows, result);
  if (A->columns == A->rows && A->rows > 0) {
    res = 0;
    for (int i = 0; i < A->rows; i++) {
      for (int j = 0; j < A->columns; j++) {
        matrix_t minor;
        s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
        s21_minor(A, i + 1, j + 1, &minor);

        s21_determinant(&minor, &det);
        result->matrix[i][j] = det * pow(-1, i + j);
        s21_remove_matrix(&minor);
      }
    }
  }
  return res;
}

int s21_determinant(matrix_t *A, double *result) {
  int res = 1;

  if (A->columns == A->rows && A->columns > 0) {
    if (A->columns == 2)
      *result = (A->matrix[0][0] * A->matrix[1][1] -
                 A->matrix[0][1] * A->matrix[1][0]);
    else if (A->columns == 1)
      *result = A->matrix[0][0];
    else {
      if (A->columns % 2 == 0)
        *result = determinant(A, 1);
      else
        *result = determinant(A, -1);
    }
    res = 0;
  }
  return res;
}

double determinant(matrix_t *A, int exp) {
  if (A->columns == 2) {
    return (A->matrix[0][0] * A->matrix[1][1] -
            A->matrix[0][1] * A->matrix[1][0]);
  } else {
    double buf = 0;
    for (int j = 0; j < A->columns; j++) {
      matrix_t minor;
      s21_create_matrix(A->rows - 1, A->columns - 1, &minor);
      s21_minor(A, 0 + 1, j + 1, &minor);
      buf += determinant(&minor, 1) * A->matrix[0][j] * pow(-1, j + 1);
      s21_remove_matrix(&minor);
    }
    return buf * exp;
  }
}

void s21_minor(matrix_t *A, int rows, int columns, matrix_t *result) {
  int def_rows = 0, def_columns = 0;
  for (int m = 0; m < A->rows; m++) {
    for (int n = 0; n < A->columns; n++) {
      if (m == rows - 1 || n == columns - 1) {
        if (m == rows - 1) def_rows = 1;
        if (n == columns - 1) def_columns = 1;
      } else if (n < columns - 1) {
        result->matrix[m - def_rows][n] = A->matrix[m][n];
      } else if (m < rows - 1) {
        result->matrix[m][n - def_columns] = A->matrix[m][n];
      } else {
        result->matrix[m - def_rows][n - def_columns] = A->matrix[m][n];
      }
    }
  }
}

int s21_transpose(matrix_t *A, matrix_t *result) {
  int res = 1;
  s21_create_matrix(A->columns, A->rows, result);
  if (A->rows == result->columns && A->columns == result->rows && A->rows > 0 &&
      A->columns) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[n][m] = A->matrix[m][n];
      }
    }
    res = 0;
  }
  return res;
}

int s21_mult_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 2;
  s21_create_matrix(A->rows, B->columns, result);

  if (A->rows == B->columns && A->columns == B->rows &&
      result->rows >= A->rows && result->columns >= A->rows) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->rows; n++) {
        for (int i = 0; i < A->columns; i++) {
          result->matrix[m][n] += (A->matrix[m][i] * B->matrix[i][n]);
          // printf("<A[%d][%d]%.1f * B[%d][%d]%.1f += %.1f>\n",m, i,
          // A->matrix[m][i], i, n, B->matrix[i][n], (A->matrix[m][i] *
          // B->matrix[i][n]));
        }
      }
    }
    res = 0;
  }
  return res;
}

int s21_create_matrix(int rows, int columns, matrix_t *result) {
  int res = 1;
  if (rows > 0 && columns > 0) {
    res = 0;
    result->matrix = (double **)calloc(rows, sizeof(double *));
    for (int i = 0; i < rows; i++) {
      result->matrix[i] = (double *)calloc(columns, sizeof(double));
    }
    result->rows = rows;
    result->columns = columns;
    for (int m = 0; m < rows; m++) {
      for (int n = 0; n < columns; n++) {
        result->matrix[m][n] = 0;
      }
    }
  }
  return res;
}

void s21_remove_matrix(matrix_t *A) {
  for (int i = 0; i < A->rows; i++) {
    free(A->matrix[i]);
  }
  free(A->matrix);
  A->columns = 0;
  A->rows = 0;
  A->matrix = S21_NULL;
}

int s21_eq_matrix(matrix_t *A, matrix_t *B) {
  int status = 1;

  if (s21_is_bad_matrix(A) == 0) {
    if (s21_is_bad_matrix(B) == 0)
      status = (A->rows == B->rows && A->columns == B->columns) ? 1 : 0;
  }

  for (int x = 0; status == 1 && x < A->rows; x += 1) {
    for (int y = 0; status == 1 && y < A->columns; y += 1) {
      if (fabs(A->matrix[x][y] - B->matrix[x][y]) > 1e-07) status = FAILURE;
    }
  }

  return status;
}

int s21_eq_matrix_size(matrix_t *A, matrix_t *B) {
  int result = FAILURE;
  if ((A->columns == B->columns) && ((A->rows == B->rows))) {
    result = SUCCESS;
  }
  return result;
}

int s21_sum_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 2;
  s21_create_matrix(A->rows, A->columns, result);

  if (s21_eq_matrix_size(A, B) && s21_eq_matrix_size(A, result)) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[m][n] = A->matrix[m][n] + B->matrix[m][n];
      }
    }
    res = 0;
  }
  return res;
}

int s21_sub_matrix(matrix_t *A, matrix_t *B, matrix_t *result) {
  int res = 2;
  s21_create_matrix(A->rows, A->columns, result);
  if (s21_eq_matrix_size(A, B) && s21_eq_matrix_size(A, result)) {
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[m][n] = A->matrix[m][n] - B->matrix[m][n];
      }
    }
    res = 0;
  }
  return res;
}

int s21_mult_number(matrix_t *A, double number, matrix_t *result) {
  int res = 1;
  if (A->rows > 0 && A->columns > 0) {
    res = 0;
    s21_create_matrix(A->rows, A->columns, result);
    for (int m = 0; m < A->rows; m++) {
      for (int n = 0; n < A->columns; n++) {
        result->matrix[m][n] = A->matrix[m][n] * number;
      }
    }
  }

  return res;
}

void s21_init_matrix(double number, matrix_t *A) {
  for (int x = 0; x < A->rows; x += 1) {
    for (int y = 0; y < A->columns; number += 1.0, y += 1)
      A->matrix[x][y] = number;
  }
}

int s21_is_bad_matrix(matrix_t *A) {
  return (A == NULL || A->matrix == NULL || A->rows <= 0 || A->columns <= 0);
}