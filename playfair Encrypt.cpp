/*#include<iostream>
#include<string>
#include<vector>
#include<map>
using namespace std;
int main(){
    int i,j,k,n;
    cout<<"Enter the message"<<endl;
    string s,origin;
    getline(cin,origin);
    cout<<"Enter the key"<<endl;
    string key;
    cin>>key;
    for(i=0;i<origin.size();i++){
        if(origin[i]!=' ')
            s+= origin[i];
    }
    vector<vector<char> > a(5,vector<char>(5,' '));
    n=5;
    map<char,int> mp;
    k=0;
    int pi,pj;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            while(mp[key[k]]>0&&k<key.size()){
                k++;
            }
            if(k<key.size()){
                a[i][j]=key[k];
                mp[key[k]]++;
                //pi=i;
                //pj=j;
            }
            if(k==key.size())
            break;
        }
        if(k==key.size())
            break;
    }
    k=0;
    for(;i<n;i++){
        for(;j<n;j++){
            while(mp[char(k+'a')]>0&&k<26){
                k++;
            }
            if(char(k+'a')=='j'){
                j--;
                k++;
                continue;
            }
            if(k<26){
                a[i][j]=char(k+'a');
                mp[char(k+'a')]++;
            }
        }
        j=0;
    }
    string ans;
    if(s.size()%2==1)
        s+="x";
    for(i=0;i<s.size()-1;i++){
        if(s[i]==s[i+1])
            s[i+1]='x';
    }
    map<char,pair<int,int> > mp2;
    for(i=0;i<n;i++){
        for(j=0;j<n;j++){
            mp2[a[i][j]] = make_pair(i,j);
        }
    }

    for(i=0;i<s.size()-1;i+=2)
        {
        int y1 = mp2[s[i]].first;
        int x1 = mp2[s[i]].second;
        int y2 = mp2[s[i+1]].first;
        int x2 = mp2[s[i+1]].second;
        if(y1==y2){
            ans+=a[y1][(x1+1)%5];
            ans+=a[y1][(x2+1)%5];
        }
        else if(x1==x2){
            ans+=a[(y1+1)%5][x1];
            ans+=a[(y2+1)%5][x2];
        }
        else {
            ans+=a[y1][x2];
            ans+=a[y2][x1];
        }
        }
    cout<<ans<<'\n';
    return 0;
} */




#include<bits/stdc++.h>
using namespace std;

int main(){


    //-->input
    string pt;
    getline(cin,pt);
    pt.erase(remove(pt.begin(), pt.end(), ' '), pt.end());
    string key;
    getline(cin,key);
    key.erase(remove(key.begin(), key.end(), ' '), key.end());

    //--> make digraph
    vector<pair<char,char>>digraph;
    int i=0;
    while(i<pt.size()){
        if(i+1==pt.size())(pt[i]=='x')?digraph.push_back({pt[i++],'z'}):digraph.push_back({pt[i++],'x'});
        else{
            char c1 = pt[i], c2 = pt[i+1];
            if(c1==c2){
                (c1=='x')?digraph.push_back({c1,'z'}):digraph.push_back({c1,'x'});
                (c2=='x')?digraph.push_back({c2,'z'}):digraph.push_back({c2,'x'});
            }
            else digraph.push_back({c1,c2});
            i+=2;
        }
    }
    //-->make key matrix
    int keyMat[5][5], taken[26]={0}, pos[26], ind = 0;
    taken[9] = 1;
    for(int i=0;i<5;i++){
        for(int j=0;j<5;j++){
            while(taken[key[ind]-'a'] && ind<key.size())ind++;
            if(ind<key.size()){
                taken[key[ind]-'a'] = 1;
                keyMat[i][j] = key[ind++];
            }
            else{
                int k = 0;
                while(k<26 && taken[k])k++;
                keyMat[i][j] = (char)(k+'a');
                taken[k] = 1;
            }
        }
    }
    // --> encrypt part
    for(int i=0;i<digraph.size();i++){
        char c1 = digraph[i].first, c2 = digraph[i].second;
        int pos1x,pos1y,pos2x,pos2y;
        for(int j=0;j<5;j++){
            for(int k=0;k<5;k++){
                if(keyMat[j][k]==c1)pos1x = j, pos1y = k;
                if(keyMat[j][k]==c2)pos2x = j, pos2y = k;
            }
        }
        // cout << pos1x<< " " << pos1y << endl << pos2x << " " << pos2y << endl;
        if(pos1x==pos2x){
            c1 = keyMat[pos1x][(pos1y+1)%5];
            c2 = keyMat[pos2x][(pos2y+1)%5];
        }
        else if(pos1y==pos2y){
            c1 = keyMat[(pos1x+1)%5][pos1y];
            c2 = keyMat[(pos2x+1)%5][pos2y];
        }
        else{
            c1 = keyMat[pos1x][pos2y];
            c2 = keyMat[pos2x][pos1y];
        }
        digraph[i].first = c1;
        digraph[i].second = c2;
    }
    string cipher_text = "";
    for(int i=0;i<digraph.size();i++)
        {cipher_text+=digraph[i].first;
    cipher_text+=digraph[i].second;}
    cout << cipher_text << endl;
}


