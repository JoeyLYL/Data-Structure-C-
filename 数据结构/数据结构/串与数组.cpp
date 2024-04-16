#include<iostream>
using namespace std;
#include<string>

/******************˳��**************/
#define MAXLEN 255
class SqString {
public:
	char ch[MAXLEN + 1];
	int length;
};
//����ģʽƥ�䣨���Ӵ���һ�γ���λ�ã�
//BF������ƥ�䷨��
int Index_BF(SqString S, SqString T) {// int pos
	int i = 1, j = 1;//i=pos(��posλ�ÿ�ʼ����)
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			i = i - j + 2;
			j = 1;
		}
	}
	if (j >= T.length) return(i - T.length);
	else return 0;
}
//KMP�㷨
int Index_KMP(SqString S, SqString T, int pos) {
	int i = pos, j = 1;
	while (i <= S.length && j <= T.length) {
		if (S.ch[i] == T.ch[j]) {
			i++;
			j++;
		}
		else {
			//j = next[j];
		}
	}
	if (j >= T.length) return(i - T.length);
	else return 0;
}