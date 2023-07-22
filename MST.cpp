#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
const int N = 505;
int n, par[N], cnt[N];
double dis[N][N], B;
struct Edge{
    double w;
    int x, y;
    Edge(){}
    Edge(double _w, int _x, int _y): w(_w), x(_x), y(_y){}
};
bool cmp(Edge a, Edge b){
    return a.w < b.w;
}
vector<Edge> edge;
vector<double> ans(N);
int find(int x){
    return x == par[x] ? x : par[x] = find(par[x]);
}
bool uni(int a, int b){
    a = find(a), b = find(b);
    if(a == b) 
        return 0;
    if(ans[a] + ans[b] + dis[a][b] > B / 2) 
        return 0;
    // cout << a << " " << b << " " << ans[a] + ans[b] << '\n'; 
    par[b] = a;
    ans[a] += ans[b] + dis[a][b];
    return 1;
}
void init(int n){
    for(int i = 0; i < n; i++){
        par[i] = i;
    }
}
int main(){
    cin >> B >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            cin >> dis[i][j];
        }
    }
    double threshold = B / 5;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            if(dis[i][j] <= threshold){
                edge.emplace_back(dis[i][j], i, j);
            }
        }
    }
    init(n);
    sort(edge.begin(), edge.end(), cmp);
    double sum = 0;
    for(auto i : edge){
        if(uni(i.x, i.y)){
            sum += i.w * 2;
        }
    }
    int cycle = 0;
    int max_IoT = 0;
    int min_IoT = 1e9;
    double avg_IoT = 0;
    for(int i = 0; i < n; i++){
        // cout << i << " " << par[i] << '\n';
        if(par[i] == i){
            cycle++;
        }
        cnt[par[i]] += 1;
        max_IoT = max(max_IoT, cnt[par[i]]);
    }
    for(int i = 0; i < n; i++){
        if(cnt[i])
            min_IoT = min(min_IoT, cnt[par[i]]);
    }
    cout << "ANS: " << cycle << '\n';
    cout << "AVG: " << sum / cycle << '\n';
    cout << "MAX_IOT: " << max_IoT << '\n';
    cout << "MIN_IOT: " << min_IoT << '\n';
    cout << "AVG_IOT: " << (double) n / cycle << '\n';
}