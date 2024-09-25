#include<stdio.h>
#include<string.h>

int face = 0; // 每一次投入的票面
int per = 0; // 每一次购买所需的金额
int total = 0; // 需付的总金额
int sum = 0; // 投入总金额
int change = 0; // 找零金额
char name; // 所购买货物的名称
int passage=0; // 购买货物的通道
int n = 0; // 记录购买货物的数量
int cnt1 = 0; // 记录摆货次数
int cnt2; // 记录购买次数
char jieshu[100]; // 用于实现输入END结束
char ch = 0;
char c = 0;
int i1 = 0;
int i2 = 0;
struct stuff {
	char label;
	int channel;
	int price;
	int num;
};
struct stuff goods[5]; // 结构体数组分别用于摆放五个通道的货物
int main() {
	while (1) {
		printf("请输入货物的名称，通道号（请按照从1到5的顺序输入），单价及数量（输入END结束摆货，输入END外任意单词继续摆货）：\n");
		scanf_s("%c", &goods[cnt1].label, 1);
		scanf_s("%d", &goods[cnt1].channel);
		scanf_s("%d", &goods[cnt1].price);
		scanf_s("%d", &goods[cnt1].num);
		while ((ch = getchar()) != EOF && ch != '\n');
		scanf_s("%s", jieshu, 100);
		if (strcmp(jieshu, "END") == 0) {
			break;
		}
		else if (strcmp(jieshu, "END") != 0) {
			printf("请继续摆放货物\n");
		}
		if (goods[cnt1].channel == goods[cnt1 - 1].channel && goods[cnt1].label == goods[cnt1 - 1].label) { // 判断用户是否在同一个通道摆放多种货物
			printf("一个通道只允许摆放一种货物哦");
			continue;
		}
	    if (goods[cnt1].channel == goods[cnt1 - 1].channel) { // 判断用户摆放的货物是否位于同一通道
			printf("该通道已存在货物，请更换到其他通道\n");
			continue;
		}
	    if (cnt1 < 5) {  // 判断是否还有多余通道来摆放货物
			cnt1++;
			continue;
		}
		else {
			printf("已经没有足够的通道摆放货物了\n");
			break;
		}
	}
	while (1) {
		printf("输入END外任何单词开始购买，选好商品后输入END结束购买\n");
		while ((c = getchar()) != EOF && c != '\n');
		scanf_s("%s", jieshu, 100);
		if (strcmp(jieshu, "END") == 0) {
			break;
		}
		printf("请输入需要购买货物的名称：\n");
		while ((c = getchar()) != EOF && c != '\n');
		scanf_s("%c", &name, 1);
		for (i1 = 0;i1 < 5;) {
			if (name == goods[i1].label) {
				printf("名称正确\n"); // 判断用户是否正确输入名称
				break;
			}
			else {
				i1++;
				continue;
			}
		}
		printf("请输入需要购买货物的通道：\n");
		scanf_s("%d", &passage);
		for (i2 = 0;i2 < 5;) {
			if (passage == goods[i2].channel) {
				printf("通道号正确\n"); // 判断用户是否正确输入通道号
				break;
			}
			else {
				i2++;
				continue;
			}
		}
		printf("请输入需要购买货物的数量\n");
		scanf_s("%d", &n);
		if (goods[passage - 1].num >= n) {
			goods[passage - 1].num -= n;
			per = goods[passage - 1].price * n;
			total += per;
			continue;
		}
		else {
			printf("暂时没有那么多货物哦,请重新输入\n");
			continue;
		}
		if (goods[0].num == 0 && goods[1].num == 0 && goods[2].num == 0 && goods[3].num == 0 && goods[4].num == 0) { // 判断售货机中是否还有货物
			printf("商品已经被你买完了哦\n");
			break;
		}
	}
		while (1) {
			printf("请开始投币（只能投入1、2、5元）：\n");
			while ((c = getchar()) != EOF && c != '\n');
			scanf_s("%d", &face);
			if (!(face == 1 || face == 2 || face == 5)) {
				printf("只能投入1、2、5元哦，请重新投币\n");
				continue;
			}
			else {
				sum += face;
				if (sum >= total) {
					change = sum - total;
					printf("找零%d元\n", change);
					break;
				}
				else {
					printf("你投的钱还不够呢\n");
					continue;
				}
			}
		}
		return 0;
	}
	

