//
// Created by Collin on 1/7/2022.
//

#include "Matrix.h"
#include <stdexcept>
#include <iostream>



Matrix::Matrix(const Matrix &other) {
    _rows = other.rows;
    _columns = other.columns;

    for(const auto& y : other.values){
        values.emplace_back();
        for(const auto& x : y){
            values.back().push_back(x);
        }
    }
}

Matrix::Matrix(std::vector<std::vector<double>> values) {
    this->values = values;
    _rows = values.size();
    if(_rows == 0){
        throw std::runtime_error("Cannot make a matrix with no rows.");
    }

    _columns = values.at(0).size();
    if(_columns == 0){
        throw std::runtime_error("Cannot make a matrix with no columns.");
    }

    for(const auto& y : values){
        if(y.size() != _columns){
            throw std::runtime_error("Trying to make a matrix with different numbers of columns in different rows.");
        }
    }
}

Matrix::Matrix(int rows, int columns) {
    _rows = rows;
    _columns = columns;

    for(int row = 0; row < rows; row++){
        values.emplace_back();
        for(int column = 0; column < columns; column++){
            values[row].push_back(0);
        }
    }
}

Matrix::Matrix(const Vector3 &vector, Matrix::VectorType orientation) {
    switch(orientation){
        case ROW:
            _columns = 3;
            _rows = 1;
            values.emplace_back();
            values[0].push_back(vector.x);
            values[0].push_back(vector.y);
            values[0].push_back(vector.z);
            break;
        case COLUMN:
            _rows = 3;
            _columns = 1;
            values.emplace_back();
            values.back().push_back(vector.x);

            values.emplace_back();
            values.back().push_back(vector.y);

            values.emplace_back();
            values.back().push_back(vector.z);
            break;
        default:
            throw std::runtime_error("Trying to turn a vector into a matrix using an invalid orientation.");
    }
}

Matrix &Matrix::operator=(const Matrix &other) {
    _rows = other.rows;
    _columns = other.columns;

    values.clear();
    for(const auto& y : other.values){
        values.emplace_back();
        for(const auto& x : y){
            values.back().push_back(x);
        }
    }

    return *this;
}

Matrix Matrix::operator*(const Vector3 &vector) const {
    if(columns != 3){
        std::runtime_error("When multiplying a vector by a matrix the matrix must have 3 columns.");
    }
    std::vector<std::vector<double>> values;

    for(int row = 0; row < rows; row++){
        values.emplace_back();
        values.back().push_back(vector.x * this->values[row][0] + vector.y * this->values[row][1] + vector.z * this->values[row][2]);
    }
    return Matrix(values);
}

Matrix Matrix::operator*(const Matrix &other) const {
    if(columns != other.rows){
        std::runtime_error("When multiplying matrices, the columns of the first must match the rows of the second.");
    }
    std::vector<std::vector<double>> values;

    for(int row = 0; row < this->rows; row++){
        values.emplace_back();
        for(int column = 0; column < other.columns; column++){
            double value = 0;

            for(int i = 0; i < this->columns; i++){
                value += this->values[row][i] * other.values[i][column];
            }

            values.back().push_back(value);
        }
    }

    return Matrix(values);
}

Matrix Matrix::operator+(const Matrix &other) const {
    if(columns != other.columns && rows != other.rows){
        std::runtime_error("When adding matrices, they must have the same shape.");
    }

    std::vector<std::vector<double>> values;
    for(int row = 0; row < rows; row++){
        values.emplace_back();
        for(int column = 0; column < columns; column++){
            values.back().push_back(this->values[row][column] + other.values[row][column]);
        }
    }

    return Matrix(values);
}

Matrix Matrix::operator-(const Matrix &other) const {
    if(columns != other.columns && rows != other.rows){
        std::runtime_error("When subtracting matrices, they must have the same shape.");
    }

    std::vector<std::vector<double>> values;
    for(int row = 0; row < rows; row++){
        values.emplace_back();
        for(int column = 0; column < columns; column++){
            values.back().push_back(this->values[row][column] - other.values[row][column]);
        }
    }

    return Matrix(values);
}

Matrix &Matrix::operator+=(const Matrix &other) {
    if(columns != other.columns && rows != other.rows){
        std::runtime_error("When adding matrices, they must have the same shape.");
    }

    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            values[row][column] += other.values[row][column];
        }
    }

    return *this;
}

Matrix &Matrix::operator-=(const Matrix &other) {
    if(columns != other.columns && rows != other.rows){
        std::runtime_error("When subtracting matrices, they must have the same shape.");
    }

    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            values[row][column] -= other.values[row][column];
        }
    }

    return *this;
}

double Matrix::get(int row, int column) const {
    return values.at(row).at(column);
}

void Matrix::print() const {
    for(int row = 0; row < rows; row++){
        for(int column = 0; column < columns; column++){
            if(column == columns - 1){
                std::cout << values[row][column];
            }else{
                std::cout << values[row][column] << ", ";
            }

        }
        std::cout << std::endl;
    }
}



