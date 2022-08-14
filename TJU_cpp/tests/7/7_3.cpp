#include <iostream>
#include <cstring>
using namespace std;
class human
{
private:
    char *FamilyName;
    char *SelfName;
    char *Bias;
    char *Job;
    int Age;

public:
    human()
    { //这里不知道为什么会在family的构造过程中调用human的默认构造函数
        FamilyName = new char[1];
        strcpy(FamilyName, "B");
        SelfName = new char[1];
        strcpy(SelfName, "B");
        Bias = new char[1];
        strcpy(Bias, "B");
        Job = new char[1];
        strcpy(Job, "B");
        Age = 0;
        cout << "B human constructed" << endl;
    }
    void print()
    {
        cout << "姓：" << FamilyName << endl;
        cout << "名：" << SelfName << endl;
        cout << "性别：" << Bias << endl;
        cout << "职业：" << Job << endl;
        cout << "年龄：" << Age << endl;
    }
    human(const char *a, const char *b, const char *c, const char *d, int f)
    {
        FamilyName = new char[strlen(a) + 1];
        strcpy(FamilyName, a);
        SelfName = new char[strlen(b) + 1];
        strcpy(SelfName, b);
        Bias = new char[strlen(c) + 1];
        strcpy(Bias, c);
        Job = new char[strlen(d) + 1];
        strcpy(Job, d);
        Age = f;
        cout << "human constructed" << endl;
    }
    human(human &r)
    { //这里for循环new
        FamilyName = new char[strlen(r.FamilyName)];
        for (int i = 0; i < strlen(r.FamilyName) + 1; i++)
        {
            *(FamilyName + i) = *(r.FamilyName + i);
        }
        SelfName = new char[strlen(r.SelfName)];
        for (int i = 0; i < strlen(r.SelfName) + 1; i++)
        {
            *(SelfName + i) = *(r.SelfName + i);
        }
        Bias = new char[strlen(r.Bias)];
        for (int i = 0; i < strlen(r.Bias) + 1; i++)
        {
            *(Bias + i) = *(r.Bias + i);
        }
        Job = new char[strlen(r.Job)];
        for (int i = 0; i < strlen(r.Job) + 1; i++)
        {
            *(Job + i) = *(r.Job + i);
        }
        Age = r.Age;
    }
    char *FN()
    {
        return FamilyName;
    }

    ~human()
    {
        delete[] FamilyName;
        delete[] SelfName;
        delete[] Bias;
        delete[] Job;
        FamilyName = SelfName = Bias = Job = 0;
        cout << "human destructed" << endl;
    }
};

class Family : public human
{
private:
    human husband;
    human wife;
    human infant;

public:
    Family(human fere, human mere, const char *b, const char *c, const char *d, int f);
    void Output_All()
    {
        cout << "父亲" << endl;
        husband.print();
        cout << "母亲" << endl;
        wife.print();
        cout << "孩子" << endl;
        infant.print();
    }
    void Wife_Output()
    {
        wife.print();
    }
    void Infant_output()
    {
        infant.print();
    }
    Family();
    ~Family()
    {
        husband.~human();
        wife.~human();
        infant.~human();
        cout << "family destructed" << endl;
    }
};
Family::Family(human pere, human mere, const char *b, const char *c, const char *d, int f) : husband(pere), wife(mere), infant(pere.FN(), b, c, d, f)
{
    // human husband(fere);
    // human wife(mere);
    // human temp(fere.FN(), b, c, d, f);
    // human infant(temp);
    cout << "create a family" << endl;
}
int main()
{
    human guojing("郭", "靖", "男", "自由职业", 39);
    human huangrong("黄", "蓉", "女", "自由", 69);
    guojing.print();
    Family fam(guojing, huangrong, "芙", "女", "孩子", 15);
    cout << "wife: " << endl;
    fam.Wife_Output();
    cout << "infant: " << endl;
    fam.Infant_output();
    //fam.Output_All();
    return 0;
}
