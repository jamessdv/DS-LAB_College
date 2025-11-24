#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct tree {
    char name[30];
    int salary;
    struct tree *left;
    struct tree *right;
} *BST;


BST createNode(char name[], int salary) {
    BST newNode = (BST)malloc(sizeof(struct tree));
    strcpy(newNode->name, name);
    newNode->salary = salary;
    newNode->left = newNode->right = NULL;
    return newNode;
}

//insert employee
BST insertEmp(BST root, char name[], int salary) {
    if (root == NULL)
        return createNode(name, salary);

    if (salary < root->salary)
        root->left = insertEmp(root->left, name, salary);
    else
        root->right = insertEmp(root->right, name, salary);

    return root;
}

//display employees sorted by salary
void inorder(BST root) {
    if (root != NULL) {
        inorder(root->left);
        printf("Name: %-15s | Salary: %d\n", root->name, root->salary);
        inorder(root->right);
    }
}

//minimum salary
BST findMin(BST root) {
    if (root == NULL)
        return NULL;
    while (root->left != NULL)
        root = root->left;
    return root;
}

//maximum salary
BST findMax(BST root) {
    if (root == NULL)
        return NULL;
    while (root->right != NULL)
        root = root->right;
    return root;
}

//total salary expense
int totalSalary(BST root) {
    if (root == NULL)
        return 0;
    return root->salary + totalSalary(root->left) + totalSalary(root->right);
}

int main() {
    BST root = NULL;
    int choice, salary;
    char name[30];

    do {
        printf("\n--- Employee Database using BST ---\n");
        printf("1. Add Employee\n");
        printf("2. Display Employees (by Salary)\n");
        printf("3. Employee with Minimum Salary\n");
        printf("4. Employee with Maximum Salary\n");
        printf("5. Total Monthly Salary Expense\n");
        printf("6. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
        case 1:
            printf("Enter Employee Name: ");
            scanf("%s", name);
            printf("Enter Salary: ");
            scanf("%d", &salary);
            root = insertEmp(root, name, salary);
            break;

        case 2:
            if (root == NULL)
                printf("No employees to display.\n");
            else {
                printf("\nEmployees sorted by salary:\n");
                inorder(root);
            }
            break;

        case 3: {
            BST minEmp = findMin(root);
            if (minEmp)
                printf("Employee with Minimum Salary: %s (%d)\n", minEmp->name, minEmp->salary);
            else
                printf("No employees in database.\n");
            break;
        }

        case 4: {
            BST maxEmp = findMax(root);
            if (maxEmp)
                printf("Employee with Maximum Salary: %s (%d)\n", maxEmp->name, maxEmp->salary);
            else
                printf("No employees in database.\n");
            break;
        }

        case 5:
            printf("Total Monthly Expense on Salaries: %d\n", totalSalary(root));
            break;

        case 6:
            printf("Exiting...\n");
            break;

        default:
            printf("Invalid choice! Try again.\n");
        }
    } while (choice != 6);

    return 0;
}
