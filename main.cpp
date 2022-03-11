#include <iostream>
#include <string>
using namespace std;
int ucln(int a, int b);
int bcnn(int a, int b);
class PS
{
private:
    int ts, ms;

public:
    PS() {}
    PS(int ts, int ms)
    {
        this->ts = ts;
        this->ms = ms;
    }
    void rutgon()
    {
        int ucln1 = ucln(this->ts, this->ms);
        this->ts = ts / ucln1;
        this->ms = ms / ucln1;
    }
    friend istream &operator>>(istream &in, PS &ps)
    {
        cout << "Nhap tu so : ";
        in >> ps.ts;
        cout << "Nhap mau so : ";
        in >> ps.ms;
        return in;
    }
    friend ostream &operator<<(ostream &out, PS ps)
    {
        out << ps.ts << "/" << ps.ms;
        return out;
    }
    friend PS operator+(PS a, PS b)
    {
        PS tong;
        int mc = bcnn(a.ms, b.ms);
        tong.ts = mc / a.ms * a.ts + mc / b.ms * b.ts;
        tong.ms = mc;
        int g = ucln(tong.ts, tong.ms);
        tong.ts = tong.ts / g;
        tong.ms = tong.ms / g;
        return tong;
    }
};
int ucln(int a, int b)
{
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
int bcnn(int a, int b)
{
    return a / ucln(a, b) * b;
}
int main()
{
    PS ps1, ps2;
    cin >> ps1;
    cin >> ps2;
    cout << ps1 + ps2;
    return 0;
}