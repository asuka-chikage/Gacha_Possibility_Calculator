#include <cstdlib>
#include <cfloat>
#include <climits>
#include <csetjmp>
#include <csignal>
#include <cstdarg>
#include <cstddef>
#include <exception>
#include <cstdint>
#include <limits>
#include <new>
#include <typeinfo>
#include <cassert>
#include <cerrno>
#include <stdexcept>
#include <memory>
#include <ratio>
#include <bitset>
#include <functional>
#include <utility>
#include <deque>
#include <forward_list>
#include <list>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <unordered_map>
#include <unordered_set>
#include <vector>
#include <iterator>
#include <algorithm>
#include <numeric>
#include <cstring>
#include <string>
#include <cctype>
#include <clocale>
#include <cwchar>
#include <cwctype>
#include <locale>
#include <regex>
#include <cmath>
#include <complex>
#include <random>
#include <valarray>
#include <chrono>
#include <ctime>
#include <cinttypes>
#include <cstdio>
#include <fstream>
#include <iomanip>
#include <ios>
#include <iostream>
#include <iosfwd>
#include <istream>
#include <ostream>
#include <sstream>
#include <streambuf>
#include <atomic>
#include <condition_variable>
#include <future>
#include <mutex>
#include <thread>
#define LD long double
#define LL long long
#define CP Color_Possibility
#define SN Scietific_Numerial
class Scietific_Numerial
{
    public:
        void Check()
        {
            if(Front==0)    return;
            while(Front>=10){Front=Front/10.0;Exponent++;}
            while(Front<1){Front=Front*10;Exponent--;}
        }
        Scietific_Numerial(LD a,LL b)
        {
            Front=a;
            Exponent=b;
        }
        LD Front;
        LL Exponent;
};
std::ofstream Output("output.txt");
std::ifstream Input("input.txt");
LD Color_Possibility=0.03;
int Gacha_times=200;
SN Calculate_C(int n, int p)
{
    SN Result(1.0,0);
    for(int i=1;i<=p;i++)
    {
        Result.Front=Result.Front*(n-i+1)/i;
        Result.Check();
    }
    return Result;
}
SN Sum(SN a,SN b)
{
    if(a.Exponent<b.Exponent)
    std::swap(a,b);
    if(a.Exponent-b.Exponent>10)
    return a;
    while(a.Exponent>b.Exponent)
    {
        b.Front=b.Front/10;
        b.Exponent++;
    }
    a.Front=a.Front+b.Front;
    return a;
}
std::string Result_Output(Scietific_Numerial a,std::string form)
{
    if(form=="%")
    a.Exponent+=2;
    if(a.Exponent<=5 && a.Exponent>=-5)
    {
        a.Front=a.Front*std::pow(10,a.Exponent);
        if(form=="%")
            return std::to_string(a.Front)+"%";
        
        return std::to_string(a.Front);
    }

    if(form=="%")
        a.Exponent-=2;
        
    return std::to_string(a.Front)+"e"+std::to_string(a.Exponent);
    
}
int main()
{
    Input>>Color_Possibility>>Gacha_times;

    for(int i=0;i<=Gacha_times;i++)
    {
        SN t(0,0);
        t.Exponent=0;
        t.Front=1;
        for(int j=1;j<=i;j++){t.Front=t.Front*Color_Possibility;t.Check();}
        for(int j=i+1;j<=Gacha_times;j++){t.Front=t.Front*(1-Color_Possibility);t.Check();}
        SN p=Calculate_C(Gacha_times,i);
        t.Front=t.Front*p.Front;
        t.Exponent=t.Exponent+p.Exponent;
        Output<<"The possibility to get "<<i<<" color archives in "<<Gacha_times<<" times Gacha is "<<Result_Output(t,"%")<<std::endl;
    }
    Output.close();
    Input.close();
}