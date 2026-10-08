int main() {
    ll n , Budget ; 
    cin >> n >> budget ; 
    vector<int> array(n+1) ; 
    for(int i = 1 ; i<n+1 ; i++) cin >> array[i] ; 
    int ans = 0; 
    int sum = 0 , st_idx = 1,, end_idx ; 
    // contigious meaning like non broken segments of the code 
    for(int i = 1 ; i<n+1; i++) {
        end_idx = i ; 
        sum += array[i] ; 
        while(sum> budget) {
            sum -= array[st_idx] ;
            st_idx = min(i , st_idx+1) ; 

        }
        ans = max(ans,end_idx-st_idx) 
    }
}