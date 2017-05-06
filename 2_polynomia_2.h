#ifndef POLYNOMIAL_H_  
#define POLYNOMIAL_H_  
  
  
#include <iostream>  
#include <stdlib.h>  
using namespace std;  
typedef int ElementType;  
typedef struct PolyNode *Polynomial;  
struct PolyNode{  
    ElementType coef;  
    ElementType expon;  
    Polynomial next;  
};  
  
Polynomial Initialize();  
Polynomial Find_kth(int k, Polynomial L);  
Polynomial Insert(ElementType x, int i, Polynomial L);  
Polynomial Delete(int i, Polynomial L);  
int Length(Polynomial L);  
Polynomial Read(int len);  
void PrintPolynomial(Polynomial L);  
Polynomial read(Polynomial L);  
void attach(int xishu, int zhishu, Polynomial *p);  
Polynomial Sum(Polynomial L1, Polynomial L2);  
Polynomial Multiplication(Polynomial L1, Polynomial L2);  
  
  
Polynomial Initialize(){  
    Polynomial L;  
    L = (Polynomial)malloc(sizeof(struct PolyNode));  
    L->next = NULL;  
    return L;  
}  
  
Polynomial Find_kth(int k, Polynomial L){  
    Polynomial Lp = L;  
    int i = 1;  
    while(Lp != NULL && i < k){  
        Lp = Lp->next;  
        i++;  
    }  
    if(i == k){  
        return Lp;  
    }else{  
        return NULL;  
    }  
}  
//在第i个节点前面  
Polynomial Insert(ElementType xishu, ElementType zhishu, int i, Polynomial L){  
    Polynomial p,s;  
    if(i == 1){  
        s = (Polynomial)malloc(sizeof(struct PolyNode));  
        s->coef = xishu;  
        s->expon = zhishu;  
        s->next = L;  
        return s;  
    }  
    p = Find_kth(i-1, L);  
    if(p == NULL)return NULL;  
    else  
    {  
        s = (Polynomial)malloc(sizeof(struct PolyNode));  
        s->coef = xishu;  
        s->expon = zhishu;  
        s->next = p->next;  
        p->next = s;  
        return L;  
    }  
}  
Polynomial Delete(int i, Polynomial L){  
    Polynomial p, s;  
    if(i == 1){  
        s = L;  
        if(L != NULL)L = L->next;  
        else  
            return NULL;  
        free(s);  
        return L;  
    }  
    p = Find_kth(i-1, L);  
    if(p == NULL){  
        return NULL;  
    }else if(p->next == NULL){  
        return NULL;  
    }else{  
        s = p->next;  
        p->next = s->next;  
        free(s);  
        return L;  
    }  
}  
int Length(Polynomial L){  
    Polynomial Lp = L;  
    int i = 0;  
    while(Lp){  
        i++;  
        Lp = Lp->next;  
    }  
    return i;  
}  
void PrintPolynomial(Polynomial L){  
    Polynomial Lp = L;  
    int i = 0;  
    while(Lp){  
        if(i){  
            cout<<' ';  
        }  
        cout<<Lp->coef<<' '<<Lp->expon;  
        i++;  
        if(Lp->next == NULL)break;  
        Lp = Lp->next;  
    }  
    if(Lp == NULL){  
        cout<<0<<' '<<0;  
    }  
}  
Polynomial read(int len, Polynomial L){  
    int xishu, zhishu;  
    for(int i = 0; i < len; i++){  
        cin>>xishu>>zhishu;  
        L = Insert(xishu, zhishu, i+1, L);  
    }  
    L = Delete(len+1, L);  
    return L;  
}  
void attach(int xishu, int zhishu, Polynomial *p){  
    Polynomial P;  
    P = Initialize();  
    P->coef = xishu;  
    P->expon = zhishu;  
    P->next = NULL;  
    (*p)->next = P;  
    *p = P;  
}  
Polynomial Sum(Polynomial L1, Polynomial L2){  
    if(!L1 && !L2){  
        if(!L1){  
            return L2;  
        }else{  
            return L1;  
        }  
    }  
    Polynomial L, p, s;  
    int sum;  
    L = Initialize();  
    p = Initialize();  
    s = Initialize();  
    L = p;  
    while(L1 && L2){  
        if(L1->expon < L2->expon){  
            if(L2->coef){  
                attach(L2->coef, L2->expon, &p);  
            }  
            L2 = L2->next;  
        }else if(L1->expon > L2->expon){  
            if(L1->coef){  
                attach(L1->coef, L1->expon, &p);  
            }  
            L1 = L1->next;  
        }else{  
            sum = L1->coef + L2->coef;  
            if(sum){  
                attach(sum, L2->expon, &p);  
            }  
            L1 = L1->next;  
            L2 = L2->next;  
        }  
    }  
    if(L1){  
        for(; L1; L1 = L1->next){  
            attach(L1->coef, L1->expon, &p);  
        }  
    }  
    if(L2){  
        for(; L2; L2 = L2->next){  
            attach(L2->coef, L2->expon, &p);  
        }  
    }  
    p->next = NULL;  
    s = L;  
    L = L->next;  
    free(s);  
    return L;  
}  
Polynomial Multiplication(Polynomial P1, Polynomial P2){  
    Polynomial P, temp1, temp2, Rear, temp;  
    int c, e;  
    if(!P1 || !P2)  
        return NULL;  
    temp1 = P1;  
    temp2 = P2;  
    P = Initialize();  
    P->next = NULL;  
    Rear = P;  
    while(temp2){  
        c = temp1->coef * temp2->coef;  
        e = temp1->expon + temp2->expon;  
        if(c != 0){  
            attach(c, e, &Rear);  
        }  
        temp2 = temp2->next;  
    }  
    temp1 = temp1->next;  
    while(temp1){  
        temp2 = P2, Rear = P;  
        while(temp2){  
            c = temp1->coef * temp2->coef;  
            e = temp1->expon + temp2->expon;  
            if(c != 0){  
                while(Rear->next && Rear->next->expon > e)  
                    Rear = Rear->next;  
                if(Rear->next && Rear->next->expon == e){  
                    if(Rear->next->coef + c)  
                        Rear->next->coef += c;  
                    else{  
                        temp = Rear->next;  
                        Rear->next = temp->next;  
                        free(temp);  
                    }  
                }  
                else{  
                    temp = Initialize();  
                    temp->coef = c;  
                    temp->expon = e;  
                    temp->next = Rear->next;  
                    Rear->next = temp;  
                    Rear = Rear->next;  
                }  
            }  
            temp2 = temp2->next;  
        }  
        temp1 = temp1->next;  
    }  
    temp = P;  
    P = P->next;  
    free(temp);  
    return P;  
}  
  
  
#endif /* POLYNOMIAL_H_ */  
