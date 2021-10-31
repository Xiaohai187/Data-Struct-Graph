#pragma once
#include<iostream>
#define MAXInt 32767    //���ֵ������
#define MVNum 100       //���ı���������󶥵���
#define TRUE 1
#define FALSE 0
using namespace std;

//ͼ���ڽӾ���洢��ʾ��
typedef int VerType;                //����Ϊint��
typedef int ArcType;                //�ߵ�ȨֵΪint��
typedef struct {
	VerType vexs[MVNum];            //�����͵Ķ�������
	ArcType arcs[MVNum][MVNum];     //���͵ı߶�ά����
	int vexsnum, arcsnum;
}AMGraph;                           //�ڽӾ���ṹ��


AMGraph AMUDNGraphCreate(AMGraph& G);                   //��Ӿ��󴴽�������
int AMlocate(AMGraph G,VerType v);                      //����ĳһ���������ڽӾ���G.vexs[MVNum](��������)���±꣬vΪ����Ķ����β�
void AMgraphBasicOperation(AMGraph G, VerType v);       //������������



//ͼ���ڽӱ�洢��ʾ��
typedef int OtherInfo;                 
typedef int VerTexType;
typedef struct ArcNode{             //�߽ڵ�
 	int adjvex;                     //��������ָ��Ķ����λ��
	struct ArcNode* nextarc;        //ָ����һ���ߵ�ָ��
	OtherInfo info;                 //�ߵ�Ȩֵ��Ϣ
}ArcNode;

typedef struct VNode {              //����ڵ�
	VerTexType data;                //�������ݣ��綥��3������4
	ArcNode* firstarc;              //��һ���ߵĵ�ַ
}Vnode,Adjlist[MVNum];

typedef struct {                    //�ڽӱ�
	Adjlist vertices;               //����ṹ��
	int vexnum, arcnum;             //�����Ͷ�����
}ALGraph;                           