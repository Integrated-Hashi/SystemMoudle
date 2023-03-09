//
//  main.c
//  SystemMoudle
//
//  Created by chen on 2023/3/6.
//

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>

//病人表
typedef struct patient
{
    char patientName[20];
    char gender[2];
    int age;
    char address[200];
    char telephone[11];
    char mail[50];
    char symptom[200];
    char doctor[20];
}patient;

//记录表
typedef struct recode
{
    char patientName[20];
    char gender[2];
    int age;
    char date[20];
    char telephone[11];
    char type[12];
}record;

//病人表结点
typedef struct patientNode
{
    patient data;
    struct patientNode* next;
}patientNode;

//记录表结点
typedef struct recordNode
{
    record data;
    struct recordNode* next;
}recordNode;

patientNode* patientList;
recordNode* recordList;

//建立病人表链表
patientNode* createPatientList() {
    patientNode* head = (patientNode*)malloc(sizeof(patient));
    head->next = NULL;
    return head;
}

//建立记录表链表
recordNode* createRecordList() {
    recordNode* head = (recordNode*)malloc(sizeof(record));
    head->next = NULL;
    return head;
}

//插入病人表链表
void insertPatientNode(patientNode* list, patient data) {
    patientNode* newNode = (patientNode*)malloc(sizeof(patientNode));
    newNode->next = list->next;
    list->next = newNode;
    newNode->data = data;
}

//插入记录表链表
void insertRecordNode(recordNode* list, record data) {
    recordNode* newNode = (recordNode*)malloc(sizeof(recordNode));
    newNode->next = list->next;
    list->next = newNode;
    newNode->data = data;
}

//写入病人文件
void writePatientFile(patientNode* list, char *filename) {
    patientNode* tmpNode = list->next;
    FILE *fp = fopen(filename, "w");

    while(tmpNode != NULL) {
        fprintf(fp, "%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
        tmpNode->data.patientName,
        tmpNode->data.gender,
        tmpNode->data.age,
        tmpNode->data.address,
        tmpNode->data.telephone,
        tmpNode->data.mail,
        tmpNode->data.symptom,
        tmpNode->data.doctor
        );

        tmpNode = tmpNode->next;
    }

    fclose(fp);
}

//写入记录文件
void writeRecordFile(recordNode* list, char *filename) {
    recordNode* tmpNode = list->next;
    FILE *fp = fopen(filename, "w");

    while(tmpNode != NULL) {
        fprintf(fp, "%s\t%s\t%d\t%s\t%s\t%s\n",
        tmpNode->data.patientName,
        tmpNode->data.gender,
        tmpNode->data.age,
        tmpNode->data.date,
        tmpNode->data.telephone,
        tmpNode->data.type
        );

        tmpNode = tmpNode->next;
    }
    
    fclose(fp);
}

//读取病人文件
void readPatientFile(patientNode* list, char *filename) {
    FILE *fp = fopen(filename, "r");

    patient data;

    if(fp == NULL){
        fp = fopen(filename,"w");
    }
    while(fscanf(fp, "%s\t%s\t%d\t%s\t%s\t%s\t%s\t%s\n",
        data.patientName,
        data.gender,
        &data.age,
        data.address,
        data.telephone,
        data.mail,
        data.symptom,
        data.doctor) != EOF) {
            insertPatientNode(list, data);
        }

    fclose(fp);
}

//读取记录文件
void readRecordFile(recordNode* list, char *filename) {
    FILE *fp = fopen(filename, "r");

    record data;

    if(fp == NULL){
        fp = fopen(filename,"w");
    }
    while(fscanf(fp, "%s\t%s\t%d\t%s\t%s\n",
        data.patientName,
        data.gender,
        &data.age,
        data.date,
        data.telephone,
        data.type) != EOF) {
            insertRecordNode(list, data);
        }

    fclose(fp);
}

//密码获取
void getPassword(char *password) {
    int i=0, flag=0;
    char input;
    while(1) {
        // \r是回车 \b是退格符
        if((input = getchar()) != '\r') {
            if(input != '\b') {
                password[i++] = input;
                printf("*");
                fflush(stdin);
                flag++;
            }
            if(input == '\b' && flag != 0) {
                flag--;
                i--;
                
            }
        }
    }
}






int main(int argc, const char * argv[]) {
    // insert code here...
    printf("Hello, World!\n");
    return 0;
}
