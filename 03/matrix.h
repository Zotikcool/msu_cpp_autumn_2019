#include <exception>
#include <stdexcept>

class Row
{
public:

    Row(int len): row_len(len), row(new int[len]) {}

    ~Row() {
        delete[] row;
    }

    const int& operator[](int i) const
    {
        if (i > row_len) {
            throw std::out_of_range("Matrix does not have as many columns");
        }
        return row[i - 1];
    }

    int& operator[](int i)
    {
        if (i > row_len) {
            throw std::out_of_range("Matrix does not have as many columns");
        }
        return row[i - 1];
    }

    void operator*=(int n)
    {
        for (int i = 0; i < row_len; i++){
            row[i] *= n;
        }
    }

private:
    int row_len;
    int *row;
};


class Matrix
{
public:

    Matrix(int rows, int cols): rows(rows), cols(cols), rows_array(new Row*[rows]) {

        for (int i = 0; i < rows; i++) {
            rows_array[i] = new Row(cols);
        }
    }

    int getRows() {
        return rows;
    }

    int getColumns() {
        return cols;
    }

    const Row& operator[](int n) const
    {
        if (n > rows) {
            throw std::out_of_range("Matrix does not have as many rows");
        }
        return *rows_array[n - 1];
    }

    Row& operator[](int n)
    {
        if (n > rows) {
            throw std::out_of_range("Matrix does not have as many rows");
        }
        return *rows_array[n - 1];
    }

    const Matrix& operator*=(int n) const
    {
        for (int i = 0; i < rows; i++){
            *rows_array[i] *= n;
        }
        return *this;
    }

    bool operator==(const Matrix& other) const
    {
        if (this == &other)
            return true;
        for (int i = 1; i <= rows; ++i) {
            for (int j = 1; j <= cols; j++) {
                if ((*this)[i][j] != other[i][j])
                    return false;
            }
        }
        return true;
    }

    bool operator!=(const Matrix& other) const
    {
        if (*this == other) {
            return false;
        }
        return true;
    }

private:
        int rows;
        int cols;
        Row **rows_array;
};
