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
	cout << "������ߵ�������"; cin >> G.arcsnum;                                        //���������ͱߵ�����
	for (int i = 0; i < G.vexsnum; i++) {
		cout << "�������"<<i+1<<"�����㣺";
		cin >> G.vexs[i];
	}                                                                                     //�������α�����G.vexs[]��
	for (int i = 0; i < G.vexsnum; i++) {
		for (int j = 0; j < G.vexsnum; j++) {
			G.arcs[i][j] = MAXInt;                                                        //�ߵĳ�ʼ����������Ϊ���ֵ
		}
	}
	for (int k = 1; k <= G.arcsnum; k++) {
		cout << "����������һ���߶�Ӧ�����������Լ�����Ȩ�أ�";
		cin >> v1 >> v2 >> weight;
		v1 = AMlocate(G, v1); v2 = AMlocate(G, v2);
	 	G.arcs[v1][v2] = weight; G.arcs[v2][v1] = G.arcs[v1][v2];                          //����ÿһ�����Լ����ڽӶ����Ȩ��
	}
	return G;
}

void OutAMGvexs(AMGraph G) {    //˳�����ͼ�����ж��� 
	cout << "ͼ�ж�������Ϊ��";                                                           
	for (int i = 0; i < G.vexsnum; i++) {
		cout << G.vexs[i] << " ";
	}
}

void AMAdjVex(AMGraph G) {       //���һ��������ڽӵ�
	ArcType v; int i = 0,j = 0;
	cout << "��������Ҫ��ѯ�Ķ��㣺"; cin >> v;
	while (i < G.vexsnum) {                                          //�ҵ���һ�������ǲ�����ͼ���ڽӱ�����У�����ڣ�i�����ڶ��������е�λ���±�
		if (G.vexs[i] == v) {
			break;
		}
		else { i++; }
	}
	if (i >= G.vexsnum) {
		cout << v << "���㲻����!";                                 //����������û���ҵ�������û��
	}
	while (j < G.vexsnum) {
		if (G.arcs[i][j]!=MAXInt) {
			cout << G.vexs[j]<<" ";
			j++;
		}
		else { j++; }
	}
}

void AMGSearchArc(AMGraph G) {  //��ѯ������������֮���Ƿ��бߣ�����бߣ��򷵻رߵ�Ȩֵ�����û�У�����ʾ������
	ArcType v1, v2; int i=0, j = 0;
	cout << "��������Ҫ��ѯ���������㣺"; cin >> v1 >> v2;
	while (i < G.vexsnum) {                                          //�ҵ���һ�������ǲ�����ͼ���ڽӱ�����У�����ڣ�i�����ڶ��������е�λ���±�
		if (G.vexs[i] == v1) {
			break;
		}
		else { i++; }
	}
	if (i >= G.vexsnum) {
		cout << v1 << "���㲻����!";                                 //����������û���ҵ�������û��
	}
	while (j < G.vexsnum) {                                          //�Եڶ���������ͬ���Ĳ������ҵ��ڶ����ڵ��λ��
		if (G.vexs[j] == v2) {
			break;
		}
		else { j++; }
	}
	if (j >= G.vexsnum) {
		cout << v2 << "���㲻����!";
	}
	if (G.arcs[i][j] != MAXInt) {                                    //����߾����ж�Ӧ��Ȩֵ������󣬼����ڣ����Ȩֵ
		cout << v1 << "��" << v2 << "֮��ߵ�ȨֵΪ" << G.arcs[i][j];
	}
	else {
		cout << "�߲����ڣ�";
	}
}


void AMGraphbasicPerface() {
	cout << "\n*********************************************************************\n";
	cout << "                       AMGraph BasicOpreation                          \n\n";
	cout << "1������һ������Ӿ���洢��������    2������һ��ͼ�������ڽӾ����е�λ��\n";
	cout << "3��˳�����ͼ�����ж���              4����ѯ������������֮���Ƿ���ڱ�\n"; 
	cout << "5����ѯһ��������ڽӶ���            10��������һ��\n����ѡ������0ֱ���˳���\n";
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
			cout << "\n���ѡ���ǣ�1������һ������Ӿ���洢��������\n";
			AMUDNGraphCreate(G);
			break;
		case 2:
			cout << "��������Ҫ��ѯ�Ķ��㣺"; cin >> v;
			cout << "����ͼ��λ��Ϊ��"<<AMlocate(G, v);
			break;
		case 3:
			cout << "\n���ѡ���ǣ�3��˳�����ͼ�����ж���\n";
			OutAMGvexs(G);
			break;
		case 4:
			cout << "\n���ѡ���ǣ�4����ѯ������������֮���Ƿ���ڱ�\n";
			AMGSearchArc(G);
			break;
		case 5:
			cout << "\n���ѡ���ǣ�5����ѯһ��������ڽӶ���\n";
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
