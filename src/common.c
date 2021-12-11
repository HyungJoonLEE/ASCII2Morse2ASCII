/*
 * This file is part of dc_dump.
 *
 *  dc_dump is free software: you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation, either version 3 of the License, or
 *  (at your option) any later version.
 *
 *  Foobar is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with dc_dump.  If not, see <https://www.gnu.org/licenses/>.
 */


#include "common.h"
#include <stdio.h>
struct dc_posix_env env;
struct dc_error err;

char* character[] = { "A", "B", "C", "D", "E", "F", "G", "H", "I", "J",      // 10
                            "K", "L", "M", "N", "O", "P", "Q", "R", "S", "T",      // 10
                            "U", "V", "W", "X", "Y", "Z",                          // 6
                            "0", "1", "2", "3", "4", "5", "6", "7", "8", "9",      // 10
                            "&", "\'", "@", ")", "(", ":", ",", "=", "!", "*",     // 10
                            "%", "+", "\"", "?", "/", "\n", ".", "-", " "               // 9
};

char* morse[] = {".-", "-...", "-.-.", "-..", ".", "..-.", "--.", "....", "..", ".---",
         //       A      B       C      D      E      F      G       H      I      J

                       "-.-", ".-..", "--", "-.", "---", ".--.", "--.-", ".-.", "...", "-",
                 //       K     L      M      N      O      P      Q       R      S     T

                       "..-", "...-", ".--", "-..-", "-.--", "--..",
                 //       U     V      W      X       Y       Z

                       "-----", ".----", "..---", "...--", "....-", ".....", "-....", "--...", "---..", "----.",
                 //       0         1       2        3       4         5        6        7        8       9

                       ".-...", ".----.", ".--.-.", "-.--.-", "-.--.", "---...", "--..--", "-...-", "-.-.--", "-..-",
                 //       &         '         @        )         (         :         ,        =         !        *

                       "------..-.-----", ".-.-.", ".-..-.", "..--..", "-..-.", ".-.-", ".-.-.-", "-....-", " "
                 //          %               +         "         ?        /       \n         .        -
};


/***
 * create hashtable with size of 54 (key = character, data = morse)
 * set hash table with <key, data> form
 */
char* getMorseFromHashTable(char alphabet) {
    ENTRY e, *ep;
    int i;
    hcreate(55);

    for (i = 0; i < 55; i++) {
        e.key = character[i];
        e.data = morse[i];
        ep = hsearch(e, ENTER);
        if (ep == NULL) {
            fprintf(stderr, "entry failed\n");
            exit(EXIT_FAILURE);
        }
    }
    char str[2] = "";
    sprintf(str, "%c", alphabet);
    e.key = str;
    ep = hsearch(e, FIND);
//    printf("%s", (char*)ep->data);
    return ep->data;
}


LinkedList* createLinkedList() {
    LinkedList *pReturn = NULL;

    pReturn = (LinkedList *)malloc(sizeof(LinkedList));

    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(LinkedList));
    }
    else {
        printf("ERROR: Memory allocation failed.\n");
        return NULL;
    }

    return pReturn;
}


void addElement(LinkedList* pList, int position, ListNode element) {
    ListNode *pPreNode = NULL;
    ListNode *pNewNode = NULL;

    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (ListNode*)malloc(sizeof(ListNode));
            if (pNewNode != NULL) {
                *pNewNode = element;
                pNewNode->next = NULL;

                pPreNode = &(pList->headerNode);
                for (int i = 0; i < position; i++) {
                    pPreNode = pPreNode->next;
                }

                pNewNode->next = pPreNode->next;
                pPreNode->next = pNewNode;

                pList->currentElementCount++;
            }
            else {
                printf("ERROR: Memory allocation failed : addLLElement()\n");
            }
        }
        else {
            printf("ERROR: [%d] Index out of rage: addLLElement()\n", position);
        }
    }
}


ListNode* getElement(LinkedList* pList, int position) {
    ListNode *pReturn = NULL;
    ListNode *pNode = NULL;

    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            pNode = &(pList->headerNode);
            for (int i = 0; i <= position; i++) {
                pNode = pNode->next;
            }
            pReturn = pNode;
        }
    }
    return pReturn;
}


void displayLinkedListAlphabet(LinkedList* pList) {
    if (pList != NULL) {
        for (int i = 0; i < pList->currentElementCount; i++) {
            printf("%c", getElement(pList, i)->data);
        }
        printf("\n");
    }
    else {
        printf("No element.\n");
    }
}


void displayLinkedListMorse(LinkedList* pList) {
    if (pList != NULL) {
        for (int i = 0; i < pList->currentElementCount; i++) {
            printf("%s", getElement(pList, i)->morse);
        }
        printf("\n");
    }
    else {
        printf("No element.\n");
    }
}


/***
 * bit masking and bit shifting in terms of our protocol
 * computer can read 1byte minimum so once it hits 8 bits,
 * print the <unsigned char> and start with beginning
 *
 * <protocol>
 *  00 - eoc(E)
 *  01 - dash
 *  10 - dot
 *  11 - "\s"
 *  00 00 - eot
 */
void morseProcessing(LinkedList* pList) {
    if (pList != NULL) {
        for (int i = 0; i < pList->currentElementCount; i++) {
            int size = (int) strlen(getElement(pList, i)->morse) + 1;
            char morse_eoc[size];
            strcpy(morse_eoc, getElement(pList, i)->morse);
            strcat(morse_eoc, "E");
            bitShifting(morse_eoc, pList->currentElementCount);
        }
    }
}


