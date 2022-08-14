#include <string>
#include <complex>
#include <iostream>
#include <vector>

using namespace std;
int main(){
bool next_seq = true;

const int seq_size = 18;
int pell_seq[ seq_size ];//声明了pell_seq是一个array//
int elem_seq[seq_size]= {
        1,2,3,
        3,4,7,
        2,5,12,
        3,6,10,
        4,9,16,
        5,12,22,
    };
vector<int> elem_vals (elem_seq, elem_seq+seq_size);
//array的用法//
cout << "The First "<< elem_vals.size()
<< "elements of the pell series:\n\t";
for (int ix = 0 ; ix<seq_size ; ++ix)
cout << pell_seq [ix] << ' ';
int cur_tuple = 0;
while (next_seq == true && cur_tuple < seq_size )
{
    cout << "the first two elements of the sequence are: "
    << elem_seq [cur_tuple]<< ","
    << elem_seq [cur_tuple+1]
    <<"\nWhat is the next element?";
}
const int max_seq = 6;
string seq_names[max_seq] = {
    "fibbo"
    "Lucas"
    ""
};
return 0;
}