#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <stdbool.h>
#include <ctype.h>

typedef struct Chest {
    int IDF;
    char message[100];
    struct Chest* next;
} Chest;

// Adding a chest 1st option
void addChest(Chest** L, int idf, char string[100]) {
    Chest* P = (Chest*)malloc(sizeof(Chest));
    P->IDF = idf;
    strncpy(P->message, string, 100);
    P->message[99] = '\0';
    P->next = NULL;

    if (*L == NULL || (*L)->IDF > idf) {
        P->next = *L;
        *L = P;
        return;
    }

    Chest* current = *L;
    while (current->next != NULL && current->next->IDF < idf) {
        current = current->next;
    }

    P->next = current->next;
    current->next = P;
}

// Deleting a chest 2nd option
void deleteChest(Chest** L, int idf) {
    if (*L == NULL) return;

    Chest* P;

    if ((*L)->IDF == idf) {
        P = *L;
        *L = (*L)->next;
        free(P);
        return;
    }

    Chest* prev = *L;
    P = (*L)->next;

    while (P != NULL && P->IDF != idf) {
        prev = P;
        P = P->next;
    }

    if (P != NULL) {
        prev->next = P->next;
        free(P);
    }
}

// Modify a chest 3rd option ig
void modifyChest(Chest* L, int idf, char string[100]) {
    Chest* P = L;

    while (P != NULL) {
        if (P->IDF == idf) {
            strncpy(P->message, string, 100);
            P->message[99] = '\0'; 
        }
        P = P->next;
    }
}

// Display chests 4th option
void displayChests(Chest* L) {
    Chest* P = L;

    if (P == NULL) {
        printf("No chests in the list.\n");
        return;
    }

    printf("List of chests:\n");
    while (P != NULL) {
        printf("IDF: %d, Message: \"%s\"\n", P->IDF, P->message);
        P = P->next;
    }
}


int checkPrime(int n) {
    if (n <= 1) return 0;
    for (int i = 2; i <= sqrt(n); i++) {
        if (n % i == 0){ 
            return 0;
    }
}
    return 1;
}

// extracting 5th option
int extractNum(char message[100]) {
    int length = strlen(message);
    if (!checkPrime(length)){
        return -1;
    }

    int number = 0;
    bool found = false;

    for (int i = 0; message[i] != '\0'; i++) {

        if (isdigit(message[i])) {

            number = number * 10 + (message[i] - '0');
            found = true;

        } else if (found) {

            break;
        }
    }

    return found ? number : -1;
}

// bismillah 


int main() {
    Chest* L = NULL;
    int choice, idf;
    char message[100];

    do {
        printf("\n\n=====LOVELY SCAM CHEST MENU! =====\n");
        printf("1. Add a chest\n");
        printf("2. Delete a chest ya greedy!\n");
        printf("3. Modify a chest\n");
        printf("4. Display chests\n");
        printf("5. Extract number (by the prime string rules hm hm)\n");
        printf("0. Exit\n\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        getchar();

        switch (choice) {
            case 1:
                printf("Enter chest IDF: ");
                scanf("%d", &idf);
                getchar();
                printf("leave your mark on the chest, *wink*: ");
                fgets(message, sizeof(message), stdin);
                message[strcspn(message, "\n")] = 0;
                addChest(&L, idf, message);
                break;

            case 2:
                printf("Enter chest IDF to delete: ");
                scanf("%d", &idf);
                deleteChest(&L, idf);
                break;

            case 3:
                printf("Enter chest IDF to modify: ");
                scanf("%d", &idf);
                getchar();
                printf("Enter new message: ");
                fgets(message, sizeof(message), stdin);
                modifyChest(L, idf, message);
                break;

            case 4:
                displayChests(L);
                break;

            case 5: {

                Chest* current = L;
                int finalnumber = 0;
                bool anyFound = false;

                while (current != NULL) {
                    int num = extractNum(current->message);
                    if (num != -1) {
                        finalnumber += num;
                        anyFound = true;
                    }
                    current = current->next;
                }

                if (anyFound) {
                    printf("lottery combination: %d\n", finalnumber);
                } else {
                    printf("allah ghaleb no gold for you.\n");
                }
                break;
            }

            case 0:
                printf("BYE JACK SPARROW\n");
                break;

            default:
                printf("Invalid try again.\n");
        }
    } while (choice != 0);

    return 0;
}
