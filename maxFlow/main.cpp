#include "EdmondsKarp.h"
#include "Dinic.h"

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		EdmondsKarp ek;
		cout << "�����Ϊ" << ek.maxflow()<<endl;
	}
	char ch;
	cin >> ch;
	return 0;
}