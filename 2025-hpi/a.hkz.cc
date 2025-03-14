#include <iostream>
using namespace std;

int main(){
    int t;
    cin>>t;
    while(t--){
        int q;
        cin>>q;
        int p = 85;
        while(q--){
            int x;
            cin>>x;
            p*=x;
        }
        cout<<p<<endl;
    }
}
