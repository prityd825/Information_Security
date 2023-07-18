#include<bits/stdc++.h>
using namespace std;
int main()
{
    cout<< "Enter the message : ";
    char msg[100];
    cin.getline(msg,100);
    int i,j,length,choice,key;
    cout<<"Enter the key: " ;
    cin>> key;
    length = strlen(msg);

    while(1){
    cout<<"Enter your choice where 1. Encryption\t\t 2.decryption \t\t 3.Exit ";
    cout<<endl;
    cout<<"Enter your choice : ";
    cin>> choice;
    if (choice == 1)
    {
        char ch;
        for(int i=0; msg[i]!='\0';++i)
        {
            ch = msg[i];
            if(ch>= 'a' && ch<= 'z')
            {
                ch = ch+ key;
                if(ch > 'z')
                {
                    ch = ch - 'z'+ 'a' -1;
                }
                msg[i] = ch;
            }
            else if (ch >= 'A' && ch <= 'Z')
            {
                ch = ch+key;
                if(ch > 'Z')
                {
                    ch = ch - 'Z' + 'A'-1;
                }
                msg[i] = ch;
            }
        }
        //printf("Encrypted message : %s", msg);
        cout<<"Encrypted message : "<<msg<<endl;
        cout<<endl;
    }
     else if(choice ==2)
     {
         char ch;
         for(int i=0; msg[i] != '\0'; ++i)
         {
             ch = msg[i];
             if(ch >= 'a' && ch <= 'z')
             {
                 ch = ch - key;
                 if(ch < 'a')
                 {
                     ch = ch + 'z'- 'a' +1;
                 }
                 msg[i] = ch;
             }
             else if ( ch>= 'A' && ch <= 'Z')
             {
                 ch = ch - key;
                 if(ch < 'A')
                 {
                     ch = ch + 'Z' - 'A' +1;
                 }
                 msg[i] = ch;
             }

         }
         cout<<"Decrypted message: " << msg;
         cout<<endl;
     }
     else if(choice==3){
            break;

    }
}
}
