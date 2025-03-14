#include <iostream>
#include <string>
using namespace std;

int64_t n;
string strings[3010];

void read(){
    cin>>n;
    for(int64_t i = 0;i<n;i++){
        cin>>strings[i];
    }
}

string merge(string str1, string str2){
    if(str1[str1.length()-1]==str2[0]){
        return str1+str2.substr(1);
    }
    return "cannotmerge";
}

int64_t calc_score(string str){
    int64_t score = 0;
    if(str=="cannotmerge"){
        return -1;
    }
    for(char c : str){
        if(c=='R'){
            score+=5;
        }else if(c=='H'){
            score+=10;
        }else if(c=='L'){
            score-=3;
        }else{
            score+=1;
        }
    }
    return score;
}
int main() {
    read();
    int64_t ans = INT_MIN;
    for(int64_t i = 0;i<n;i++){
        for(int64_t j = i+1;j<n;j++){
            ans=max(calc_score(merge(strings[i],strings[j])),ans);
            ans=max(calc_score(merge(strings[j],strings[i])),ans);
        }
    }
    cout<<ans;
}
