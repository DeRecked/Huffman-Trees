#include "Heap.hpp"

void Heap::enqueue(HNode* newNode)
{
    tree.push_back(newNode);
    fix_up(tree.size()-1);
    count++;
}

void Heap::fix_up(const int& fixFrom)
{
    HNode* newNode = tree[fixFrom];
    int index = fixFrom;

    while ((index > 1) && (*tree[index] < *tree[index/2]))
    {
        tree[index] = tree[index/2];
        index = index/2;
    }

    tree[index] = newNode;
    position = index;
}

HNode* Heap::dequeue()
{
    HNode* root = tree[1];
    int lastIndex = tree.size()-1;
    HNode* last = tree[lastIndex];

    tree.pop_back();

    if (lastIndex > 1)
    {
        tree[1] = last;
        fix_down(1);
    }

    count--;
    return root;
}

void Heap::fix_down(const int& fixFrom)
{
    HNode* root = tree[fixFrom];
    bool more = true;
    int index = fixFrom;
    int lastIndex = tree.size()-1;

    while(more)
    {
    	int childIndex = 2*index;
        if(childIndex <= lastIndex)
        {
            HNode* child = tree[childIndex];

            if ((childIndex+1 <= lastIndex) && (*tree[childIndex+1] < *child))
            {
                childIndex++;
                child = tree[childIndex];
            }
            if (*child < *root)
            {
                tree[index] = child;
                index = childIndex;
            }
            else { more = false; }
        }
        else { more = false; }
    }

    tree[index] = root;
}

void Heap::clear()
{
    count = 0;
    position = 0;

    while(tree.size() > 1)
        tree.pop_back();
}
