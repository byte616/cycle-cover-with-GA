#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
#include <cmath>
using namespace std;

const int MAX_N = 505;
int n, B, idx, now_size, near[MAX_N][MAX_N];
double x, y, d, dis[MAX_N][MAX_N];
bool vis[MAX_N];

struct node{
    double x, y, data;
    node(){}
    node(double _x, double _y, double _data): x(_x), y(_y), data(_data){}
} vertex[MAX_N];

bool cmp(int a, int b){
    return dis[idx][a] < dis[idx][b];
}

int get_nextnode(int idx, int type){
    // nearest
    if(type == 1){
        for(int i = 1; i < n; i++){
            if(!vis[near[idx][i]])
                return near[idx][i];
        }
        return vis[near[idx][0]] ? -1 : near[idx][0];
    }
    // farest
    else if(type == 2){
        for(int i = n - 1; i >= 1; i--){
            if(!vis[near[idx][i]])
                return near[idx][i];
        }
        return vis[near[idx][0]] ? -1 : near[idx][0];
    }
    // visit nearest
    else if(type == 3){
        for(int i = 0; i < n; i++){
            if(i == idx) continue;
            if(!vis[i]) return i;
        }
        return -1;
    }
    // visit farest
    else if(type == 4){
        for(int i = n - 1; i >= 0; i--){
            if(i == idx) continue;
            if(!vis[i]) return i;
        }
        return -1;
    }
    return -1;
}

vector<vector<int>> travel(int idx, int type){
    memset(vis, 0, sizeof(vis));
    vector<vector<int>> ans(MAX_N);
    now_size = 0;
    for(int i = 0; i < n; i++){
        if(get_nextnode(i, 1) == -1){
            break;
        }
        double cost = B;
        int start = idx;
        int nearest = -1;
        while(true){
            if((nearest = get_nextnode(idx, 1)) == -1){
                break;
            }
            if(cost < dis[start][nearest] + dis[idx][nearest]){
                ans[i].push_back(idx);
                vis[idx] = 1;
                idx = get_nextnode(idx, type);
                break;
            }
            else{
                cost -= dis[idx][nearest];
                ans[i].push_back(idx);
                vis[idx] = 1;
                idx = nearest;
            }
        }
        now_size += 1;
    }
    return ans;
}

void check_ans(int ans, int limit){
    if(ans <= limit){
        cerr << "OK!!" << '\n';
    }
    else{
        cerr << "OH NO..." << '\n';
    }
}

int main(){
    // input
    cin >> B >> n;
    for(int i = 0; i < n; i++){
        // cin >> x >> y >> d;
        vertex[i] = node(x, y, d);
    }
    // initialize
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            near[i][j] = j;
        }
    }
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            // x = vertex[i].x - vertex[j].x;
            // y = vertex[i].y - vertex[j].y;
            cin >> dis[i][j];
        }
    }
    for(int i = 0; i < n; i++){
        idx = i;
        sort(near[i], near[i] + n, cmp);
    }
    int ans_size = 1e9;
    vector<vector<int>> ans(MAX_N), tmp(MAX_N);
    for(int type = 1; type <= 4; type++){
        for(int i = 0; i < n; i++){
            tmp = travel(i, type);
            if(ans_size > now_size){
                ans_size = now_size;
                ans = tmp;
            }
        }
    }
    double total = 0;
    // cout << "ANS: " << ans_size << '\n';
    for(int i = 0; i < ans_size; i++){
        cerr << "PATH #" << i << ": " << '\n';
        double sum = 0;
        for(int j = 0; j < ans[i].size(); j++){
            cerr << ans[i][j] << " ";
            if(j != 0){
                int x1 = ans[i][j], x2 = ans[i][j - 1];
                sum += dis[x1][x2];
            }
        }
        int x1 = ans[i][0], x2 = ans[i].back();
        sum += dis[x1][x2];
        cerr << '\n';
        cout << "SUM: " << sum << '\n';
        check_ans(sum, B);
        total += sum;
    }
    cout << "ANS: " << ans_size << '\n';
    cout << "AVG: " << total / ans_size << '\n';
}
