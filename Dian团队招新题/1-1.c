#include<stdio.h>

int main() {
	int price=0;
	int channel = 0;
	char label;
	int num = 0;
	printf("请输入货物名称，所在通道，单价及货物数量：\n");
		scanf_s("%c", &label, 1);
		scanf_s("%d %d %d",&channel, &price, &num);
		printf("%d:", channel);
		int cnt;
		for (cnt = 0;cnt < num;cnt++) {
			printf("%c", label);
		}
		if(num > 0 && num < 10) {
			printf(" %d", price);
		}
		return 0;
}