#include <iostream>
using namespace std;
//姓：QWER
//名：ASDF
//性别：0 男    1 女
//年龄：数字
//职业：ZXCV
class human
{
private:
    char FamilyName;
    char SelfName;
    bool Bias;
    int Age;
    char Job;

public:
    human()
    {
        FamilyName = 'Q';
        SelfName = 'A';
        Bias = 0;
        Age = 0;
        Job = 'Z';
        cout << "human constructed" << endl;
    }
    human(char a1, char a2, bool a3, int a4, char a5);
    human(human &r)
    {
        FamilyName = r.FamilyName;
        SelfName = r.SelfName;
        Bias = r.Bias;
        Age = r.Age;
        Job = r.Job;
    }
    char Get_FamilyName()
    {
        return FamilyName;
    }
    char Get_SelfName()
    {
        return SelfName;
    }
    bool Get_Bias()
    {
        return Bias;
    }
    int Get_Age()
    {
        return Age;
    }
    char Get_Job()
    {
        return Job;
    }
    void Output_All()
    {
        cout << Get_FamilyName() << endl;
        cout << Get_SelfName() << endl;
        cout << Get_Age() << endl;
        cout << Get_Bias() << endl;
        cout << Get_Job() << endl;
    }
    ~human()
    {
        cout << "human destructed" << endl;
    }
};

human::human(char a1, char a2, bool a3, int a4, char a5)
{
    FamilyName = a1;
    SelfName = a2;
    Bias = a3;
    Age = a4;
    Job = a5;
    cout << "含参human consturcted" << endl;
}
class Family : public human
{
private:
    human husband;
    human wife;
    human infant;

public:
    Family(human fere, human mere, char a2, bool a3, int a4, char a5);
    void output(human t)
    {
        t.Output_All();
    }
    void Output_All()
    {
        husband.Output_All();
        wife.Output_All();
        infant.Output_All();
    }
    Family();
    ~Family()
    {
        cout << "family destructed" << endl;
    }
};
Family::Family(human fere, human mere, char a2, bool a3, int a4, char a5) : human()
{
    human husband(fere);
    cout << "b ren" << endl;
    human wife(mere);
    human temp(fere.Get_FamilyName(), a2, a3, a4, a5);
    human infant(temp);
    cout << "create a family" << endl;
}
int main()
{
    human guojing('W', 'S', 0, 50, 'X');
    human huangrong('E', 'D', 1, 40, 'C');
    cout << "b ren" << endl;
    Family aaa();
    Family fam(guojing, huangrong, 'F', 1, 15, 'V');
    fam.Output_All();
}
