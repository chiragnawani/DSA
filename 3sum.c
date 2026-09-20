class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<int> a = nums;
        vector<int> single;
        vector<vector<int>> doubleres;
        int target = -1;
        int size = a.size();
        vector<int> res;
        int gi = 0;
        for(int i=0; i<size; i++){
            if(i > 0 && nums[i] == nums[i - 1]) continue;
            int j = i+1; int k = size-1;//{-4,-1,-1,0,1,2}
            // cout<<endl<<"i: "<<i<<endl;
            // cout<<" i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
            if(i<j && j<k){
            while(j<k){
                //cout<< "a ";
                int sum = a[i] + a[j] + a[k];
                // if(a[i] == a[j]){
                //     j++;
                //     continue;
                // }
                // if(a[i] == a[k]){
                //     k--;
                //     continue;
                // }
                // if(a[j]==a[k]){
                //     j++;
                //     continue;
                // }
                
                if(sum == 0){
                    cout<<endl<<" i: "<<i<<" j: "<<j<<" k: "<<k<<endl;
                    cout<<"a[i]: "<<a[i]<<" a[j]: "<<a[j]<<" a[k]: "<<a[k]<<endl;
                    doubleres.push_back({nums[i], nums[j], nums[k]});

                    // Skip duplicates for j and k
                    while(j < k && nums[j] == nums[j + 1]) j++;
                    while(j < k && nums[k] == nums[k - 1]) k--;

                    j++;
                    k--;
                }
                else if(sum>0){
                    k--;
                }
                else{
                    j++;
                }
            }
            }
        }
        // for(int j = 0; j <doubleres.size(); j++){
        //     for(int i = 0; i<3; i++){
        //         cout<<doubleres[j][i]<<",";
        //     }
        //     cout<<endl;
        return doubleres;
        
    }
};