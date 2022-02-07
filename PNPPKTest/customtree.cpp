#include "customtree.h"

treenode* treenode::Generate(const unsigned int currentDepth, const unsigned int maxDepth){
    if(currentDepth < maxDepth){
        float rand = QRandomGenerator::global()->generate();
        rand /= (float)QRandomGenerator::max();

        float chance = (float)(maxDepth - currentDepth) / maxDepth;

        if(rand < chance){
            treenode* root = new treenode;

            root->left = treenode::Generate(currentDepth+1, maxDepth);
            root->right = treenode::Generate(currentDepth+1, maxDepth);

            return root;
        }
    }

    return nullptr;
}

int treenode::CountMaxDepth(treenode *root){
    int right = 0, left = 0;

    if(root->left != nullptr)
        left = treenode::CountMaxDepth(root->left);

    if(root->right != nullptr)
        right = treenode::CountMaxDepth(root->right);

    if(left > right)
        return left + 1;
    else
        return right + 1;
}

void treenode::OnlyMaxDepth(treenode *root, int depth){
    int leftDepth = 0;
    int rightDepth = 0;

    if(root->left != nullptr){
        leftDepth = treenode::CountMaxDepth(root->left);

        if(leftDepth < depth - 1){
            delete root->left;
            root->left = nullptr;
        }
        else{
            treenode::OnlyMaxDepth(root->left, depth - 1);
        }
    }

    if(root->right != nullptr){
        rightDepth = treenode::CountMaxDepth(root->right);

        if(rightDepth < depth - 1){
            delete root->right;
            root->right = nullptr;
        }
        else{
            treenode::OnlyMaxDepth(root->right, depth - 1);
        }
    }
}

QTreeWidgetItem* treenode::ToQTreeWidgetItem(treenode *root){
    QTreeWidgetItem* rootItem = new QTreeWidgetItem();

    if(root->left != nullptr){
        auto item = treenode::ToQTreeWidgetItem(root->left);
        item->setText(0, "Left");
        rootItem->addChild(item);
    }
    if(root->right != nullptr){
        auto item = treenode::ToQTreeWidgetItem(root->right);
        item->setText(0, "Right");
        rootItem->addChild(item);
    }

    return rootItem;
}
