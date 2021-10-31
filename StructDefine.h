#pragma once
#include<iostream>
#define MAXInt 32767   //最大值，无穷
#define MVNum 100       //最大的边数
#define TRUE 1
#define FALSE 0
using namespace std;

//图的邻接矩阵存储表示法
typedef int VerType;               //顶点为int型
typedef int ArcType;               //边的权值为int型
typedef struct {
	VerType vexs[MVNum];            //顶点型的顶点数组
	ArcType arcs[MVNum][MVNum];    //边型的边二维数组
	int vexsnum, arcsnum;
}AMGraph;                          //邻接矩阵结构体


AMGraph AMUDNGraphCreate(AMGraph& G);   //领接矩阵创建无向网
int AMlocate(AMGraph G,VerType v);     //返回某一个顶点在邻接矩阵G.vexs[MVNum](顶点数组)的下标，v为传入的顶点形参
void HigherOperation(AMGraph G);       //基础操作界面