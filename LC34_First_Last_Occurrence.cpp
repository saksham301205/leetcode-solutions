int firstOcc(vector<int>& nums, int n, int key){
    int s = 0, e = n - 1;
    int mid = (s+e)/2;
    int ans = -1;
    while(s<=e){
        if (key == nums[mid]){
            ans = mid;
            e = mid - 1;
        }
        else if(key >= nums[mid]){
            s = mid + 1;
        }
        else if(key <= nums[mid]){
            e = mid - 1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

int lastOcc(vector<int>& nums, int n, int key){
    int s = 0, e = n - 1;
    int mid = (s+e)/2;
    int ans = -1;
    while (s<=e){
        if (key == nums[mid]){
            ans = mid;
            s = mid + 1;
        }
        else if(key >= nums[mid]){
            s = mid + 1;
        }
        else if(key <= nums[mid]){
            e = mid - 1;
        }
        mid = (s+e)/2;
    }
    return ans;
}

class Solution {
public:
    vector<int> searchRange(vector<int>& nums, int target) {
        int n = nums.size();
        int first = firstOcc(nums, n, target);
        int last = lastOcc(nums, n, target);
        return {first, last};
    }
};
