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

ALGraph ALUDNGraphCreate(ALGraph& G) {
	VerTexType v1, v2; OtherInfo weight;
	cout << "请输入图的顶点数和边数：";
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		cout << "请输入第" << i + 1 << "个顶点："; 
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int j = 0; j < G.arcnum; j++) {
		cout << "请输入每一条边对应的两个顶点，以及边的权值："; cin >> v1 >> v2 >> weight;
		int m = ALGLocate(G, v1); int n = ALGLocate(G, v2);
		//ArcNode p,q;
		ArcNode *p = new ArcNode; ArcNode *q = new ArcNode;
		p.adjvex = m; q.adjvex = n;
		p.info = q.info = weight;
		p.nextarc = G.vertices[j].firstarc; G.vertices[j].firstarc = p;
	}
}

void ALGraphbasicPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       ALGraph BasicOpreation                          \n\n";
	cout << "1、创建一个用邻接表存储的无向网    2、返回一个图顶点在邻接表中的位置\n";
	cout << "3、暂定  4、返回上一级\n 输入选择，输入0直接退出！\n";
	cout << "*********************************************************************\n";
}

void ALgraphBasicOperation(ALGraph G) {
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
			cout << "\n你的选择是：2、\n";
			ALGLocate(G, v);
			break;
		case 3:
			cout << "\n你的选择是：3、\n";
			break;
		case 4:
			break;
		case 0:
			exit(0);
		default:
			break;
		}if (chose == 4) {
			break;
		}
	}
}
