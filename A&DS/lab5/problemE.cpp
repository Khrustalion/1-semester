#include <iostream>
#include <string>

struct Node {
	std::string name;
	Node* left_child;
	Node* right_child;

	Node(std::string name) : name{ name }, left_child{ nullptr }, right_child{ nullptr } {}
};

Node* insert(Node* root, std::string name) {
	if (root == nullptr) {
		Node* new_node = new Node(name);
		return new_node;
	}

	if (root->name > name) {
		root->left_child = insert(root->left_child, name);
	}
	else {
		root->right_child = insert(root->right_child, name);
	}
	return root;
}

Node* find(Node* root, std::string name) {
	if (root == nullptr || root->name == name) {
		return root;
	}

	if (root->name < name) {
		return find(root->right_child, name);
	}
	else {
		return find(root->left_child, name);
	}
}

int count_ball(std::string name, Node* friend_first, Node* friend_second) {
	int ball1 = (find(friend_first, name) == nullptr) ? 1 : 0;
	int ball2 = (find(friend_second, name) == nullptr) ? 1 : 0;
	if ((ball1 == ball2) && ball1 == 1) {
		return 3;
	}
	else if ((ball1 == ball2) && ball1 == 0) {
		return 0;
	}
	return 1;
}

int dfs(Node* root, int count, Node* friend_first, Node* friend_second) {
	if (root == nullptr) {
		return count;
	}
	
	count += dfs(root->left_child, 0, friend_first, friend_second);
	count += dfs(root->right_child, 0, friend_first, friend_second);
	count += count_ball(root->name, friend_first, friend_second);
	return count;
}

int main(){
	int n; std::cin >> n;
	Node** friends = new Node* [3];
	std::string name;
	for (int i = 0; i < 3; ++i) {
		friends[i] = nullptr;
		for (int j = 0; j < n; ++j) {
			std::cin >> name;

			friends[i] = insert(friends[i], name);
		}
	}
	std::cout << dfs(friends[0], 0, friends[1], friends[2]) << " " << dfs(friends[1], 0, friends[0], friends[2]) << " " << dfs(friends[2], 0, friends[0], friends[1]);
	return 0;
}