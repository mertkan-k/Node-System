#ifndef _NODE_H_
#define _NODE_H_

#include "main.h"

typedef int NodeValue;

typedef struct Node
{
	NodeValue value;
	struct Node *next;
} Node;

typedef struct Node *NodeP;

/**
 * HeadNode nin degeri ozellikle verilmediyse bos tutuluyor.
 */

NodeP NodeCreate();
NodeP NodeCreateWithValue(NodeValue value);
NodeP NodeGetLast(NodeP headNode);
NodeP NodeExpand(NodeP headNode);
void NodePush(NodeP headNode, NodeValue value);
NodeP NodeGetByIndex(NodeP headNode, size_t index);
NodeValue NodeGetValueByIndex(NodeP headNode, size_t index);
size_t NodeGetSize(NodeP headNode);
bool NodeIsIn(NodeP headNode, NodeValue value);
NodeP NodeFindByValue(NodeP headNode, NodeValue value);
void NodeClear(NodeP headNode);
bool NodeRemoveByValue(NodeP headNode, NodeValue value);
void NodeMakeRecursive(NodeP headNode);

#endif