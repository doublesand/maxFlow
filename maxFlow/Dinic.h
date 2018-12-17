#pragma once

#include <iostream>
#include <fstream>
#include <queue>
#include <list>

class Dinic
{
	struct Node
	{
		int v;
		
	};
	int vn;      //顶点个数
	int en;      //边的个数
	int *layer;  //记录每个点到终点的距离

public:
	Dinic(); 
	bool countLayer(int s, int t);    //Dinic算法的分层
	int maxflow(int s, int t);        //Dinic算法
	~Dinic();
};

