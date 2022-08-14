#include <iostream>
using namespace std;
class rectangle
{
private:
    double height, weighth;

public:
    void set_height(double a)
    {
        if (a >= 0)
        {
            height = a;
        }
        else
        {
            height = -a;
            cout << "smaller than 0 ";
        }
    }
    void set_weighth(double a)
    {
        if (a >= 0)
        {
            weighth = a;
        }
        else
        {
            weighth = -a;
            cout << "smaller than 0 ";
        }
    }
    double get_height()
    {
        return height;
    }
    double get_weighth()
    {
        return weighth;
    }
    rectangle() {}
    rectangle(double h, double w)
    {
        if (h >= 0)
        {
            height = h;
        }
        else
        {
            height = -h;
            cout << "smaller than 0 ";
        }
        if (w >= 0)
        {
            weighth = w;
        }
        else
        {
            weighth = -w;
            cout << "smaller than 0 ";
        }
        //cout << "rectangle constructed" << endl;
    }
    ~rectangle()
    {
        //cout << "rectangle destructed" << endl;
    }
    virtual double measure()
    {
        return height * weighth;
    }
};
class cuboid : public rectangle
{
private:
    double depth;
    rectangle base;

public:
    cuboid(double d, rectangle b) : base(b)
    {
        if (d >= 0)
        {
            depth = d;
        }
        else
        {
            depth = -d;
        }
        //cout << "cubiod constructed" << endl;
    }
    ~cuboid()
    {
        //cout << "cubiod destructed" << endl;
    }
    virtual double measure()
    {
        return 2 * (depth * base.get_height() + depth * base.get_weighth() + base.get_weighth() * base.get_height());
    }
};
int main()
{
    rectangle test1(10, 5); //长方形面积
    cout << "the area is " << test1.measure() << endl;
    cuboid test2(7, test1); //补充高
    cout << "the area of the cuboid is " << test2.measure() << endl;
    return 0;
}
