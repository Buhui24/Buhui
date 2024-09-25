#include<stdio.h>

char name; // 表示需要购买货物的名称
int passage; // 表示需要购买货物所在通道
int n[50]; // 表示需要购买货物的数量
int total[50]; // 表示每一次所购买货物的总金额
int sum[50]; // 表示每一次购物投入总金额
int change[50]; //  表示每一次购物找回的零钱
int face; // 表示所投入的票面
int cnt=0; // 用于计数（购买次数）
int rest = 0;// 表示每一次购买后剩余的货物数量
char ch; // 用于吸收回车
struct stuff {
	int price;
	int channel;
	char label;
	int num;
};
struct stuff goods; // 通道中摆放好的货物
int main() {
	printf("请输入货物名称，所在通道，单价及货物数量：\n");
	scanf_s("%c", &goods.label, 1);
	scanf_s("%d %d %d", &goods.channel, &goods.price, &goods.num);
	while(1){
		ch = getchar();
	printf("请输入需要购买货物的名称：\n");
	scanf_s("%c", &name,1);
	if (name != goods.label) {
		printf("货物名称有误，请重新输入\n");
		continue; // 判断商品名称是否输入正确
	}
	else {
		printf("请输入需要购买货物所在通道：\n");
		scanf_s("%d", &passage);
		if (passage != goods.channel) {
			printf("货物通道有误，请重新输入\n");
			continue; // 判断商品所在通道是否输入正确
		}
		else {
		再次购买:
			printf("请输入需要购买货物的数量：\n");
			scanf_s("%d", &n);
			if (n[cnt]<= goods.num) {
				total[cnt] = n[cnt] * goods.price;
				break;
			}
			else {
				printf("暂时没有那么多货物哦，请重新输入\n");
				continue;
			}
			}
		}
	}
	while (1) {
		printf("请投币(只能投入1、2、5元):\n");
		scanf_s("%d", &face);
		if (!(face == 1 || face == 2 || face == 5)) { // 判断用户是否正确输入投币金额
			printf("只能投入1、2、5元哦，请重新投币\n");
			continue;
		}
		else {
			sum[cnt] += face;
			if (sum[cnt] >= total[cnt]) {
				change[cnt] = sum[cnt] - total[cnt];
				printf("找零%d元\n", change[cnt]);
				for (int cnt = 0;cnt < 50;) { // 用于计数（购买及找零次数）
					cnt++;
				}
				rest = goods.num - n[cnt];
				if (rest > 0) {
					goto 再次购买; // 用于实现多次重复购买
				}
				else {
					printf("已经没有货物可以买了哦\n");
					break;
				}
			}
			else {
				printf("你投入的钱还不够哦，请继续投币\n");
				continue;
			}
		}
		}
	return 0;
	}
	