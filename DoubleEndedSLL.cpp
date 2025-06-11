#include<stdio.h>
#include<stdlib.h>
struct DESLL {
    int data;
    struct DESLL *next;
};
struct DESLL *S = NULL;
struct DESLL *T = NULL;
void IB_DESLL();
void IF_DESLL();
void I_POS_DESLL();
void I_VAL_DESLL();
void DEL_F_DESLL();
void DEL_B_DESLL();
void DEL_POS_DESLL();
void DEL_VAL_DESLL();
void Disp_DESLL();
void Count();
void Search();

int main() {
    int choice;
    while(1) {
        printf("[ 1 ]  for INSERT FROM BACK\n");
        printf("[ 2 ]  for INSERT FROM FRONT\n");
        printf("[ 3 ]  for INSERT BY POSITION\n");
        printf("[ 4 ]  for INSERT BY VALUE\n");
        printf("[ 5 ]  for DELETE FROM BACK\n");
        printf("[ 6 ]  for DELETE FROM FRONT\n");
        printf("[ 7 ]  for DELETE BY POSITION\n");
        printf("[ 8 ]  for DELETE BY VALUE\n");
        printf("[ 9 ]  for DISPLAY\n");
        printf("[ 10 ] for COUNT\n");
        printf("[ 11 ] for SEARCH\n");
        printf("[ 12 ] EXIT THE PROGRAM!!!!!\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch(choice) {
            case 1: IB_DESLL();
                break;
            case 2: IF_DESLL();
                break;
            case 3: I_POS_DESLL();
                break;
            case 4: I_VAL_DESLL();
                break;
            case 5: DEL_B_DESLL(); 
                break;
            case 6: DEL_F_DESLL();
                break;
            case 7: DEL_POS_DESLL();
                break;
            case 8: DEL_VAL_DESLL();
                break;
            case 9: Disp_DESLL();
                break;
            case 10: Count();
                break;
            case 11: Search();
                break;
            case 12: 
                printf("EXITED SUCCESSFULLY\n");
                return 0;
            default: printf("INVALID CHOICE ENTERED\n");
        }
    }
}

void IB_DESLL() {
    int x;
    struct DESLL *p;
    p = (struct DESLL *)malloc(sizeof(struct DESLL));
    if(p == NULL)
        printf("INSUFFICIENT MEMORY\n");
    else {
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &x);
        p->data = x;
        p->next = NULL;
        if(S == NULL) {
            S = T = p;
        } else {
            T->next = p;
            T = p;  
        }
        printf("Element %d inserted at the back\n", x);
    }
}

void IF_DESLL() {
    struct DESLL *p;
    int x;
    p = (struct DESLL *)malloc(sizeof(struct DESLL));
    if(p == NULL)
        printf("INSUFFICIENT MEMORY\n");
    else {
        printf("ENTER THE ELEMENT: ");
        scanf("%d", &x);
        p->data = x;
        p->next = S;
        S = p;
        if(T == NULL)
            T = p;
            
        printf("Element %d inserted at the front\n", x);
    }
}

void I_POS_DESLL() {
    struct DESLL *p, *t;
    int el, pos, i = 1, count = 0;

    t = S;
    while(t != NULL) {
        count++;
        t = t->next;
    }
    
    printf("Enter Element To INSERT: ");
    scanf("%d", &el);
    printf("ENTER position to insert at (1 to %d): ", count + 1);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > count + 1) {
        printf("Invalid position! Valid range is 1 to %d\n", count + 1);
        return;
    }
    
    p = (struct DESLL*)malloc(sizeof(struct DESLL));
    if(p == NULL) {
        printf("INSUFFICIENT MEMORY\n");
        return;
    }
    
    p->data = el;
   
    if(pos == 1) {
        p->next = S;
        S = p;
        if(T == NULL)
            T = p;
            
        printf("Element %d inserted at position %d\n", el, pos);
        return;
    }
    
    if(pos == count + 1) {
        p->next = NULL;
        T->next = p;
        T = p;
        printf("Element %d inserted at position %d\n", el, pos);
        return;
    }
    
    t = S;
    for(i = 1; i < pos - 1; i++) {
        t = t->next;
    }
    
    p->next = t->next;
    t->next = p;
    printf("Element %d inserted at position %d\n", el, pos);
}

void I_VAL_DESLL() {
    struct DESLL *p, *t;
    int newEl, searchVal;
    int found = 0;
    
    if(S == NULL) {
        printf("LIST IS EMPTY!\n");
        return;
    }
    
    printf("Enter the value after which to insert: ");
    scanf("%d", &searchVal);
    printf("Enter the new element to insert: ");
    scanf("%d", &newEl);
    
    p = (struct DESLL *)malloc(sizeof(struct DESLL));
    if(p == NULL) {
        printf("INSUFFICIENT MEMORY\n");
        return;
    }
    
    p->data = newEl;
    
    t = S;
    while(t != NULL) {
        if(t->data == searchVal) {
            p->next = t->next;
            t->next = p;
        
            if(t == T) {
                T = p;
            }
            
            found = 1;
            printf("Element %d inserted after value %d\n", newEl, searchVal);
            break;
        }
        t = t->next;
    }
    
    if(!found) {
        printf("Value %d not found in the list\n", searchVal);
        free(p);
    }
}

