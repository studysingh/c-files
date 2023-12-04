#include<bits/stdc++.h>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int val){
        this -> data = val;
        this -> left = NULL;
        this -> right = NULL;
    }
};
class tree{
public:
    // building a tree using inorder traversal
    Node* buildTree(Node* root){
        int data;
        cin>>data;
        if(data == -1) return NULL;
        Node* new_node = new Node(data);
        root = new_node;
        // take for left
        cout<<"Enter the data to insert at the left of "<<data<<endl;
        root -> left = buildTree(root);
        cout<<"Enter the data to insert at the right of "<<data<<endl;
        root -> right = buildTree(root);
        return root;
    }
    
    // building a tree using level order traversal
    void buildLevel(Node* &root){
        queue<Node*> q;
        cout<<"Enter the data for root ";
        int data;
        cin>>data;
        Node* new_node = new Node(data);
        root = new_node;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            //left side
            cout<<"Enter the data for the left side of "<<temp->data<<endl;
            int leftData;
            cin>>leftData;
            if(leftData != -1){
                Node* leftNode = new Node(leftData);
                temp -> left = leftNode;
                q.push(temp -> left);
            }

            // right side
            cout<<"Enter the data for the right side of "<<temp->data<<endl;
            int rightData;
            cin>>rightData;
            if(rightData != -1){
                Node* rightNode = new Node(rightData);
                temp -> right = rightNode;
                q.push(temp -> right);
            }
        }
    }

    //Printing the tree level wise
    void levelSeparated(Node* root){
        queue<Node*> q;
        q.push(root);
        q.push(NULL);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();

            if(temp == NULL){

                cout<<endl;
                if(!q.empty()) q.push(NULL);

            } else {

                cout<<temp->data<<" ";

                if(temp->left != NULL){
                    q.push(temp->left);
                }

                if(temp->right != NULL){
                    q.push(temp->right);
                }
            }
           
        }
    }
};
class traversal{
public:
    // level order traversal
    void levelOrder(Node* root){
        queue<Node*> q;
        q.push(root);

        while(!q.empty()){
            Node* temp = q.front();
            q.pop();
            cout<<temp->data<<" ";
      
           if(temp->left != NULL){
            q.push(temp->left);
           }

           if(temp->right != NULL){
            q.push(temp->right);
           }
           
        }
    }

    // Inorder
    void inorder(Node* root){
        if(root == NULL) return;
        inorder(root -> left);
        cout<<root->data<<" ";
        inorder(root -> right);
    }

    // Preorder
    void preorder(Node* root){
        if(root == NULL) return;
        cout<<root->data<<" ";
        preorder(root -> left);
        preorder(root -> right);
    }

    // Postorder
    void postorder(Node* root){
        if(root == NULL) return;
        postorder(root -> left);
        postorder(root -> right);
        cout<<root->data<<" ";
    }

    // zig zag traversal
    vector<int> zigzag(Node* root){
        if(root == NULL) return {};
        queue<Node*> q;
        q.push(root);
        vector<int> result;
        bool leftToRight = true; // checks from which side the array is being filled

        while(!q.empty()){
            int qsize = q.size();
            vector<int> temp(qsize); // temp array to store the element of last level

            // Processing the each level
            for(int i=0;i<qsize;i++){ // filling the temp array
                Node* frontNode = q.front();
                q.pop();
                int index = leftToRight ? i : qsize - i - 1; // calculate the index acc. to previous filling pattern
                temp[index] = frontNode -> data;
                if(frontNode->left) q.push(frontNode->left);
                if(frontNode->right) q.push(frontNode->right);

            } leftToRight = !leftToRight; // inverting the state
            for(auto i : temp){ // copying the temp data to the result
                result.push_back(i);
            }
        }
        return result;
    }

};
class boundaryTraversal{
public:
    void leftNode(Node* root , vector<int> &store){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        store.push_back(root->data);
        if(root->left != NULL) leftNode(root->left , store);
        else leftNode(root->right , store);
    }
    void rightNode(Node* root , vector<int> &store){
        if(root == NULL) return;
        if(root->left == NULL && root->right == NULL) return;
        if(root->right != NULL) rightNode(root->right , store);
        else rightNode(root->left , store);
        store.push_back(root->data);
    }
    void leaf(Node* root , vector<int> &store){
        if(root == NULL) return;
        leaf(root->left , store);
        leaf(root->right , store);
        if(root->left == NULL && root->right == NULL) store.push_back(root->data);
    }
    void copy(vector<int> &v1 , vector<int> &v2){
        for(auto i : v1){
            v2.push_back(i);
        }
    }
    vector<int> boundary(Node* root){
        if(root == NULL) return {};
        vector<int> vleft , vleaf , vright , ans;
        ans.push_back(root->data); // root node
        leftNode(root->left , vleft);
        leaf(root->left , vleaf);
        leaf(root->right , vleaf);
        rightNode(root->right , vright);
        copy(vleft ,ans);
        copy(vleaf ,ans);
        copy(vright ,ans);
        return ans;
    }
};
class concept{
public:
    // finding the height of a tree
    int height(Node* root){
    if(root == NULL) return 0;
    int hl = height(root -> left);
    int hr = height(root -> right);
    int ans = 1 + max(hl,hr);
    return ans;
    // Note that the time complexity is O(n) where n is the number of nodes
    }

