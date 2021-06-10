#include <iostream>
using namespace std;
int main(){
int a, b, i, d, k, x;
cin >> a >> b;   
for(i=a; i<=b; i++) {
	if (i % 2 != 0)
		k = 2;
	else
		k = 1;
	d = 2;
    while (d * d < i)
	{
        if (i % d == 0)
		{
        	if (d % 2 != 0)
        		k ++;
			if (i/d % 2 != 0)
        		k ++;
    	}
    	if (k > 5)
			break;
		d ++;
	}
	if (d * d == i && d % 2 != 0)
		k ++;
    if (k == 5){
        cout << i << endl;
        x ++;
		}
}
if (x == 0)
    cout << 0;
}

