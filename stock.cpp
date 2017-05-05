#include <iostream>
#include <vector>
#include <cstdio>
#include <algorithm>

using namespace std;

/*请完成下面这个函数，实现题目要求的功能*/
/*当然，你也可以不按照下面这个模板来作答，完全按照自己的想法来 ^-^ */
/******************************开始写代码******************************/
double StockGod(int n, int m, double p, const vector<vector<double>>& prices)
{
    // 答案基于假设：在同一个交易期内可以卖出股票然后买入新股票。
    vector<double> stock(n,0);//在某个交易期内最多可持有第i只股票的数量。
    double total=1.0;//在某个交易期内将股票全换成现金，最多可以变现多少钱。
    for(int i=0;i<n;i++){
        stock[i]=1.0/prices[0][i];
        //cout<<stock[i]<<" ";
    }
    for(int i=1;i<m;i++){
            for(int j=0;j<n;j++){
                if(prices[i][j]*stock[j]*(1.0-p)>total)
                    total=prices[i][j]*stock[j]*(1.0-p);
                //stock[j]=max(stock[j],total/prices[i][j]);
            }
            for(int j=0;j<n;j++){
                stock[j]=max(stock[j],total/prices[i][j]);
              //  cout<<stock[j]<<" ";
            }
        //cout<<"             total = "<<total<<endl;
    }
    return total;
}
/******************************结束写代码******************************/


int main()
{
    //freopen("D:\\input.txt","r",stdin);
    int n = 0;
    int m = 0;
    double p = 0;
    cin >> n >> m >> p;

    vector<vector<double>> prices;
    for(int i = 0; i < m; ++i) {
        prices.push_back(vector<double>());
        for(int j = 0; j < n; ++j) {
            double x = 0;
            cin >> x;
            prices.back().push_back(x);
        }
    }
    //printf("here\n");
    double final = StockGod(n, m, p, prices);
    printf("%.1f\n", final);

    return 0;
}
