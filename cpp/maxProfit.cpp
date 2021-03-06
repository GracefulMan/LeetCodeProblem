//
// Created by 马鸿英 on 2019/2/17.
//
#include <iostream>
#include <vector>
using namespace std;

int maxProfit(vector<int>& prices) {
    int difference=0;
    for(int i=0;i<prices.size();i++){
        for(int j=i+1;j<prices.size();j++){
            if(prices[j]-prices[i]>difference){
                difference = prices[j] - prices[i];
            }
        }
    }
    return difference;
}

int maxProfit1(vector<int>& prices){
    int minItem = INT_MAX;
    int difference = 0;
    for(int i = 0; i < prices.size(); i++){
        if(minItem > prices[i]){
            minItem =  prices[i];
        } else {
            difference =  max(difference , prices[i] - minItem);
        }
    }
    return  difference;
}