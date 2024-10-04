#include <iostream>
#include <bits/stdc++.h>

using namespace std;

struct Node{
    Node *next;
    int val;
    Node(int v){
        val = v;
        next = NULL;
    }
};

bool cycleDetect(Node *head){
    Node* slow = head;
    Node* fast = head;
    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;
        if(slow == fast) break;
    }
    
    if(fast != slow) return false;
    slow = head;
    while(slow != fast){
        slow = slow->next;
        fast = fast->next;
    }

    cout<<"The node where cycle starts is "<<slow->val<<"\n";
    return true;
}


int main(){
    Node* head = new Node(0);
    head->next = new Node(1);
    head->next->next = new Node(2);
    head->next->next->next = new Node(3);
    head->next->next->next->next = head->next;
    if(!cycleDetect(head)){
        cout<<"No cycle detected"<<"\n";
    }
    return 0;
}