void DEL_F_DESLL() {
    struct DESLL *t;
    if(S == NULL) {
        printf("LIST IS EMPTY!!\n");
    } else {
        t = S;
        printf("Node deleted successfully - data = %d at address %p\n", t->data, t);
        S = S->next;
        
        if(S == NULL) {
            T = NULL;
        }
        
        free(t);
    }
}

void DEL_B_DESLL() {
    struct DESLL *t, *prev;
    if(S == NULL) {
        printf("LIST IS EMPTY!!\n");
        return;
    }
    if(S == T) {
        printf("Node deleted successfully - data = %d at address %p\n", S->data, S);
        free(S);
        S = T = NULL;
        return;
    }
    
    t = S;
    while(t->next != T) {
        t = t->next;
    }
    
    printf("Node deleted successfully - data = %d at address %p\n", T->data, T);
    free(T);
    T = t;     
    T->next = NULL;
}

void DEL_POS_DESLL() {
    struct DESLL *temp, *prev;
    int pos, i = 1, count = 0;
    
    if(S == NULL) {
        printf("LIST IS EMPTY!!\n");
        return;
    }
    
    temp = S;
    while(temp != NULL) {
        count++;
        temp = temp->next;
    }
    
    printf("Enter position to delete (1 to %d): ", count);
    scanf("%d", &pos);
    
    if(pos < 1 || pos > count) {
        printf("Invalid position! Valid range is 1 to %d\n", count);
        return;
    }
    
    if(pos == 1) {
        temp = S;
        S = S->next;
        
        if(S == NULL) {
            T = NULL;
        }
        
        printf("Node at position %d deleted successfully - data = %d\n", pos, temp->data);
        free(temp);
        return;
    }
    
    temp = S;
    for(i = 1; i < pos; i++) {
        prev = temp;
        temp = temp->next;
    }
    
    prev->next = temp->next;
    
    if(temp == T) {
        T = prev;
    }
    
    printf("Node at position %d deleted successfully - data = %d\n", pos, temp->data);
    free(temp);
}

void DEL_VAL_DESLL() {
    struct DESLL *temp, *prev = NULL;
    int val, found = 0;
    
    if(S == NULL) {
        printf("LIST IS EMPTY!!\n");
        return;
    }
    
    printf("Enter value to delete: ");
    scanf("%d", &val);
    
    if(S->data == val) {
        temp = S;
        S = S->next;
        
        if(S == NULL) {
            T = NULL;
        }
        
        printf("Node with value %d deleted successfully\n", val);
        free(temp);
        found = 1;
        return;
    }
    
    temp = S;
    while(temp != NULL) {
        if(temp->data == val) {
            prev->next = temp->next;
            
            if(temp == T) {
                T = prev;
            }
            
            printf("Node with value %d deleted successfully\n", val);
            free(temp);
            found = 1;
            break;
        }
        prev = temp;
        temp = temp->next;
    }
    
    if(!found) {
        printf("Value %d not found in the list\n", val);
    }
}

void Disp_DESLL() {
    struct DESLL *t;
    int i = 1;

    if(S == NULL) {
        printf("\n-------------------\n");
        printf("List is empty !!!\n");
        printf("-------------------\n");
    } else {
        t = S;
        printf("\nList Elements:\n");
        printf("------------------------------------------\n");
        printf("Head points to = %p | Address of Head = %p\n", S, &S);
        printf("Tail points to = %p | Address of Tail = %p\n", T, &T);
        
        while(t != NULL) {
            printf("\nIn Node: %d INFO:\n", i);
            printf("t->data = %d | Address = %p | next contains = %p\n", t->data, t, t->next);
            t = t->next;
            i++;
        }
        
        printf("------------------------------------------\n");
    }
}

void Count() {
    struct DESLL *p;
    int c = 0;
    p = S;
    if(S == NULL) {
        printf("LIST IS EMPTY\n");
    } else {
        while(p != NULL) {
            c++;
            p = p->next;
        }
        printf("Count is %d\n", c);
    }
}

void Search() {
    struct DESLL *p;
    int c = 0, key = 0;
    int el;
    p = S;
    
    if(S == NULL) {
        printf("LIST IS EMPTY\n");
        return;
    }
    
    printf("ENTER ELEMENT TO SEARCH: ");
    scanf("%d", &el);
    
    while(p != NULL) {
        c++;
        if(p->data == el) {
            printf("ELEMENT '%d' FOUND AT POSITION %d (ADDRESS: %p)\n", el, c, p);
            key++;
        }
        p = p->next;
    }
    
    if(!key) {
        printf("ELEMENT %d NOT FOUND!!!!\n", el);
    } else {
        printf("Element %d found %d time(s)\n", el, key);
    }
}
