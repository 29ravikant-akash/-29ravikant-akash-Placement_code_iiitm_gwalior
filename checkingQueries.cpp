#include <bits/stdc++.h>
using namespace std;

//Representing a node structure containing a key, list of children and a parent reference;
struct Node{
    int key;
    Node *parent;
    vector<Node *> children;
};

Node *newNode(int key, Node *parent){
    Node *temp = new Node;
    temp->key = key;
    temp->parent = parent;
    return temp;
}
int main(){
    int numOfTestCases;
    cin>>numOfTestCases;

    while(numOfTestCases-- != 0){
        Node *root = NULL;
        int numOfNodes;
        cin>>numOfNodes;
        
        Node *nodesArray[numOfNodes + 1] = {};
        for(int i = 0; i < numOfNodes - 1; i++){
            int u, v;
            cin>>u>>v;

            Node *tempU;
            if(nodesArray[u] != NULL){
                tempU = nodesArray[u];
            }
            else{
                tempU = newNode(u, NULL);
                nodesArray[u] = tempU;
            }


            Node *tempV;
            if(nodesArray[v] != NULL){
                tempV = nodesArray[v];
            }else{
                tempV = newNode(v, tempU);
                nodesArray[v] = tempV;
            }
            tempU->children.push_back(tempV);
        }

        for(int j = 1; j < numOfNodes + 1; j++){
                if(nodesArray[j]->parent == NULL){
                    root = nodesArray[j];
                    break;
                }
            }
        int noOfQueries; 
        cin>>noOfQueries;
        int queryEntries[numOfNodes + 1] = {};
        vector<vector<int>> queries;
        string str;
        for(int i = 0; i < noOfQueries; i++){
            int k;
            cin>>k;
            vector<int> temp;
            temp.resize(k);
            for(int j = 0; j < k; j++){
                int currEntry;
                cin>>currEntry;
                temp.push_back(currEntry);
                queryEntries[currEntry] = 1;
            }
            queries.push_back(temp);
        }

        // create an empty stack and push the root node
    stack<Node*> s;
    s.push(root);
    vector<int> pathSequences;
    // loop till stack is empty
    while (!s.empty())
    {
        // pop a node from the stack and push the data into the output stack
        Node* curr = s.top();
        s.pop();


        if(queryEntries[curr->key] == 1){
        reverse(pathSequences.begin(), pathSequences.end());
        int decimal = 1;
        int total = 0;
        for (auto& it : pathSequences)
        {
            total += it * decimal;
            decimal *= 10;
        }
        queryEntries[curr->key] = total;
        reverse(pathSequences.begin(), pathSequences.end());
        }

        pathSequences.push_back(curr->key);


        for(auto it: curr->children){
            s.push(it);
        }
    }
    for(int i = 0; i < numOfNodes + 1; i++)
    {
        cout<<queryEntries[i] + " ";
    }  
    }
    system("pause");
    return 0;
}
