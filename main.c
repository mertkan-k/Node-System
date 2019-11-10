#include "main.h"
#include "node.h"

int main(int argc, char const *argv[]) {
	NodeP headNode = NodeCreate();

	NodePush(headNode, 5);
	NodePush(headNode, 15);
	NodePush(headNode, 25);
	NodePushFront(headNode, 1);
	printf("Node Size: %d\n", NodeGetSize(headNode));
	NodePrint(headNode);
	NodeMakeReverse(headNode);
	NodePrint(headNode);
	printf("Node Last Value: %d\n", NodeGetLast(headNode)->value);
	printf("15 Is In Node: %d\n", NodeIsIn(headNode, 15));
	printf("25 Is In Node: %d\n", NodeIsIn(headNode, 25));
	printf("35 Is In Node: %d\n", NodeIsIn(headNode, 35));
	printf("35 Is Removed From Node: %d\n", NodeRemoveByValue(headNode, 35));
	printf("5 Is Removed From Node: %d\n", NodeRemoveByValue(headNode, 5));
	printf("Node Size: %d\n", NodeGetSize(headNode));
	printf("15 Is Removed From Node: %d\n", NodeRemoveByValue(headNode, 15));
	printf("15 Is In Node: %d\n", NodeIsIn(headNode, 15));
	printf("Node Size: %d\n", NodeGetSize(headNode));

	NodeP headNode2 = NodeCreate();
	NodePush(headNode2, 5);
	NodeConnect(headNode, headNode2);
	printf("Node Size: %d\n", NodeGetSize(headNode));

	NodeClear(headNode);

	return 0;
}
