#include <bits/stdc++.h>
using namespace std;

int main(){
	int n, num[15], gue[15], ran, inp;
	cout << "Please input the digits of the number you want to guess (less than 10).\n";
	cin >> n;
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis((int)(pow(10, n - 1)), (int)(pow(10, n) - 1));
	bool flag;
	do{
		flag = true;
		ran = dis(gen);
		for(int i = n; i >= 1; i--){
			num[i] = ran % 10;
			ran /= 10;
		}
		for(int i = 1; i <= n; i++)
			for(int j = 1; j != i && j <= n; j++)
				if(num[i] == num[j]) flag = false;
	}while(flag == false);
	cout << "Please input your guess.\n";
	int a, b;
	while(true){
		a = 0, b = 0;
		cin >> inp;
		for(int i = n; i >= 1; i--){
			gue[i] = inp % 10;
			inp /= 10;
		}
		for(int i = 1; i <= n; i++)
			if(num[i] == gue[i]) a++;
			else
				for(int j = 1; j != i && j <= n; j++)
					if(num[j] == gue[i]) b++;
		if(a == n){
			cout << "You got it! Congratulations!\n";
			break;
		}else cout << a << "A" << b << "B\n";
	}
	return 0;
}
