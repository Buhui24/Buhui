#include<stdio.h>

int sum = 0; //  ���ڱ�ʾͶ����
int face; //  �ñ������ڴ洢ÿһ��Ͷ���Ʊ��
int change = 0; // �ñ������ڱ�ʾ������
int total = 0; // �ñ������ڱ�ʾ�û������������ܽ��
int n = 0; // �ñ������ڱ�ʾ�û���Ҫ������������
struct stuff {
	int price;
	int channel;
	char label;
	int num;
};
struct stuff goods; // ͨ���аڷźõĻ���
int main() {
	printf("������������ƣ�����ͨ�������ۼ�����������\n");
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
	printf("��������Ҫ������Ʒ������:\n");
	scanf_s("%d", &n);
	if (n > goods.num) {
		printf("Ŀǰû����ô�����Ŷ������������\n");
		scanf_s("%d", &n);
		total = n * goods.price;
		while (1) {
			printf("��Ͷ�ң�ֻ��Ͷ��1��2��5Ԫ��\n");
			scanf_s("%d", &face);
			if (!(face == 1 || face == 2 || face == 5)) {
				printf("ֻ������1��2��5Ԫ��\n");
				continue;
			}
			else {
				sum += face;
				if (sum >= total) {
					change = sum - total;
					printf("����ɹ�������%dԪ", change);
					break;
				}
				else {
					printf("��Ͷ��Ǯ��������\n");
					continue;
				}
			}
		}
	}
	else{
		total = n * goods.price;
		while (1) {
			printf("��Ͷ�ң�ֻ��Ͷ��1��2��5Ԫ��\n");
			scanf_s("%d", &face);
			if (!(face == 1 || face == 2 || face == 5)) {
				printf("ֻ������1��2��5Ԫ��\n");
				continue;
			}
			else {
				sum += face;
				if (sum >= total) {
					change = sum - total;
					printf("����ɹ�������%dԪ", change);
					break;
				}
				else {
					printf("��Ͷ��Ǯ��������");
					continue;
				}
			}
		}
	}
	return 0;
}
