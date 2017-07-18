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

void insert(node *root, node *new) {
	node *x, *y;
	x = root;
	while (x != NULL) {
		y = x->p;
		if (new->key <= x->key) {
			x = x->l;
		} else if (new->key > x->key){
			x = x->r;
		}
	}

	if (y == NULL) {
		root = new;
		return;
	}
	
	new->p = y;
	if (y->key > new->key) {
		y->l = new;
	} else {
		y->r = new;
	}
}

void transplant(node *root, node *origin, node *replace) {
	//root node
	if (origin->p == NULL) {
		root = replace;
	} else if (origin == origin->p->l) {
		origin->p->l = replace;
	} else {
		origin->p->r = replace;
	}
	if (replace != NULL) {
		replace->p = origin->p;
	}
}

void delete(node *root, node *target) {
	node *replace;
	if (target->l == NULL) {
		transplant(root, target, target->r);
	} else if (target->r == NULL) {
		transplant(root, target, target->l);
	} else {
		replace = minimum(target->r);	//find successor
		//如果待删除的
		if (replace->p != target) {		
			transplant(root, replace, replace->r);
			replace->r = target->r;
			replace->r->p = replace;
		}
		transplant(root, target, replace);
		replace->l = target->l;
		replace->l->p = replace;
	}
}
