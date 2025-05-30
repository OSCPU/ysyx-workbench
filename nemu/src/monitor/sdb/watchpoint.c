/***************************************************************************************
* Copyright (c) 2014-2024 Zihao Yu, Nanjing University
*
* NEMU is licensed under Mulan PSL v2.
* You can use this software according to the terms and conditions of the Mulan PSL v2.
* You may obtain a copy of Mulan PSL v2 at:
*          http://license.coscl.org.cn/MulanPSL2
*
* THIS SOFTWARE IS PROVIDED ON AN "AS IS" BASIS, WITHOUT WARRANTIES OF ANY KIND,
* EITHER EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO NON-INFRINGEMENT,
* MERCHANTABILITY OR FIT FOR A PARTICULAR PURPOSE.
*
* See the Mulan PSL v2 for more details.
***************************************************************************************/

#include "sdb.h"

#define NR_WP 32
int n = 32;

static WP wp_pool[NR_WP] = {};
static WP wp_pool_head[NR_WP] = {};
static WP *head, *free_wp = NULL;

WP* new_wp(char *str){
	WP* new = NULL;
	WP* tmp = NULL;
	if(n == 1){
		printf("free_wp empty\n");
		assert(0);
	}
	else{
		for(new = free_wp; new -> next != NULL; new = new -> next){}//将指针移至链表末尾
		for(tmp = free_wp; tmp -> next -> next != NULL; tmp = tmp -> next){} 
		tmp -> next = NULL;//释放末尾单元
		/*
		for(tmp = free_wp; tmp != NULL; tmp = tmp -> next){	
			printf("1-%d-%s-1\n",tmp -> NO, tmp -> expr);
		}
		*/
		strcpy(new -> expr, str);
		new -> result = expr(str,  false);
		new -> times = 0;
		for(tmp = head; tmp -> next != NULL; tmp = tmp -> next){}//将new接到head末尾
		tmp -> next = new;
		/*
		for(tmp = head; tmp != NULL; tmp = tmp -> next){	
			printf("2-%d-%s-2\n",tmp -> NO, tmp -> expr);
		}
		*/
		n = n - 1;
	}
	new -> next = NULL;
	return new;
}

void free_Wp(int data)
{
	int flag = 0;
	WP *wp;
	if(n == 32){
		printf("free_wp full\n");
		assert(0);
	}	
	else{
		data = 32 - data;
		WP* tmp = NULL;
		for(tmp = head; tmp -> next != NULL; tmp = tmp -> next){
			if(tmp -> next -> NO == data){
				wp = tmp -> next;
				tmp -> next = tmp -> next -> next;
				flag = 1;
				break;
			}	
		}
		if(flag == 0) {
			printf("No such watchpoint!\n");
			return;	
		}
		else
		{
			strcpy(wp -> expr, "none");
			wp -> result = 0;
			wp -> times = 0;
			for(tmp = free_wp; tmp -> next != NULL; tmp = tmp -> next){	
			}
			tmp -> next = wp;
			tmp -> next -> next = NULL;
			/*
			for(tmp = free_wp; tmp != NULL; tmp = tmp -> next){	
				printf("3-%d-%s-3\n",tmp -> NO, tmp -> expr);
			}
			for(tmp = head; tmp != NULL; tmp = tmp -> next){	
				printf("4-%d-%s-4\n",tmp -> NO, tmp -> expr);
			}
			*/
			n = n + 1;
		}
	}
	return;
}

void watch_display(){
	WP* tmp = NULL;
	printf("NUM  Type         Disp  Enb   Address   what\n");
	for(tmp = head -> next; tmp != NULL; tmp = tmp -> next){	
		printf("%d    watchpoint   keep  y               %s\n",(32-tmp -> NO), tmp -> expr);
		if(tmp -> times != 0)
		printf("     breakpoint already hit %d time\n\n", tmp -> times);
		//times记录监视点被改变了几次
	}
}

int watchpoint_check()
{
	int temp;
	int flag_w = 0;
	WP *tmp = NULL;
	for(tmp = head -> next; tmp != NULL; tmp = tmp -> next){	
		temp = expr(tmp -> expr, false);
		if(temp != tmp -> result)
		{
			flag_w = 1;
			printf("Hardware watchpoint %d: %s\n\n", tmp -> NO, tmp -> expr);
			printf("Old value = 0x%08x\n", tmp -> result);
			printf("New value = 0x%08x\n\n\n", temp);
			tmp -> result = temp;
			tmp -> times = tmp -> times + 1;
		}
	}
	return flag_w;
}

void init_wp_pool() { //监视点池初始化
  int i;
  for (i = 0; i < NR_WP; i ++) {
    wp_pool[i].NO = i;
    wp_pool[i].result = 0;
    wp_pool[i].times = 0;
    strcpy(wp_pool[i].expr , "none");
    wp_pool[i].next = (i == NR_WP - 1 ? NULL : &wp_pool[i + 1]);
  }
    
	wp_pool_head[0].NO = 0;
	wp_pool_head[0].result = 0;
	wp_pool_head[0].times = 0;
	strcpy(wp_pool_head[0].expr, "0");
	wp_pool_head[0].next = NULL;
	head = wp_pool_head;
	free_wp = wp_pool;
	/*
	WP *a1;
	WP *a2;
	WP *a3;
	a1 = new_wp("0x1+0x1");
	a2 = new_wp("0x1+0x2");
	a3 = new_wp("0x1+0x3");
	watch_display();
	printf("~~~~~\n");
	free_Wp(1);
	free_Wp(2);
	watch_display();
	printf("~~~~~\n");
	a1 = new_wp("0x1+0x1");
	a2 = new_wp("0x1+0x2");
	a3 = new_wp("0x1+0x3");
	watch_display();
	printf("~~~~~\n");
	free_Wp(1);
	free_Wp(2);
	free_Wp(3);
	printf("%d  %d  %d\n",a1 -> NO, a2-> NO, a3-> NO);
	watch_display();
	*/
}
