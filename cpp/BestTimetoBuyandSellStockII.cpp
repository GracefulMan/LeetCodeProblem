//
// Created by 马鸿英 on 2019/2/27.
//
#include <iostream>
#include <vector>
using namespace std;
int maxProfit(vector<int>& prices) {

    int totalProfit = 0,i = 0, j = 0;
    int size = prices.size();
    if(size==0) return 0;
    while(i < size){
        j = i;
        while (j < size && prices[j] < prices[j+1]) j++;
        if(j==size) j--;
        totalProfit = max(totalProfit,totalProfit+prices[j] -prices[i] );
        i = j+1;
    }
    return totalProfit;
}
int main(){
    vector<int>prices = {7,1,5,3,6,4};
    cout<<maxProfit(prices);

}