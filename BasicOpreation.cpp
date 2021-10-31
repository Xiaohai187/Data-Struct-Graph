#include <iostream>
#include"StructDefine.h"
using namespace std;


//在图的邻接矩阵存储中返回顶点在图中的位置
int AMlocate(AMGraph G, VerType v) {
	for (int i = 0; i < G.vexsnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
}


//领接矩阵创建无向网
AMGraph AMUDNGraphCreate(AMGraph& G) {
	VerType v1, v2; ArcType weight;                                                       //顶点v1,v2
	cout << "请输入顶点个数："; cin >> G.vexsnum; cout <<"顶点个数：" << G.vexsnum<<endl;
	cout << "请输入边的数量："; cin >> G.arcsnum;
	for (int i = 0; i < G.vexsnum; i++) {
		cout << "请输入第"<<i+1<<"个顶点：";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexsnum; i++) {
		for (int j = 0; j < G.vexsnum; j++) {
			G.arcs[i][j] = MAXInt;
		}
	}
	for (int k = 1; k <= G.arcsnum; k++) {
		cout << "请输入任意一条边对应的两个顶点以及它的权重：";
		cin >> v1 >> v2 >> weight;
		v1 = AMlocate(G, v1); v2 = AMlocate(G, v2);
		G.arcs[v1][v2] = weight; G.arcs[v2][v1] = G.arcs[v1][v2];
	}
	return G;
}


void HigherPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                         Graph BasicOpreation                          \n\n";
	cout << "1、创建一个用领接矩阵存储的无向网    2、暂定   3、暂定  4、返回上一级\n 输入选择，输入0直接退出！\n";
	cout << "*********************************************************************\n";
}

void HigherOperation(AMGraph G) {
	//HTtree HT;
	int chose = 0;
	while (1) {
		HigherPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n你的选择是：1、创建一个用领接矩阵存储的无向网\n";
			AMUDNGraphCreate(G);
			break;
		case 2:
			cout << "\n你的选择是：2、\n";
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
