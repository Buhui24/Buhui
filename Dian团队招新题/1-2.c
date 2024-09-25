#include<stdio.h>

int sum = 0; //  用于表示投入金额
int face; //  该变量用于存储每一次投入的票面
int change = 0; // 该变量用于表示找零金额
int total = 0; // 该变量用于表示用户所购买货物的总金额
int n = 0; // 该变量用于表示用户需要购买货物的数量
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
	printf("%d:", goods.channel);
	int cnt;
	for (cnt = 0;cnt < goods.num;cnt++) {
		printf("%c", goods.label);
	}
	if (goods.price > 0 && goods.price < 10) {
		printf(" %d\n", goods.price);
	}
	printf("请输入需要购买商品的数量:\n");
	scanf_s("%d", &n);
	if (n > goods.num) {
		printf("目前没有那么多货物哦，请重新输入\n");
		scanf_s("%d", &n);
		total = n * goods.price;
		while (1) {
			printf("请投币（只能投入1，2，5元）\n");
			scanf_s("%d", &face);
			if (!(face == 1 || face == 2 || face == 5)) {
				printf("只能输入1，2，5元噢\n");
				continue;
			}
			else {
				sum += face;
				if (sum >= total) {
					change = sum - total;
					printf("购买成功，找您%d元", change);
					break;
				}
				else {
					printf("你投的钱还不够呢\n");
					continue;
				}
			}
		}
	}
	else{
		total = n * goods.price;
		while (1) {
			printf("请投币（只能投入1，2，5元）\n");
			scanf_s("%d", &face);
			if (!(face == 1 || face == 2 || face == 5)) {
				printf("只能输入1，2，5元噢\n");
				continue;
			}
			else {
				sum += face;
				if (sum >= total) {
					change = sum - total;
					printf("购买成功，找您%d元", change);
					break;
				}
				else {
					printf("你投的钱还不够呢");
					continue;
				}
			}
		}
	}
	return 0;
}
