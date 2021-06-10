#include <iostream>
using namespace std;
int a[40],n;
void func(int x, int k,int y){
    if(k == n){
        for(int j = 0;j < x;++j){
            cout << a[j] << " ";
        }
        cout << endl;
        return;
    }
    if(k>n){
        return;
    }
    for(int i = y; i <= n; ++i){
        a[x] = i;
        func(x + 1, k + a[x], a[x]);
    }
    return;
}
int main(){
    cin >> n;
    func(0,0,1);
}
