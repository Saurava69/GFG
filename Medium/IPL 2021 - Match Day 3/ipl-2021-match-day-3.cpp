//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

struct Node
{
    int data;
    Node* left;
    Node* right;
};

Node* newNode(int val)
{
    Node* temp = new Node;
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;
    
    return temp;
}

Node* buildTree(string str)
{   
    // Corner Case
    if(str.length() == 0 || str[0] == 'N')
            return NULL;
    
    // Creating vector of strings from input 
    // string after spliting by space
    vector<string> ip;
    
    istringstream iss(str);
    for(string str; iss >> str; )
        ip.push_back(str);
        
    // Create the root of the tree
    Node* root = newNode(stoi(ip[0]));
        
    // Push the root to the queue
    queue<Node*> queue;
    queue.push(root);
        
    // Starting from the second element
    int i = 1;
    while(!queue.empty() && i < ip.size()) {
            
        // Get and remove the front of the queue
        Node* currNode = queue.front();
        queue.pop();
            
        // Get the current node's value from the string
        string currVal = ip[i];
            
        // If the left child is not null
        if(currVal != "N") {
                
            // Create the left child for the current node
            currNode->left = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->left);
        }
            
        // For the right child
        i++;
        if(i >= ip.size())
            break;
        currVal = ip[i];
            
        // If the right child is not null
        if(currVal != "N") {
                
            // Create the right child for the current node
            currNode->right = newNode(stoi(currVal));
                
            // Push it to the queue
            queue.push(currNode->right);
        }
        i++;
    }
    
    return root;
}


// } Driver Code Ends
/*
// node structure:

struct Node
{
    int data;
    Node* left;
    Node* right;
};

*/

class Solution {
public:
    int dist;
    map<Node*, bool> m;

    void findpath(Node* root, int tar, vector<Node*> cur, vector<Node*>& path, int hk) {
        if (root == NULL) return;
        cur.push_back(root);
        if (root->data == tar) {
            path = cur;
            dist = hk;
            return;
        }
        findpath(root->left, tar, cur, path, hk + 1);
        findpath(root->right, tar, cur, path, hk + 1);
        cur.pop_back();
    }

    void dfs(Node* root, int ex, int& sum) {
        if (root == NULL) return;
        if (ex < 0) return;
        if (m[root] != 1) {
            m[root] = 1;
            sum += root->data;
        }
        dfs(root->left, ex - 1, sum);
        dfs(root->right, ex - 1, sum);
    }

    int sum_at_distK(Node* root, int target, int k) {
        vector<Node*> path, cur;
        dist = 0;
        findpath(root, target, cur, path, 0);
        int sum = 0;
        m.clear();
        int curDist = 0;
        for (auto it : path) {
            if (dist - curDist > k) {
                int x;
            } else if (dist - curDist == k) {
                m[it] = 1;
                sum += it->data;
            } else {
                int extra = k - (dist - curDist);
                dfs(it, extra, sum);
            }
            curDist++;
        }
        return sum;
    }
};



//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    getchar();
    
    while(t--)
    {
        string s;
        getline(cin,s);
        Node* root = buildTree(s);
        
        int target,k;
        cin>> target >> k;
        getchar();
        Solution obj;
        cout<< obj.sum_at_distK(root,target,k) << endl;
    }
	return 0;
}


// } Driver Code Ends