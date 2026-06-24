int numberOfGasStationsRequired(long double dist, vector<int> &arr) {
    int cnt = 0;
    for(int i = 1; i < arr.size(); i++) {
        int stations = (arr[i] - arr[i - 1]) / dist;

        if((arr[i] - arr[i - 1]) == stations * dist)
            stations--;

        cnt += stations;
    }

    return cnt;
}
double minimiseMaxDistance(vector<int> &arr, int k) {
    long double low = 0;
    long double high = 0;

    for(int i = 1; i < arr.size(); i++) {
        high = max(high, (long double)(arr[i] - arr[i - 1]));
    }
    long double diff = 1e-6;
    while((high - low) > diff) {
        long double mid = (low + high) / 2.0;
        int cnt = numberOfGasStationsRequired(mid, arr);
        if(cnt > k)
            low = mid;
        else
            high = mid;
    }
    return high;
}
