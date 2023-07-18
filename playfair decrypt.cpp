#include<bits/stdc++.h>
using namespace std;

int main(){


    string ct; cin >> ct;
    string key; cin >> key;

    vector<pair<char,char>>digraph;
    int i=0;
    while(i<ct.size()){
        digraph.push_back({ct[i],ct[i+1]}); i+=2;
    }

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

    for(int i=0;i<digraph.size();i++){
        char c1 = digraph[i].first, c2 = digraph[i].second;
        int pos1x,pos1y,pos2x,pos2y;
        for(int j=0;j<5;j++){

            for(int k=0;k<5;k++){

                if(keyMat[j][k]==c1)pos1x = j, pos1y = k;
                if(keyMat[j][k]==c2)pos2x = j, pos2y = k;
            }
        }
        if(pos1x==pos2x){
            (pos1y-1<0)?pos1y = (pos1y-1)%5+5: pos1y = (pos1y-1);
            (pos2y-1<0)?pos2y = (pos2y-1)%5+5: pos2y = (pos2y-1);
            c1 = keyMat[pos1x][pos1y];
            c2 = keyMat[pos2x][pos2y];
        }
        else if(pos1y==pos2y){

            (pos1x-1<0)?pos1x = (pos1x-1)%5+5: pos1x = (pos1x-1);
            (pos2x-1<0)?pos2x = (pos2x-1)%5+5: pos2x = (pos2x-1);
            c1 = keyMat[pos1x][pos1y];
            c2 = keyMat[pos2x][pos2y];
        }
        else{

            c1 = keyMat[pos1x][pos2y];
            c2 = keyMat[pos2x][pos1y];
        }
        digraph[i].first = c1;
        digraph[i].second = c2;
    }
    string cipher_text = "";
    for(int i=0;i<digraph.size();i++){cipher_text+=digraph[i].first; cipher_text+=digraph[i].second;}
    cout << cipher_text << endl;

}

