//solve's quesntion inn log(n)  time 
//require linear memory 
class NumArray {
public:
vector<int> tree;
vector<int> arr;
int n;
    NumArray(vector<int>& nums) {
        n=nums.size();
        arr.resize(nums.size());
        for(int i=0;i<nums.size();i++){
            arr[i]=nums[i];
        }
        tree.resize(4*n);//it initialise all the values with '0'
        int left=0;//start of segment trees
        int right=n-1;//end of segment trees we have at last n-1 leaf nodes
        build(nums,0,left,right);
    }
    void build(vector<int> &nums,int index,int left,int right){
        if(left==right){
            tree[index]=arr[left];
            return ;
        }
        int mid=(left+((right-left)>>1));
        build(nums,2*index+1,left,mid);//build left
        build(nums,2*index+2,mid+1,right);//build right
        tree[index]=tree[2*index+1]+tree[2*index+2];//back track
        return;
    }

    int sum(int index,int left,int right,int ql,int qr){
        if(right<ql||left>qr){
            return 0;
        }
        if(left>=ql&&right<=qr){
            return tree[index];
        }
        int mid=(left+((right-left)>>1));
        int leftsum=sum(2*index+1,left,mid,ql,qr);
        int rightsum=sum(2*index+2,mid+1,right,ql,qr);
        return leftsum+rightsum;
    } 
    int sumRange(int ql, int qr) {
        int si=0;
        return sum(si,0,n-1,ql,qr);
    }
};
