#include <iostream>
#include <vector>
using namespace std;

// 判断一个数是否为质数
bool isPrime(int n)
{
    if (n < 2)
    {
        return false;
    }
    for (int i = 2; i * i <= n; i++)
    {
        if (n % i == 0)
        {
            return false;
        }
    }
    return true;
}

// 将一个数拆分为若干个两两不同的质数之和
void splitIntoPrimes(int n, vector<int> &primes, vector<vector<int>> &result)
{
    if (n == 0)
    {
        result.push_back(primes);
        return;
    }
    for (int i = 2; i <= n; i++)
    {
        if (isPrime(i))
        {
            if (primes.empty() || i > primes.back())
            {
                primes.push_back(i);
                splitIntoPrimes(n - i, primes, result);
                primes.pop_back();
            }
        }
    }
}

int main()
{
    int p;
    cin >> p;
    vector<int> primes;
    vector<vector<int>> result;
    splitIntoPrimes(p, primes, result);
    for (auto &v : result)
    {
        for (int i = 0; i < v.size(); i++)
        {
            cout << v[i];
            if (i != v.size() - 1)
            {
                cout << "+";
            }
        }
        cout << endl;
    }
    return 0;
}
