#include <iostream>
using namespace std;

struct Node {
    int coeff;
    int exp;
    Node *next;
    Node() : next(nullptr) {}
};

class Polynomial {
    Node *head;

public:
    Polynomial() : head(nullptr) {}

    ~Polynomial() {
        Node *current = head;
        while (current) {
            Node *next = current->next;
            delete current;
            current = next;
        }
    }

    void create() {
        int n;
        cout << "\nEnter the number of terms in polynomial: ";
        cin >> n;
        for (int i = 0; i < n; i++) {
            Node *newNode = new Node();
            cout << "\nEnter the coefficient: ";
            cin >> newNode->coeff;
            cout << "Enter the exponent: ";
            cin >> newNode->exp;

            if (head == nullptr) {
                head = newNode;
            } else {
                Node *temp = head;
                Node *prev = nullptr;
                while (temp && temp->exp > newNode->exp) {
                    prev = temp;
                    temp = temp->next;
                }
                // Insert in the sorted position
                if (prev == nullptr) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    newNode->next = temp;
                    prev->next = newNode;
                }
            }
        }
    }

    void display() {
        cout << "\nThe polynomial is: ";
        Node *te = head;
        while (te) {
            cout << te->coeff << "x^" << te->exp;
            te = te->next;
            if (te) {
                cout << " + ";
            }
        }
        cout << endl;
    }

    Polynomial add(const Polynomial &p) {
        Polynomial result;
        Node *p1 = head;
        Node *p2 = p.head;

        while (p1 || p2) {
            if (p1 && (!p2 || p1->exp > p2->exp)) {
                result.append(p1->coeff, p1->exp);
                p1 = p1->next;
            } else if (p2 && (!p1 || p1->exp < p2->exp)) {
                result.append(p2->coeff, p2->exp);
                p2 = p2->next;
            } else { // p1->exp == p2->exp
                result.append(p1->coeff + p2->coeff, p1->exp);
                p1 = p1->next;
                p2 = p2->next;
            }
        }
        return result;
    }

    Polynomial multiply(const Polynomial &p) {
        Polynomial result;
        Node *p1 = head;

        while (p1) {
            Polynomial temp;
            Node *p2 = p.head;

            while (p2) {
                temp.append(p1->coeff * p2->coeff, p1->exp + p2->exp);
                p2 = p2->next;
            }
            result = result.add(temp);
            p1 = p1->next;
        }
        return result;
    }

private:
    void append(int coeff, int exp) {
        if (coeff == 0) return; // Skip zero coefficients
        Node *newNode = new Node();
        newNode->coeff = coeff;
        newNode->exp = exp;

        if (head == nullptr) {
            head = newNode;
        } else {
            Node *temp = head;
            Node *prev = nullptr;
            while (temp && temp->exp > exp) {
                prev = temp;
                temp = temp->next;
            }
            if (temp && temp->exp == exp) {
                // Combine terms if the exponent is the same
                temp->coeff += coeff;
                delete newNode; // Free memory if we are not using it
            } else {
                // Insert in the correct position
                if (prev == nullptr) {
                    newNode->next = head;
                    head = newNode;
                } else {
                    newNode->next = temp;
                    prev->next = newNode;
                }
            }
        }
    }
};

int main() {
    Polynomial p1, p2;
    p1.create();
    p2.create();
    p1.display();
    p2.display();

    Polynomial sum = p1.add(p2);
    Polynomial product = p1.multiply(p2);

    cout << "Sum of polynomials: ";
    sum.display();
    cout << "Product of polynomials: ";
    product.display();

    return 0;
}
