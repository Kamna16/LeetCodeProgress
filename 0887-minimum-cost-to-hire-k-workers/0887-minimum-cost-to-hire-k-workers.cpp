class Solution {
public:
    double mincostToHireWorkers(vector<int>& quality, vector<int>& min_wage, int k) {
        int n = quality.size();

        vector<pair<double, int>> worker_ratio(n);
        for(int worker = 0; worker < n; worker++) {
            worker_ratio[worker] = make_pair((double)min_wage[worker]/quality[worker], quality[worker]);
        }
        sort(begin(worker_ratio), end(worker_ratio));

        priority_queue<int, vector<int>> pq;
        
        double sum_quality = 0;
        for(int i = 0; i < k; i++) { 
            pq.push(worker_ratio[i].second); //push all qualities in max-heap
            sum_quality += worker_ratio[i].second; //Find sum of qualities
        }

        double managerRatio = worker_ratio[k-1].first; 
        double result       = managerRatio * sum_quality;

        for(int manager = k; manager < n; manager++) {
            
            managerRatio = worker_ratio[manager].first;

            pq.push(worker_ratio[manager].second); //push all qualities in max-heap
            sum_quality += worker_ratio[manager].second; //Find sum of qualities

            if(pq.size() > k) {
                sum_quality -= pq.top();
                pq.pop();
            }

            result = min(result, managerRatio*sum_quality);

        }

        return result;
    }
};