// ConsoleApplication27.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
//

#include "pch.h"
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
//연결리스트 테스트. 삽입,삭제,검색
typedef struct NODE {
	int data;
	struct NODE *link;
}NODE;

void AddNode(struct NODE *target, int data)
{
	struct NODE *newNode = (NODE *)malloc(sizeof(struct NODE));
	newNode->link = target->link;
	newNode->data = data;
	target->link = newNode;
}
void DeleteNode(struct NODE* target)
{
	struct NODE *remove = (NODE *)malloc(sizeof(struct NODE));
	remove = target->link;
	target->link = remove->link;

	free(remove);
}

struct NODE *findNode(struct NODE *node, int data)
{
	if (node == NULL)
		return NULL;

	struct NODE *temp = node->link;
	while (temp != NULL)
	{
		if (temp->data == data)
			return temp;

		temp = temp->link;
	}

	return NULL;
}
int main()
{
	NODE *head = (NODE*)malloc(sizeof(struct NODE));
    head->link = NULL;
	
	AddNode(head, 1);
	AddNode(head, 2);
	AddNode(head, 3);
	DeleteNode(head);
	
	struct NODE *temp = head->link;
	while (temp != NULL)
	{
		printf("%d\n", temp->data);
		temp = temp->link;
	}

	temp = head->link;
	while (temp != NULL)
	{
		struct NODE *link = temp->link;
		free(temp);
		temp = link;
	}
	
	free(head);

	return 0;
	
}

// 프로그램 실행: <Ctrl+F5> 또는 [디버그] > [디버깅하지 않고 시작] 메뉴
// 프로그램 디버그: <F5> 키 또는 [디버그] > [디버깅 시작] 메뉴

// 시작을 위한 팁: 
//   1. [솔루션 탐색기] 창을 사용하여 파일을 추가/관리합니다.
//   2. [팀 탐색기] 창을 사용하여 소스 제어에 연결합니다.
//   3. [출력] 창을 사용하여 빌드 출력 및 기타 메시지를 확인합니다.
//   4. [오류 목록] 창을 사용하여 오류를 봅니다.
//   5. [프로젝트] > [새 항목 추가]로 이동하여 새 코드 파일을 만들거나, [프로젝트] > [기존 항목 추가]로 이동하여 기존 코드 파일을 프로젝트에 추가합니다.
//   6. 나중에 이 프로젝트를 다시 열려면 [파일] > [열기] > [프로젝트]로 이동하고 .sln 파일을 선택합니다.
