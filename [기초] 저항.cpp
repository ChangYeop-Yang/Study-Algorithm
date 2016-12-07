#include <iostream>
#include <string>
using namespace std;

int Aatoi(char str1[]);
void Sstrcat(char * c1, char c2);
void matchValue(string str1);
int matchDiv(string str1);

char str[2];

int main(void)
{
	/* string */
	string s1, s2, s3;
	long long int sum = 0;

	/* 저항 값 입력 */
	cin >> s1 >> s2 >> s3;
	
	matchValue(s1);
	matchValue(s2);
	sum = Aatoi(str);
	sum *= matchDiv(s3);

	cout << sum << endl;

	return 0;
}

/* 사용자 정의 함수 정의 */
int Aatoi(char str1[])
{
	int num = 0;

	for (int count = 0; str1[count] != 0x00; count++)
	{
		num = num * 10;
		num = num + (str1[count] - 0x30);
	}

	return num;
}
void Sstrcat(char * c1, char c2)
{
	int count = 0;
	for (; *(c1 + count) != '\0'; count++);
	*(c1 + count) = c2;
}
void matchValue(string str1)
{
	if (str1.compare("black") == 0) { Sstrcat(str, '0'); }
	else if (str1.compare("brown") == 0) { Sstrcat(str, '1'); }
	else if (str1.compare("red") == 0) { Sstrcat(str, '2'); }
	else if (str1.compare("orange") == 0) { Sstrcat(str, '3'); }
	else if (str1.compare("yellow") == 0) { Sstrcat(str, '4'); }
	else if (str1.compare("green") == 0) { Sstrcat(str, '5'); }
	else if (str1.compare("blue") == 0) { Sstrcat(str, '6'); }
	else if (str1.compare("violet") == 0) { Sstrcat(str, '7'); }
	else if (str1.compare("grey") == 0) { Sstrcat(str, '8'); }
	else { Sstrcat(str, '9'); }
}
int matchDiv(string str1)
{
	int count = 0;

	if (str1.compare("black") == 0) { count = 1; }
	else if (str1.compare("brown") == 0) { count = 10; }
	else if (str1.compare("red") == 0) { count = 100; }
	else if (str1.compare("orange") == 0) { count = 1000; }
	else if (str1.compare("yellow") == 0) { count = 10000; }
	else if (str1.compare("green") == 0) { count = 100000; }
	else if (str1.compare("blue") == 0) { count = 1000000; }
	else if (str1.compare("violet") == 0) { count = 10000000; }
	else if (str1.compare("grey") == 0) { count = 100000000; }
	else { count = 1000000000; }

	return count;
}
