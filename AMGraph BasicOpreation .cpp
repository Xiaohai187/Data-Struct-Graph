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

void OutAMGvexs(AMGraph G) {    //顺序输出图的所有顶点 
	cout << "图中顶点依次为：";                                                           
	for (int i = 0; i < G.vexsnum; i++) {
		cout << G.vexs[i] << " ";
	}
}

void AMAdjVex(AMGraph G) {       //输出一个顶点的邻接点
	ArcType v; int i = 0,j = 0;
	cout << "请输入需要查询的顶点："; cin >> v;
	while (i < G.vexsnum) {                                          //找到第一个顶点是不是在图的邻接表矩阵中，如果在，i就是在顶点数组中的位置下标
		if (G.vexs[i] == v) {
			break;
		}
		else { i++; }
	}
	if (i >= G.vexsnum) {
		cout << v << "顶点不存在!";                                 //遍历结束都没有找到，就是没有
	}
	while (j < G.vexsnum) {
		if (G.arcs[i][j]!=MAXInt) {
			cout << G.vexs[j]<<" ";
			j++;
		}
		else { j++; }
	}
}

void AMGSearchArc(AMGraph G) {  //查询任意两个顶点之间是否有边，如过有边，则返回边的权值，如果没有，则提示不存在
	ArcType v1, v2; int i=0, j = 0;
	cout << "请输入需要查询的两个顶点："; cin >> v1 >> v2;
	while (i < G.vexsnum) {                                          //找到第一个顶点是不是在图的邻接表矩阵中，如果在，i就是在顶点数组中的位置下标
		if (G.vexs[i] == v1) {
			break;
		}
		else { i++; }
	}
	if (i >= G.vexsnum) {
		cout << v1 << "顶点不存在!";                                 //遍历结束都没有找到，就是没有
	}
	while (j < G.vexsnum) {                                          //对第二个顶点做同样的操作，找到第二个节点的位置
		if (G.vexs[j] == v2) {
			break;
		}
		else { j++; }
	}
	if (j >= G.vexsnum) {
		cout << v2 << "顶点不存在!";
	}
	if (G.arcs[i][j] != MAXInt) {                                    //如果边矩阵中对应边权值不是最大，即存在，输出权值
		cout << v1 << "和" << v2 << "之间边的权值为" << G.arcs[i][j];
	}
	else {
		cout << "边不存在！";
	}
}


void AMGraphbasicPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       AMGraph BasicOpreation                          \n\n";
	cout << "1、创建一个用领接矩阵存储的无向网    2、返回一个图顶点在邻接矩阵中的位置\n";
	cout << "3、顺序输出图的所有顶点              4、查询任意两条顶点之间是否存在边\n"; 
	cout << "5、查询一个顶点的邻接顶点            10、返回上一级\n输入选择，输入0直接退出！\n";
	cout << "*********************************************************************\n";
}

void AMgraphBasicOperation(){
	AMGraph G; VerType v=0;
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
			cout << "请输入你要查询的顶点："; cin >> v;
			cout << "其在图中位置为："<<AMlocate(G, v);
			break;
		case 3:
			cout << "\n你的选择是：3、顺序输出图的所有顶点\n";
			OutAMGvexs(G);
			break;
		case 4:
			cout << "\n你的选择是：4、查询任意两条顶点之间是否存在边\n";
			AMGSearchArc(G);
			break;
		case 5:
			cout << "\n你的选择是：5、查询一个顶点的邻接顶点\n";
			AMAdjVex(G);
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
