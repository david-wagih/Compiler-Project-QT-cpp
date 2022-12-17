#pragma once
#include "scanner.h"

struct Node
{
	Token key;
	vector<Node*> child;
	Node* sibling;
};

Node* newNode(Token key);
Node* program(queue<Token>* q);
Node* stmt_seq(queue<Token>* q);
Node* statement(queue<Token>* q);
Node* if_stmt(queue<Token>* q);
Node* repeat_stmt(queue<Token>* q);
Node* assign_stmt(queue<Token>* q);
Node* read_stmt(queue<Token>* q);
Node* write_stmt(queue<Token>* q);
Node* exp(queue<Token>* q);
Node* simple_exp(queue<Token>* q);
Node* term(queue<Token>* q);
Node* factor(queue<Token>* q);
