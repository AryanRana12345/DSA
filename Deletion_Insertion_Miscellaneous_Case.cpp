#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node(int data1){
            data = data1;
            next = NULL;
        }
};
Node* Array_To_List(vector<int>& arr){
    if(arr.size() == 0) return NULL;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i = 1;i<arr.size();i++){
        Node* new_el = new Node(arr[i]);
        temp->next = new_el;
        temp = temp->next;
    }
    return head;
}
Node* deleting_tail_of_list(Node* head){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        delete head;
        return NULL;
    }
    Node* temp = head;
    while(temp->next->next != NULL){
        temp=temp->next;
    }
    Node* tail = temp->next;
    temp->next = NULL;
    delete tail;
    return head;
}
Node* inserting_tail_of_list(Node* head, int num){
    if(head == NULL) return new Node(num);
    Node* temp = head;
    while(temp->next!=NULL) temp = temp->next;
    Node* new_el = new Node(num);
    temp->next = new_el;
    return head;
}
Node* deleting_node_with_value_num(Node* head, int num){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        if(head->data == num){
            delete head;
            return NULL;
        }
        else return head;
    }
    Node* temp = head;
    while(temp->next!= NULL){
        if(temp->next->data == num){
            Node* del_el = temp->next;
            temp->next = temp->next->next;
            delete del_el;
            return head;
        }
        temp = temp->next;
    }
    return head;
}
Node* inserting_node_before_value_k(Node* head, int num, int k){
    if(head == NULL) return NULL;
    if(head->next == NULL){
        if(head->data == k){
            Node* new_el = new Node(num);
            new_el->next = head;
        }
        return head;
    }
    Node* temp = head;
    while(temp->next->next!= NULL){
        if(temp->next->data == k){
            Node* new_el = new Node(num);
            Node* temp2 = temp->next;
            temp->next = new_el;
            new_el->next = temp2;
        }
        temp = temp->next;
    }
    return head;
}
Node* deleting_node_at_kth_position(Node* head, int k){
    if(k==1){
        Node* temp = head->next;
        delete head;
        return temp;
    }
    Node* temp = head;
    for(int i = 1;i<k-1;i++){
        temp = temp->next;
        if(temp == NULL) return head;
    }
    Node* del_el = temp->next;
    temp->next = temp->next->next;
    delete del_el;
    return head;
}
Node* inserting_node_at_kth_position(Node* head, int k, int num){
    if(k==1){
        Node* new_el = new Node(num);
        new_el->next = head;
    }
    Node* temp = head;
    for(int i = 1;i<k-1;i++){
        temp = temp->next;
        if(temp == NULL) return head;
    }
    Node* new_el = new Node(num);
    new_el->next = temp->next;
    temp->next = new_el;
    return head;
}