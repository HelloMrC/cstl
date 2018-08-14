/** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** ** **
 *  This file is part of cstl library
 *  Copyright (C) 2011 Avinash Dongre ( dongre.avinash@gmail.com )
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

#include "c_lib.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

static int
compare_e(const void* left, const void* right) {
    int *l = (int*)left;
    int *r = (int*)right;
    return (*l - *r);
}

static int
compare_e_ptr(const void* left, const void* right) {
    int *l = *((int**)left);
    int *r = *((int**)right);
    return (*l - *r);
}

static void
free_e(void* ptr) {
    if (ptr) {
        void *p = *((void **)ptr);
        if (p) {
            free(p);
        }
    }
}

static void
replace_values_using_iterators(struct cstl_deque* myDeq) {
    struct cstl_iterator *myItr;
    struct cstl_object *pElement;

    myItr = cstl_deque_new_iterator(myDeq);
    pElement = myItr->get_next(myItr);
    while (pElement) {
        const void* old_value = myItr->get_value(pElement);
        int new_value = *(int*)old_value;
        new_value = new_value * 2;
        myItr->replace_value(myItr, &new_value, sizeof(new_value));
        pElement = myItr->get_next(myItr);
    }
    cstl_deque_delete_iterator(myItr);
}
static struct cstl_deque*
create_deque() {
    int flip = 1;
    int i = 0;
    int limit = 20;
    struct cstl_deque* myDeq = cstl_deque_new(10, compare_e, NULL);
    assert((struct cstl_deque*)0 != myDeq);

    for (i = 0; i <= limit; i++) {
        if (flip) {
            cstl_deque_push_back(myDeq, &i, sizeof(int));
            flip = 0;
        } else {
            cstl_deque_push_front(myDeq, &i, sizeof(int));
            flip = 1;
        }
    }
    return myDeq;
}
static void
print_using_iterator(struct cstl_deque* myDeq) {
    struct cstl_iterator *myItr;
    struct cstl_object *pElement;

    printf("------------------------------------------------\n");
    myItr = cstl_deque_new_iterator(myDeq);
    pElement = myItr->get_next(myItr);
    while (pElement) {
        const void* value = myItr->get_value(pElement);
        printf("%d\n", *(int*)value);
        pElement = myItr->get_next(myItr);
    }
    cstl_deque_delete_iterator(myItr);
}

static void
test_with_deque_iterator() {
    struct cstl_deque* myDeq = create_deque();
    print_using_iterator(myDeq);
    replace_values_using_iterators(myDeq);
    print_using_iterator(myDeq);
    cstl_deque_delete(myDeq);
}

void
test_c_deque() {
    int flip = 1;
    int i = 0;
    int limit = 20;
    const void*  element = NULL;
    int j = 0;

    struct cstl_deque* myDeq = cstl_deque_new(10, compare_e, NULL);
    assert((struct cstl_deque*)0 != myDeq);

    for (i = 0; i <= limit; i++) {
        if (flip) {
            cstl_deque_push_back(myDeq, &i, sizeof(int));
            flip = 0;
        } else {
            cstl_deque_push_front(myDeq, &i, sizeof(int));
            flip = 1;
        }
    }
    cstl_deque_front(myDeq, &element);
    assert(*(int*)element == limit - 1);

    cstl_deque_back(myDeq, &element);
    assert(*(int*)element == limit);

    while (cstl_deque_empty(myDeq) != cstl_true) {
        cstl_deque_pop_front(myDeq);
    }
    cstl_deque_delete(myDeq);

    myDeq = cstl_deque_new(10, compare_e_ptr, free_e);
    for (i = 0; i <= limit; i++) {
        int *v = (int*)calloc(1, sizeof(int));
        memcpy(v, &i, sizeof(int));
        cstl_deque_push_back(myDeq, &v, sizeof(int*));
    }
    for (i = myDeq->head + 1; i < myDeq->tail; i++) {
        int **elem = (int **) cstl_deque_element_at(myDeq, i);
        if ( elem ) {
            assert(**elem == j++);
        }
    }
    cstl_deque_delete(myDeq);
    test_with_deque_iterator();
}
