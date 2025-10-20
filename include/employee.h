#pragma once

typedef struct Employee {
    int id;
    char name[50];
    float salary;
    struct Employee *next;
} Employee;

Employee* create_employee(int id, const char* name, float salary);
void add_employee(int id, const char* name, float salary);
void display_employees();
Employee* find_employee_by_id(int id);
void update_employee_details(Employee* emp_to_update, const char* new_name, float new_salary);
void delete_employee(int id_to_delete);
void free_all_employees();
void save_employees(const char *filename);
void load_employees(const char *filename);