#pragma once
using namespace std;

template <typename T>
class Matrix {

    T** data;
    int rows;
    int columns;

public:

    Matrix(int rows, int columns) {

        this->rows = rows;
        this->columns = columns;
        data = new T * [rows];

        for (int i = 0; i < rows; i++) {

            data[i] = new T[columns];
        }
    }

    Matrix(const Matrix<T>& cop) {

        this->rows = cop.rows;
        this->columns = cop.columns;
        data = new T * [rows];

        for (int i = 0; i < rows; i++) {

            data[i] = new T[columns];

            for (int j = 0; j < rows; j++) {

                this->data[i][j] = cop.data[i][j];
            }
        }
    }

    Matrix<T>& operator= (const Matrix<T>& cop) {

        if (this != &cop) {

            this->rows = cop.rows;
            this->columns = cop.columns;
            data = new T * [rows];

            for (int i = 0; i < rows; i++) {

                data[i] = new T[columns];

                for (int j = 0; j < rows; j++) {

                    this->data[i][j] = cop.data[i][j];
                }
            }
        }
        return *this;
    }

    ~Matrix() {

        for (int i = 0; i < rows; i++) {

            delete data[i];
        }
        delete[] data;
    }

    void set_data(int row, int column, T& new_data){ this->data[row][column] = new_data; }

    T get_data(int row, int column) { return data[row][column]; }

    int get_rows() const{ return this->rows; }

    int get_columns() const{ return this->columns; }

    Matrix<T>& operator+ (const Matrix<T>& cop) {

        if (this->rows == cop.rows && this->columns == cop.columns) {

            Matrix<T>* new_martix = new Matrix(this->rows, this->columns);

            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->columns; j++) {

                    new_martix->data[i][j] = this->data[i][j] + cop.data[i][j];
                }
            }
            return *new_martix;
        }
        else {
            return *this;
        }
    }

    Matrix<T>& operator* (Matrix<T>& cop) {

        if (this->columns == cop.rows) {

            Matrix<T>* new_martix = new Matrix(this->rows, cop.columns);

            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < this->columns; j++) {

                    new_martix->data[i][j] = 0;
                }
            }
            for (int i = 0; i < this->rows; i++) {
                for (int j = 0; j < cop.columns; j++) {
                    for (int k = 0; k < this->columns; k++) {

                        new_martix->data[i][j] += this->data[i][k] * cop.data[k][j];
                    }
                }
            }
            return *new_martix;
        }
        else {
            return *this;
        }
    }

    friend ostream& operator<< (ostream& cou, const Matrix<T>& cop) {

        int row = cop.get_rows(), column = cop.get_columns();
        cout << "Matrix:" << endl;

        for (int i = 0; i < row; i++) {
            for (int j = 0; j < column; j++) {

                cou << cop.data[i][j] << " ";
            }
            cou << '\n';
        }
        return cou;
    }

    friend istream& operator>> (istream& in, Matrix<T>& cop) {

        T x;
        for (int i = 0; i < cop.get_rows(); i++) {
            for (int j = 0; j < cop.get_columns(); j++) {

                in >> x;
                cop.set_data(i, j, x);
            }
        }
        return in;
    }
};