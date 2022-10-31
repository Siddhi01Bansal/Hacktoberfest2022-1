#include <bits/stdc++.h>
using namespace std;

struct Item{
    int value;
    int weight;
};

class Solution
{
    public:
    static bool mycmp(Item &I1,Item &I2){
        return ((double)I1.value/I1.weight)>((double)I2.value/I2.weight);
    }
    double fractionalKnapsack(int W, Item arr[], int n)
    {
        double ans=0;
        sort(arr,arr+n,mycmp);
        for(int i=0;i<n;i++){
            if(W>arr[i].weight){
                W=W-arr[i].weight;
                ans+=arr[i].value;
            }
            else{
                ans+=(double)W*arr[i].value/arr[i].weight;
                break;
            }
        }
       return ans; 
    }
        
};

int main()
{
	int t;
	cin>>t;
	cout<<setprecision(2)<<fixed;
	while(t--){
		int n, W;
		cin>>n>>W;
		
		Item arr[n];
		for(int i=0;i<n;i++){
			cin>>arr[i].value>>arr[i].weight;
		}

		Solution ob;
		cout<<ob.fractionalKnapsack(W, arr, n)<<endl;
	}
    return 0;
}
