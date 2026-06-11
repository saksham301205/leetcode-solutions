vector<int> moveZeros(int n, vector<int> a) {

    vector<int> temp;

    // store all non-zero elements
    for(int i = 0; i < n; i++) {
        if(a[i] != 0) {
            temp.push_back(a[i]);
        }
    }

    int nz = temp.size();

    // put non-zero elements back
    for(int i = 0; i < nz; i++) {
        a[i] = temp[i];
    }

    // fill remaining positions with 0
    for(int i = nz; i < n; i++) {
        a[i] = 0;
    }

    return a;
}
