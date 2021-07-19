#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


#define MAXWORD 100


struct tnode {
    char* word;
    int count;
    struct tnode* left;
    struct tnode* right;
};

struct tnode *talloc(void);
struct tnode* addtree(struct tnode* p, char* w);
void treeprint(struct tnode*);
char* getline();


int main(void)
{
    struct tnode* root = NULL;
    char* str = getline();
    const char s[2] = " ";
    char *token[20];
    int i = 1;

    /* get the first token */
    token[0] = strtok(str, s);

    /* walk through other tokens */
    while (token != NULL) {
        token[i] = strtok(NULL, s);
        root = addtree(root, token[i]);
        treeprint(root);
        i++;
    }

}


struct tnode* addtree(struct tnode* p, char* w) {

    int cond;

    if (p == NULL) {
        p = talloc();
        p->word = _strdup(w);
        p->count = 1;
        p->left = p->right = NULL;
    }
    else if ((cond = strcmp(w, p->word)) == 0)
        p->count++;
    else if (cond < 0)
        p->left = addtree(p->left, w);
    else
        p->right = addtree(p->right, w);
    return p;
}


void treeprint(struct tnode* p) {

    if (p != NULL) {
        treeprint(p->left);
        printf("%4d %s\n", p->count, p->word);
        treeprint(p->right);
    }
}


struct tnode *talloc(void) {
    return (struct tnode* ) malloc(sizeof(struct tnode));
}


char* getline() {

    char str[MAXWORD], ch;
    int i;
    printf("Enter a string: ");
    i = 0;
    ch = getchar();

    while (ch != '\n')
    {
        str[i] = ch;
        i++;
        ch = getchar();
    }
    str[i] = '\0';

    return str;
}