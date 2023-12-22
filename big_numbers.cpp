#include<bits/stdc++.h>
using namespace std;

class bigNum
{
    public:
    // this is where the number will be stored in the string format
    string num;
    
    // constructor that intializes the big number
    bigNum(string s) {
        num = s;
    }

    // overloading the operators

    string operator +(bigNum a) {
        string res;
        res = add(a.num , num);
        return res;
    }
    string operator -(bigNum a) {
        string res;
        res = subtract(num , a.num);
        return res;
    }
    string operator *(bigNum a) {
        string res;
        res = multiply(a.num , num);
        return res;
    }
    string operator /(bigNum a) {
        string res;
        res = divide(num , a.num);
        return res;
    }
    bool operator >(bigNum a) {

    }

    bool operator ==(bigNum a) {

    }

    bool operator <(bigNum a) {

    }
    // defining different operations 
    private:

    string add(string a , string b) {

        // used how we do basic addition linearly

        int n = a.size();
        int m = b.size();
        string sum="";
        int carry = 0;

        while(m || n)
        {
            if(n == 0) {

                int x = b[m - 1] - '0' + carry;
                carry = x / 10;
                x = x % 10;
                sum += to_string(x);
                m--;
                continue;

            }

            if(m == 0) {

                int y = a[n - 1] - '0' + carry;
                carry = y / 10;
                y = y % 10;
                sum += to_string(y);
                n--;
                continue;

            }

            int x = b[m-1] - '0';
            int y = a[n-1] - '0';
            int result = x + y + carry;
            carry = result / 10;
            result = result % 10;
            sum += to_string(result);

            n--,m--;
        }

        if(carry) {
            sum += to_string(carry);
        }

        reverse(sum.begin() , sum.end());
        string res = "";
        int flag = 1;
        for(int i = 0 ; i < sum.size() ; i++) {

            // check for any leading 0's and also if th sum is 0 itself then leave the last index
            if(sum[i] == '0' && flag && i != sum.size() - 1)continue;
            flag = 0;
            res += sum[i];

        }

        return res;
    }


    string subtract(string a , string b) {

        int n = a.size();
        int m = b.size();
        int negativeSign = 0;
        string ans ="";
        //if the second number is bugger than the result will be a negative number
        if(n < m) {
            // checking if there will be negative sign
            negativeSign = 1;
            swap(a,b);
            swap(n,m);
        }

        if(n == m) {

            for(int i = 0 ; i < n ; i++) {

                if(a[i] < b[i]) {
                    // checking if there will be negative sign
                    negativeSign = 1;
                    swap(a,b);
                    break;
                }
                else if(a[i] > b[i]) {
                    break;
                }
            }
        }

        int carry = 0;
        while(m || n) {

            if(n == 0) {
                int x = b[m - 1] - '0' - carry;
                carry = x / 10;
                x = x % 10;
                ans += to_string(x);
                m--;
                continue;
            }

            if(m == 0) {
                int y = a[n - 1] - '0' - carry;
                carry = y / 10;
                y = y % 10;
                ans += to_string(y);
                n--;
                continue;
            }

            // get carry function because in case where i have to borrow carry from 0
            int y = a[n-1] - '0' - carry;
            int x = b[m-1] - '0';
            carry = 0;
            int result = y - x;
            if(result < 0) {
                carry = 1;
                result += 10;
            }
            ans += to_string(result);
            n--,m--;
        }

        if(carry) {
            ans += to_string(carry);
        }
        if(negativeSign) {
            ans += "-";
        }

        reverse(ans.begin() , ans.end());
        string res = "";
        int flag = 1;
        for(int i = 0 ; i < ans.size() ; i++) {
            if(ans[i] == '0' && flag && i != ans.size() - 1)continue;
            flag = 0;
            res += ans[i];
        }

        return res;
    }


    string multiply(string a, string b) {
        // used the method we used to use while we were kids
        // linerly multiplying with every digit and then adding the results
        // ex 100 * 22
        // first we will miltply it with 2 and store that value which is 200
        // than we will muultiply with 2 gain than add both the results
        // which is 400

        int n = a.size();
        int m = b.size();
        int start = 0;
        vector<char>ans(n+m ,'0');
        while(m)
        {
            int j = m + n - 1;
            int mul_carry = 0 , sum_carry = 0;
            int mul = b[m - 1] - '0';
            for(int i = n - 1 ; i >= 0 ; i--)
            {
                int x = a[i] - '0';
                int mul_res = x * mul;
                mul_res += mul_carry;
                mul_carry = mul_res/10;
                mul_res = mul_res % 10;

                int y = ans[j] - '0';
                y = y + mul_res + sum_carry;
                sum_carry = y / 10;
                y = y % 10;
                ans[j] = '0' + y;
                j--;
            }
            if(j >= 0)
            ans[j] = char('0' + sum_carry + mul_carry);
            start++;
            m--;
            
        }
        string res = "";
        int flag = 1;
        for(auto t : ans) {
            if(flag && t == '0')continue;
            else res += t, flag = 0;
        }

        //if the result was 0 than we directly return 0
        if(res.size() == 0) return "0";
        return res;
    }


    string divideBy2(string s) {
        // this fuction is used for getting tht mid point of 2 numbers as it divides the number by 2
        // this function is used as a helper function for divide


        int n = s.size();
        int carry = 0 , cur = 0;
        string quotient = "";
        for(int i = 0 ; i < n ; i++) {

            cur = carry*10 + int(s[i] - '0');
            quotient += to_string(cur / 2);
            carry = cur % 2;

        }

        string temp = quotient;
        quotient = "";
        int flag = 1;
        for(int i = 0 ; i < temp.size() ; i++) {

            if(flag && temp[i] == '0' && i != temp.size() - 1) {
                continue;
            }
            else {
                quotient += temp[i];
                flag = 0;
            }

        }

        return quotient;

    }

    // this function is to compare two strings as if they were integer
    // normal string comaprion does no work. lets take a example
    // "9" > "100"  in string this is true becuase the first character is greater that the other strings
    // first charactor but in case of ints the second string should be big
    // thats why this function
    bool comp(string a , string b) {

        if(a.size() == b.size())
        {
            return a >= b;
        }
        return a.size() > b.size();

    }

    string divide(string a , string b) {
        // divide is implemented using binary search on answer 
        // as the we try to find the right quotient for the given divisor and the divident

        string quotient = "";
        string start = "0" , end = a , mid;

        // doing bniary search on ans
        while(comp(end,start)) {

            mid = add(start, end);  
            mid = divideBy2(mid);
            string res = multiply(mid , b);
            if(comp(a , res)) {

                quotient = mid;
                start = add(mid , "1") ;
            
            }
            else {

                end = subtract(mid , "1");
            
            }

        }

        return quotient;

    }

};


int main()
{
    bigNum a("100") , b("299");

    cout << a - b << '\n';
    cout << a * b << '\n';
    cout << a / b << '\n';
    cout << a + b << '\n';
}