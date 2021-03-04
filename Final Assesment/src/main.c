/******************************************************************************
 * Copyright (C) 2021 by Josh Illes
 *
 * Redistribution, modification or use of this software in source or binary
 * forms is permitted as long as the files maintain the copyright found in 
 * the LICENSE file.
 *
 * THE SOFTWARE IS PROVIDED 'AS IS', WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE
 *
 *****************************************************************************/

/**
 * @file main.c 
 * @brief This file is the main file for the final assessment of course1.
 *
 * @author Josh Illes
 * @date February 25th, 2021
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include "memory.h"

int main(){
    #ifdef COURSE1
        print("calling course1()\n");
        course1();  
    #endif

    printf("Testing out Memory.c\n");
    uint8_t testData[]={9,4,1,7,7,9,4,6,86,0,0,0,0,0,0,0,0,0};
    uint8_t samNumber[]={1,2,3,4,5,6,7,8,9};
    uint8_t moreData[]={8,6,7,5,3,0,9,1,1,1,1,1,1,1,1,1,1,9,8,7,6,5,4,3,2,1,0,0,1};
    volatile uint8_t reverseMe[]="Hello my name is Josh";

    printf("Location of testData: 0x%x\nLocation of samNumber: 0x%x\nLocation of moreData: 0x%x\n\n", testData, samNumber, moreData);

    // // Test move
    // uint8_t *newDest = my_memmove(testData, testData-0x0f00, sizeof(testData));
    // printf("Location of newDest: 0x%x\n", newDest);
    // for(uint8_t i=0; i<sizeof(testData); i++){
    //     printf("0x%x: %d\n", newDest+i, *(newDest+i));
    // }
    
    // // Another test move
    // newDest = my_memmove(moreData, newDest-0x10, sizeof(moreData));
    // printf("Location of newDest: 0x%x\n", newDest);
    // for(uint8_t i=0; i<sizeof(moreData); i++){
    //     printf("0x%x: %d\n", newDest+i, *(newDest+i));
    // }

    // // Test overlap move
    // newDest = my_memmove(moreData, moreData-0x03, sizeof(moreData));
    // printf("Location of newDest: 0x%x\n", newDest);
    // printf("  Original\t\t New\n");
    // for(uint8_t i=0; i<sizeof(moreData)+10; i++){
    //     printf("0x%x: %d\t\t0x%x: %d\n", moreData+i-5, *(moreData+i-5), newDest+i-5, *(newDest+i-5));
    // }


    // // Test copy
    // newDest = my_memcopy(moreData, testData, sizeof(moreData));
    // printf("  Original\t\t COPY\n");
    // for(uint8_t i=0; i<sizeof(moreData); i++){
    //     printf("0x%x: %d\t\t0x%x: %d\n", moreData+i, *(moreData+i), newDest+i, *(newDest+i));
    // }

    // // Test overlap copy
    // newDest = my_memcopy(moreData, moreData-0x03, sizeof(moreData));
    // printf("Location of newDest: 0x%x\n", newDest);
    // printf("  Original\t\t Copy\n");
    // for(uint8_t i=0; i<sizeof(moreData); i++){
    //     printf("0x%x: %d\t\t0x%x: %d\n", moreData+i, *(moreData+i), newDest+i, *(newDest+i));
    // }
    
    printf("Before setting values:\n");
    for(uint8_t i=0; i<sizeof(testData); i++){
        printf("0x%x: %d\n", testData+i, *(testData+i));
    }
    uint8_t *newDest = my_memset(testData, sizeof(testData), 5);
    printf("After setting values:\n");
    for(uint8_t i=0; i<sizeof(testData); i++){
        printf("0x%x: %d\n", testData+i, *(testData+i));
    }

    newDest = my_memzero(testData, sizeof(testData));
    printf("After zeroing values:\n");
    for(uint8_t i=0; i<sizeof(testData); i++){
        printf("0x%x: %d\n", testData+i, *(testData+i));
    }

    // printf("Before reverse: %s\n", reverseMe);
    for(uint8_t i=0; i<sizeof(reverseMe); i++){
        // printf("0x%x: %c\n", reverseMe+i, *(reverseMe+i));
    }
    uint8_t *reversed = my_reverse(reverseMe, sizeof(reverseMe));
    // printf("After reverse: %s\n", reversed);
    for(uint8_t i=0; i<sizeof(reverseMe); i++){
        // printf("0x%x: %c\n", reversed+i, *(reversed+i));
    }


    // printf("Before reverse: %s\n", samNumber);
    for(uint8_t i=0; i<sizeof(samNumber); i++){
        // printf("0x%x: %d\n", samNumber+i, *(samNumber+i));
    }
    reversed = my_reverse(samNumber, sizeof(samNumber));
    // printf("After reverse: %s\n", reversed);
    for(uint8_t i=0; i<sizeof(samNumber); i++){
        // printf("0x%x: %d\n", reversed+i, *(reversed+i));
    }

    return 0;
}

