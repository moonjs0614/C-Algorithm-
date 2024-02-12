#include <iostream>
#include <queue>
#include <vector>
using namespace std;


// �׷���(���� �������� ����) ���� Ž��
// Ư�� ��忡�� �� �� �ִ� ��� ��带 Ȯ��

// DFS : Depth First Search. ���� �켱 Ž��
// -> Ž�� ��� : ���

// BFS : Breadth First Search. ���� �켱 Ž��
// -> Ž�� ��� : Queue
// -> Ư¡ : �߰ߵ� ������� ����� �� �ִ� �ڷᱸ���� ������ �ȴ�(�װ� ť)
//         : �׷����� �ִ� "����� ��� ���"�� �Ϸķ� �����Ǿ� �ִ°��� Ȯ��


// ť ��ɾ�
// q.push(value) : value�� ť�� �� �������� ���
// q.front() : ť�� �� �տ� �ִ� value Ȯ��
// q.pop() : ť�� �� �տ� �ִ� value���� ����
// q.empty() : ť�� ������� Ȯ��

// 1. ť ��� ��⿭�� �غ�
// 2. Ư�� ���(������)�� ť�� ���
// 3. �� �տ� �ִ� ��带 Ȯ���ϰ� ����
// 4. ���� ����� ���� ����Ǿ� �־��� �ٸ� ��带 Ž�� (now -> next)
// 5. next�� �ش��ϴ� �ٸ� ������ ť�� ���

/*
Test Case

6 7
1 2
1 4
2 3
2 5
4 5
4 6
3 6

*/

int N, M;
vector<int>alis[15];
int visited[15];

void bfs(int node)
{
	// 1. ť ��⿭ �غ�
	queue<int>q;

	// 2. ������ ť�� ���
	q.push(node); // ������(1�� ���) ���
	visited[node] = 1;


	while (!q.empty())
	{
		// 3. �� �� ��� Ȯ���ϰ� ����
		int now = q.front(); // �� �� �� Ȯ��
		q.pop(); // ��� ����

		cout << now << " ";

		// 4. ����� ���� ����Ǿ� �־��� �ٸ� ��� Ž��
		for (int i = 0; i < alis[now].size(); i++)
		{
			// now > next �� �� �� �ִ� �ٸ� �ĺ��� ã��
			int next = alis[now][i];

			if (visited[next] != 0)continue; //�Ǻ�

			// 5. next�� �ش��ϴ� �ٸ� ��带 ť�� ���
			q.push(next); // now -> next �� ���� �ȴ�
			visited[next] = visited[now] + 1; // ���
		}
	}
	cout << endl;

	for (int i = 1; i <= 6; i++)
	{
		cout << i << " = " << visited[i] << endl;
	}
}

// visited üũ : index = ����ȣ / value = �湮�ߴ°�?


/*
BFS �⺻ Ž�����
1. ť ��⿭ �غ�
2. �������� ť�� ���
3. �� �� ��带 Ȯ���ϰ� ����
4. ����� ���� ����Ǿ��ִ� �ٸ� ��� Ž��
5. next �� �ش��ϴ� �ٸ� ��带 ť�� ���

3~5�� ť�� �� ������ �ݺ�
*/



int main() {

	/*q.push(1);
	q.push(11);
	q.push(123);
	q.push(14);
	q.push(156);
	q.push(124);
	q.push(1);
	q.pop();*/

	cin >> N >> M;
	for (int i = 0; i < M; i++)
	{
		int from, to;
		cin >> from >> to;
		alis[from].push_back(to);
		alis[to].push_back(from);
	}
	bfs(1);
}

// DFS VS BFS
// 1. DFS
// : �پ��� ��θ� Ž��. �� �������� �� �� �ִµ����� ����
// : ex) ���� ���, ��� case, �پ��� case
// : ȿ���� ���� ����ġ�� ��� �ʿ�

// 2. BFS
// : �߰ߵǴ� ������� ����. ������ ������ Ž��
// : �� ������ �߰ߵǴ���
// : ex) �ִ��� ���� ������ ��带 ��ġ�鼭 ���������� �� �� �ִ� ���