#include "smart_calc.h"
#include <complex.h>

double s21_smart_calc_double(const char * mainString, double xvalue){

    struct node conclusion[255];
    struct node stack[255];
    struct node result_stack[510];
    for (int i = 0; i < 255; i++) {
        stack[i].value = 0;
        stack[i].function = 'N';
        stack[i].priority = 0;
        conclusion[i].value = 0;
        conclusion[i].function = 'N';
        conclusion[i].priority = 0;
    }
    int conln_num = -1;
    int stack_num = -1;
    char * inputString = strdup(mainString);

    int flag = 1;

    while (*inputString != '\0' && flag == 1){
        if (s21_isdigit(*inputString)){
            conln_num++;
            if (*inputString == 'x'){
                conclusion[conln_num].value = xvalue;
                conclusion[conln_num].priority = 0;
                conclusion[conln_num].function = 'N';
                inputString++;
            } else s21_num_parser(&inputString, &conclusion[conln_num]);
        } else if (s21_isfunction(*inputString)){
            stack_num++;
            s21_function_parser(&inputString, &stack[stack_num]);
            stack_num++;
            stack[stack_num].function = '('; stack[stack_num].value = 0; stack[stack_num].priority = -1;
        } else if(*inputString == '('){
            stack_num++; stack[stack_num].function = '('; stack[stack_num].value = 0; stack[stack_num].priority = -1; inputString++;
        } else if (s21_isoperator(*inputString)){
            s21_operator_parser(&inputString, stack, &stack_num, conclusion, &conln_num);
        }else if (*inputString == ')'){
            flag = s21_bracket_parser(&inputString, stack, &stack_num, conclusion, &conln_num);
        }else inputString++;
    }
    int result_stack_lenght = conln_num;
    if (!isempty_node(stack, 0)) result_stack_lenght += stack_num + 1;
    s21_combine_stacks(result_stack, &result_stack_lenght,  stack, &stack_num, conclusion, &conln_num);

    double result = 0;
    notation_conversion(result_stack, &result_stack_lenght, &result);
    return result;
}

char *s21_smart_calc(const char * mainString, double xvalue){

    struct node conclusion[255];
    struct node stack[255];
    struct node result_stack[510];
    for (int i = 0; i < 255; i++) {
        stack[i].value = 0;
        stack[i].function = 'N';
        stack[i].priority = 0;
        conclusion[i].value = 0;
        conclusion[i].function = 'N';
        conclusion[i].priority = 0;
    }
    int conln_num = -1;
    int stack_num = -1;
    char * inputString = strdup(mainString);

    int flag = 1;

    while (*inputString != '\0' && flag == 1){
        if (s21_isdigit(*inputString)){
            conln_num++;
            if (*inputString == 'x'){
                conclusion[conln_num].value = xvalue;
                conclusion[conln_num].priority = 0;
                conclusion[conln_num].function = 'N';
                inputString++;
            } else s21_num_parser(&inputString, &conclusion[conln_num]);
        } else if (s21_isfunction(*inputString)){
            stack_num++;
            s21_function_parser(&inputString, &stack[stack_num]);
            stack_num++;
            stack[stack_num].function = '('; stack[stack_num].value = 0; stack[stack_num].priority = -1;
        } else if(*inputString == '('){
            stack_num++; stack[stack_num].function = '('; stack[stack_num].value = 0; stack[stack_num].priority = -1; inputString++;
        } else if (s21_isoperator(*inputString)){
            s21_operator_parser(&inputString, stack, &stack_num, conclusion, &conln_num);
        }else if (*inputString == ')'){
            flag = s21_bracket_parser(&inputString, stack, &stack_num, conclusion, &conln_num);
        }else inputString++;
    }
    int result_stack_lenght = conln_num;
    if (!isempty_node(stack, 0)) result_stack_lenght += stack_num + 1;
    s21_combine_stacks(result_stack, &result_stack_lenght,  stack, &stack_num, conclusion, &conln_num);

    static char str[32];
    double result = 0;
    for (int i = 0; i <= result_stack_lenght; i++){
        if (result_stack[i].function == '(') flag = 0;
    }
    notation_conversion(result_stack, &result_stack_lenght, &result);
    if (flag == 1 && result != INFINITY) sprintf(str, "%.7g", result);
    else strcpy(str, "ERROR");
    return str;
}

