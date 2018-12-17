#include "EdmondsKarp.h"
#include "Dinic.h"

using namespace std;

int main() {
	int t;
	cin >> t;
	while (t--)
	{
		EdmondsKarp ek;
		cout << "最大流为" << ek.maxflow()<<endl;
	}
	char ch;
	cin >> ch;
	return 0;
}