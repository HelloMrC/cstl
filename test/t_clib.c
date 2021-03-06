/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
 *  This file is part of cstl library
 *  Copyright (C) 2011 Avinash Dongre ( dongre.avinash@gmail.com )
 *  Copyright (C) 2018 ssrlive ( ssrlivebox@gmail.com )
 * 
 *  Permission is hereby granted, free of charge, to any person obtaining a copy
 *  of this software and associated documentation files (the "Software"), to deal
 *  in the Software without restriction, including without limitation the rights
 *  to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 *  copies of the Software, and to permit persons to whom the Software is
 *  furnished to do so, subject to the following conditions:
 * 
 *  The above copyright notice and this permission notice shall be included in
 *  all copies or substantial portions of the Software.
 * 
 *  THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 *  IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 *  FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 *  AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 *  LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 *  OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN
 *  THE SOFTWARE.
 ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **/

#include <stdio.h>
extern void test_c_array();
extern void test_c_deque();
extern void test_c_tree();
extern void test_c_rb();
extern void test_c_set();
extern void test_c_map();
extern void test_c_slist();
extern void test_c_map();
extern void test_c_algorithms();

int main( int argc, char**argv ) {
    size_t i = 0;
    for (i = 0; i < 10000; i++)
    {
        printf("Performing test for red-black tree\n");
        test_c_rb();

        printf("Performing test for dynamic array\n");
        test_c_array();
        printf("Performing test for deque\n");
        test_c_deque();
        printf("Performing test for sets\n");
        test_c_set();
        printf("Performing test for map\n");
        test_c_map();
        printf("Performing test for slist\n");
        test_c_slist();
        printf("Performing algorithms tests\n");
        test_c_algorithms();
    }
    return 0;
}
