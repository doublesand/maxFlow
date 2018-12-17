#include "EdmondsKarp.h"

EdmondsKarp::EdmondsKarp()
{
	cin >> vn >> en;
	C = new int*[vn];
	F = new int*[vn];
	for (int i = 0; i < vn; i++) {
		C[i] = new int[vn];
		F[i] = new int[vn];
	}
	for (int i = 0; i < vn; i++) {
		for (int j = 0; j < vn; j++) {
			C[i][j] = 0;
			F[i][j] = 0;
		}
	}
	/* �������� */
	int a, b, c;
	for (int i = 0; i < en; i++) {
		cin >> a >> b >> c;
		C[a-1][b-1] += c;              //����ļӺű�ʾ�������ر�
		F[a-1][b-1] += c;
	}
}

EdmondsKarp::EdmondsKarp(string path)
{
	ifstream fin;
	fin.open(path);
	fin >> vn >> en;
	/* ��ʼ������C��F */
	C = new int*[vn];
	F = new int*[vn];
	for (int i = 0; i < vn; i++) {
		C[i] = new int[vn];
		F[i] = new int[vn];
	}
	for (int i = 0; i < vn; i++) {
		for (int j = 0; j < vn; j++) {
			C[i][j] = 0;
			F[i][j] = 0;
		}
	}
	/* �������� */
	int a, b, c;
	for (int i = 0; i < en; i++) {
		fin >> a >> b >> c;
		C[a][b] += c;              //����ļӺű�ʾ�������ر�
		F[a][b] += c;
	}
	fin.close();
}

int EdmondsKarp::maxflow(int s, int t)
{
	int maxflow = 0;
	int path_flow;
	while (path_flow = path(s, t)) {
		maxflow += path_flow;
	}
	return maxflow;
}

int EdmondsKarp::maxflow()
{
	int maxflow = 0;
	int path_flow;
	while (path_flow = path(0, vn-1)) {
		maxflow += path_flow;
	}
	return maxflow;
}

int EdmondsKarp::path(int s, int t)
{
	int path_flow = 0;                 //Ĭ��û������·��
	int* pre = new int[vn];       //��¼ǰ�̽ڵ�
	bool* visited = new bool[vn];
	for (int i = 0; i < vn; i++) {
		pre[i] = -1;
		visited[i] = false;
	}
	visited[s] = true;
	bool find_path = false;

	queue<int> q;
	q.push(s);
	while (!q.empty())
	{
		int u = q.front();
		q.pop();
		for (int v = 0; v < vn; v++) {
			if (F[u][v] > 0 && !visited[v]) {
				visited[v] = true;
				pre[v] = u;
				if (v == t) {
					find_path = true;
					break;
				}
				q.push(v);
			}
		}
		if (find_path) {
			int v = t;
			path_flow = F[pre[v]][v];
			//Ѱ������·������С��·��
			while (v != s) {
				int u = pre[v];
				path_flow = path_flow < F[u][v] ? path_flow : F[u][v];
				v = u;
			}
			v = t;
			//���в���ͼ����
			while (v != s) {
				int u = pre[v];
				F[u][v] -= path_flow;
				F[v][u] += path_flow;
				v = u;
			}
			break;
		}
	}

	delete[]pre;
	delete[]visited;
	return path_flow;
}


EdmondsKarp::~EdmondsKarp()
{
	for (int i = 0; i < vn; i++)
	{
		delete[]C[i];
		delete[]F[i];
	}
	delete[]C;
	delete[]F;
}
