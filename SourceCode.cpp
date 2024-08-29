#include <iostream>
#include <string>
#include <cstdlib>
using namespace std;
class Post {
public:
    string post;
    Post* next;
    Post(string p) : post(p), next(nullptr) {}
};
class User {
public:
    string name;
    User* friends;
    Post* posts;
    User* next;
    User(string n) : name(n), friends(nullptr), posts(nullptr), next(nullptr) {}
};

class SocialNetwork {
private:
    User* head;

public:
    SocialNetwork() : head(nullptr) {}

    // O(n)
    void add_user(string name) {
        User* temp = new User(name);
        if (head == nullptr) {
            head = temp;
        } else {
            User* ptr = head;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp;
        }
    }
    // O(n)
    void add_friend(string name1, string name2) {
        User* ptr1 = head;
        User* ptr2 = head;
        while (ptr1->name != name1) {
            ptr1 = ptr1->next;
        }
        while (ptr2->name != name2) {
            ptr2 = ptr2->next;
        }
        User* temp1 = new User(name1);
        User* temp2 = new User(name2);

        if (ptr1->friends == nullptr) {
            ptr1->friends = temp2;
        } else {
            User* ptr = ptr1->friends;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp2;
        }
        if (ptr2->friends == nullptr) {
            ptr2->friends = temp1;
        } else {
            User* ptr = ptr2->friends;
            while (ptr->next != nullptr) {
                ptr = ptr->next;
            }
            ptr->next = temp1;
        }
    }

    // O(n + m)
    void add_post(string name, string post) {
        User* ptr = head;
        while (ptr->name != name) {
            ptr = ptr->next;
        }
        Post* temp = new Post(post);
        if (ptr->posts == nullptr) {
            ptr->posts = temp;
        } else {
            Post* ptr1 = ptr->posts;
            while (ptr1->next != nullptr) {
                ptr1 = ptr1->next;
            }
            ptr1->next = temp;
        }
    }

    // O(n + m)
    void show_posts(string name) {
        User* ptr = head;
        while (ptr->name != name) {
            ptr = ptr->next;
        }
        Post* ptr1 = ptr->posts;
        while (ptr1 != nullptr) {
            cout << ptr->name << ": " << ptr1->post << endl;
            ptr1 = ptr1->next;
        }
    }

    // O(n + k)
    void show_friends(string name) {
        User* ptr = head;
        while (ptr->name != name) {
            ptr = ptr->next;
        }
        User* ptr1 = ptr->friends;
        while (ptr1 != nullptr) {
            cout << ptr1->name << endl;
            ptr1 = ptr1->next;
        }
    }

    // O(n + k + m)
    void show_mutuals(string name1, string name2) {
        User* ptr1 = head;
        User* ptr2 = head;
        while (ptr1->name != name1) {
            ptr1 = ptr1->next;
        }
        while (ptr2->name != name2) {
            ptr2 = ptr2->next;
        }
        User* ptr = ptr1->friends;
        while (ptr != nullptr) {
            User* ptr3 = ptr2->friends;
            while (ptr3 != nullptr) {
                if (ptr->name == ptr3->name) {
                    cout << ptr->name << endl;
                }
                ptr3 = ptr3->next;
            }
            ptr = ptr->next;
        }
    }

    // O(n)
    void remove_friend(string name1, string name2) {
        User* ptr1 = head;
        User* ptr2 = head;
        while (ptr1->name != name1) {
            ptr1 = ptr1->next;
        }
        while (ptr2->name != name2) {
            ptr2 = ptr2->next;
        }
        User* ptr = ptr1->friends;
        if (ptr->name == name2) {
            ptr1->friends = ptr->next;
            delete ptr;
        } else {
            while (ptr->next->name != name2) {
                ptr = ptr->next;
            }
            User* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
        ptr = ptr2->friends;
        if (ptr->name == name1) {
            ptr2->friends = ptr->next;
            delete ptr;
        } else {
            while (ptr->next->name != name1) {
                ptr = ptr->next;
            }
            User* temp = ptr->next;
            ptr->next = temp->next;
            delete temp;
        }
    }

    void menu() {
        int choice;
        string name1, name2, post;
        while (true) {
            cout << "1. Add user\n2. Add friend\n3. Add post\n4. Show posts\n5. Show friends\n6. Show mutual\n7. Remove friend\n8. Exit\nEnter your choice: ";
            cin >> choice;
            switch (choice) {
                case 1:
                    cout << "Enter the name of the user: ";
                    cin >> name1;
                    add_user(name1);
                    break;
                case 2:
                    cout << "Enter the names of user 1: ";
                    cin >> name1;
                    cout << "Enter the names of user 2: ";
                    cin >> name2;
                    add_friend(name1, name2);
                    break;
                case 3:
                    cout << "Enter the name of the user: ";
                    cin >> name1;
                    cout << "Enter the post: ";
                    cin >> post;
                    add_post(name1, post);
                    break;
                case 4:
                    cout << "Enter the name of the user: ";
                    cin >> name1;
                    show_posts(name1);
                    break;
                case 5:
                    cout << "Enter the name of the user: ";
                    cin >> name1;
                    show_friends(name1);
                    break;
                case 6:
                    cout << "Enter the names of user 1: ";
                    cin >> name1;
                    cout << "Enter the names of user 2: ";
                    cin >> name2;
                    show_mutuals(name1, name2);
                    break;
                case 7:
                    cout << "Enter the names of user 1: ";
                    cin >> name1;
                    cout << "Enter the names of user 2: ";
                    cin >> name2;
                    remove_friend(name1, name2);
                    break;
                case 8:
                    exit(0);
            }
        }
    }
};

int main() {
    SocialNetwork network;
    network.menu();
    return 0;
}
