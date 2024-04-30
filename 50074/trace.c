#include "trace.h"
#include <stdlib.h>

int total_internal = 0, leaves = 0, mbf = 0, mb = 0;

int find_child(Node *root, int depth) {
    if (depth > mb) mb = depth;
    if (root->list == NULL) return 0;

    ChildList *curr = root->list;
    int ret = 0;
    while (curr != NULL) {
        int childs = find_child(curr->node, depth + 1);
        if (childs > 0) total_internal++;
        else leaves++;
        curr = curr->next;
        ret++;
    }
    if (ret > mbf) mbf = ret;

    return ret;
}

void trace(Node *root, Answer *ans) {
    int childs = find_child(root, 0);
    if (childs > 0) total_internal++;
    else leaves++;

    ans->InternalNode = total_internal;
    ans->Leaf = leaves;
    ans->MaxBranchFactor = mbf;
    ans->Depth = mb;
}