int notation_conversion(struct node *stack, int *stack_len, double * result){  // преобразование из обратной польской нотации в число
    int flag = 0;
    int i = 0;
    while (flag == 0 && *stack_len > 0){
        if (s21_isoperator(stack[i].function)){
            if (i >= 2){
                stack[i - 2].value = s21_binary(stack[i - 2].value, stack[i - 1].value, stack[i].function);
                left_shift(stack, stack_len, i+1, 2);
                i = 0;
            } else flag = 1;
        } else  if (s21_isfunction(stack[i].function)){
            if (i >= 1){
                stack[i - 1].value = s21_unarny(stack[i - 1].value, stack[i].function);
                left_shift(stack, stack_len, i+1, 1);
                i = 0;
            } //else flag = 1;
        } else i++;

    }
    *result = stack[0].value;
    return flag;
}

int left_shift(struct node *stack, int *stack_len, int start, int amount){    // сдвиг стека влево на указанное количество нод
    int res = 0;
    if (start > amount){
        for (int j = start; j <= *stack_len; j++){
            stack[j - amount] = stack[j];
        }
        *stack_len -= amount;
        res = 1;
    }
    return res;
}

int isempty_node(struct node * result_stack, int num){
    int res = 0;
    if (result_stack[num].value == 0 && result_stack[num].function == 'N' && result_stack[num].priority == 0) res = 1;
    return res;
}

int s21_combine_stacks(struct node * result_stack, int *result_stack_num, struct node *stack, int *last_stack_num, struct node *concl, int *last_concl_num){  //объединяет стек и выходную строку
    for (int i = 0; i <= *last_concl_num; i++){
        result_stack[i].value = concl[i].value;
        result_stack[i].function = concl[i].function;
        result_stack[i].priority = concl[i].priority;
    }
    if (!isempty_node(stack, 0)){
        for (int i = *last_stack_num; i >= 0; i--){
            result_stack[*result_stack_num - i].value = stack[i].value;
            result_stack[*result_stack_num - i].function = stack[i].function;
            result_stack[*result_stack_num - i].priority = stack[i].priority;
        }
    }
    return 0;
}

int s21_bracket_parser(char ** mainString, struct node * stack, int * last_stack_num, struct node * concl, int * last_concl_num){
    int res = 1;
    while((stack[*last_stack_num].function != '(') && *last_stack_num > 0){
        move_node(stack, last_stack_num, concl, last_concl_num);
        *last_stack_num-=1;
        if (*last_stack_num == -1) res = 0;
    }
    if (stack[*last_stack_num].function == '('){
        clear_node(stack, last_stack_num);
        *last_stack_num-=1;
        if (s21_isfunction(stack[*last_stack_num].function) && stack[*last_stack_num].function == '~'){
            move_node(stack, last_stack_num, concl, last_concl_num);
            if (*last_stack_num > 0) *last_stack_num-=1;
        }
        (*mainString)++;
    } else res = 0;
    return res;
}

int full_node(struct node * stack, char function, int last_stack_num){
    stack[last_stack_num].function = function;
    stack[last_stack_num].value = 0;
    if (function == '+' || function == '-') stack[last_stack_num].priority = 1;
    if (function == '*' || function == '/') stack[last_stack_num].priority = 2;
    if (function == '^') stack[last_stack_num].priority = 3;
    return 0;
}

