#include <iostream>
#include"StructDefine.h"
using namespace std;


//返回顶点在图的邻接表中的位置
int ALGLocate(ALGraph& G, VerTexType &v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == v) {
			return i;
		}
	}
}

//[创建一个邻接表存储的图
ALGraph ALUDNGraphCreate(ALGraph& G) {  
	VerTexType v1, v2; OtherInfo weight;
	cout << "请输入图的顶点数和边数：";
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {                                                   //将顶点数据存储到顶点表中
		cout << "请输入第" << i + 1 << "个顶点："; 
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int j = 0; j < G.arcnum; j++) {
		cout << "请输入每一条边对应的两个顶点，以及边的权值："; cin >> v1 >> v2 >> weight;
		int m = ALGLocate(G, v1); int n = ALGLocate(G, v2);
		//ArcNode p,q;
		ArcNode* p = new ArcNode; ArcNode *q = new ArcNode;                                 //边节点p和边节点q，p是接在点v1后的边，q是接在点v2后的邻接边
		p->adjvex = n; q->adjvex = m;                                                       //边指向的顶点位置
		p->info = q->info = weight;                                                         //边的权值
		p->nextarc = G.vertices[m].firstarc; G.vertices[m].firstarc = p;                    //下一条边指向的点，类似于头插法
		q->nextarc = G.vertices[n].firstarc; G.vertices[n].firstarc = q;
	}
	return G;
}

void OutALGvexs(ALGraph G) {                                                                //顺序输出图的所有顶点
	cout << "图中顶点依次为：";
	for (int i = 0; i < G.vexnum; i++) {
		cout << G.vertices[i].data<< " ";
	}
}

void ALAdjVex(ALGraph G) {                                                                  //输出一个顶点的邻接点
	ArcType v; int i = 0;
	cout << "请输入需要查询的顶点："; cin >> v;
	while (i < G.vexnum) {                                          //找到第顶点是不是在图的邻接表矩阵中，如果在，i就是在顶点数组中的位置下标
		if (G.vertices[i].data == v) {
			break;
		}
		else { i++; }
	}
	Arcnode p; p = G.vertices[i].firstarc;
	while (p != NULL) {                                             //输出这个顶点的所有邻接点（逆序）
		cout << G.vertices[p->adjvex].data<<" ";
		p = p->nextarc;
	}
	
}
void ALGraphbasicPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       ALGraph BasicOpreation                          \n\n";
	cout << "1、创建一个用邻接表存储的无向网    2、返回一个图顶点在邻接表中的位置\n";
	cout << "3、输出图的所有顶点                4、输出一个顶点的邻接点\n 10、返回上一级            输入选择，输入0直接退出！\n";
	cout << "*********************************************************************\n";
}

void ALgraphBasicOperation( ) {
	ALGraph G;
	int chose = 0; VerTexType v;
	while (1) {
		ALGraphbasicPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n你的选择是：1、创建一个用领接矩阵存储的无向网\n";
			ALUDNGraphCreate(G);
			break;
		case 2:
			cout << "\n你的选择是：2、返回一个图顶点在邻接表中的位置\n";
			cout << "请输入你要查询的顶点："; cin >> v;
			cout<<"其在图中位置为："<<ALGLocate(G, v);
			break;
		case 3:
			cout << "\n你的选择是：3、输出图的所有顶点\n";
			OutALGvexs(G);
			break;
		case 4:
			cout << "你的选择是：4、输出一个顶点的邻接点\n";
			ALAdjVex(G);
			break;
		case 0:
			exit(0);
		default:
			break;
		}if (chose == 10) {
			break;
		}
	}
}
