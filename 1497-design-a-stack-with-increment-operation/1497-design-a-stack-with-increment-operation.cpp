class CustomStack {
public:
    vector<int> st;
    int size;
    int top;
    CustomStack(int maxSize) {
        st = vector<int>(maxSize);
        size = maxSize;
        top = -1;
    }
    
    void push(int x) {
        if(top+1 < size)
        {
            top++;
            st[top] = x;
        }
    }
    
    int pop() {
        if(top == -1) return -1;
        int poppedValue = st[top];
        top--; 
        return poppedValue;
    }
    
    void increment(int k, int val) {
        int n = st.size();
        int len = n<k ? n: k;
        for(int i=0;i<len;i++)
        {
            st[i] += val;
        }
    }
};

/**
 * Your CustomStack object will be instantiated and called as such:
 * CustomStack* obj = new CustomStack(maxSize);
 * obj->push(x);
 * int param_2 = obj->pop();
 * obj->increment(k,val);
 */