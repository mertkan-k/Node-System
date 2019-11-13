#include "node.h"

void NodePrint(NodeP headNode){
	while (headNode != NULL)
	{
		printf("%d, ", headNode->value);
		headNode = headNode->next;
	}
	printf("\n");
}

/**
 * Sadece bellekten yer ayarliyor.
 */
NodeP NodeCreate(){
	NodeP headNood;
	headNood = (NodeP) malloc(sizeof(Node));

	headNood->next = NULL;
	return headNood;
}

/**
 * Bellekten yer ayarlayip deger veriyor.
 */
NodeP NodeCreateWithValue(NodeValue value){
	NodeP tempNode = NodeCreate();
	tempNode->value = value;

	return tempNode;
}

/**
 * next'i Null olana kadar tarar ve onu dondurur.
 */
NodeP NodeGetLast(NodeP headNode){
	while (headNode->next != NULL)
		headNode = headNode->next;

	return headNode;
}

/**
 * Bellekten yer ayarlayip gelen node'ye ekler ve yeni nodenin p sini dondurur.
 */
NodeP NodeExpand(NodeP headNode){
	return (NodeGetLast(headNode)->next = NodeCreate());
}

/**
 * Simdilik kullanilmiyor
 */
NodeP NodeExpandFront(NodeP *headNode){
	NodeP expandedNode = NodeCreate();

	expandedNode->next = *headNode;
	*headNode = expandedNode;

	return expandedNode;
}

/**
 * Genisletiyor ve degeri atiyor.
 */
void NodePush(NodeP headNode, NodeValue value){
	NodeExpand(headNode)->value = value;
}

void NodePushFront(NodeP headNode, NodeValue value){
	// NodeExpandFront(headNode)->next->value = value;

	NodeP expandedNode = NodeCreateWithValue(value);

	expandedNode->next = headNode->next;
	headNode->next = expandedNode;
}

/**
 * Indexleme 0 dan baslar ama 0 in degeri verilmiyor!
 * Indexe kadar gidemezse sonuncuyu basar.
 */
NodeP NodeGetByIndex(NodeP headNode, size_t index){
	size_t i = 0;

	while (headNode->next != NULL){
		if (i++ == index)
			break;

		headNode = headNode->next;
	}

	return headNode;
}

NodeValue NodeGetValueByIndex(NodeP headNode, size_t index){
	return NodeGetByIndex(headNode, index)->value;
}

/**
 * Gelenden itibaren sayar.
 */
size_t NodeGetSize(NodeP headNode){
	size_t i = 0;

	while (headNode->next != NULL){
		i++;
		headNode = headNode->next;
	}

	return i;
}

bool NodeIsIn(NodeP headNode, NodeValue value){
	return NodeFindByValue(headNode, value) != NULL;
}

NodeP NodeFindByValue(NodeP headNode, NodeValue value){
	while (headNode != NULL)
	{
		if (headNode->value == value)
			return headNode;

		headNode = headNode->next;
	}

	return NULL;
}

/**
 * Gelenden itibaren baslar.
 */
void NodeClear(NodeP headNode){
	NodeP deletingNode = headNode;

	while (headNode != NULL)
	{
		headNode = headNode->next;
		free(deletingNode);
	}
}

/**
 * Gelenden itibaren baslar.
 */
bool NodeRemoveByValue(NodeP headNode, NodeValue value){
	NodeP prevNode = NULL;

	while (headNode != NULL)
	{
		if (headNode->value == value){
			prevNode->next = headNode->next;
			free(headNode);

			return true;
		}

		prevNode = headNode;
		headNode = headNode->next;
	}

	return false;
}

/**
 *         (node)<-(node)<-(node)
 *            |              |
 * (head)->(node)->(node)->(node)
 */
void NodeMakeRecursive(NodeP headNode){
	if (headNode->next == NULL)
		return;

	NodeGetLast(headNode)->next = headNode->next;
}

void NodeConnect(NodeP fNode, NodeP sNode){
	NodeGetLast(fNode)->next = sNode->next;
	free(sNode);
}

/**
 * Take a coffee before look
 */
void NodeMakeReverse(NodeP headNode){
	NodeP prevNode = NULL;
	NodeP tempNode = headNode->next;
	NodeP nextNode;

	while (tempNode != NULL)
	{
		nextNode = tempNode->next;
		tempNode->next = prevNode;

		prevNode = tempNode;
		tempNode = nextNode;
	}

	headNode->next = prevNode;
}

