#include <iostream>
using namespace std;

int n,m;
int stock_prices[1010][1010];

void read(){
    cin>>n>>m;
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            cin>>stock_prices[i][j];
        }
    }
}

int calc_max_profit(int stock_num){
    int max_profit = INT_MIN;
    for(int i = 0;i<m;i++){
        for(int j = i+1;j<m;j++){
            max_profit = max(max_profit,stock_prices[stock_num][j]-stock_prices[stock_num][i]);
        }
    }
    return max_profit;
}

int main(){
    read();
    int ans = 0;
    for(int i = 0;i<n;i++){
       //cout<<i<<" "<<calc_max_profit(i)<<endl;
        ans+=calc_max_profit(i);
    }
    cout<<ans;
}
