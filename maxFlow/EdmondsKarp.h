#pragma once

#include <iostream>
#include <fstream>
#include <string>
#include <queue>

using namespace std;

class EdmondsKarp
{
	int **C;     //����ͼ
	int **F;     //�д�ͼ
	int vn;      //�������
	int en;      //�ߵĸ���
public:
	EdmondsKarp();              //�Լ���������
	EdmondsKarp(string path);   //���ļ��ж�������
	int maxflow(int s, int t);  //����s��t�������
	int maxflow();              //Ĭ�������
	int path(int s, int t);     //����s��t������·��
	~EdmondsKarp();             //���ٶ�̬�ڴ�
};

