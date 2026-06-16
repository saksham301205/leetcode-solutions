pair<int, int> getFloorAndCeil(vector<int> &arr, int n, int x)
{
    int floorVal = -1;
    int ceilVal = -1;

    for(int i = 0; i < n; i++)
    {
        if(arr[i] <= x)
            floorVal = arr[i];

        if(arr[i] >= x)
        {
            ceilVal = arr[i];
            break;
        }
    }

    return {floorVal, ceilVal};
}
