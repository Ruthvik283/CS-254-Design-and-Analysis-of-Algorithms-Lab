#include <bits/stdc++.h>
using namespace std;
#define ll long long
#define ld long double
#define pb push_back
#define mp make_pair

// Applied code formatting for better readability

// function returns the median of 2 sorted vectors
ld find_median(vector<int> &a, vector<int> &b)
{
    int n = a.size(), m = b.size();
    if (n == 0)
    {
        if (m % 2)
        {
            return b[m / 2];
        }
        else
        {
            return (double)(b[m / 2] + b[m / 2 - 1]) / 2;
        }
    }
    else if (m == 0)
    {
        if (n % 2)
        {
            return a[n / 2];
        }
        else
        {
            return (double)(a[n / 2] + a[n / 2 - 1]) / 2;
        }
    }
    // case 1 (when there is a single middle element)
    if ((n + m) % 2)
    {
        ll k = (n + m) / 2 + 1;
        ll l = 0, r = n;
        while (l + 1 < r)
        {
            ll mid = (l + r) / 2;
            ll j = upper_bound(b.begin(), b.end(), a[mid]) - b.begin();
            if (mid + j + 1 == k)
                return a[mid];
            else if (mid + j + 1 > k)
            {
                r = mid;
            }
            else
                l = mid;
        }
        ll j = upper_bound(b.begin(), b.end(), a[l]) - b.begin();
        if (j + l + 1 == k)
        {
            return a[l];
        }
        if (j + l + 1 > k)
        {
            return b[k - 1];
        }
        else
        {
            return b[k - l - 1 - 1];
        }
    }
    else
    {
        // case 2 (when there are 2 middle elements)
        double p = INT_MAX, q = INT_MAX;
        // in this case (n + m) / 2 + 1 and (n + m)/ 2 elements are medians
        // so using the case 1's code in scope operator twice for finding these 2 elements to locate 2 medians
        {
            ll k = (n + m) / 2 + 1;
            ll l = 0, r = n;
            while (l + 1 < r)
            {
                ll mid = (l + r) / 2;
                ll j = upper_bound(b.begin(), b.end(), a[mid]) - b.begin();
                if (mid + j + 1 == k)
                {
                    p = a[mid];
                    break;
                }
                else if (mid + j + 1 > k)
                {
                    r = mid;
                }
                else
                    l = mid;
            }
            if (p == INT_MAX)
            {
                ll j = upper_bound(b.begin(), b.end(), a[l]) - b.begin();
                if (j + l + 1 == k)
                {
                    p = a[l];
                }
                else if (j + l + 1 > k)
                {
                    p = b[k - 1];
                }
                else
                {
                    p = b[k - l - 1 - 1];
                }
            }
        }
        {
            ll k = (n + m) / 2;
            ll l = 0, r = n;
            while (l + 1 < r)
            {
                ll mid = (l + r) / 2;
                ll j = upper_bound(b.begin(), b.end(), a[mid]) - b.begin();
                if (mid + j + 1 == k)
                {
                    q = a[mid];
                    break;
                }
                else if (mid + j + 1 > k)
                {
                    r = mid;
                }
                else
                    l = mid;
            }
            if (q == INT_MAX)
            {
                ll j = upper_bound(b.begin(), b.end(), a[l]) - b.begin();
                if (j + l + 1 == k)
                {
                    q = a[l];
                }
                else if (j + l + 1 > k)
                {
                    q = b[k - 1];
                }
                else
                {
                    q = b[k - l - 1 - 1];
                }
            }
        }

        return (p + q) / 2;
    }
    // Time complexity = log (m) * log (n)
}

int main()
{

    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    ll t;
    cin >> t;
    while (t--)
    {
        ll n, m;
        cin >> n >> m;
        vector<int> a(n), b(m);
        for (ll i = 0; i < n; i++)
            cin >> a[i];
        for (ll j = 0; j < m; j++)
            cin >> b[j];
        cout << fixed << find_median(a, b) << endl;
    }

    return 0;
}