#include <iostream>

using namespace std;

class LinearLine
{
    private:
        float x1;
        float x2;
        float y1;
        float y2;
    public:
        LinearLine (float x1, float y1, float x2, float y2)
        {
            this -> x1 = x1;
            this -> x2 = x2;
            this -> y1 = y1;
            this -> y2 = y2;
        }
        
        float gradient(){
            return (y2-y1)/(x2-x1);
        }

        float y_intercept(){
            return (((-x1*y2) + (x1*y1))/(x2-x1)) + y1;
        }

        void operator + (float a)
        {
            float temp = y_intercept();
            temp += gradient() * (-a);
            cout << "y = " << gradient() << "x + " << temp << endl; 


        }
        void printEquation(){
            cout << "y = " << gradient() << "x + " << y_intercept() << endl; 
        }
        void printPoints()
        {
            cout << "(x1 , y1) = (" << x1 << " , " << y1 << ")" << endl;
            cout << "(x2 , y2) = (" << x2 << " , " << y2 << ")" << endl;

        }
};

int main()
{
    LinearLine line(1.0f,8.0f,2.0f,3.0f);
    int a = 3;
    line.printPoints();
    cout << "Sehingga didapatkan" << endl;
    cout << "gradient = " << line.gradient() << endl;
    cout << "y_intercept = " << line.y_intercept() << endl;
    line.printEquation();
    cout << "Setelah digeser sejauh a, didapatkan persamaan baru: " << endl;
    line.operator+(a);

    return 0;
}