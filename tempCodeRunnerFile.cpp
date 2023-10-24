#include<bits/stdc++.h>
using namespace std;

vector<vector<int>>power_set(vector<int>&nums, vector<vector<int>>&ans, vector<int>&output,  int index)
{
    if(index >= nums.size())
    {   ans.push_back(output);
        return ans;
    }

    //for exclude
    power_set(nums,ans,output,index+1);

    //for include
    int element=nums[index];
    output.push_back(element);
    power_set(nums,ans,output,index+1);
    output.pop_back();
    return ans;    
}

int main()
{
    vector<int>nums;
    nums.push_back(1);
    nums.push_back(2);
    nums.push_back(3);
    int index=0;
    vector<vector<int>>ans;
    vector<int>output;
    vector<vector<int>>k = power_set(nums,ans,output,index);
    for(int i=0;i<k.size();i++)
    {
        for(int j=0;j<k[i].size();j++)
        {
            cout<<ans[i][j]<<" ";
        }
        cout << endl;
    }

}