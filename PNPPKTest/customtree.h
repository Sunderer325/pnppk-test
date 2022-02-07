#ifndef CUSTOMTREE_H
#define CUSTOMTREE_H

#include <QTreeWidgetItem>
#include <QRandomGenerator>

struct treenode
{
    treenode* left;
    treenode* right;

    static treenode* Generate(const unsigned int currentDepth, const unsigned int maxDepth);
    static int CountMaxDepth(treenode* root);
    static void OnlyMaxDepth(treenode* root, int depth);
    static QTreeWidgetItem* ToQTreeWidgetItem(treenode* root);
};

#endif // CUSTOMTREE_H
