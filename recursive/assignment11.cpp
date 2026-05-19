// #include<iostream>
// #include<vector>
// #include<algorithm>
// using namespace std;

// class Item{
// public:
//     int value;
//     int weight;

//     Item(int v,int w){
//         value = v;
//         weight = w;
//     }
// };

// bool cmp(Item a,Item b){
//     double r1 = (double)a.value / a.weight;
//     double r2 = (double)b.value / b.weight;
//     return r1 > r2;
// }

// double fractionalKnapsack(int W,vector<Item> items){
//     sort(items.begin(),items.end(),cmp);

//     double totalValue = 0.0;

//     for(auto &item : items){
//         if(W >= item.weight){
//             totalValue += item.value;
//             W -= item.weight;
//         }

//         else{
//             totalValue += item.value * ((double)W / item.weight);
//             break;
//         }
//     }

//     return totalValue;
// }

// int main()
// {
//     int n , W;
//     cout << "Enter no. of items : ";
//     cin >> n;

//     vector<Item> items;

//     cout << "Enter value and weight for each item : ";
//     for(int i=0;i<n;i++){
//         int v, w;
//         cin >> v >> w;
//         items.push_back(Item(v,w));
//     }

//     cout << "Enter knapsack capacity : ";
//     cin >> W;

//     double maxValue = fractionalKnapsack(W,items);
//     cout << "maximum value in knapsack : " << maxValue << endl;
//     return 0;
// }
# include <iostream>
# include <algorithm>
# include <vector>
class Item{
   public:
   int value;
   int weight;

   Item(int v,int w){
    value = v;
    weight = w;
   }
}

bool cmp(Item a,Item b){
   r1 = a.value/a.weight;
   r2 = b.value/b.weight;
   return r1>r2;
}

double Frac(vector<Item> items,int W){
   sort(items.begin(),items.end(),cmp);
   double totalWt = 0.0;
   for(auto &item : items){
         if(W >= item.weight){
             totalValue += item.value;
             W -= item.weight;
         }

         else{
             totalValue += item.value * ((double)W / item.weight);
             break;
         }
     }

}