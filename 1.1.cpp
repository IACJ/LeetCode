//#include<iostream>
//#include<algorithm>
//#include<cmath>
//#include<algorithm>
//using namespace std;
///*
//ͷ���⿪1
//
//��һ������㼯�ĸ��� N�� ������ N �У�ÿ���������ִ����� X ��� Y �ᡣ
//���� 50%������,  1 <= N <= 10000;
//���� 100%������, 1 <= N <= 500000;
//
//��������ġ� �㼯�ϣ� ���� X ���С����ķ�ʽ�����ÿ���������ֱַ������ X ��� Y�ᡣ
//
//���г�ʱ:���ĳ���δ���ڹ涨ʱ�������н����������Ƿ�ѭ���д���㷨���Ӷȹ���
//(node[i].x < node[j].x) && (node[i].y < node[j].y)
//
//����yֵ�Ӵ�С����Ȼ��ɨ�裬���浱ǰ����x������õ��x����ô�õ���������
//ע��Ҫʹ��scanf,printf,ʹ��cin,cout�ᳬʱ!
//*/
//struct Node{
//	long x;
//	long y;
//}node[500001],nodes[500000];
//
//bool cmp(Node a, Node b){
//	return a.y > b.y;
//}
//int main(){
//	int k;
//	cin >> k;
//	for (int i = 0; i < k; i++){
//		cin >> node[i].x;
//		cin >> node[i].y;
//	}
//	sort(node, node + k, cmp);
//	//int p=0;
//	//for (int i = 0; i < k; i++){
//	//	bool flag = true;
//	//	
//	//	for (int j = i+1; j < k; j++){
//	//		if ((node[i].y < node[j].y)){
//	//			flag = false;
//	//			break;
//	//		}
//	//	}
//	//	if (flag == true){
//	//		nodes[p].x = node[i].x;
//	//		nodes[p].y = node[i].y;
//	//		p++;
//	//	}
//	//		
//	//}
//
//	////cout << "p=" << p << endl;
//	//sort(nodes, nodes + p, cmp);
//
//	//for (int i = 0; i < p; i++){
//	//	cout << nodes[i].x << ' ' << nodes[i].y << endl;
//	//}
//
//	int maxx = -1;
//	for (int i = 0; i < k; i++){
//		if (node[i].x>maxx){
//			maxx = node[i].x;
//			cout << node[i].x << ' ' << node[i].y << endl;
//		}
//	}
//	return 0;
//}
//
