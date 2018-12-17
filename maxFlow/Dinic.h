#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <string>
#include <list>

using namespace std;

class Dinic
{
	struct Node
	{
		int v;
		int out;
		Node() {
			v = -1;
			out = 0;
		}
		Node(int v0) {
			v = v0;
			out = 0;
		}
		Node(int v0, int out0) {
			v = v0;
			out = out0;
		}
	};

	int vn;      //顶点个数
	int en;      //边的个数
	int *layer;  //记录每个点到终点的距离

public:
	Dinic(); 
	Dinic(string path);
	bool countLayer(int s, int t);    //Dinic算法的分层
	int maxflow(int s, int t);        //Dinic算法
	~Dinic();
};

