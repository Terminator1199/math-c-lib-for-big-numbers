#include<bits/stdc++.h>
using namespace std;


bool comp(int a , int b)
{
    int set_bits1 = 0;
    int set_bits2 = 0;
    int pow_2 = 1;

    while(a >= pow_2)
    {
        if( (a&pow_2) != 0) {
            set_bits1++;
        }
        pow_2 *= 2;
    }

    pow_2 = 1;
    while(b >= pow_2)
    {
        if( (b&pow_2) != 0) {
            set_bits2++;
        }
        pow_2 *= 2;
    }
    // a  , b ;
    // cout << set_bits1 << " " <<  set_bits2 << "  ";

    if(set_bits1 < set_bits2) return true;
    return false;

}


int main()
{
    int n;
    cin >> n;
    int pots[n];
    for(int i = 0;  i < n ; i++) cin >> pots[i];

    sort(pots , pots + n  , comp);

    for(int i = 0 ; i < n ;i++)cout << pots[i] << " ";
}
