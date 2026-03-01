//
//  main.cpp
//  大作业
//
//  Created by 张瑾然 on 2025/5/6.
//

#include <iostream>
#include <ctime>
#include <random>
#include <cmath>
#include <algorithm>

using namespace std;

int clamp_price(double val)
{
    int rounded_val=static_cast<int>(val+0.5);
    if (rounded_val<1)
        return 1;
    if (rounded_val>100)
        return 100;
    return rounded_val;
}

//x1是3个的输出+回溯，使用两种价格方式
//x2是3个的时间测试，使用两种价格方式
//x3是21个的输出+回溯，使用两种价格方式
//x4是21个的时间测试，使用两种价格方式
//方案一是正态分布prices，方案二是随机分布prices
#define x3

#ifdef x1
int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> n_dist(1000,2000);
    uniform_int_distribution<> fee_dist(10,20);

    int N=n_dist(rd);
    int fee=fee_dist(gen);
    cout<<"N:"<<N<<endl;
    cout<<"fee:"<<fee<<endl;
    vector<int> prices(N+1);
    
    //<方案一>正态随机价格
    normal_distribution<> price_dist(50.0,20.0);
    for(int i=0;i<=N;i++)
    {
        double val=price_dist(gen);
        prices[i]=clamp_price(val);
    }
    //<方案二>随机随机价格
    /*uniform_int_distribution<> distrib(1,100);
    for(int i=0; i<=N;i++)
    {
        prices[i]=distrib(gen);
    }*/

    vector<vector<int>> dp(N+1,vector<int>(3,-10000));
    vector<vector<pair<int, string>>> path(N+1,vector<pair<int,string>>(3));
    dp[0][0]=0;

    for(int i=1;i<=N;i++)
    {
        dp[i][0]=max({dp[i-1][0],dp[i-1][1]+prices[i]*10-fee*10});
        if(dp[i-1][0]>=(dp[i-1][1]+prices[i]*10-fee*10))
        {
            path[i][0]={0,"HOLD"};
        }
        else{
            path[i][0]={1,"SELL 10"};
        }
        dp[i][1]=max({dp[i-1][1],dp[i-1][0]-prices[i]*10-fee*10,dp[i-1][2]+prices[i]*10-fee*10});
        
        if(dp[i-1][1]>=(dp[i-1][0]-prices[i]*10-fee*10) && dp[i-1][1]>=(dp[i-1][2]+prices[i]*10-fee*10))
        {
            path[i][1]={1,"HOLD"};
        }
        else if((dp[i-1][0]-prices[i]*10-fee*10)>dp[i-1][1] && (dp[i-1][0]-prices[i]*10-fee*10)>(dp[i-1][2]+prices[i]*10-fee*10))
        {
            path[i][1]={0,"BUY 10"};
        }
        else
        {
            path[i][1]={2,"SELL 10"};
        }
        dp[i][2]=max({dp[i-1][2],dp[i-1][1]-prices[i]*10-fee*10});
        if(dp[i-1][2]>=(dp[i-1][1]-prices[i]*10-fee*10))
        {
            path[i][2]={2,"HOLD"};
        }else
        {
            path[i][2]={1,"BUY 10"};
        }
    }

    int res=0;
    int best_stock=0;
    if(N>0)
    {
        res=max({dp[N][0],dp[N][1]+10*prices[N],dp[N][2]+20*prices[N]});
        if(res==dp[N][0])
        {
            best_stock=0;
        }
        else if(res==dp[N][1]+10*prices[N])
        {
            best_stock=1;
        }
        else
        {
            best_stock=2;
        }
    }
    cout<<"最终最大利润："<<res<<endl;
        
    cout<<"回溯路径:"<<endl;
    vector<string> actions;
    int stock=best_stock;
    for(int day=N;day>=1;day--)
    {
        pair<int,string>pa=path[day][stock];
        int prev_stock=pa.first;
        string action=pa.second;
        string record="Day "+to_string(day)+": "+action+" (Stock: "+to_string(stock * 10)+") Prices="+to_string(prices[day-1]);
        actions.push_back(record);
        stock=prev_stock;
    }
    reverse(actions.begin(),actions.end());
    for(size_t i=0;i<actions.size();i++)
    {
        cout<<actions[i]<<endl;
    }
    return 0;
}
#endif


