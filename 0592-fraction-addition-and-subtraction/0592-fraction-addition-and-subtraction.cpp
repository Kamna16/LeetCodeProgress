class Solution {
public:
    string fractionAddition(string exp) {
       long long num = 0;   
        long long deno = 1;  
        int i = 0;
        int n = exp.size();
        
        while (i < n) {
            long long currNum = 0;
            long long currDeno = 0;
            bool isNeg = exp[i] == '-';
            
            if (exp[i] == '+' || exp[i] == '-') {
                i++;
            }
            
            while (i < n && isdigit(exp[i])) {
                int val = exp[i] - '0';
                currNum = (currNum * 10) + val;
                i++;
            }
            
            if (isNeg) {
                currNum *= -1;
            }
            
            i++; 
            while (i < n && isdigit(exp[i])) {
                int val = exp[i] - '0';
                currDeno = (currDeno * 10) + val;
                i++;
            }
            
            num = num * currDeno + currNum * deno;
            deno = deno * currDeno;
        }
        
        long long gcd = abs(__gcd(num, deno));
        num /= gcd;
        deno /= gcd;
        
        return to_string(num) + "/" + to_string(deno);
    }
};