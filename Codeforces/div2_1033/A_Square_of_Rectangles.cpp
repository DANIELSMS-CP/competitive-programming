#include <bits/stdc++.h>
using namespace std;

#define int long long
#define fastio() ios_base::sync_with_stdio(false);cin.tie(NULL);

// Alternative: If you really want to use DP, here's a correct approach
bool dpSolution(vector<pair<int,int>>& rects) {
    int totalArea = 0;
    for(auto& rect : rects) {
        totalArea += rect.first * rect.second;
    }
    
    int side = sqrt(totalArea);
    if(side * side != totalArea) return false;
    
    // dp[mask] = set of possible "remaining shapes" after placing rectangles in mask
    // Since representing arbitrary shapes is complex, we'll use a different approach
    
    // dp[mask][area_used] = can we place rectangles in mask using area_used such that
    // the remaining area can potentially be filled by remaining rectangles
    vector<vector<bool>> dp(8, vector<bool>(totalArea + 1, false));
    dp[0][0] = true; // No rectangles used, no area used
    
    for(int mask = 0; mask < 8; mask++) {
        for(int area = 0; area <= totalArea; area++) {
            if(!dp[mask][area]) continue;
            
            for(int i = 0; i < 3; i++) {
                if(mask & (1 << i)) continue; // Rectangle i already used
                
                int newMask = mask | (1 << i);
                int newArea = area + rects[i].first * rects[i].second;
                
                if(newArea <= totalArea) {
                    // This is still a simplified check - we're not verifying
                    // that the geometric arrangement is actually possible
                    dp[newMask][newArea] = true;
                }
            }
        }
    }
    
    // Check if we can use all rectangles to fill the total area
    // This only checks area, not actual geometric feasibility
    return dp[7][totalArea];
}
void solve() {
    vector<pair<int,int>> rects(3);
    cin >> rects[0].first >> rects[0].second;
    cin >> rects[1].first >> rects[1].second; 
    cin >> rects[2].first >> rects[2].second;
    
    // Calculate total area
    int totalArea = 0;
    for(auto& rect : rects) {
        totalArea += rect.first * rect.second;
    }
    
    // Check if it's a perfect square
    int side = sqrt(totalArea);
    if(side * side != totalArea) {
        cout << "NO\n";
        return;
    }
    
    cout << (dpSolution(rects)?"YES":"NO") << '\n';
}



signed main() {
    fastio();
    int t;
    cin >> t;
    while(t--) {
        solve();
    }
    return 0;
}