#include <iostream>
using namespace std;
int main()
{
    long sec_0;
    int hour = 0;
    int min = 0;
    int sec_1 = 0;
    cin >> sec_0;
    hour = (sec_0 - sec_0 % 3600) / 3600;
    min = (sec_0 - 3600 * hour - (sec_0 - 3600 * hour) % 60) / 60;
    sec_1 = sec_0 - hour * 3600 - min * 60;
    cout << hour << " hours " << min << " minutes and " << sec_1 << " seconds" << endl;
    return 0;
}