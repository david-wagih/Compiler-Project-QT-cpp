#include "parser.h"

Node* newNode(Token key) {
    Node* temp = new Node;
    temp->key.type = key.type;
    temp->key.value = key.value;
    temp->sibling = nullptr;
    return temp;
}

Node* parse(queue<Token>* q) {
    //recursive-descent parsing algorithm
    return program(q);
}

Node* program(queue<Token>* q) {
    Token program;
    program.type = "PROGRAM";
    program.value = "program";
    Token error;
    error.type = "ERROR";
    error.value = "missing ;";

    Node* root = newNode(program);
    Node* child = stmt_seq(q);
    if (child->key.type == "ERROR")		root = child;
    else if (!q->empty())				root = newNode(error);
    else								root->child.push_back(child);
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

    string type = q->empty() ? "" : q->front().type;
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
            if (!q->empty() && q->front().type == "THEN") {
                q->pop();
                child = stmt_seq(q);
                if (child->key.type == "ERROR") root = child;
                else {
                    root->child.push_back(child);
                    if (!q->empty() && q->front().type == "ELSE") {
                        q->pop();
                        child = stmt_seq(q);
                        if (child->key.type == "ERROR") root = child;
                        else							root->child.push_back(child);
                    }
                    if (!q->empty() && q->front().type == "END") q->pop();
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

            if (!q->empty() && q->front().type == "UNTIL") {
                q->pop();
                child = exp(q);
                if (child->key.type == "ERROR") root = child;
                else							root->child.push_back(child);
            }
            else {
                error.value = "missing until in repeat-statement";
                root = newNode(error);
            }
        }
    }
    return root;
}

Node* assign_stmt(queue<Token>* q) {
    Node* root = nullptr;
    Node* child;
    Token assign, error;
    error.type = "ERROR";
    if (q->front().type == "IDENTIFIER") {
        assign.value = q->front().value;
        q->pop();
        if (!q->empty() && q->front().type == "ASSIGN") {
            assign.type = "assign";
            q->pop();
            root = newNode(assign);
            child = exp(q);
            if (child->key.type == "ERROR") root = child;
            else							root->child.push_back(child);
        }
        else {
            error.type = "invalid assign syntax";
            root = newNode(error);
        }
    }
    return root;
}

Node* read_stmt(queue<Token>* q) {
    Node* root = nullptr;
    Token read, error;
    error.type = "ERROR";
    if (q->front().type == "READ") {
        read.type = "read";
        q->pop();
        if (!q->empty() && q->front().type == "IDENTIFIER") {
            read.value = q->front().value;
            q->pop();
            root = newNode(read);
        }
        else {
            error.value = "invalid read syntax";
            root = newNode(error);
        }
    }
    return root;
}

Node* write_stmt(queue<Token>* q) {
    Node* root = nullptr;
    Node* child;
    if (q->front().type == "WRITE") {
        root = newNode(q->front());
        q->pop();
        child = exp(q);
        if (child->key.type == "ERROR") root = child;
        else							root->child.push_back(child);
    }
    return root;
}

Node* exp(queue<Token>* q) {
    Node* simple_1 = simple_exp(q);
    Node* op = simple_1;
    if (simple_1->key.type != "ERROR") {
        if (!q->empty() && (q->front().value == "<" || q->front().value == "=")) {
            Token comparison_op;
            comparison_op.type = "op";
            comparison_op.value = q->front().value;
            op = newNode(comparison_op);
            q->pop();
            Node* simple_2 = simple_exp(q);
            op->child.push_back(simple_1);
            if (simple_2->key.type == "ERROR")	op = simple_2;
            else								op->child.push_back(simple_2);
        }
    }
    return op;
}

Node* simple_exp(queue<Token>* q) {
    Node* term_1 = term(q);
    if (term_1->key.type != "ERROR") {
        while (!q->empty() && (q->front().value == "+" || q->front().value == "-")) {
            Token add_op;
            add_op.type = "op";
            add_op.value = q->front().value;
            Node* add_op_node = newNode(add_op);
            q->pop();
            Node* term_2 = term(q);
            add_op_node->child.push_back(term_1);
            if (term_2->key.type == "ERROR") {
                term_1 = term_2;
                break;
            }
            else {
                add_op_node->child.push_back(term_2);
                term_1 = add_op_node;
            }
        }
    }
    return term_1;
}

Node* term(queue<Token>* q) {
    Node* root = nullptr;
    Node* left;
    Node* right;
    Token mulop;
    root = factor(q);
    if (root->key.type != "ERROR") {
        while (!q->empty() && (q->front().value == "*" || q->front().value == "/")) {
            left = root;
            mulop.type = "op";
            mulop.value = q->front().value;
            root = newNode(mulop);
            root->child.push_back(left);
            q->pop();
            right = factor(q);
            if (right->key.type == "ERROR") {
                root = right;
                break;
            }
            else root->child.push_back(right);
        }
    }
    return root;
}

Node* factor(queue<Token>* q) {
    Node* root = nullptr;
    Token temp, error;
    error.type = "ERROR";
    if (q->empty()) {
        error.value = "invalid syntax";
        root = newNode(error);
    }
    else if (q->front().type == "OPENBRACKET") {
        q->pop();
        root = exp(q);
        if (!q->empty() && q->front().type == "CLOSEDBRACKET") q->pop();
        else {
            error.value = "missing closed bracket";
            root = newNode(error);
        }
    }
    else if (q->front().type == "NUMBER") {
        temp.type = "const";
        temp.value = q->front().value;
        root = newNode(temp);
        q->pop();
    }
    else if (q->front().type == "IDENTIFIER") {
        temp.type = "id";
        temp.value = q->front().value;
        root = newNode(temp);
        q->pop();
    }
    else {
        error.value = "invalid syntax";
        root = newNode(error);
    }
    return root;
}
