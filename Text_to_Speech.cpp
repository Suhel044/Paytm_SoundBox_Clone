#include<bits/stdc++.h>
using namespace std;

vector<string> ones = {"","One ","Two ","Three ","Four ","Five ","Six ","Seven ","Eight ","Nine "};
vector<string> tens = {"","Ten ","Twenty ","Thirty ","Forty ","Fifty ","Sixty ","Seventy ","Eighty ","Ninety "};
vector<string> teens = {"Ten ","Eleven ","Twelve ","Thirteen ","Fourteen ","Fifteen ","Sixteen ","Seventeen ","Eighteen ","Nineteen "};

string solve(int num)
    {
        if(num < 10)
            return ones[num];
        else if(num < 20)
            return teens[num%10];
        else if(num < 100)
            return tens[num/10] + solve(num%10);
        else if(num < 1000)
            return ones[num/100] + "Hundred " + solve(num%100);
        else if(num < 100000)
            return solve(num/1000) + "Thousand " + solve(num%1000);
        else if(num < 10000000)
            return solve(num/100000) + "Lakh " + solve(num%100000);
        else
            return solve(num/10000000) + "Crore " + solve(num%10000000);
    }

int main()
{
    int num;
    cin>>num;
    string ans;
    if(num == 0)
        ans = "Zero";
    else
        ans = solve(num);

    int n = ans.size();
    ans.erase(n-1);
    for(int i = 0; i < n; i++)
        cout<<ans[i];
    string command = "espeak \" Payment of " + ans + "Rupees Received\"";
    const char *charCommand = command.c_str();
    system(charCommand);
    return 0;
}