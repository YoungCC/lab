/**************************************************************************************************/
/* Copyright (C) SoftwareDesign@USTC, 2014                                                        */
/*                                                                                                */
/*  FILE NAME             :  lab1menu.c                                                           */
/*  PRINCIPAL AUTHOR      :  Caoyang                                                              */
/*  PRINCIPAL AUTHOR ID   :  JG14225028                                                           */
/*  SUBSYSTEM NAME        :  lab1menu                                                             */
/*  MODULE NAME           :  lab1menu                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/12                                                           */
/*  DESCRIPTION           :  This is a menu program                                               */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Caoyang, 2014/09/12
 *
 */


#include <stdio.h>
#include <stdlib.h>
#include "linklist.h"

int Help();

#define CMD_MAX_LEN 128
#define DESC_LEN    1024
#define CMD_NUM     10

/* menu program */

static tDataNode head[] = 
{
    {"help", "this is help cmd!", Help,&head[1]},
    {"delete", "delete the files in the remote host",NULL,&head[2]},
    {"cdup", "return to the higher level directory",NULL,&head[3]},
    {"pwd", "list the current remote host directory",NULL,&head[4]},
    {"version", "menu program v1.0", NULL,NULL}
};

main()
{    
   /* cmd line begins */
    while(1)
    {
        char cmd[CMD_MAX_LEN];
        printf("Input a cmd string > ");
        scanf("%s", cmd);
        tDataNode *p = FindCmd(head, cmd);
        if( p == NULL)
        {
            printf("This is a wrong cmd!\n ");
            continue;
        }
        printf("%s - %s\n", p->cmd, p->desc); 
        if(p->handler != NULL) 
        { 
            p->handler();
        }
   
    }
}

int Help()
{
    ShowAllCmd(head);
    return 0; 
}
