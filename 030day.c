#include <stdio.h>
#include <stdlib.h>

struct node {
    int coeff;
    int exp;
    struct node* next;
};

struct node* createNode(int c, int e) {
    struct node* newNode = (struct node*)malloc(sizeof(struct node));
    newNode->coeff = c;
    newNode->exp = e;
    newNode->next = NULL;
    return newNode;
}

struct node* insertTerm(struct node* head, int c, int e) {
    struct node* newNode = createNode(c, e);

    if (head == NULL)
        return newNode;

    struct node* temp = head;
    while (temp->next != NULL)
        temp = temp->next;

    temp->next = newNode;
    return head;
}

void display(struct node* head) {
    while (head != NULL) {
        printf("%dx^%d", head->coeff, head->exp);
        if (head->next != NULL)
            printf(" + ");
        head = head->next;
    }
    printf("\n");
}

struct node* addPolynomial(struct node* p1, struct node* p2) {
    struct node* result = NULL;

    while (p1 != NULL && p2 != NULL) {
        if (p1->exp > p2->exp) {
            result = insertTerm(result, p1->coeff, p1->exp);
            p1 = p1->next;
        }
        else if (p1->exp < p2->exp) {
            result = insertTerm(result, p2->coeff, p2->exp);
            p2 = p2->next;
        }
        else {
            result = insertTerm(result, p1->coeff + p2->coeff, p1->exp);
            p1 = p1->next;
            p2 = p2->next;
        }
    }

    while (p1 != NULL) {
        result = insertTerm(result, p1->coeff, p1->exp);
        p1 = p1->next;
    }

    while (p2 != NULL) {
        result = insertTerm(result, p2->coeff, p2->exp);
        p2 = p2->next;
    }

    return result;
}

int main() {
    struct node* poly1 = NULL;
    struct node* poly2 = NULL;
    struct node* result = NULL;
    int n, coeff, exp;

    printf("Enter number of terms in first polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly1 = insertTerm(poly1, coeff, exp);
    }

    printf("Enter number of terms in second polynomial: ");
    scanf("%d", &n);

    for (int i = 0; i < n; i++) {
        printf("Enter coefficient and exponent: ");
        scanf("%d %d", &coeff, &exp);
        poly2 = insertTerm(poly2, coeff, exp);
    }

    printf("\nFirst Polynomial: ");
    display(poly1);

    printf("Second Polynomial: ");
    display(poly2);

    result = addPolynomial(poly1, poly2);

    printf("Resultant Polynomial after Addition: ");
    display(result);

    return 0;
}