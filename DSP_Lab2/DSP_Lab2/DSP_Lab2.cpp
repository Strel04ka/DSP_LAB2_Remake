#include <iostream>
using namespace std;

void draw(bool*, bool*, bool*, bool*, bool*, const int);
void binary(bool*, bool*, bool*, bool*, bool*, const int);
bool implication(bool, bool);

int main()
{
    const int n = 9;
    bool p[n] = { 0, 0, 0, 0, 1, 1, 1, 0, 1}; bool* pp = p;
    bool q[n] = { 0, 0, 1, 1, 1, 0, 0, 1, 1}; bool* qq = q;
    bool r[n] = { 0, 1, 1, 0, 0, 0, 1, 1, 1}; bool* rr = r;
    bool OR[n]; bool* ORR = OR;
    bool IMOR[n]; bool* IMORR = IMOR;
    bool result = true;
    //if (p == 1 && (q or r) == 0) 
    //{
    //    result = 0;
    //}
    //cout << "p -> (q ^ r) = " << result;
    binary(pp, qq, rr, ORR, IMORR, n);
    draw(pp, qq, rr, ORR, IMORR, n);
}

void draw(bool* p, bool* q, bool* r, bool* OR, bool* IMOR, const int n)
{
    cout << "-----------------------------------------------\n";
    cout << "|  p  |  q  |  r  |  q || r  |  p -> (q || r) |\n";
    cout << "-----------------------------------------------\n";
    for (int i = 0; i < n; i++)
    {
        cout << "|  " << p[i] << "  " << "|  " << q[i] << "  " << "|  " << r[i] << "  " << "|     " << OR[i] << "    " << "|        " << IMOR[i] << "       " << "|" << '\n';
    }
    cout << "-----------------------------------------------\n";
}
void binary(bool* p, bool* q, bool* r, bool* OR, bool* IMOR, const int n)
{
    for (int i = 0; i < n; i++)
    {
        OR[i] = *(q + i) || *(r + i);   //  OR	Disunction
    }
    for (int i = 0; i < n; i++)
    {
        IMOR[i] = implication(*(p + i), *(OR + i));  //  Implication 
    }
}
bool implication(bool a, bool b)
{
    bool resp;
    if (a == 1 && b == 0)
        resp = 0;
    else { resp = 1; }
    return resp;
}