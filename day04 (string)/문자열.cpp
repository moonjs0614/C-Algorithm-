// 문자열
// 반드시 출제되는 타입
// 데이터를 다룰 때 어떻게 처리할 것인가?
// 임베디드 -> 장치 로그 파일들 -> 데이터 파싱

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // c에서 사용하는 string
#include <string.h> // c에서 .h 파일 형태로 함수의 원형들이 모여있음.
#include <string>
using namespace std;

int custom_strcmp(char str1[], char str2[])
{
	int i = 0;
	for (i = 0; str1[i]; i++) {
		if (str1[i] < str2[i]) return -1;
		else if (str1[i] > str2[i]) return 1;
	}
	if (str1[i] > 0) return 1;
	if (str2[i] > 0) return -1;

	return 0;
}

int custom_strlen(char str1[])
{
	int len = 0;
	while (str1[len]) len++;
	return len;
}

void custom_strcpy(char dest[], char source[])
{
	int i = 0;
	for (int i = 0; source[i]; i++)
	{
		dest[i] = source[i];
	}
	dest[i] = '\0';
}

// 주로 사용하는 함수 암기
int main() {

	// strcmp : 문자열 비교
	// strlen : 문자열 길이
	// strcpy : 문자열 복사
	// memset : 문자열 메모리 초기화
	// =======================> 자주 사용하는 함수

	/*strtok
	strcat
	strstr*/
	// ==> 임베디드 c에서 다룰 예정

	char str1[100] = "AAA";
	char str2[100] = "AAABB";

	cout << strcmp(str1, str2) << endl; // -1 (str1 < str2) / 음수
	cout << strcmp(str2, str1) << endl; // 1 / 양수
	cout << strcmp(str1, str1) << endl; // 0

	cout << custom_strcmp(str1, str2) << endl; // -1 (str1 < str2) / 음수
	cout << custom_strcmp(str2, str1) << endl; // 1 / 양수
	cout << custom_strcmp(str1, str1) << endl; // 0
	cout << endl;

	//=========================================================================

	cout << strlen(str1) << endl;
	cout << strlen(str2) << endl;
	cout << custom_strlen(str1) << endl;
	cout << custom_strlen(str2) << endl;
	cout << endl;

	//==========================================================================

	char str3[100] = { 0, };

	strcpy(str3, "samsung");
	cout << "str3 : " << str3 << endl;

	//==========================================================================

	custom_strcpy(str3, str1);
	cout << str3 << endl;

	//==========================================================================

	int arr[100];
	memset(arr, 0, sizeof(arr));
	//유의점
	// int 배열 초기화의 경우, 0 or -1 (모든 비트가 서로 같은 경우) 로 초기화
	// 원하는 수로 초기화를 하려면 #include <algorithm> 추가
	// fill(arr, arr+100, 100);

	//==========================================================================

	char arr_1[100] = "AAB";
	string str_2 = "AAB";
	int de = -1;

	//strlen("AAB"); // 반복횟수 : 문자열 길이만큼
	// cout << str_2.length(); // 컴파일러마다 counting
	// cout << str_2.size();

	string kkk1 = "AAA";
	string kkk2 = "AAB";

	if (kkk1 < kkk2) cout << "왼쪽이 빠름" << endl;
	if (kkk1 > kkk2) cout << "오른쪽이 빠름" << endl;
	if (kkk1 == kkk2) cout << "같다" << endl;
	cout << endl;

	//===========================================================================

	//strcpy()
	string kkk3;
	kkk3 = kkk2;
	cout << "kkk3 : " << kkk3 << endl;

	//===========================================================================

	string kkk4 = kkk1 + kkk2;
	cout << "kkk4 : " << kkk4 << endl;
	cout << kkk1 << endl;
	cout << kkk2 << endl;

	// 문자열을 더할때는 적어도 둘 중 하나는 string 이어야 함

	//===========================================================================

	string ddd1 = "AAA";
	string ddd2 = "AAAB";
	string ddd3 = "AABBCC";

	//erase()
	ddd2.erase(2); // 2번 인덱스부터 삭제
	ddd3.erase(1, 3); // 1번 인덱스 포함 뒤로 3개 삭제
	cout << ddd2 << endl;
	cout << ddd3 << endl;

	//insert()
	//ddd1.insert(1, "BBB"); //1번 인덱스에 "BBB" 끼워넣기. 출력 : "ABBBAA"
	//cout << ddd1 << endl;
	//ddd1.insert(1, "BCDEF", 3); // 1번 인덱스에 "BCDEF" 의 앞 3개 끼워넣기. 출력 : "ABCDAA"
	//cout << ddd1 << endl;

	//replace()
	ddd1.replace(1, 3, 10, 'z');
	cout << ddd1 << endl;

	//substr() : 부분문자열 추출
	cout << ddd1.substr(1, 3) << endl;

	//find() : 찾으려는 문자의 인덱스 출력. (중복값이 있을 경우 가장 빠른 인덱스)
	string xxx = "TBVA";
	cout << xxx << endl;
	cout << xxx.find('A') << endl;
	int pos = xxx.find('A');
	if (pos == string::npos)
	{
		cout << "Not Find" << endl;
	}
	else
	{
		cout << "Find" << " " << xxx.find('V');
	}
}