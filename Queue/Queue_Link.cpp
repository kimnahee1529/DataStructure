#include <iostream>
#include <algorithm>
using namespace std;

void show(int *arr,int n) {
	for (int i = 0; i <n; i++) {
		cout << "arr["<<i<<"]:" << arr[i]<<" ";
	}
	cout << endl;
}
int main() {
	int n;
	cout << "개수를 입력하시오:";
	cin >> n;
	if (n <= 0) return 0;//예외1
	int *p = new int[n];
	if (!p) {//예외2
		cout << "메모리를 할당할 수 없습니다.";
		return 0;
	}
	for (int i = 0; i < n; i++) {
		cout << i + 1 << "번째 정수: ";
		cin >> p[i];
	}
	show(p,n);
	sort(p,p + n);
	show(p,n);
}
