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

	int vn;      //�������
	int en;      //�ߵĸ���
	int *layer;  //��¼ÿ���㵽�յ�ľ���

public:
	Dinic(); 
	Dinic(string path);
	bool countLayer(int s, int t);    //Dinic�㷨�ķֲ�
	int maxflow(int s, int t);        //Dinic�㷨
	~Dinic();
};

