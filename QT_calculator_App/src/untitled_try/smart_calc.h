#ifndef SMART_CALC_H
#define SMART_CALC_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <string.h>


struct node {
    double value;
    char function;
    int priority;
};

char *s21_smart_calc(const char * mainString, double xvalue);
double s21_smart_calc_double(const char * mainString, double xvalue);

int s21_isdigit(char num);
int s21_isfunction(char num);
int s21_isoperator(char num);
int s21_num_parser(char ** mainString, struct node * conclusion);
int s21_function_parser(char ** mainString, struct node * stack);
int s21_operator_parser(char ** mainString, struct node* stack, int* last_stack_num, struct node* concl, int* last_concl_num);
int s21_bracket_parser(char ** mainString, struct node* stack, int* last_stack_num, struct node* concl, int* last_concl_num);
int s21_combine_stacks(struct node * result_stack, int *result_stack_num, struct node *stack, int *last_stack_num, struct node *concl, int *last_concl_num);
void cut(char ** mainString, int n);
void print_stack_node(struct node * stack, int last_stack_num);
void print_concl_node(struct node * stack, int last_stack_num);
int move_node(struct node * from, int *last_from_num, struct node * to, int *last_to_num);
int clear_node(struct node * stack, int *last_stack_num);
int full_node(struct node * stack, char function, int last_stack_num);
void print_node(struct node * stack, int last_stack_num);
int isempty_node(struct node * result_stack, int num);

int notation_conversion(struct node *stack, int *stack_len, double * result);
int left_shift(struct node *stack, int *stack_len, int start, int amount);
double s21_binary(double first_bum, double second_num, char operator1);
double s21_unarny(double first_num, char operator1);

#endif // SMART_CALC_H
