#include <iostream>
using namespace std;
int ucln(int a, int b);
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
};
int ucln(int a, int b)
{
    if (b == 0)
        return a;
    return ucln(b, a % b);
}
int main()
{
    PS ps;
    cin >> ps;
    ps.rutgon();
    cout << ps;
}