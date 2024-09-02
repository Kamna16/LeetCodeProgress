class Solution {
public:
    int chalkReplacer(vector<int>& chalk, int k) {
        int n = chalk.size();
        long long sum = accumulate(chalk.begin(),chalk.end(),0LL);
        int rem = k%sum;
        int i=0;
        while(rem >= chalk[i])
        {
            rem -= chalk[i];
            i = (i+1) % n;
        }
        return i;
    }
};