int s21_operator_parser(char ** mainString, struct node * stack, int * last_stack_num, struct node * concl, int * last_concl_num){
    if (!isempty_node(stack, *last_stack_num)) *last_stack_num +=1;
    if (*last_stack_num == 0 && *last_concl_num == -1 && **mainString == '-'){
        stack[*last_stack_num].function = '~';
        stack[*last_stack_num].priority = 4;
        (*mainString)++;
    } else if (*last_stack_num == 0){
        full_node(stack, **mainString, 0);
        (*mainString)++;
    } else if (**mainString == '+'){
        while (stack[*last_stack_num - 1].priority >= 1 && *last_stack_num > 0){
            *last_stack_num-=1;
            move_node(stack, last_stack_num, concl, last_concl_num);
        }
        full_node(stack, **mainString, *last_stack_num);
        (*mainString)++;
    } else if (**mainString == '-'){
        (*mainString)--;
        if (**mainString == '('){
            stack[*last_stack_num].function = '~';
            stack[*last_stack_num].priority = 1;
            (*mainString)++;
            (*mainString)++;
        } else {
            (*mainString)++;
            while (stack[*last_stack_num - 1].priority >= 1 && *last_stack_num > 0){
                *last_stack_num-=1;
                move_node(stack, last_stack_num, concl, last_concl_num);
            }
            full_node(stack, **mainString, *last_stack_num);
            (*mainString)++;
        }
    } else if (**mainString == '*' || **mainString == '/'){
        while (stack[*last_stack_num - 1].priority >= 2 && *last_stack_num > 0){
            *last_stack_num-=1;
            move_node(stack, last_stack_num, concl, last_concl_num);
        }
        full_node(stack, **mainString, *last_stack_num);
        (*mainString)++;
    }  else if (**mainString == '^'){
        while (stack[*last_stack_num - 1].priority >= 3 && *last_stack_num > 0){
            *last_stack_num-=1;
            move_node(stack, last_stack_num, concl, last_concl_num);
        }
        full_node(stack, **mainString, *last_stack_num);
        (*mainString)++;
    }
    return 0;
}

int move_node(struct node * from, int *last_from_num, struct node * to, int *last_to_num){
    to[*last_to_num + 1].function = from[*last_from_num].function;
    to[*last_to_num + 1].value = from[*last_from_num].value;
    to[*last_to_num + 1].priority = from[*last_from_num].priority;
    clear_node(from, last_from_num);
    *last_to_num += 1;
    return 1;
}

int clear_node(struct node * stack, int *last_stack_num){
    stack[*last_stack_num].function = 'N';
    stack[*last_stack_num].value = 0;
    stack[*last_stack_num].priority = 0;
    return 0;
}

int s21_function_parser(char ** mainString, struct node * stack){
    stack->value = 0;
    stack->priority = 4;
    if (**mainString == 's'){
        (*mainString)++;
        if (**mainString == 'i'){         //sin = s
            cut(mainString, 3);
            stack->function = 's';
        } else if (**mainString == 'q'){  //sqrt = q
            cut(mainString, 4);
            stack->function = 'q';
        }
    } else if (**mainString == 'c'){
        (*mainString)++;
        if (**mainString == 'o'){         //cos = c
            cut(mainString, 3);
            stack->function = 'c';
        } else if (**mainString == 't'){  //ctg = G
            cut(mainString, 3);
            stack->function = 'G';
        }
    } else if (**mainString == 't'){
        cut(mainString, 4);
        stack->function = 't';
    } else if (**mainString == 'a'){
        (*mainString)++;
        if (**mainString == 's'){         //asin = S
            cut(mainString, 4);
            stack->function = 'S';
        } else if (**mainString == 'c'){  //acos = C
            cut(mainString, 4);
            stack->function = 'C';
        } else if (**mainString == 't'){  //atan = T
            cut(mainString, 4);
            stack->function = 'T';
        }
    } else if (**mainString == 'l'){
        (*mainString)++;
        if (**mainString == 'n'){         //ln = l
            cut(mainString, 2);
            stack->function = 'l';
        } else if (**mainString == 'o'){  //log = g
            cut(mainString, 3);
            stack->function = 'g';
        }
    } else if (**mainString == 'm'){
        cut(mainString, 4);
        stack->function = 'm';
    }
    return 0;
}

void cut(char ** mainString, int n){
    for (int i = 0; i < n; i++){
        if (** mainString != '\0'){
            (*mainString)++;
        }
    }
}

