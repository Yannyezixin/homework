#include "expre.h"

char output[50];

/**
 * 获取优先级
 *
 * @param c 需要判断的字符
 * @param flag: 字符是否在栈中， 0表示不在，1表示在
 */
int get_precedence(char c, int flag)
{
    if (c == '+' || c == '-') {
        return 1;
    } else if (c == '*' || c == '/') {
        return 2;
    } else if (c == '(' && flag == 0) {
        return 3;
    } else if (c == '(' && flag == 1) {
        return 0;
    } else {
        return -1;
    }
}


/**
 * 判断是否为操作符
 *
 * @return 1 是 | 0 否
 */
int is_operator(char c) {
    if (c == '+' || c == '-' || c == '/' || c == '*' || c == '(' || c == ')') {
        return 1;
    } else {
        return 0;
    }
}

char *infix_to_postfix(char *infix, sq_stack sq)
{
    int index = 0;
    elem_type e;
    char c;
    while((c=*infix) != '\0') {
        if (is_operator(c) != 1) {
            output[index++] = c;
            infix++;
        } else {

            if(sq_stack_empty(sq) == SQ_TRUE) {
            // 栈为空时，操作符入栈
                sq_stack_push(&sq, c);
                infix++;
                continue;
            } else {

                if (c == ')') {
                // 遇到右括号，将栈元素弹出并输出直到遇到左括号, 左括号不输出
                    sq_stack_top(&sq, &e);
                    while(sq_stack_empty(sq) == SQ_FALSE && e != '(') {
                        output[index++] = e;
                        sq_stack_pop(&sq, &e);
                        sq_stack_top(&sq, &e);
                    }
                    sq_stack_pop(&sq, &e);
                    infix++;
                    continue;
                } else {
                // 从栈中弹出元素知道遇到发现更底优先级的元素（或栈为空)为止
                    int out_pre = get_precedence(c, 0);
                    sq_stack_top(&sq, &e);
                    while(sq_stack_empty(sq) == SQ_FALSE && get_precedence(e, 1) >= out_pre) {
                        output[index++] = e;
                        sq_stack_pop(&sq, &e);
                        sq_stack_top(&sq, &e);
                    }
                    sq_stack_push(&sq, c);
                    infix++;
                    continue;
                }
            }

        }
    }
    while (sq_stack_empty(sq) == SQ_FALSE) {
        sq_stack_top(&sq, &e);
        output[index++] = e;
        sq_stack_pop(&sq, &e);
    }
    output[index] = '\0';
    return output;
}