unsigned char bitShifting(char* morse_string, int node_count) {
    static unsigned char byte = 0;
    unsigned char *p_byte = &byte;
    int length = (int)strlen(morse_string);
    static int n_count = 0;
    static int count = 0;

    for (int i = 0; i < length; i++) {
        switch (morse_string[i]) {
            case ('.'):
                case_dot(p_byte);
                count += 2;
                break;
            case ('-'):
                case_dash(p_byte);
                count += 2;
                break;
            case (' '):
                case_space(p_byte);
                count += 2;
                break;
            case ('E'):
                case_EOC(p_byte);
                count += 2;
                break;
            default:
                printf("Invalid Morse code\n");
        }
        if (count == 8) {
            writeToFile(byte);
            count = 0;
            byte = 0;
        }
    }
    n_count += 1;

    if (node_count == n_count) {
        if (count != 8) {
            byte <<= (unsigned char) 1U * (8 - count);
            writeToFile(byte);
        }
    }
}


void case_dot(unsigned char* byte) {
    *byte <<= 2U;
    *byte |= 2U;
}


void case_dash(unsigned char* byte) {
    *byte <<= 2U;
    *byte |= 1U;
}


void case_EOC(unsigned char* byte) {
    *byte <<= 2U;
}


void case_space(unsigned char* byte) {
    *byte <<= 2U;
    *byte |= 3U;
}


void writeToFile(unsigned char byte) {
    FILE *fp = fopen("morse_bin", "a");
    if (!fp) {
        printf("Can't open the file\n");
    }
    printf("%u\n", byte);
    fprintf(fp, "%c", byte);
    fclose(fp);
}


char* changeToBinary(int num) {
    char printable[9];
    bool bits[8];
    char *binaryString = malloc(9);
    dc_to_binary8(&env, (uint8_t) num, bits);
    dc_to_printable_binary8(&env, bits, printable);
    strcat(binaryString, printable);
//    printf("%s\n", binaryString);
    return binaryString;
}


char* readByTwoBits(const char* binaryString) {
    char* binary_to_morse = malloc(4);
    for (int i = 0; i < 8; i+=2) {
        if (binaryString[i] == '1' && binaryString[i + 1] == '0') {
            strcat(binary_to_morse, ".");
        }
        else if (binaryString[i] == '0' && binaryString[i + 1] == '1') {
            strcat(binary_to_morse, "-");
        }
        else if (binaryString[i] == '1' && binaryString[i + 1] == '1') {
            strcat(binary_to_morse, " ");
        }
        else if (binaryString[i] == '0' && binaryString[i + 1] == '0') {
            strcat(binary_to_morse, "E");
        }
    }
    return binary_to_morse;
}


MorseList* createMorseList() {
    MorseList *pReturn = NULL;

    pReturn = (MorseList *)malloc(sizeof(MorseList));

    if (pReturn != NULL) {
        memset(pReturn, 0, sizeof(MorseList));
    }
    else {
        printf("ERROR: Memory allocation failed.\n");
        return NULL;
    }

    return pReturn;
}


void addMorseElement(MorseList* pList, int position, MorseNode element) {
    MorseNode *pPreNode = NULL;
    MorseNode *pNewNode = NULL;

    if (pList != NULL) {
        if (position >= 0 && position <= pList->currentElementCount) {
            pNewNode = (MorseNode*)malloc(sizeof(MorseNode));
            if (pNewNode != NULL) {
                *pNewNode = element;
                pNewNode->next = NULL;

                pPreNode = &(pList->headerNode);
                for (int i = 0; i < position; i++) {
                    pPreNode = pPreNode->next;
                }

                pNewNode->next = pPreNode->next;
                pPreNode->next = pNewNode;

                pList->currentElementCount++;
            }
            else {
                printf("ERROR: Memory allocation failed : addLLElement()\n");
            }
        }
        else {
            printf("ERROR: [%d] Index out of rage: addLLElement()\n", position);
        }
    }
}


char* getAsciiFromHashTable(char* morse_string) {
    ENTRY e, *ep;
    int i;
    hcreate(55);

    for (i = 0; i < 55; i++) {
        e.key = morse[i];
        e.data = character[i];
        ep = hsearch(e, ENTER);
        if (ep == NULL) {
            fprintf(stderr, "entry failed\n");
            exit(EXIT_FAILURE);
        }
    }
//    char str[15] = "";
//    sprintf(str, "%s", morse_string);
    e.key = morse_string;
    ep = hsearch(e, FIND);
//    printf("%s", (char*)ep->data);
    return ep->data;
}


void displayLinkedListAscii(MorseList* pList) {
    if (pList != NULL) {
        for (int i = 0; i < pList->currentElementCount; i++) {
            printf("%s", getAsciiElement(pList, i)->data);
        }
        printf("\n");
    }
    else {
        printf("No element.\n");
    }
}


MorseNode* getAsciiElement(MorseList* pList, int position) {
    MorseNode *pReturn = NULL;
    MorseNode *pNode = NULL;

    if (pList != NULL) {
        if (position >= 0 && position < pList->currentElementCount) {
            pNode = &(pList->headerNode);
            for (int i = 0; i <= position; i++) {
                pNode = pNode->next;
            }
            pReturn = pNode;
        }
    }
    return pReturn;
}


int display(const char *str)
{
    printf("%s\n", str);

    return 0;
}


