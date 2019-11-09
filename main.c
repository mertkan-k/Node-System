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
	printf("15 Is In Node: %d, pointer: %d\n", NodeIsIn(headNode, 15), NodeFindByValue(headNode, 15));
	printf("35 Is In Node: %d, pointer: %d\n", NodeIsIn(headNode, 35), NodeFindByValue(headNode, 35));
	NodeClear(headNode);

	return 0;
}
