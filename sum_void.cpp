#include <iostream>
#include <iomanip>
using namespace std;
int main(){
    string str;
    int N = 50;
    double x1, x2, x3, x4, x5;
    double sum1 = 0, sum2 = 0, sum3 = 0, sum4 = 0, sum5 = 0;
    for(int i = 0; i < N; i++){
        cin >> str >> x1; sum1 += x1;
        cin >> str >> x2; sum2 += x2;
        cin >> str >> x3; sum3 += x3;
        cin >> str >> x4; sum4 += x4;
        cin >> str >> x5; sum5 += x5;
    }
    
    double x6, x7, x8, x9, x10;
    double sum6 = 0, sum7 = 0, sum8 = 0, sum9 = 0, sum10 = 0;
    for(int i = 0; i < N; i++){
        cin >> str >> x6; sum6 += x6;
        cin >> str >> x7; sum7 += x7;
        cin >> str >> x8; sum8 += x8;
        cin >> str >> x9; sum9 += x9;
        cin >> str >> x10; sum10 += x10;
    }
    
    double x11, x12, x13, x14, x15;
    double sum11 = 0, sum12 = 0, sum13 = 0, sum14 = 0, sum15 = 0;
    for(int i = 0; i < N; i++){
        cin >> str >> x11; sum11 += x11;
        cin >> str >> x12; sum12 += x12;
        cin >> str >> x13; sum13 += x13;
        cin >> str >> x14; sum14 += x14;
        cin >> str >> x15; sum15 += x15;
    }
    

    cout << fixed << setprecision(6);
    cout << 0.5 << " " << sum1 / N << " " << sum6 / N << " " << sum11 / N << " " << '\n';
    cout << 1.0 << " " << sum2 / N << " " << sum7 / N << " " << sum12 / N << " " << '\n';
    cout << 1.5 << " " << sum3 / N << " " << sum8 / N << " " << sum13 / N << " " << '\n';
    cout << 2.0 << " " << sum4 / N << " " << sum9 / N << " " << sum14 / N << " " << '\n';
    cout << 2.5 << " " << sum5 / N << " " << sum10 / N << " " << sum15 / N << " " << '\n';
}