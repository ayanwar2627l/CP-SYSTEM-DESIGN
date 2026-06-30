class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                }else{
                    dp[i+1][j+1]=max(dp[i][j+1],dp[i+1][j]);
                }

            }
        }
        return dp[n][m];
    }
};
// This is used to find the longest common subsequence where we can skip some values



//Longest Substring where skipping not allowed 
// But this one is different we need to find and update the connected one if mismatch found put it 0(which is already done as we have intialised it with 0 array) 
class Solution {
public:
    int findLength(vector<int>& nums1, vector<int>& nums2) {
        int n=nums1.size();
        int m=nums2.size();
        int ans=0;//no match found
        vector<vector<int>> dp(n+1,vector<int> (m+1,0));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(nums1[i]==nums2[j]){
                    dp[i+1][j+1]=1+dp[i][j];
                    ans=max(dp[i+1][j+1],ans);
                }

            }
        }
        return ans;
    }
};