#include<bits/stdc++.h>
using namespace std;

long long int power(long long int a,long long int b,long long int P)
{
    if (b == 1)
        return a;
    else
        return (((long long int)pow(a, b)) % P);
}


int main()
{
    int P, Q, x, a, y, b, ka, kb;

    cout << "The value of P : ";
    cin>>P;
    cout << "The value of Q : ";
    cin>>Q;
    cout<<endl;

    cout << "public key a for Alice : ";
    cin>>a ;
    x = power(Q, a, P);

    cout << "public key b for Bob : ";
    cin>>b;
    cout<<endl;

    y = power(Q, b, P);
    ka = power(y, a, P);
    kb = power(x, b, P);


    cout << "Duplicate Secret key for the Alice is : " << ka << endl;
    cout << "Duplicate Secrete key for the Bob is : " << kb << endl;

    return 0;
}
