#include<bits/stdc++.h>
using namespace std;

typedef struct {
    int profit, weight;
    float ratio_v;
}Item;

bool compare(Item i1, Item i2)
{
    return (i1.ratio_v > i2.ratio_v);
}

void knapsack(Item item[], int no_item, int W) {

    int max_profit = 0, max_weight = 0;

    for(int i =  0; i < no_item; i++) {
        item[i].ratio_v = item[i].profit / item[i].weight;
    }
    sort(item, item+no_item, compare);


    for(int i = 0; i < no_item; i++)
    {
        if(max_weight + item[i].weight < W)
        {
            max_weight = max_weight + item[i].weight;
            max_profit = max_profit + item[i].profit;
        }
        else
        {
            int wt = W - max_weight;
            max_profit = max_profit + (wt * item[i].ratio_v);
            max_weight = max_weight + wt;
            break;
        }
    }
    cout << max_profit<< endl;
}


int main()
{
    int W,no_item;
    cout << "Enter maximum capacity: ";
    cin >> W;

    cout << "Enter No. of item : ";
    cin >> no_item;

    Item item[10];


    for(int i = 0; i < no_item; i++) {
        cout << "Enter " << i+1 << "Profit";
        cin >> item[i].profit;

        cout << "Enter " << i+1 << "Weight";
        cin >> item[i].weight;
    }

    knapsack(item, no_item, W);
}
