#include<iostream>
#include<cmath>
#include<algorithm>
#include<iomanip> 
using namespace std;

/**
�ֽ�����2019���к�˿���3��16�ձ�����
������:
��N�����ӣ���i����ΪLi������Ҫm���ȳ����ӡ�
����Զ�N�����ӽ����������(����ƴ��)���������m��������ĳ����Ƕ���?
���˼·�����ַ�

ע����������Ϊ������
**/

//ÿ������length�������Ա��гɼ���
int num(double*a,double length,int n){
	int k = 0;
	for (int i = 0; i < n; i++){
		k = k + a[i] / length;
	}
	return k;
}
int main(){
	int n;
	double maxn = 0;//��¼�������
	cin >> n;
	double*len = new double[n];
	for (int i = 0; i < n; i++){
		cin >> len[i];
		maxn = max(maxn, len[i]);
	}
	int m;
	cin >> m;

	//ʹ�ö��ַ�����󳤶�
	bool flag = false;
	double l = 0;
	double r = maxn;
	double mid;
	while ((r-l)>1e-4){
		mid = (l + r) / 2;
		if (num(len, mid, n) == m && (r - l)<=1e-4){//�տ�ʼ��������(r - l)<=1e-4)
			flag = true;
			break;
		}
		if (num(len, mid, n) < m){
			r = mid;//�տ�ʼд��r = mid-1;���Ǹ����͵Ķ��ַ�������
		}
		else {
			l = mid;
		}
	}
	if (flag == true) cout << setprecision(2)<<mid*m << endl;
	else cout << "l=" << mid << ' ' << "l*m=" << l*m << endl;
	// else cout << l*m << endl;

}