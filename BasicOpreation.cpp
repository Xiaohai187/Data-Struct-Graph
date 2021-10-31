#include <iostream>
#include"StructDefine.h"
using namespace std;


//��ͼ���ڽӾ���洢�з��ض�����ͼ�е�λ��
int AMlocate(AMGraph G, VerType v) {
	for (int i = 0; i < G.vexsnum; i++) {
		if (G.vexs[i] == v) {
			return i;
		}
	}
}


//��Ӿ��󴴽�������
AMGraph AMUDNGraphCreate(AMGraph& G) {
	VerType v1, v2; ArcType weight;                                                       //����v1,v2
	cout << "�����붥�������"; cin >> G.vexsnum; cout <<"���������" << G.vexsnum<<endl;
	cout << "������ߵ�������"; cin >> G.arcsnum;
	for (int i = 0; i < G.vexsnum; i++) {
		cout << "�������"<<i+1<<"�����㣺";
		cin >> G.vexs[i];
	}
	for (int i = 0; i < G.vexsnum; i++) {
		for (int j = 0; j < G.vexsnum; j++) {
			G.arcs[i][j] = MAXInt;
		}
	}
	for (int k = 1; k <= G.arcsnum; k++) {
		cout << "����������һ���߶�Ӧ�����������Լ�����Ȩ�أ�";
		cin >> v1 >> v2 >> weight;
		v1 = AMlocate(G, v1); v2 = AMlocate(G, v2);
		G.arcs[v1][v2] = weight; G.arcs[v2][v1] = G.arcs[v1][v2];
	}
	return G;
}


void HigherPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                         Graph BasicOpreation                          \n\n";
	cout << "1������һ������Ӿ���洢��������    2���ݶ�   3���ݶ�  4��������һ��\n ����ѡ������0ֱ���˳���\n";
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
			cout << "\n���ѡ���ǣ�1������һ������Ӿ���洢��������\n";
			AMUDNGraphCreate(G);
			break;
		case 2:
			cout << "\n���ѡ���ǣ�2��\n";
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
