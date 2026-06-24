class Solution {
public:

    bool possible(vector<int>& bloomDay, int day, int m, int k) {

        int flowers = 0;
        int bouquets = 0;

        for(int i = 0; i < bloomDay.size(); i++) {

            if(bloomDay[i] <= day)
                flowers++;
            else
                flowers = 0;

            if(flowers == k) {
                bouquets++;
                flowers = 0;
            }
        }

        return bouquets >= m;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        long long need = 1LL * m * k;

        if(need > bloomDay.size())
            return -1;

        int low = bloomDay[0];
        int high = bloomDay[0];

        for(int i = 1; i < bloomDay.size(); i++) {
            low = min(low, bloomDay[i]);
            high = max(high, bloomDay[i]);
        }

        while(low <= high) {

            int mid = (low + high) / 2;

            if(possible(bloomDay, mid, m, k))
                high = mid - 1;
            else
                low = mid + 1;
        }

        return low;
    }
};