    // finding the diameter of tree
    int diameter(Node* root){
        if(root == NULL) return 0;
        int op1 = diameter(root->left); // diameter may exist in left side only
        int op2 = diameter(root->right); // diameter may exist in right side only
        int op3 = height(root->left) + height(root->right) + 1; // diameter may exist such that the root is included
        int ans = max(op1 , max(op2 , op3));
        return ans;
        // Note that its time complexity is O(n*n) where n is the number of nodes
    }

    // finding the diameter and height simultaneously in the O(n) time complexity
    pair<int,int> diameterAndHeight(Node* root){ // here first int shows diameter and second shows height
        if(root == NULL){
            return {0,0};
        }
        auto leftSide = diameterAndHeight(root->left);
        auto rightSide = diameterAndHeight(root->right);
        pair<int,int> ans;
        ans.second = max(leftSide.second , rightSide.second)+1; // height
        int op1 = leftSide.first;
        int op2 = rightSide.first;
        int op3 = leftSide.second + rightSide.second + 1;
        ans.first = max(op1 , max(op2 , op3));
        return ans;
    }

    // Checking if the tree is balanced or not
    pair<bool , int> balance(Node* root){ // first data is to check if the node is balanced and second is the height of the tree
        if(root == NULL){
            return {true , 0};
        }
        auto leftSide = balance(root->left);
        auto rightSide = balance(root->right);
        int hl = leftSide.second;
        int hr = rightSide.second;
        pair<bool , int> ans;
        ans.second = max(hl , hr)+1;
        if(leftSide.first && rightSide.first && abs(hl - hr)<=1)  ans.first = true;
        else ans.first = false;
        return ans;
    }
    
    // Lowest common ancestor of p and q
    Node* lca(Node* root , Node* p , Node* q){
        if(root == NULL) return NULL;
        if(root == p || root == q){
            return root;
        }
        Node* leftNode = lca(root -> left , p , q);
        Node* rightNode = lca(root -> right , p , q);
        if(leftNode != NULL && rightNode != NULL) return root;
        else if(leftNode != NULL && rightNode == NULL) return leftNode;
        else if(leftNode == NULL && rightNode != NULL) return rightNode;
        else return NULL;
    }

    // finding the parent array
    Node* fun(Node* root , int node , vector<int> &parent){ // here parent is filled
    if(root == NULL) return NULL;
    if(root->data == node){
        parent.push_back(root->data);
        return root;
    }
    Node* left = fun(root -> left , node , parent);
    Node* right = fun(root -> right , node , parent);
    if((left != NULL || right != NULL)){
        parent.push_back(root->data);
        return root;
    } else return NULL;
}
};
// nodes at a given distance in binary tree
void parentStore(Node* root , vector<Node*> &v , int target , bool &check){
    if(root == NULL) return;
    if(root->data == target){
        check = true;
    }
    if(check == false) parentStore(root->left , v , target , check);
    if(check == false){
        parentStore(root->right , v , target , check);
    }
    v.push_back(root);
}
int main(){
    Node* root = NULL;
    tree t;
    traversal tr;
    t.buildLevel(root);
    vector<int> ans;
    for(auto i : ans){
        cout<<i<<" ";
    }
    // vector<int> v1 , v2 ,v3;
    // leftNode(root , v1);
    // rightNode(root , v2);
    // leaf(root , v3);
    // for(int i=0;i<v1.size();i++){
    //     cout<<v1[i]<<" ";
    // // } cout<<endl;
    // // for(int i=0;i<v2.size();i++){
    // //     cout<<v2[i]<<" ";
    // // } cout<<endl;
    // // for(int i=0;i<v3.size();i++){
    // //     cout<<v3[i]<<" ";
    // // } cout<<endl;
}
// inorder :-> 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1 
// levelorder :-> 1 3 7 11 5 17 -1 -1 -1 -1 -1 -1 -1
1
12 9 7 13 2 3 4 6 N N N 5 11 N N N N N N N N
4
1