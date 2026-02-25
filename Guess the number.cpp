#include <bits/stdc++.h>
using namespace std;

int num[5], gue[5], ran, inp;

int main(){
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<> dis(1000, 9999);
	bool flag = true;
	do{
		ran = dis(gen);
		for(int i = 4; i >= 1; i--){
			num[i] = ran % 10;
			ran /= 10;
		}
		for(int i = 1; i <= 4; i++)
			for(int j = 1; j <= 4 && j != i; j++)
				if(num[i] == num[j]) flag = false;
	}while(flag == false);
	cout << "Please input your guess (4 digits):\n";
	while(true){
		int a = 0, b = 0;
		cin >> inp;
		for(int i = 4; i >= 1; i--){
			gue[i] = inp % 10;
			inp /= 10;
		}
		for(int i = 1; i <= 4; i++)
			if(num[i] == gue[i]) a++;
			else
				for(int j = 1; j <= 4 && j != i; j++)
					if(num[j] == gue[i]) b++;
		if(a == 4){
			cout << "You got it! Congratulations!\n";
			break;
		}else cout << a << "A" << b << "B\n";
	}
	return 0;
}
