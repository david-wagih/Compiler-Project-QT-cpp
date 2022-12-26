#include "gui.h"

gui::gui(QWidget* parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
}

gui::~gui()
{}

int counter;

int gui::draw_node(Node* node, string& str, int id)
{
    int edge;
    if (node->key.type == "read" || node->key.type == "assign") {
        str += "node[shape = rect label=\"" + node->key.type + "\n(" + node->key.value + ")\"]id" + to_string(id) + " ";
    }
    else if (node->key.type == "IF" || node->key.type == "WRITE" || node->key.type == "REPEAT") {
        str += "node[shape = rect label=\"" + node->key.value + "\"]id" + to_string(id) + " ";
    }
    else {
        str += "node[shape = oval label=\"" + node->key.type + "\n(" + node->key.value + ")\"]id" + to_string(id) + " ";
    }

    // this one here draws edge between the node and its children
    for (int i = 0; i < (int)node->child.size(); i++) {
        counter++;
        edge = draw_node(node->child[i], str, counter);
        str += "id" + to_string(id) + "--id" + to_string(edge) + " ";
        node->child[i]->key.id = edge;
    }

    // in this one, draw the children for the IF and check if it has siblings then draw them as well with invisible edges
    if (node->key.type == "IF") {
        Node* temp, * temp2;
        for (int i = 0; i < (int)node->child.size() - 1; i++) {
            if (node->child[i]->sibling != nullptr) {
                temp = node->child[i]->sibling;
                temp2 = node->child[i + 1];
                str += "{rank = same; id" + to_string(temp->key.id) + "; id" + to_string(temp2->key.id) + "; }" + " id" + to_string(temp->key.id) + "--id" + to_string(temp2->key.id) + " [style = invis]; ";
            }
        }
    }

    // if node children > 1 && the node has no siblings >> ????? [operators??]
    for (int i = 0; i < (int)node->child.size() - 1; i++) {
        Node* temp, * temp2;
        if (node->child.size() != 1 && node->child.size() != 0 && node->sibling == nullptr) {
            temp = node->child[i];
            temp2 = node->child[i + 1];
            str += "{rank = same; id" + to_string(temp->key.id) + "; id" + to_string(temp2->key.id) + "; }" + " id" + to_string(temp->key.id) + "--id" + to_string(temp2->key.id) + " [style = invis]; ";
        }
    }

    // if the node itself has siblings then it draws edges between the siblings as normal
    if (node->sibling != nullptr) {
        counter++;
        edge = draw_node(node->sibling, str, counter);
        str += "{rank = same; id" + to_string(id) + "; id" + to_string(edge) + "; }" + " id" + to_string(id) + "--id" + to_string(edge) + " ";
        node->sibling->key.id = edge;
    }

    return id;
}

void gui::generate_syntax_tree(Node* tree)
{
    // will use draw_node to convert from Node into dot language and pass the Node tree to it
    // then we will use the string that we referenced in the draw_node function
    // use the library functions to convert this string to picture
    // then set the Label in the GUI to take the picture inside.

    Agraph_t* G;
    GVC_t* gvc = gvContext();
    string dotLang = "graph main{";
    draw_node(tree->child[0], dotLang, 0);
    dotLang += "}";

    char* y = &dotLang[0];
    G = agmemread(y);
    gvLayout(gvc, G, "dot");
    string path = "syntax_tree.png";
    const char* c = path.c_str();
    gvRenderFilename(gvc, G, "png", c);
    gvFreeLayout(gvc, G);
    agclose(G);
    gvFreeContext(gvc);

    // put the pictue in the label
    QPixmap pix(c);
    ui.pictureLabel->setPixmap(pix);
    ui.pictureLabel->setScaledContents(true);
}

void gui::on_browseBTN_clicked()
{
    ui.filePathText->clear();
    ui.inputProgram->clear();
    ui.listOfTokens->clear();
    ui.pictureLabel->clear();

    QString filter = "Text File(*.txt)";
    QString openFile = QFileDialog::getOpenFileName(this, "Open a file", "C://", filter);
    QFile file(openFile);
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Error", "File could not be opened");
    }
    else {
        ui.filePathText->setText(openFile);
        QTextStream in(&file);
        QString text = in.readAll();
        ui.inputProgram->setPlainText(text);
        file.close();
    }
}

// main function that will scan the program and then parse it
void gui::on_scan_parseBTN_clicked()
{
    QString program = ui.inputProgram->toPlainText();
    if (program == "") {
        QMessageBox::warning(this, "Error", "Null Input");
        return;
    }

    queue<Token> tokensQueue = scan(program.toStdString());
    QFile file("scanner_output.txt");
    if (!file.open(QFile::ReadOnly | QFile::Text)) {
        QMessageBox::warning(this, "Error", "File could not be opened");
        return;
    }
    QTextStream out(&file);
    QString tokens = out.readAll();
    ui.listOfTokens->setPlainText(tokens);

    if (tokensQueue.empty()) {
        QMessageBox::warning(this, "Error", "No tokens!");
        return;
    }
    else if (tokensQueue.back().type == "ERROR") {
        QMessageBox::warning(this, "Error", "Scanning Error");
        return;
    }

    Node* root = parse(&tokensQueue);
    if (root->key.type == "ERROR") {
        QMessageBox::warning(this, "Error", QString::fromStdString(root->key.value));
        return;
    }
    generate_syntax_tree(root);
}
