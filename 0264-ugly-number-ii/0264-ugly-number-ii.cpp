class Solution {
public:
    int nthUglyNumber(int n) {
        int arr[n+1];
        arr[1]=1;
        int i2 ,i3,i5;
        i2 = i3= i5 = 1;
        for(int i=2;i<=n;i++)
        {
            int i2Num = arr[i2]*2; 
            int i3Num = arr[i3]*3; 
            int i5Num = arr[i5]*5;

            int mini = min({i2Num, i3Num, i5Num});
            arr[i] = mini;

            if(mini == i2Num) i2++;
            if(mini == i3Num) i3++;
            if(mini == i5Num) i5++;
        }
        return arr[n];
    }
};