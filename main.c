#include "main.h"
#include "node.h"

int main(int argc, char const *argv[]) {
	NodeP headNode = NodeCreate();

	NodePush(headNode, 5);
	NodePush(headNode, 15);
	NodePush(headNode, 25);
	printf("Node Size: %d\n", NodeGetSize(headNode));
	printf("Node 0 Value: %d\n", NodeGetValueByIndex(headNode, 0));
	printf("Node 1 Value: %d\n", NodeGetValueByIndex(headNode, 1));
	printf("Node 2 Value: %d\n", NodeGetValueByIndex(headNode, 2));
	printf("Node 3 Value: %d\n", NodeGetValueByIndex(headNode, 3));
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
	printf("25 Is In Node: %d\n", NodeIsIn(headNode, 25));
	printf("25 Is Removed From Node: %d\n", NodeRemoveByValue(headNode, 25));
	printf("Node Size: %d\n", NodeGetSize(headNode));
	NodeClear(headNode);

	return 0;
}
