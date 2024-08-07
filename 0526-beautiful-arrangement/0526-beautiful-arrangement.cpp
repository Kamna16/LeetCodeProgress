class Solution {
public:
    int count =0;
    void swap(vector<int> &arr, int i,int j)
    {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
    void check(vector<int> &arr,int j)
    {
        if(j == arr.size()){
            count++;
            return;
        }
        for(int i=j;i<arr.size();i++)
        {
            swap(arr,i,j);
            if((arr[j]%(j+1) == 0) || ((j+1)%arr[j] ==0))
            {
                check(arr,j+1);
            }
            swap(arr,i,j);
        }
        
    }
    int countArrangement(int n) {
        vector<int> arr(n,0);
        for(int i=0;i<n;i++)
        {
            arr[i] = i+1;
        }
        check(arr,0);
        return count;
    }
};