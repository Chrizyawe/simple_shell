#ifndef __SHELL_H__
#define __SHELL_H__
#define UNUSED(x) (void)(x)

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <sys/wait.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>

/**
 * struct command_history -  structure for each command read
 * @str: character string
 * @counter: An integer representing the number of inputs or commands
 * @next: A pointer to the next element
 */
typedef struct command_history
{
	char *str;
	int counter;
	struct command_history *next;
} history_t;
/**
 * struct variables -A variables for a shell
 * @array_tokens: A pointer to an array of arguments
 * @buffer:  A pointer to a buffer for storing a command
 * @status: An integer to handle the exit status of a command
 * @argv:  an array of arguments at the opening of the shell
 * @counter: An integer for counting commands entered
 * @env: A pointer to an array of environment variables
 * @commands: an array of commands
 * @history: A pointer to a structure
 * @reverse_history: structure
 */
typedef struct variables
{
	char **array_tokens;
	char *buffer;
	int status;
	char **argv;
	int counter;
	char **env;
	char **commands;
	history_t *history;
	history_t *reverse_history;
} vars_t;
/**
 * struct builtin_command - a struct for the builtin functions
 * @name: A pointer to a character string that stores the name
 * @f: A function pointer that points to the implementation
 */
typedef struct builtin_command
{
	char *name;
	void (*f)(vars_t *);
} builtin_command_t;


void configure_env(vars_t *vars);
void unset_env(vars_t *vars);
void print_cd_2(vars_t *vars);
void print_cd(vars_t *vars);
void change_directory(vars_t *vars);
char **tokenize_path_directories(vars_t vars, int idx, char *str);
char *find_executable_path(vars_t vars, char *command);
char *search_directories(char **path_tokens, char *command);
void execute_child_process(vars_t vars);
void display_custom_message(char *string);
void create_new_command_history(vars_t *vars);
void free_command_history_list(history_t *head);
void *add_command_history_node(history_t **head, char *str);
int main(int argc __attribute__((unused)), char **argv, char **environment);
void handle_end_of_file(char *buffer);
unsigned int signal_flag;
char *custom_strtok(char *str, const char *delim);
unsigned int check_for_match(char c, const char *str);
void display_help_for_other_commands(vars_t *vars);
void display_help_for_history(vars_t *vars);
void display_help_for_env(vars_t *vars);
void display_help_for_change_directory(vars_t *vars);
void display_help_for_exit(vars_t *vars);
void display_help_for_set_environment(vars_t *vars);
void display_help_for_unset_environment(vars_t *vars);
void display_help_for_unalias(vars_t *vars);
void display_help_for_help(vars_t *vars);
void display_help_for_unset_env(vars_t *vars);
void display_help_for_unset(vars_t *vars);
void display_help_for_set_env(vars_t *vars);
void display_help_for_alias(vars_t *vars);
void new_help_alias(vars_t *vars);
void display_custom_help(vars_t *vars);
int calculate_factorial(int n);
int custom_string_compare(char *str1, char *str2);
void handle_execution_error(char *argv, int command_count, char *failed_comm);
void handle_fetal_error(void);
void print_error_message(char *argv, int command_count, char *missing_command);
void print_custom_string(char *str, int newline);
char *duplicate_string(char *str);
int reverse_string_compare(char *str1, char *str2);
int calculate_string_length(char *str);
ssize_t print_string(char *str);
char *concatenate_strings(char *str1, char *str2);
int print_integer(int n);
int write_character(char c);
void print_erro(char *str);
void error_message(vars_t *vars, char *message);
char *convert_unsigned_integer(unsigned int counter);
int _atoi(char *str);
char *generate_path(char *dir, char *command);
char **tokenize_child_string(int num_token, char *buf, const char *delim);
char **token_interface(char *buf, const char *delim, int num_token);
char **tokenize_string(char *buf, char *delim);
int count_tokens(char *str, const char *delim);
void change_directory_env(vars_t *vars, char *str);
void free_env(char **env);
char **create_new_environment(char **env);
int find_env_index(vars_t vars, char *str);
char **resize_and_allocate(char **ptr, size_t *size);
char *add_value_to_key(char *key, char *value);
char **find_env_key(char **env, char *key);
void add_new_variable(vars_t *vars);
void (*check_builtin(vars_t *vars))(vars_t *vars);
void exit_shell(vars_t *vars);
void display_env(vars_t *vars);
void put_error_message(char *str);
int simple_code(void);
ssize_t print_str1(char *string);





#endif
