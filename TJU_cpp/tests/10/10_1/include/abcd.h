#ifndef ABCD_H
#define ABCD_H


class abcd
{
    public:
        abcd();
        virtual ~abcd();

        int Getqwer() { return qwer; }
        void Setqwer(int val) { qwer = val; }

    protected:

    private:
        int qwer;
};

#endif // ABCD_H
