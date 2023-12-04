#include<iostream>
#include<vector>
#include<queue>
#include<limits.h>
#include<algorithm>
using namespace std;
class Node{
public:
    int data;
    Node* left;
    Node* right;
    Node(int data){
        this -> data = data;
        this -> left = NULL;
        this -> right = NULL;
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
class BinarySearchTree{
public:
    // inserting a node in the tree
    Node* insertAtTree(Node* root , int data){
        if(data == -1) return root;
        if(root == NULL){
            Node* new_node = new Node(data);
            root = new_node;
            return root;
        }
        if(data < root->data){
            root -> left = insertAtTree(root -> left , data);
        } else{
            root -> right = insertAtTree(root -> right , data);
        }
        return root;
    }
    // building the tree
    void buildTree(Node* &root){
        int data;
        cin>>data;
        if(data == -1) return;
        root = insertAtTree(root , data);
        buildTree(root);
    }
    // finding the minimum value
    void minVal(Node* root ,  int &potential){
        if(root == NULL) return;
        potential = root -> data;
        minVal(root->left , potential);
    }

    // deleting a node in the binary tree
    Node* deleteNode(Node* root , int key){
        if(root == NULL) return NULL;
        // node is found
        if(root -> data == key){
            // 0 child
            if(root -> left == NULL && root -> right == NULL){
                Node* temp = root;
                root = NULL;
                delete(temp);
                return root;
            }
            // 1 child
            if(root -> left == NULL && root -> right != NULL){ // right child
                Node* temp = root;
                root = root -> right;
                delete(temp);
                return root;
            }
            if(root -> left != NULL && root -> right == NULL){ // left child
                Node* temp = root;
                root = root -> left;
                delete(temp);
                return root;
            }
            // 2 child
            if(root -> left != NULL && root -> right != NULL){
                int mini = INT_MAX; // finding the minimum value
                minVal(root -> right , mini);
                deleteNode(root , mini); // deleting the minimum value node
                root -> data = mini; // initialising the current data to minimum value data
                return root; 
            }
            // node is not found
        } else if(root-> data > key){
            root -> left = deleteNode(root->left , key);
        } else{
            root -> right = deleteNode(root -> right , key);
        }
    }

    // Checking if a bst
    bool isBST(Node* root , int leftRange = INT_MIN , int rightRange = INT_MAX){
        if(root == NULL) return true;
        if(root -> data >leftRange && root -> data < rightRange){ // checking the current element in the range
                bool left = isBST(root -> left , leftRange , root->data);
                bool right = isBST(root->right , root->data , rightRange);
                return left && right; // both subtree must be bst
        } else{
            return false;
        }
    }
};
// two sum in bst
bool fun(Node* root , int curr ,  int target ){
    if(root == NULL) return false;
    int x = root->data;
    if(x+curr == target){
        return true;
    } else if(x+curr<target){
        fun(root->right , curr , target);
    } else{
        fun(root->left , curr , target);
    }
}
bool twoSum(Node* root , int target){
    if(root == NULL) return false;
    int curr = root->data;
    if(fun(root, curr,target)) return true;
    else{
        if(target>2*curr) twoSum(root -> right , target);
        else if(target<2*curr) twoSum(root->left , target);
        else return false;
    }
}
void printLevel(Node* root){
    queue<Node*> q;
    q.push(root);
    q.push(NULL);

    while(!q.empty()){
        Node* temp = q.front();
        q.pop();
        if(temp == NULL){
            cout<<endl;
            if(!q.empty()) q.push(NULL);
        } else{
            cout<<temp->data<<" ";
            if(temp->left != NULL) q.push(temp->left);
            if(temp->right != NULL) q.push(temp->right);
        }
    } cout<<endl;
}
int main(){
    Node* root = NULL;
    traversal tr;
    BinarySearchTree bst;
    bst.buildTree(root);
    cout<<"Level order is \n";
    printLevel(root);
    cout<<"Inorder traversal \n";
    tr.inorder(root);
    cout<<"\n Preorder traversal \n";
    tr.preorder(root);
     cout<<"\n Postorder traversal \n";
    tr.postorder(root);
     cout<<"\n zigzag traversal \n";
    vector<int> a = tr.zigzag(root);
    for(auto i : a) cout<<i<<" ";

    return 0;
}
// binary tree example
//4 3 8 1 N 5 10 N 2 N 6 9 N