#ifdef x2
int main() {
    srand(static_cast<unsigned int>(time(0)));

    cout<<"N,Time(ms)"<<endl;

    for(int N=0;N<=10000;N+=100)
    {
        clock_t startTime=clock();

        random_device rd;
        mt19937 gen(rd());
        
        uniform_int_distribution<> n_dist(1000,2000);
        uniform_int_distribution<> fee_dist(10,20);

        int fee=fee_dist(gen);
        vector<int> prices(N+1);
        //<方案一>正态随机价格
        normal_distribution<> price_dist(50.0,20.0);
        for(int i=0;i<=N;i++)
        {
            double val=price_dist(gen);
            prices[i]=clamp_price(val);
        }
        //<方案二>随机随机价格
        /*uniform_int_distribution<> distrib(1,100);
        for(int i=0;i<=N;i++)
        {
            prices[i]=distrib(gen);
        }*/

        vector<vector<int>> dp(N+1,vector<int>(3,-10000));
        dp[0][0]=0;

        for(int i=1;i<=N;i++)
        {
            dp[i][0]=max({dp[i-1][0],dp[i-1][1]+prices[i]*10-fee*10});
            dp[i][1]=max({dp[i-1][1],dp[i-1][0]-prices[i]*10-fee*10,dp[i-1][2]+prices[i]*10-fee*10});
            dp[i][2]=max({dp[i-1][2],dp[i-1][1]-prices[i]*10-fee*10});
        }

        int res=0;
        if(N>0)
        {
            res=max({dp[N][0],dp[N][1]+10*prices[N],dp[N][2]+20*prices[N]});
        }

        clock_t endTime=clock();
        double elapsed=double(endTime-startTime)*1000.0/CLOCKS_PER_SEC;

        cout<<N<<","<<elapsed<<endl;
    }
    return 0;
}
#endif

#ifdef x3
int main() {
    random_device rd;
    mt19937 gen(rd());

    uniform_int_distribution<> n_dist(1000,2000);
    uniform_int_distribution<> fee_dist(10,20);

    int N=n_dist(rd);
    int fee=fee_dist(gen);
    cout<<"N:"<<N<<endl;
    cout<<"fee:"<<fee<<endl;
    vector<int> prices(N+1);
    //<方案一>正态随机价格
    normal_distribution<> price_dist(50.0,20.0);
    for(int i=0;i<=N;i++)
    {
        double val=price_dist(gen);
        prices[i]=clamp_price(val);
    }
    //<方案二>随机随机价格
    /*uniform_int_distribution<> distrib(1,100);
    for(int i=0;i<=N;i++)
    {
        prices[i]=distrib(gen);
    }*/

    vector<vector<int>> dp(N+1,vector<int>(21,-10000));
    vector<vector<pair<int,string>>> path(N+1,vector<pair<int,string>>(21));
    dp[0][0]=0;
    
    for(int i=1;i<=N;i++)
    {
        for(int stock=0;stock<=20;stock++)
        {
            int stay=dp[i-1][stock];
            dp[i][stock]=stay;
            path[i][stock]={stock,"HOLD"};

            for(int k=1;k<=10;k++)
            {
                int prev=stock-k;
                if(prev>=0&&dp[i-1][prev]!=-10000)
                {
                    int cost=prices[i-1]*k+fee*k;
                    int val=dp[i-1][prev]-cost;
                    if(val>dp[i][stock])
                    {
                        dp[i][stock]=val;
                        path[i][stock]={prev,"BUY "+to_string(k)};
                    }
                }
            }
            for(int k=1;k<=10;k++)
            {
                int prev=stock+k;
                if(prev<=20&&dp[i-1][prev]!=-10000)
                {
                    int income=prices[i-1]*k-fee*k;
                    int val=dp[i-1][prev]+income;
                    if(val>dp[i][stock])
                    {
                        dp[i][stock]=val;
                        path[i][stock]={prev,"SELL "+to_string(k)};
                    }
                }
            }
        }
    }
    int res=0;
    int best_stock=0;
    for(int stock=0;stock<=20;stock++)
    {
        int total=dp[N][stock]+stock*prices[N-1];
        if(total>res)
        {
            res=total;
            best_stock=stock;
        }
    }
    cout<<"最终最大利润："<<res<<endl;
        
    cout<<"回溯路径:"<<endl;
    vector<string> actions;
    int stock=best_stock;
    for(int day=N;day>=1;day--)
    {
        pair<int,string>pa=path[day][stock];
        int prev_stock=pa.first;
        string action=pa.second;
        string record="Day "+to_string(day)+": "+action+" (Stock: "+to_string(stock)+") Prices="+to_string(prices[day-1]);
        actions.push_back(record);
        stock=prev_stock;
    }
    reverse(actions.begin(),actions.end());
    for(size_t i=0;i<actions.size();i++)
    {
        cout<<actions[i]<<endl;
    }
    return 0;
}
#endif



