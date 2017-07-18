//define the tree node
struct node{
	struct node *l, *r, *p;
	int key;
};

typedef struct node node;

node *search(node *root, int v) {
	if (root->key == v) {
		return root;
	}
	if (v < root->key && root->l != NULL) {	//如何在c中判断null(未分配)?
		return search(root->l, v);
	} else if (v > root->key && root->r != NULL){	//同上
		return search(root->r, v);
	}
	return NULL;
}

node *minimum(node *root) {
	node *min = root;
	while (min->l != NULL) {
		min = min->l;
	}
	return min;
}

node *maximum(node *root) {
	node *max = root;
	while (max->r != NULL) {
		max = max->r;
	}
	return max;
}


node *successor(node *cur) {
	node *successor_node = cur->p;
	if (cur->r != NULL) {
		return minimum(cur->r);
	}
	while (successor_node != NULL && successor_node->p->r == successor_node) {
		successor_node = successor_node->p;
	}
	return successor_node;
}

node *precedessor(node *cur) {
	node *precedessor_node = cur->p;
	if (cur->l != NULL) {
		return maximum(cur->l);
	}
	while (precedessor_node != NULL && precedessor_node->p->l == precedessor_node) {
		precedessor_node = precedessor_node->p;
	}
	return precedessor_node;
}

