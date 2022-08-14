#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
class F
{
private:
    char *s1;
    char *s2;
    int size_1;
    int size_2;

public:
    F(char *t1, char *t2);
    bool distinguish()
    {
        char *ss;
        ss = new char[size_1 * 2];
        for (int i = 0; i < size_1 * 2; i++)
        {
            ss[i] = s1[i % size_1];
        }
        bool flag = 0;
        for (int i = 0; i < size_1 * 2; i++)
        {
            if (ss[i] == s2[0])
            {
                flag = 1;
                for (int j = 0; j < size_2; j++)
                {
                    if (ss[i + j] != s2[j])
                    {
                        flag = 0;
                    }
                }
            }
            if (flag)
            {
                return flag;
            }
        }
        return flag;
    }
    ~F();
};
F::F(char *t1, char *t2)
{
    size_1 = strlen(t1);
    size_2 = strlen(t2);
    s1 = new char[size_1];
    s2 = new char[size_2];
    for (int i = 0; i < size_1; i++)
    {
        s1[i] = *(t1 + i);
    }
    for (int i = 0; i < size_2; i++)
    {
        s2[i] = *(t2 + i);
    }
}

F::~F()
{
    delete[] s1;
    delete[] s2;
}

int main()
{
    char s1[] = "kselkjkjsf";
    char s2[] = "qwer";
    F chch(s1, s2);
    if (chch.distinguish())
    {
        cout << "yes" << endl;
    }
    else
    {
        cout << "nope" << endl;
    }

    return 0;
}