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
	int vn;      //�������
	int en;      //�ߵĸ���
	int *layer;  //��¼ÿ���㵽�յ�ľ���

public:
	Dinic(); 
	bool countLayer(int s, int t);    //Dinic�㷨�ķֲ�
	int maxflow(int s, int t);        //Dinic�㷨
	~Dinic();
};

