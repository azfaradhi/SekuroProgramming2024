#include <iostream>

class Shape {
protected:
    float area;
    float keliling;

public:
    virtual float calculateArea() { return 0; }
    virtual float calculateKeliling() { return 0; }
};

class Rectangle : public Shape 
{
private:
    float width;
    float length;

public:
    Rectangle(float lebar, float panjang) : width(lebar),length(panjang) {}

    float calculateArea() {
        area = width * length;
        return area;
    }

    float calculateKeliling() {
        keliling = 2 * (width + length);
        return keliling;
    }
};

int main() {
    Rectangle rect(5.0, 4.0);
    Shape* shape1 = &rect;

    float area = shape1-> calculateArea();
    float keliling = shape1-> calculateKeliling();

    std::cout << "Luas: " << area << std::endl;
    std::cout << "Keliling: " << keliling << std::endl;

    return 0;
}
