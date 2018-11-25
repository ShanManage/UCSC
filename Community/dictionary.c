#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

struct word {
    struct word * next;
    char *name;
    char *description;
}; 

struct word * start = NULL;

struct word * createNode (char *word, char *des){
    struct word * newWord = (struct word *) malloc(sizeof(struct word));
    newWord -> name = word;
    newWord -> description = des;
    newWord -> next = NULL;

    return newWord;
}

void addWord (char *word, char *des){
    struct word * new = createNode(word, des);
    struct word * ptr = start;
    struct word * preptr = start;
    if (start != NULL){
        while (ptr != NULL){
            preptr = ptr;
            ptr = ptr->next;
        }
        preptr->next = new;
    }
    else{
        start = new;
    }
}

void findWord (char *arr){
    struct word * ptr = start;
    while (ptr != NULL){
        if(strcmp(ptr->name,arr) == 0){
            puts(ptr->description);
            return;
        }
        ptr = ptr->next;
    }
    if (ptr == NULL)
        printf("no word.!\n");
}

void deleteWord (char *arr){
    struct word * ptr = start;
    struct word * preptr = start;

    if(strcmp(start->name,arr) == 0){
        ptr = ptr->next;
        start = ptr;
        free(preptr);
    }else{
        while (ptr != NULL){
            if(strcmp(ptr->name,arr) == 0){
                preptr->next = ptr->next;
                free(ptr);
            }
            preptr = ptr;
            ptr = ptr->next;
        }
    }
}

void resetDic(){
    struct word *ptr = start;
    while (ptr != NULL){
        struct word *temp = ptr;
        start = ptr->next;
        ptr = ptr->next;
        free(temp);
    }
}

void init(){
    addWord("Photocopy","Photographic copy of printed or written matrical");
    addWord("Binding","strong covering holding the pages of a document");
    addWord("Laminate","overly with a layer of plastic or some other protective material");
    addWord("Dozen","set of twelve");
    addWord("Scan","convert image or file to a digital file");
    addWord("Typesetting","arrange text and images for document");
}
int main(){

    init();
    int run = 0;
    while (run == 0) {
        printf("1.Add any word.!\n");
        printf("2.Find any word.!\n");
        printf("3.Delete any word.!\n");
        printf("4.Reset dictionary.!\n");
        printf("5.quit programme.!\n");

        printf("=========================\n");

        char n;
        printf("what do you want.? => ");
        scanf("%c",&n);

        printf("=========================\n");

        char* wordName = (char *) calloc(50, sizeof(char));
        char temp;
        switch(n){
            case '1':
                ;
                char* description = (char *) calloc(100 , sizeof(char));
                printf("Name of word => ");
                scanf("%c", &temp);
                gets(wordName);
                printf("Disciption of word => ");
                gets(description);
                addWord(wordName, description);   
                printf("=========================\n");
                break;

            case '2':
                ;
                printf("What is the word.? => ");
                scanf("%s", wordName);
                scanf("%c", &temp);
                findWord(wordName);
                printf("=========================\n");
                break;

            case '3':
                ;
                printf("what is the word.? => ");
                scanf("%s", wordName);
                scanf("%c", &temp);
                deleteWord(wordName);
                printf("=========================\n");
                break;

            case '4':
                resetDic();
                scanf("%c", &temp);
                break;
                
            case '5':
                run = 1;
                scanf("%c", &temp);
                break;

            default:
                printf("Error.!\n");
                scanf("%c", &temp);
                return 0;
        }
    }
}