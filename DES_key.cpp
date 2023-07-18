#include<bits/stdc++.h>
using namespace std;

int key[64]=
{
    0,0,0,1,0,0,1,1,
    0,0,1,1,0,1,0,0,
    0,1,0,1,0,1,1,1,
    0,1,1,1,1,0,0,1,
    1,0,0,1,1,0,1,1,
    1,0,1,1,1,1,0,0,
    1,1,0,1,1,1,1,1,
    1,1,1,1,0,0,0,1
};
int pc1[56],ck[28],dk[28],z[48];
void PermChoice1()
{
    int k=57,i;
    for(i=0; i<28; i++)
    {
        pc1[i]=key[k-1];
        if(k-8>0)    k=k-8;
        else	     k=k+57;
    }
    k=63;
    for( i=28; i<52; i++)
    {
        pc1[i]=key[k-1];
        if(k-8>0)    k=k-8;
        else         k=k+55;
    }
    k=28;
    for(i=52; i<56; i++)
    {
        pc1[i]=key[k-1];
        k=k-8;
    }

}

void PermChoice2()
{
    int per[56],i,k;
    for(i=0; i<28; i++) per[i]=ck[i];
    for(k=0,i=28; i<56; i++) per[i]=dk[k++];

    z[0]=per[13];
    z[1]=per[16];
    z[2]=per[10];
    z[3]=per[23];
    z[4]=per[0];
    z[5]=per[4];
    z[6]=per[2];
    z[7]=per[27];
    z[8]=per[14];
    z[9]=per[5];
    z[10]=per[20];
    z[11]=per[9];
    z[12]=per[22];
    z[13]=per[18];
    z[14]=per[11];
    z[15]=per[3];
    z[16]=per[25];
    z[17]=per[7];
    z[18]=per[15];
    z[19]=per[6];
    z[20]=per[26];
    z[21]=per[19];
    z[22]=per[12];
    z[23]=per[1];
    z[24]=per[40];
    z[25]=per[51];
    z[26]=per[30];
    z[27]=per[36];
    z[28]=per[46];
    z[29]=per[54];
    z[30]=per[29];
    z[31]=per[39];
    z[32]=per[50];
    z[33]=per[46];
    z[34]=per[32];
    z[35]=per[47];
    z[36]=per[43];
    z[37]=per[48];
    z[38]=per[38];
    z[39]=per[55];
    z[40]=per[33];
    z[41]=per[52];
    z[42]=per[45];
    z[43]=per[41];
    z[44]=per[49];
    z[45]=per[35];
    z[46]=per[28];
    z[47]=per[31];
}


void keygen()
{
    int keyi[16][48];
    PermChoice1();

    int i,j,k=0;
    for(i=0; i<28; i++)
    {
        ck[i]=pc1[i];
    }
    for(i=28; i<56; i++)
    {
        dk[k]=pc1[i];
        k++;
    }
    int noshift=0,round;
    for(round=1; round<=16; round++)
    {
        if(round==1||round==2||round==9||round==16)
            noshift=1;
        else
            noshift=2;
        while(noshift>0)
        {
            int t;
            t=ck[0];
            for(i=0; i<28; i++)
                ck[i]=ck[i+1];
            ck[27]=t;
            t=dk[0];
            for(i=0; i<28; i++)
                dk[i]=dk[i+1];
            dk[27]=t;
            noshift--;
        }
        PermChoice2();
        for(i=0; i<48; i++)
            keyi[round-1][i]=z[i];
        cout << "Round : " << round  << " ";
        for(int i = 0;i<48;i++){
            cout << keyi[i];
        }
        cout << endl;
    }

}



int main(){

    keygen();


}

