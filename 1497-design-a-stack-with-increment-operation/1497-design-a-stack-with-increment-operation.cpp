class CustomStack {
public:
    vector<int> st;
    vector<int> inc;
    int size;
    int top;
    
    CustomStack(int maxSize) {
        st = vector<int>(maxSize);
        inc = vector<int>(maxSize, 0); 
        size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top + 1 < size) {
            top++;
            st[top] = x;
        }
    }
    
    int pop() {
        if(top == -1) return -1;
        int poppedValue = st[top] + inc[top];
        if(top > 0) {
            inc[top-1] += inc[top];
        }
        
        inc[top] = 0;
        top--;
        
        return poppedValue;
    }
    
    void increment(int k, int val) {
        int limit = min(k, top + 1);
        if(limit > 0) {
            inc[limit - 1] += val;
        }
    }
};
