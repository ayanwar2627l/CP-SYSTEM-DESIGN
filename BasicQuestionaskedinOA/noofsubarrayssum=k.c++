class NumArray {
public:
    vector<int> tree;
    vector<int> arr;
    int n;    
    NumArray(vector<int>& nums) {
        // public:
        n=nums.size();
        arr.resize(n);
        tree.resize(4*n);
        for(int i=0;i<n;i++){
            arr[i]=nums[i];
        }
        int si=0;
        int left=0;
        int right=n-1;
        build(si,left,right);
    }

    void build(int index,int left,int right){
        if(left==right){
            tree[index]=arr[left];
            return ;
        }
        int mid=left+(right-left)/2;
        build(2*index+1,left,mid);
        build(2*index+2,mid+1,right);
        tree[index]=tree[2*index+1]+tree[2*index+2];
        return ;
    }
    int sum(int index,int left,int right,int ql,int qr){
        if(left>qr||right<ql){//check for out of bounds
            return 0;
        }
        if(ql<=left&&right<=qr){
            return tree[index];
        }
        int mid=left+(right-left)/2;
        int leftsum=sum(2*index+1,left,mid,ql,qr);
        int rightsum=sum(2*index+2,mid+1,right,ql,qr);
        return leftsum+rightsum;
    }
    int sumRange(int ql, int qr) {
        return sum(0,0,n-1,ql,qr);
    }
    
    void updatepoint(int index,int pos,int val,int left,int right){
        if(left==right){
            tree[index]=val;
            return ;
        }
        int mid=left+(right-left)/2;
        if(pos<=mid){//pos is the index of the val
            updatepoint(2*index+1,pos,val,left,mid);
        }else{
            updatepoint(2*index+2,pos,val,mid+1,right);
        }
        tree[index]=tree[2*index+1]+tree[2*index+2];
        return ;
    }

    void update(int index, int val) {
        int pos=index;//this is the positiion where i need to update
        updatepoint(0,pos,val,0,n-1);
    }
    
};
