/**
�ֽ�����2019���к�˿���3��16�ձ�����
�ڶ���:
����
1.����ͬ������ĸ����һ��һ����ƴд����ȥ��һ���ͺ��ˡ�����:helllo --> hello
2.����һ������ĸ(AABB��)����һ��һ����ƴд����ȥ���ڶ��Եĵ�һ����ĸ������:helloo --> hello
3.����Ĺ������ȴ�����ƥ�䣬�������AABBCC�ͣ�Ӧ���ȿ����޸�AABBΪAABCC��
���룺
һ���ַ���
�����
��������ַ���
���˼·������һ���ַ�������
**/
//#include<iostream>
//#include<string>
//using namespace std;
//
//int main(){
//	string s;
//	cin >> s;
//	int n1 = 0;
//	int n2 = 1;
//	int n3 = 2;
//	int n4 = 3;
//	int len = s.length();
//	if (len <= 2){
//		cout << s << endl;
//		return 0;
//	}
//	for (; n3 < len;){
//		if (s[n1] == s[n2] && s[n1] == s[n3]){
//			s.erase(s.begin()+n3); //erase��ʹ�ã�
//		}
//		else{
//			n1++;
//			n2++;
//			n3++;
//		}
//	}
//	n1 = 0;
//	n2 = 1;
//	n3 = 2;
//	n4 = 3;
//	int len2 = s.length();
//	if (len2 <= 3){
//		cout << s << endl;
//		return 0;
//	}
//	for (; n4 < len;){
//		if (s[n1] == s[n2] && s[n3] == s[n4]){
//			s.erase(s.begin() + n4);
//		}
//		else{
//			n1++;
//			n2++;
//			n3++;
//			n4++;
//		}
//	}
//	cout << s << endl;
//	return 0;
//
//}