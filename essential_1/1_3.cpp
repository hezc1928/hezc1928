#include <string>
#include <complex>
#include <iostream>
//using namespace std;
int main(){
std::string a_string;
const int line_size = 8;
int cnt = 1;
std::cout << a_string
     << ( cnt % line_size ? ' ': '\n');//%运算符 true则执行前面的//
//++tries 和 ties++ 写法//
bool usr_more = true ;
char usr_rsp ;
/*f( usr_rsp == 'N')
usr_more = false;
else
if (usr_rsp == 'n')
usr_more = false;*/
if ( usr_rsp == 'N'|| usr_rsp == 'n')
usr_more  = false;//先求前面的是否符合，如果true,就不看后面的条件//
//||任意一个符合即可，&&两个都要符合//
//运算优先级，加括号即可//

return 0;

}