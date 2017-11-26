// hnode.cpp -- heap node class
// c. 2015 A. Deeter

#include <cctype>
#include "HNode.hpp"

// constructor for leaf nodes
HNode::HNode(const char& v, const int& w)
{
	value = toupper(v);
	weight = w;
}

// constructor for internal nodes
HNode::HNode(HNode* l, HNode* r)
{
    //value = '*';
	weight = l->weight + r->weight;

    left = l;
    right = r;
}
