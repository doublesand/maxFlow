#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class EdmondsKarp
{
	int **C;     //容量图
	int **F;     //残存图
	int vn;      //顶点个数
	int en;      //边的个数
public:
	EdmondsKarp();              //自己读入数据
	EdmondsKarp(string path);   //从文件中读入数据
	int maxflow(int s, int t);  //查找s到t的最大流
	int maxflow();              //默认最大流
	int path(int s, int t);     //查找s到t的增广路径
	~EdmondsKarp();             //销毁动态内存
};

