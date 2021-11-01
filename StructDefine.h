#pragma once
#include<iostream>
#define MAXInt 32767    //最大值，无穷
#define MVNum 100       //最大的边数或者最大顶点数
#define TRUE 1
#define FALSE 0
using namespace std;

//图的邻接矩阵存储表示法
typedef int VerType;                //顶点为int型
typedef int ArcType;                //边的权值为int型
typedef struct {
	VerType vexs[MVNum];            //顶点型的顶点数组
	ArcType arcs[MVNum][MVNum];     //边型的边二维数组
	int vexsnum, arcsnum;           //顶点数和边数
}AMGraph;                           //邻接矩阵结构体


void AMgraphBasicOperation();                           //邻接矩阵存储基础操作界面
AMGraph AMUDNGraphCreate(AMGraph& G);                   //领接矩阵创建无向网
int AMlocate(AMGraph G,VerType v);                      //返回某一个顶点在邻接矩阵G.vexs[MVNum](顶点数组)的下标，v为传入的顶点形参
void AMGSearchArc(AMGraph G);                            //查询任意两个顶点之间是否有边，如过有边，则返回边的权值，如果没有，则提示不存在
void OutAMGvexs(AMGraph G);                         //顺序输出图的所有顶点 



//图的邻接表存储表示法
typedef int OtherInfo;                 
typedef int VerTexType;
typedef struct ArcNode{             //边节点
 	int adjvex;                     //这条边所指向的顶点的位置
	struct ArcNode* nextarc;        //指向下一条边的指针
	OtherInfo info;                 //边的权值信息
}ArcNode;

typedef struct VNode {              //顶点节点
	VerTexType data;                //顶点数据，如顶点3，顶点4
	ArcNode* firstarc;              //第一条边的地址
}Vnode,Adjlist[MVNum];

typedef struct {                    //邻接表
	Adjlist vertices;               //顶点结构体
	int vexnum, arcnum;             //边数和顶点数
}ALGraph;                           

void ALgraphBasicOperation();                        //邻接表基础操作    
ALGraph ALUDNGraphCreate(ALGraph& G);                //以邻接表的方式创建一个图
int ALGLocate(ALGraph& G, VerTexType& v);            //返回图顶点在邻接表当中的位置
void OutALGvexs(ALGraph G);                          //顺序输出图的所有顶点
        