#ifdef x4
int main() {
    srand(static_cast<unsigned int>(time(0)));
    
    cout<<"N, Time(ms)"<<endl;

    for(int N=0;N<=10000;N+=100)
    {
        clock_t startTime=clock();

        random_device rd;
        mt19937 gen(rd());

        uniform_int_distribution<> n_dist(1000,2000);
        uniform_int_distribution<> fee_dist(10,20);

        int fee=fee_dist(gen);
        vector<int> prices(N+1);
        //<方案一>正态随机价格
        normal_distribution<> price_dist(50.0,20.0);
        for(int i=0;i<=N;i++)
        {
            double val=price_dist(gen);
            prices[i]=clamp_price(val);
        }
        //<方案二>随机随机价格
        /*uniform_int_distribution<> distrib(1, 100);
        for(int i=0;i<=N;i++)
        {
            prices[i]=distrib(gen);
        }*/

        vector<vector<int>> dp(N+1,vector<int>(21,-10000));
        dp[0][0]=0;

        for(int i=1;i<=N;i++)
        {
            for(int stock=0;stock<=20;stock++)
            {
                int stay=dp[i-1][stock];
                dp[i][stock]=stay;

                for(int k=1;k<=10;k++)
                {
                    int prev=stock-k;
                    if(prev>=0&&dp[i-1][prev]!=-10000)
                    {
                        int cost=prices[i-1]*k+fee*k;
                        int val=dp[i-1][prev]-cost;
                        if(val>dp[i][stock]){
                            dp[i][stock]=val;
                        }
                    }
                }
                for(int k=1;k<=10;k++)
                {
                    int prev=stock+k;
                    if(prev<=20&&dp[i-1][prev]!=-10000)
                    {
                        int income=prices[i-1]*k-fee*k;
                        int val=dp[i-1][prev]+income;
                        if(val>dp[i][stock]){
                            dp[i][stock]=val;
                        }
                    }
                }
            }
        }
        int res=0;
        if(N>0)
        {
            for(int stock=0;stock<=20;stock++)
            {
                int total=dp[N][stock]+stock*prices[N-1];
                if(total>res)
                {
                    res=total;
                }
            }
        }

        clock_t endTime=clock();
        double elapsed=double(endTime-startTime)*1000.0/CLOCKS_PER_SEC;

        cout<<N<<", "<<elapsed<<endl;
    }
    return 0;
}
#endif
