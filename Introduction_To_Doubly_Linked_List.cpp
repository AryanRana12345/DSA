#include<bits/stdc++.h>
using namespace std;
class Node{
    public:
        int data;
        Node* next;
        Node* prev;
        Node(int data1, Node* next1 = nullptr, Node* prev1 = nullptr){
            data = data1;
            next = next1;
            prev = prev1;
        }
};
Node* creating_array_to_doubly_linked_list(vector<int>& arr){
    if(arr.size() == 0) return nullptr;
    Node* head = new Node(arr[0]);
    Node* temp = head;
    for(int i=1;i<arr.size();i++){
        Node* add_el = new Node(arr[i]);
        add_el->prev = temp;
        temp->next = add_el;
        temp = temp->next;
    }
    return head;
}
Node* deleting_head_of_doubly_linked_list(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head->next;
    temp->prev = nullptr;
    head->next = nullptr;
    delete head;
    return temp;

}
Node* inserting_head_of_doubly_linked_list(Node* head, int num){
    Node* new_el = new Node(num,head);
    if(head == nullptr) return new_el;
    head->prev = new_el;
    return new_el;
}
Node* reversing_a_linked_list(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr) return head;
    Node* temp = head;
    while(true){
        Node* storage = temp->next;
        temp->next = temp->prev;
        temp->prev = storage;
        if(temp->prev != nullptr) temp = temp->prev;
        else return temp;
    }
    return temp;
}
Node* deleting_tail_of_doubly_linked_list(Node* head){
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        delete head;
        return nullptr;
    }
    Node* temp = head;
    while(temp->next != nullptr){
        temp = temp->next;
    }
    temp->prev->next = nullptr;
    temp->prev = nullptr;
    delete temp;
    return head;
}
Node* deleting_kth_element_of_doubly_linked_list(Node* head, int num){
    Node* temp = head;
    if(head == nullptr) return nullptr;
    if(head->next == nullptr && num == 1){
        delete head;
        return nullptr;
    }
    if(head->next != nullptr && num == 1){
        temp = temp->next;
        temp->prev->next = nullptr;
        temp->prev = nullptr;
        delete head;
        head = temp;
        return head;
    }
    for(int i = 1;i<num;i++){
        temp = temp->next;
        if(temp == nullptr) return head;
    }
    temp->prev->next = temp->next;
    if(temp->next != nullptr) temp->next->prev = temp->prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    return head;
}
Node* deleting_num_valued_element_of_doubly_linked_list(Node* head, int num){
    Node* temp = head;
    if(head == nullptr) return nullptr;
    if(head->data == num && head->next == nullptr){
        delete head;
        return nullptr;
    }
    if(head->data == num && head->next != nullptr){
        head = head->next;
        head->prev = nullptr;
        temp->next = nullptr;
        delete temp;
        return head;
    }
    while(temp->data != num){
        temp = temp->next;
        if(temp == nullptr) return head;
    }
    temp->prev->next = temp->next;
    temp->next->prev = temp->prev;
    temp->next = nullptr;
    temp->prev = nullptr;
    return head;
}
Node* inserting_num_valued_element_before_tail_of_doubly_linked_list(Node* head, int num){
    Node* new_el = new Node(num);
    Node* temp = head;
    if(head == nullptr) return nullptr;
    if(head->next == nullptr){
        head->prev = new_el;
        new_el->next = head;
        head = head->prev;
        return head;
    }
    while(temp->next != nullptr){
        temp = temp->next;
    }
    new_el->next = temp;
    new_el->prev = temp->prev;
    temp->prev->next = new_el;
    temp->prev = new_el;
    return head;
}
Node* inserting_num_valued_element_at_kth_position_of_doubly_linked_list(Node* head, int num, int k){
    Node* temp = head;
    Node* new_el = new Node(num);
    if(head == nullptr && k == 1){
        return new_el;
    }
    if(head != nullptr && k == 1){
        head->prev = new_el;
        new_el->next = head;
        head = head->prev;
        return head;
    }
    for(int i = 1;i<k;i++){
        temp = temp->next;
        if(temp == nullptr) return head;
    }
    new_el->next = temp;
    new_el->prev = temp->prev;
    temp->prev->next = new_el;
    temp->prev = new_el;
    return head;
}
Node* inserting_before_num_valued_element_of_doubly_linked_list(Node* head, int num, int k){
    Node* temp = head;
    Node* new_el = new Node(num);
    if(head == nullptr) return head;
    if(head->data == k){
        head->prev = new_el;
        new_el->next = head;
        return new_el;
    }
    while(temp->data != k){
        temp = temp->next;
        if(temp == nullptr) return head;
    }
    new_el->next = temp;
    new_el->prev = temp->prev;
    temp->prev->next = new_el;
    temp->prev = new_el;
    return head;
}
void PrintList(Node* head){
    Node* temp = head;
    while(temp != nullptr){
        cout << temp->data << " ";
        temp = temp->next;
    }
    cout << endl;
}
int main(){
    vector<int> arr = {1,2,3,4,5,6};
    Node* head = creating_array_to_doubly_linked_list(arr);
    Node* new_head = deleting_head_of_doubly_linked_list(head);
    int num1 = 7;
    Node* new1_head = inserting_head_of_doubly_linked_list(new_head,num1);
    Node* reversed_head = reversing_a_linked_list(new1_head);
    Node* new2_head = deleting_tail_of_doubly_linked_list(reversed_head);
    int num2 = 3;
    Node* new3_head = deleting_kth_element_of_doubly_linked_list(new2_head,num2);
    int num3 = 5;
    Node* new4_head = deleting_num_valued_element_of_doubly_linked_list(new3_head,num3);
    int num4 = 3;
    Node* new5_head = inserting_num_valued_element_before_tail_of_doubly_linked_list(new4_head,num4);
    int num5 = 1;
    int k = 2;
    Node* new6_head = inserting_num_valued_element_at_kth_position_of_doubly_linked_list(new5_head,num5,k);
    int num6 = 4;
    int num7 = 3;
    Node* new7_head = inserting_before_num_valued_element_of_doubly_linked_list(new6_head,num6,num7);
    PrintList(new7_head);
}