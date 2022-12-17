#include "parser.h"

Node* newNode(Token key) {
	Node* temp = new Node;
	temp->key.type = key.type;
	temp->key.value = key.value;
	temp->sibling = nullptr;
	return temp;
}

Node* program(queue<Token>* q) {
	Token Program;
	Program.type = "program";
	Program.value = "program";
	Token error;
	error.type = "ERROR";
	error.value = "missing ;";

	Node* root = newNode(Program);
	Node* child = stmt_seq(q);
	if (child->key.type == "ERROR") root = child;
	else if (!q->empty()) root = newNode(error);
	else root->child.push_back(child);
	return root;
}

Node* stmt_seq(queue<Token>* q) {
	Node* temp;
	Node* sibling;

	temp = statement(q);

	Node* root = temp;
	if (temp->key.type != "ERROR") {
		while (!q->empty() && q->front().type == "SEMICOLON") {
			q->pop();
			sibling = statement(q);
			if (sibling->key.type == "ERROR") {
				root = sibling;
				break;
			}
			else {
				temp->sibling = sibling;
				temp = temp->sibling;
			}
		}
	}
	return root;
}

Node* statement(queue<Token>* q) {
	Node* root;
	Token error;
	error.type = "ERROR";
	error.value = "invalid statement";
	string type = q->front().type;

	if (type == "IF")				root = if_stmt(q);
	else if (type == "REPEAT")		root = repeat_stmt(q);
	else if (type == "IDENTIFIER")	root = assign_stmt(q);
	else if (type == "READ")		root = read_stmt(q);
	else if (type == "WRITE")		root = write_stmt(q);
	else							root = newNode(error);
	return root;
}

Node* if_stmt(queue<Token>* q) {
	Node* root = nullptr;
	Node* child;
	Token error;
	error.type = "ERROR";
	if (q->front().type == "IF") {
		root = newNode(q->front());
		q->pop();
		child = exp(q);
		if (child->key.type == "ERROR") root = child;
		else {
			root->child.push_back(child);
			if (q->front().type == "THEN") {
				q->pop();
				child = stmt_seq(q);
				if (child->key.type == "ERROR") root = child;
				else {
					root->child.push_back(child);
					if (q->front().type == "ELSE") {
						q->pop();
						child = stmt_seq(q);
						if (child->key.type == "ERROR") root = child;
						else root->child.push_back(stmt_seq(q));
					}
					if (q->front().type == "END") q->pop();
					else {
						error.value = "missing end in if-statement";
						root = newNode(error);
					}
				}
			}
			else {
				error.value = "missing then in if-statement";
				root = newNode(error);
			}
		}
	}
	return root;
}

Node* repeat_stmt(queue<Token>* q) {
	Node* root = nullptr;
	Node* child;
	Token error;
	error.value = "ERROR";
	if (q->front().type == "REPEAT") {
		root = newNode(q->front());
		q->pop();
		child = stmt_seq(q);
		if (child->key.type == "ERROR") root = child;
		else {
			root->child.push_back(child);

			if (q->front().type == "UNTIL") {
				q->pop();
				child = exp(q);
				if (child->key.type == "ERROR") root = child;
				else root->child.push_back(child);
			}
			else {
				error.value = "missing until in repeat-statement";
				root = newNode(error);
			}
		}
	}
	return root;
}
