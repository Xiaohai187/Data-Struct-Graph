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
	int vexsnum, arcsnum;           //�������ͱ���
}AMGraph;                           //�ڽӾ���ṹ��


void AMgraphBasicOperation();                           //�ڽӾ���洢������������
AMGraph AMUDNGraphCreate(AMGraph& G);                   //��Ӿ��󴴽�������
int AMlocate(AMGraph G,VerType v);                      //����ĳһ���������ڽӾ���G.vexs[MVNum](��������)���±꣬vΪ����Ķ����β�
void AMGSearchArc(AMGraph G);                            //��ѯ������������֮���Ƿ��бߣ�����бߣ��򷵻رߵ�Ȩֵ�����û�У�����ʾ������
void OutAMGvexs(AMGraph G);                         //˳�����ͼ�����ж��� 



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

void ALgraphBasicOperation();                        //�ڽӱ��������    
ALGraph ALUDNGraphCreate(ALGraph& G);                //���ڽӱ�ķ�ʽ����һ��ͼ
int ALGLocate(ALGraph& G, VerTexType& v);            //����ͼ�������ڽӱ��е�λ��
void OutALGvexs(ALGraph G);                          //˳�����ͼ�����ж���
        