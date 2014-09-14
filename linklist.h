/**************************************************************************************************/
/* Copyright (C) SoftwareDesign@USTC, 2014                                                        */
/*                                                                                                */
/*  FILE NAME             :  linklist.h                                                           */
/*  PRINCIPAL AUTHOR      :  Caoyang                                                              */
/*  PRINCIPAL AUTHOR ID   :  JG14225028                                                           */
/*  SUBSYSTEM NAME        :  linklist                                                             */
/*  MODULE NAME           :  linklist                                                             */
/*  LANGUAGE              :  C                                                                    */
/*  TARGET ENVIRONMENT    :  ANY                                                                  */
/*  DATE OF FIRST RELEASE :  2014/09/12                                                           */
/*  DESCRIPTION           :  linklist for menu program                                            */
/**************************************************************************************************/

/*
 * Revision log:
 *
 * Created by Caoyang, 2014/09/12
 *
 */


/* data struct and its operations */

typedef struct DataNode 
{
    char*    cmd;
    char*    desc;
    int      (*handler)();
    struct   DataNode *next;
} tDataNode;

tDataNode* FindCmd(tDataNode * head,char * cmd);

int ShowAllCmd(tDataNode * head);
