#include "employee.h"
#include "cJSON.h"

#include <stdio.h>
#include <stdlib.h>
#include <string.h> 

Employee *head = NULL;

Employee* create_employee(int id, const char* name, float salary) {
    Employee* new_employee = (Employee*)malloc(sizeof(Employee));
    if (new_employee == NULL) {
        printf("Error: Failed to allocate memory for new employee.\n");
        exit(EXIT_FAILURE);
    }
    
    new_employee->id = id;
    strcpy(new_employee->name, name);
    new_employee->salary = salary;
    new_employee->next = NULL;
    
    return new_employee;
}

void add_employee(int id, const char* name, float salary)
    {
        Employee* new_employee = create_employee(id, name, salary);
        new_employee->next = head;
        head = new_employee;
        
        printf("Employee ID %d (%s) has been added successfully.\n", id, name);
    }
    
void display_employees() {
    if (head == NULL) {
        printf("No employee in the list.\n");
        return;
    }
    
    printf("\n--- Employee List ---\n");
    Employee* current = head;
    
    while (current != NULL) {
        printf("ID: %d, Name: %s, Salary: %.2f\n", current->id, current->name, current->salary);
        current = current->next;
        printf("---------------\n");
    }
}

Employee* find_employee_by_id(int id) {
    Employee* current = head;
    while (current != NULL) {
        if (current->id == id) {
            return current;
        }
        current = current->next;
    }
    return NULL;
}

void update_employee_details(Employee* emp_to_update, const char* new_name, float new_salary) {
    if (emp_to_update == NULL) {
        printf("Invalid employee pointer for update.\n");
        return;
    }
    
    strcpy(emp_to_update->name, new_name);
    emp_to_update->salary = new_salary;
    
    printf("Employee ID %d details has been updated successfully.\n", emp_to_update->id);
}

void delete_employee(int id_to_delete) {
    Employee *current = head;
    Employee *prev = NULL;
    
    if (current != NULL && current->id == id_to_delete) {
        head = current->next;
        free(current);
        printf("Employee ID %d has been deleted.\n", id_to_delete);
        return;
    }
    
    while (current != NULL && current->id != id_to_delete) {
        prev = current;
        current = current->next;
    }
    
    if (current == NULL) {
        printf("Employee ID %d not found.\n", id_to_delete);
        return;
    }
    
    if (prev != NULL) {
        prev->next = current->next;
    }
    
    free(current);
    printf("Employee ID %d has been deleted.\n", id_to_delete);
}

void free_all_employees() {
    Employee *current = head;
    Employee *next_employee;
    
    while (current != NULL) {
        next_employee = current->next;
        free(current);
        current = next_employee;
    }
    
    head = NULL;
    printf("\nAll employee memory has been freed.\n");
}

void save_employees(const char *filename) {
    cJSON *root = cJSON_CreateArray();
    Employee *current = head;
    
    while (current != NULL) {
        cJSON *emp_obj = cJSON_CreateObject();
        cJSON_AddNumberToObject(emp_obj, "id", current->id);
        cJSON_AddStringToObject(emp_obj, "name", current->name);
        cJSON_AddNumberToObject(emp_obj, "salary", current->salary);
        cJSON_AddItemToArray(root, emp_obj);
        current = current->next;
    }
    
    char *json_str = cJSON_Print(root);
    
    FILE *fp = fopen(filename, "w");
    if (fp == NULL) {
            printf("Error: Unable to open file '%s' for writing.\n", filename);
            cJSON_Delete(root);
            free(json_str);
            return;
    }
    
    fprintf(fp, "%s", json_str);
    fclose(fp);
    
    printf("Employee data has been saved to %s\n", filename);
    
    cJSON_Delete(root);
    free(json_str);
}

void load_employees(const char *filename) {
    FILE *fp = fopen(filename, "r");
    
    if (fp == NULL) {
        printf("No existing employee data found (%s).\n", filename);
        return;
    }
    
    fseek(fp, 0, SEEK_END);
    long length = ftell(fp);
    rewind(fp);
    
    char *data = (char *)malloc(length + 1);
    
    if (data == NULL) {
        printf("Error: Failed to allocate memory for file read.\n");
        fclose(fp);
        return;
    }
    
    fread(data, 1, length, fp);
    data[length] = '\0';
    fclose(fp);
    
    cJSON *root = cJSON_Parse(data);
    if (!root) {
        printf("Error: Failed to parse JSON from file.\n");
        free(data);
        return;
    }
    
    free_all_employees();
    
    int array_size = cJSON_GetArraySize(root);
    for (int i = 0; i < array_size; i++) {
        cJSON *emp_obj = cJSON_GetArrayItem(root, i);
        int id = cJSON_GetObjectItem(emp_obj, "id")->valueint;
        const char *name = cJSON_GetObjectItem(emp_obj, "name")->valuestring;
        float salary = (float)cJSON_GetObjectItem(emp_obj, "salary")->valuedouble;
        add_employee(id, name, salary);
    }
    
    cJSON_Delete(root);
    free(data);
    
    printf("Employee data loaded successfully from %s\n", filename);
}