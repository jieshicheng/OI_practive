#include <iostream>
#include <algorithm>
#include <stack>
#include <vector>
#include <map>
#include <set>
#include <queue>
#include <list>

using namespace std;

struct Node {

    int leftWeight, rightWeight;
    int leftDis, rightDis;
    Node *left, *right;
    
    Node() : left(nullptr), right(nullptr) {}
};


class Solution {

public:
    bool checkBalance(int &weight, Node *p) {
        p = new Node();
        cin >> p->leftWeight >> p->leftDis >> p->rightWeight >> p->rightDis;
        bool leftBal = true, rightBal = true;
        if( p->leftWeight == 0 ) {
            leftBal = checkBalance(p->leftWeight, p->left);
        }
        weight += p->leftWeight;
        if( p->rightWeight == 0 ) {
            rightBal = checkBalance(p->rightWeight, p->right);
        }
        weight += p->rightWeight;

        if( leftBal && rightBal && p->leftWeight * p->leftDis == p->rightWeight * p->rightDis )
            return true;
        else
            return false;
    }

    bool solvWasy() {
        int empty;
        Node *root;
        checkBalance(empty, root);
    }
};

int main() {
	Solution obj;
    cout << obj.solvWasy() << endl;
    
    return 0;
}

