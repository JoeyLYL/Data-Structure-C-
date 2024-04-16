#include<iostream>
using namespace std;
#include<string>

/******************顺序串**************/
#define MAXLEN 255
class SqString {
public:
	char ch[MAXLEN + 1];
	int length;
};
//串的模式匹配（求子串第一次出现位置）
//BF法（简单匹配法）
int Index_BF(SqString S, SqString T) {// int pos
	int i = 1, j = 1;//i=pos(从pos位置开始查找)
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
//KMP算法
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