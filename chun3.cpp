/**
�ֽ�����2019���к�˿���3��16�ձ�����
�����⣺
n���˲μӱ�����������ÿ����һ��������
�콱ʱ�����������ų�һȦ����һ���͵�n�����ڡ�
Ҫ��:
1.���ĳ���˵ķ������Աߵ��˸ߣ���ô��Ʒ����ҲҪ�����ࡣ
2.ÿ�����ٵ�һ����Ʒ��
������Ӧ��׼�����ٸ���Ʒ?
���˼·������Ϊֱ����̬����ѭ������
**/
//#include<iostream>
//#include<cmath>
//#include<algorithm>
//
//using namespace std;
//
//const int maxn=10000;
//struct node{   //node������ÿ���ڵ����򣬵õ�key������˳��
//	int key;
//	int value;
//	//int score;
//}nodes[maxn];
//
//bool cmp(node a, node b){
//	return a.value < b.value;
//}
//
//int main(){
//	int n;
//	cin >> n;
//	int*a = new int[n];//��¼ԭʼ�����ÿ���˵ĵ÷���
//	int m;
//	for (int i = 0; i < n; i++){
//		cin >> m;
//		nodes[i].key = i;
//		nodes[i].value = m;
//		//nodes[i].score = 0;
//		a[i] = 0;
//	}
//
//	sort(nodes, nodes + n,cmp);
//
//	int sum = 0;
//	for (int i = 0; i < n; i++){
//		int p;
//		p = nodes[i].key;
//		if (p == 0){
//			a[p] = max(a[p + 1], a[p + n - 1]) + 1;// ����д�� nodes[i].score = max(nodes[p -1].score, nodes[p -n + 1].score) + 1;
//			sum = sum + a[p];
//		}
//
//		if (p == n - 1){
//			a[p] = max(a[p - 1], a[p - n + 1]) + 1;
//			sum = sum + a[p];
//		}
//
//		else{
//			a[p] = max(a[p + 1], a[p - 1]) + 1;
//			sum = sum + a[p];
//		}
//	}
//	for (int i = 0; i < n; i++){
//		cout<<a[i] << ' ';
//	}
//	cout << endl;
//	cout << sum << endl;
//}