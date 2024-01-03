#include <iostream>
#include <vector>
#include <math.h>

// OBJEKTIF 1:
class Matrix {
private:
    std::vector<std::vector<double>> data;
    int baris;
    int kolom;

public:
    // Constructor array 2d
    Matrix(const std::vector<std::vector<double>>& input) : data(input), baris(input.size()), kolom(input[0].size()) {}

    // Constructor input banyak baris dan kolom
    Matrix(int baris, int kolom) : data(baris, std::vector<double>(kolom, 0)), baris(baris), kolom(kolom) {}

    // Constructor copy objek
    Matrix(const Matrix& other) : data(other.data), baris(other.baris), kolom(other.kolom) {}

    // Operator penjumlahan
    Matrix operator+(const Matrix& other) const 
    {
        if (baris != other.baris || kolom != other.kolom) 
        {
            std::cout << "Matrix dimension is not valid! \n";
            return Matrix(1, 1); 
        }

        Matrix pertambahan(baris, kolom);
        for (int i = 0; i < baris; ++i) 
        {
            for (int j = 0; j < kolom; ++j) 
            {
                pertambahan.data[i][j] = data[i][j] + other.data[i][j];
            }
        }
        return pertambahan;
    }

    // Operator pengurangan
    Matrix operator-(const Matrix& other) const 
    {
        if (baris != other.baris || kolom != other.kolom) 
        {
            std::cout << "Matrix dimension is not valid! \n";
            return Matrix(1, 1);
        }
        Matrix pengurangan(baris, kolom);
        for (int i = 0; i < baris; ++i) 
        {
            for (int j = 0; j < kolom; ++j) 
            {
                pengurangan.data[i][j] = data[i][j] - other.data[i][j];
            }
        }
        return pengurangan;
    }

    // Operator perkalian
    Matrix operator*(const Matrix& other) const {
        if (kolom != other.baris) {
            std::cout << "Multiplication cannot be done. The number of columns in the first matrix should be equal to the number of rows in the second\n";
            return Matrix(1, 1); 
        }

        Matrix perkalian(baris, other.kolom);
        for (int i = 0; i < baris; ++i) 
        {
            for (int j = 0; j < other.kolom; ++j) 
            {
                for (int k = 0; k < kolom; ++k) 
                {
                    perkalian.data[i][j] += data[i][k] * other.data[k][j];
                }
            }
        }
        return perkalian;
    }

    void display()  
    {
        for (int i = 0; i < baris; ++i) 
        {
            for (int j = 0; j < kolom; ++j) 
            {
                std::cout << data[i][j] << " ";
            }
            std::cout << std::endl;
        }
    }
};

// OBJEKTIF 2:
class Serway
{
private:
    float kecepatanx;
    float kecepatany;
    float omega;
    Matrix kecepatan;
    Matrix pose;
    
public:
    Serway() = default;

    void velocityCommand(float vx, float vy, float omega)
    {
        this->kecepatanx = vx;
        this->kecepatany = vy;
        this->omega = omega;
        std::vector<std::vector<double>> tambahan = {
            {1, 0, -0.2636},
            {0, 1, 0.2636},
            {1, 0, -0.2636},
            {0, 1, 0.2636},
            {1, 0, -0.2636},
            {0, 1, 0.2636},
            {1, 0, -0.2636},
            {0, 1, 0.2636}};
        Matrix A1(tambahan);

        std::vector<std::vector<double>> temp = {{vx},{vy},{omega}};
        Matrix A2(temp);
        kecepatan = A1 * temp;
    }

    void updatePose(float deltaTime)
    {
        std::vector<std::vector<double>> pose1 = {{this->kecepatanx},{this->kecepatany},{this->omega}};
        Matrix A3(pose1);
        pose = pose + A3;
    }

};

// OBJEKTIF 3:
float v_x(float t)
{
    return 48 * cos(t) * pow(sin(t),2);
}

float v_y(float t)
{
    return (4 * sin(4*t)) + 6 * sin(3*t) + 10 * sin(2*t) - 13 * sin(t);
}
int main()
{
    std::vector<std::vector<double>> temp3 = {{0},{0},{0}};
    Matrix kecepatan(temp3);
    std::vector<std::vector<double>> temp4 = {{0},{5},{0}};
    Matrix Pose(temp4);
    for (float t=0; t < 6.3; t += 0.01)
    {

    }
}