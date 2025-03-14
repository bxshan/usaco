#include <iostream>
#include <vector>
using namespace std;

int n;
struct report{
    int row;
    int col;
    int radius;
} reports[510];
bool can_exist[1510][1510];

int main(){
    cin>>n;
    for(int i =0;i<n;i++){
        int a, b, c;
        cin>>a>>b>>c;
        a+=500;
        b+=500;
        reports[i].row=a;
        reports[i].col=b;
        reports[i].radius=c;
    }
    int ans = 0;
    for(int r=0;r<=1500;r++) {
        for (int c = 0; c <= 1500; c++) {
            for(int i = 0;i<n;i++){
                bool within_range = ((abs(r-reports[i].row)+abs(c-reports[i].col))<=reports[i].radius);
                if(i==0){
                    can_exist[r][c]=within_range;
                }else{
                    can_exist[r][c]=can_exist[r][c]&&within_range;
                }
            }
        }
    }
    for(int r = 0;r<=1500;r++){
        for(int c = 0;c<1500;c++){
            ans+=(int)can_exist[r][c];
        }
    }
    cout<<ans;
}
