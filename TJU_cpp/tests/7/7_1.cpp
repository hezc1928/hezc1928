#include <iostream>
using namespace std;
class Square
{
private:
    double Side;

public:
    Square(double s = 0)
    {
        if (s < 0)
        {
            s = -s;
            cout << "s is smaller than zero, replaced by minus s" << endl;
        }
        Side = s;
    }
    double GetSide()
    {
        return Side;
    }
    double Calc_Area()
    {
        return Side * Side;
    }
    double Calc_Peri()
    {
        return 4 * Side;
    }
};
class Cube : public Square
{
public:
    Cube(float s);
    double Calc_Area()
    {
        return 6 * Square::Calc_Area();
    }
    double Calc_Volume()
    {
        return Square::GetSide() * Square::Calc_Area();
    }
};
Cube::Cube(float s) : Square(s)
{
}
int main()
{
    Square test(5.5);
    cout << "Side is " << test.GetSide() << endl;
    cout << "Area is " << test.Calc_Area() << endl;
    cout << "Peri is " << test.Calc_Peri() << endl;
    Cube testtest(5.5);
    cout << "Now is the cube" << endl;
    cout << "Area is " << testtest.Calc_Area() << endl;
    // testtest.Calc_Peri();
    cout << "Volume is " << testtest.Calc_Volume() << endl;
    // testtest.GetSide();
}
