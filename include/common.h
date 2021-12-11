#ifndef MORSE_COMMON_H
#define MORSE_COMMON_H

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
#include <dc_application/command_line.h>
#include <dc_application/config.h>
#include <dc_application/defaults.h>
#include <dc_application/environment.h>
#include <dc_application/options.h>
#include <dc_posix/dc_stdlib.h>
#include <dc_posix/dc_string.h>
#include <dc_util/bits.h>
#include <getopt.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <dc_posix/dc_unistd.h>
#include <unistd.h>
#include <ctype.h>
#include <search.h>

/**
 * A function to be documented.
 *
 * @param str a parameter to be documented.
 * @return a return value to be documented.
 */

typedef struct ListNodeType {
    char data;
    char* morse;
    struct ListNodeType *next;
}ListNode;


typedef struct LinkedListType {
    int currentElementCount;
    ListNode headerNode;
}LinkedList;

typedef struct MorseNodeType {
    char* morse;
    char* data;
    struct MorseNodeType *next;
}MorseNode;


typedef struct MorseListType {
    int currentElementCount;
    MorseNode headerNode;
}MorseList;


char* getMorseFromHashTable(char alphabet);
LinkedList* createLinkedList();
void displayLinkedListAlphabet(LinkedList* pList);
void displayLinkedListMorse(LinkedList* pList);
ListNode* getElement(LinkedList* pList, int position);
void addElement(LinkedList* pList, int position, ListNode element);
void morseProcessing(LinkedList* pList);
unsigned char bitShifting(char* morse_string, int count);
void case_dot(unsigned char* byte);
void case_dash(unsigned char* byte);
void case_space(unsigned char* byte);
void case_EOC(unsigned char* byte);
void writeToFile(unsigned char byte);

char* changeToBinary(int num);
char* readByTwoBits(const char* binaryString);
MorseList* createMorseList();
void addMorseElement(MorseList* pList, int position, MorseNode element);
char* getAsciiFromHashTable(char* morse);
void displayLinkedListAscii(MorseList* pList);
MorseNode* getAsciiElement(MorseList* pList, int position);


int display(const char *str);



#endif // TEMPLATE_COMMON_H
