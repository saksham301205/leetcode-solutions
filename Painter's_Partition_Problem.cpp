int countPainters(vector<int>& boards, int maxTime) {
    int painters = 1;
    long long currTime = 0;
    for(int i = 0; i < boards.size(); i++) {
        if(currTime + boards[i] <= maxTime) {
            currTime += boards[i];
        }
        else {
            painters++;
            currTime = boards[i];
        }
    }
    return painters;
}
int findLargestMinDistance(vector<int> &boards, int k)
{
    int low = *max_element(boards.begin(), boards.end());
    int high = accumulate(boards.begin(), boards.end(), 0);
    while(low <= high) {
        int mid = (low + high) / 2;
        int painters = countPainters(boards, mid);
        if(painters > k)
            low = mid + 1;
        else
            high = mid - 1;
    }
    return low;
}
