// ���ڿ�
// �ݵ�� �����Ǵ� Ÿ��
// �����͸� �ٷ� �� ��� ó���� ���ΰ�?
// �Ӻ���� -> ��ġ �α� ���ϵ� -> ������ �Ľ�

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring> // c���� ����ϴ� string
#include <string.h> // c���� .h ���� ���·� �Լ��� �������� ������.
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

// �ַ� ����ϴ� �Լ� �ϱ�
int main() {

	// strcmp : ���ڿ� ��
	// strlen : ���ڿ� ����
	// strcpy : ���ڿ� ����
	// memset : ���ڿ� �޸� �ʱ�ȭ
	// =======================> ���� ����ϴ� �Լ�

	/*strtok
	strcat
	strstr*/
	// ==> �Ӻ���� c���� �ٷ� ����

	char str1[100] = "AAA";
	char str2[100] = "AAABB";

	cout << strcmp(str1, str2) << endl; // -1 (str1 < str2) / ����
	cout << strcmp(str2, str1) << endl; // 1 / ���
	cout << strcmp(str1, str1) << endl; // 0

	cout << custom_strcmp(str1, str2) << endl; // -1 (str1 < str2) / ����
	cout << custom_strcmp(str2, str1) << endl; // 1 / ���
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
	//������
	// int �迭 �ʱ�ȭ�� ���, 0 or -1 (��� ��Ʈ�� ���� ���� ���) �� �ʱ�ȭ
	// ���ϴ� ���� �ʱ�ȭ�� �Ϸ��� #include <algorithm> �߰�
	// fill(arr, arr+100, 100);

	//==========================================================================

	char arr_1[100] = "AAB";
	string str_2 = "AAB";
	int de = -1;

	//strlen("AAB"); // �ݺ�Ƚ�� : ���ڿ� ���̸�ŭ
	// cout << str_2.length(); // �����Ϸ����� counting
	// cout << str_2.size();

	string kkk1 = "AAA";
	string kkk2 = "AAB";

	if (kkk1 < kkk2) cout << "������ ����" << endl;
	if (kkk1 > kkk2) cout << "�������� ����" << endl;
	if (kkk1 == kkk2) cout << "����" << endl;
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

	// ���ڿ��� ���Ҷ��� ��� �� �� �ϳ��� string �̾�� ��

	//===========================================================================

	string ddd1 = "AAA";
	string ddd2 = "AAAB";
	string ddd3 = "AABBCC";

	//erase()
	ddd2.erase(2); // 2�� �ε������� ����
	ddd3.erase(1, 3); // 1�� �ε��� ���� �ڷ� 3�� ����
	cout << ddd2 << endl;
	cout << ddd3 << endl;

	//insert()
	//ddd1.insert(1, "BBB"); //1�� �ε����� "BBB" �����ֱ�. ��� : "ABBBAA"
	//cout << ddd1 << endl;
	//ddd1.insert(1, "BCDEF", 3); // 1�� �ε����� "BCDEF" �� �� 3�� �����ֱ�. ��� : "ABCDAA"
	//cout << ddd1 << endl;

	//replace()
	ddd1.replace(1, 3, 10, 'z');
	cout << ddd1 << endl;

	//substr() : �κй��ڿ� ����
	cout << ddd1.substr(1, 3) << endl;

	//find() : ã������ ������ �ε��� ���. (�ߺ����� ���� ��� ���� ���� �ε���)
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