double s21_binary(double first_num, double second_num, char operator1){
    double res= 0;
    if (operator1 == '+'){
        res = first_num + second_num;
    } else if (operator1 == '-'){
        res = first_num - second_num;
    } else if (operator1 == '*'){
        res = first_num * second_num;
    } else if (operator1 == '/'){
        res = first_num / second_num;
    } else if (operator1 == '^'){
        res = pow(first_num, second_num);
    }
    return res;
}

double s21_unarny(double first_num, char operator1){
    double res= 0;
    if (operator1 == 's'){
        res = sin(first_num);
    } else if (operator1 == 'c'){
        res = cos(first_num);
    } else if (operator1 == 't'){
        res = tan(first_num);
    } else if (operator1 == 'G'){
        res = 1/tan(first_num);
    } else if (operator1 == 'S'){
        res = asin(first_num);
    } else if (operator1 == 'C'){
        res = acos(first_num);
    } else if (operator1 == 'T'){
        res = atan(first_num);
    } else if (operator1 == 'q'){
        res = sqrt(first_num);
    } else if (operator1 == 'l'){
        res = log(first_num);
    } else if (operator1 == 'g'){
        res = log10(first_num);
    } else if (operator1 == 'm'){
        if (first_num <= 0) res = first_num * (-1);
        else res = first_num;
    } else if (operator1 == '~'){
        res = first_num * (-1);
    }
    return res;
}

int s21_num_parser(char ** mainString, struct node * conclusion){
    char *ptr;
    conclusion->value = strtod(*mainString, &ptr);
    conclusion->priority = 0;
    conclusion->function = 'N';
    *mainString = ptr;
    return 0;
}

int s21_isoperator(char num){
    int res = 0;
    if (num == '+' || num == '-' || num == '*' || num == '/' || num == '^' || num == '('){
        res = 1;
    }
    return res;
}

int s21_isdigit(char num){
    int res = 0;
    if (num == '0' || num == '1' || num == '2' || num == '3' || num == '4' || num == '5' || num == '6' || num == '7' || num == '8' || num == '9' || num == 'x'){
        res = 1;
    }
    return res;
}

int s21_isfunction(char num){
    int res = 0;
    if (num == 'c' || num == 's' || num == 't' || num == 'a' || num == 'l'  || num == 'm' || num == 'S'|| num == 'C' || num == 'T' || num == 'q'|| num == 'l'|| num == 'g' || num == 'G' || num == '~'){
        res = 1;
    }
    return res;
}

// void print_stack_node(struct node * stack, int last_stack_num){
//     printf("\nSTACK: [%d]\n", last_stack_num);
//     printf("Value: %f\n", stack[last_stack_num].value);
//     printf("funct: %c\n", stack[last_stack_num].function);
//     printf("Prior: %d\n", stack[last_stack_num].priority);
// }

// void print_concl_node(struct node * stack, int last_stack_num){
//     printf("\nCONCL: [%d]\n", last_stack_num);
//     printf("Value: %f\n", stack[last_stack_num].value);
//     printf("funct: %c\n", stack[last_stack_num].function);
//     printf("Prior: %d\n", stack[last_stack_num].priority);
// }

// void print_node(struct node * stack, int last_stack_num){
//     for (int i = 0; i <= last_stack_num; i++){
//         printf("CONCL: [%.2d]     ", i);
//     }
//     printf("\n");
//     for (int i = 0; i <= last_stack_num; i++){
//         printf("Value: %.4f   ", stack[i].value);
//     }
//     printf("\n");
//     for (int i = 0; i <= last_stack_num; i++){
//         printf("funct: %c        ", stack[i].function);
//     }
//     printf("\n");
//     for (int i = 0; i <= last_stack_num; i++){
//         printf("Prior:%2d        ", stack[i].priority);
//     }
//     printf("\n\n");
// }

// int main(void){

//     const char * mainString = "-(1-2+4(2))";
//     printf("%s", s21_smart_calc(mainString, 99.9));
//     //printf("%f", s21_smart_calc(mainString, 0));

//     return 0;
// }
