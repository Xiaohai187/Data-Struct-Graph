#include <iostream>
#include"StructDefine.h"
using namespace std;


//���ض�����ͼ���ڽӱ��е�λ��
int ALGLocate(ALGraph& G, VerTexType &v) {
	for (int i = 0; i < G.vexnum; i++) {
		if (G.vertices[i].data == v) {
			return i;
		}
	}
}

ALGraph ALUDNGraphCreate(ALGraph& G) {
	VerTexType v1, v2; OtherInfo weight;
	cout << "������ͼ�Ķ������ͱ�����";
	cin >> G.vexnum >> G.arcnum;
	for (int i = 0; i < G.vexnum; i++) {
		cout << "�������" << i + 1 << "�����㣺"; 
		cin >> G.vertices[i].data;
		G.vertices[i].firstarc = NULL;
	}
	for (int j = 0; j < G.arcnum; j++) {
		cout << "������ÿһ���߶�Ӧ���������㣬�Լ��ߵ�Ȩֵ��"; cin >> v1 >> v2 >> weight;
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
	cout << "1������һ�����ڽӱ�洢��������    2������һ��ͼ�������ڽӱ��е�λ��\n";
	cout << "3���ݶ�  4��������һ��\n ����ѡ������0ֱ���˳���\n";
	cout << "*********************************************************************\n";
}

void ALgraphBasicOperation(ALGraph G) {
	int chose = 0; VerTexType v;
	while (1) {
		ALGraphbasicPerface();
		cin >> chose;
		switch (chose) {
		case 1:
			cout << "\n���ѡ���ǣ�1������һ������Ӿ���洢��������\n";
			ALUDNGraphCreate(G);
			break;
		case 2:
			cout << "\n���ѡ���ǣ�2��\n";
			ALGLocate(G, v);
			break;
		case 3:
			cout << "\n���ѡ���ǣ�3��\n";
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
