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
	cout << "请输入边的数量："; cin >> G.arcsnum;                                        //顶点数量和边的数量
	for (int i = 0; i < G.vexsnum; i++) {
		cout << "请输入第"<<i+1<<"个顶点：";
		cin >> G.vexs[i];
	}                                                                                     //顶点依次保存在G.vexs[]中
	for (int i = 0; i < G.vexsnum; i++) {
		for (int j = 0; j < G.vexsnum; j++) {
			G.arcs[i][j] = MAXInt;                                                        //边的初始化，都设置为最大值
		}
	}
	for (int k = 1; k <= G.arcsnum; k++) {
		cout << "请输入任意一条边对应的两个顶点以及它的权重：";
		cin >> v1 >> v2 >> weight;
		v1 = AMlocate(G, v1); v2 = AMlocate(G, v2);
	 	G.arcs[v1][v2] = weight; G.arcs[v2][v1] = G.arcs[v1][v2];                          //设置每一条边以及其邻接顶点的权重
	}
	return G;
}
//邻接表法创建无向网


void AMGraphbasicPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       AMGraph BasicOpreation                          \n\n";
	cout << "1、创建一个用领接矩阵存储的无向网    2、返回一个图顶点在邻接矩阵中的位置\n";
	cout << "3、暂定  4、返回上一级\n 输入选择，输入0直接退出！\n";
	cout << "*********************************************************************\n";
}

void AMgraphBasicOperation(AMGraph G, VerType v) {
	int chose = 0;
	while (1) {
		AMGraphbasicPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n你的选择是：1、创建一个用领接矩阵存储的无向网\n";
			AMUDNGraphCreate(G);
			break;
		case 2:
			cout << "\n你的选择是：2、\n";
			AMlocate(G, v);
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
