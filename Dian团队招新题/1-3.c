#include<stdio.h>

char name; // ��ʾ��Ҫ������������
int passage; // ��ʾ��Ҫ�����������ͨ��
int n[50]; // ��ʾ��Ҫ������������
int total[50]; // ��ʾÿһ�������������ܽ��
int sum[50]; // ��ʾÿһ�ι���Ͷ���ܽ��
int change[50]; //  ��ʾÿһ�ι����һص���Ǯ
int face; // ��ʾ��Ͷ���Ʊ��
int cnt=0; // ���ڼ��������������
int rest = 0;// ��ʾÿһ�ι����ʣ��Ļ�������
char ch; // �������ջس�
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
	while(1){
		ch = getchar();
	printf("��������Ҫ�����������ƣ�\n");
	scanf_s("%c", &name,1);
	if (name != goods.label) {
		printf("����������������������\n");
		continue; // �ж���Ʒ�����Ƿ�������ȷ
	}
	else {
		printf("��������Ҫ�����������ͨ����\n");
		scanf_s("%d", &passage);
		if (passage != goods.channel) {
			printf("����ͨ����������������\n");
			continue; // �ж���Ʒ����ͨ���Ƿ�������ȷ
		}
		else {
		�ٴι���:
			printf("��������Ҫ��������������\n");
			scanf_s("%d", &n);
			if (n[cnt]<= goods.num) {
				total[cnt] = n[cnt] * goods.price;
				break;
			}
			else {
				printf("��ʱû����ô�����Ŷ������������\n");
				continue;
			}
			}
		}
	}
	while (1) {
		printf("��Ͷ��(ֻ��Ͷ��1��2��5Ԫ):\n");
		scanf_s("%d", &face);
		if (!(face == 1 || face == 2 || face == 5)) { // �ж��û��Ƿ���ȷ����Ͷ�ҽ��
			printf("ֻ��Ͷ��1��2��5ԪŶ��������Ͷ��\n");
			continue;
		}
		else {
			sum[cnt] += face;
			if (sum[cnt] >= total[cnt]) {
				change[cnt] = sum[cnt] - total[cnt];
				printf("����%dԪ\n", change[cnt]);
				for (int cnt = 0;cnt < 50;) { // ���ڼ������������������
					cnt++;
				}
				rest = goods.num - n[cnt];
				if (rest > 0) {
					goto �ٴι���; // ����ʵ�ֶ���ظ�����
				}
				else {
					printf("�Ѿ�û�л����������Ŷ\n");
					break;
				}
			}
			else {
				printf("��Ͷ���Ǯ������Ŷ�������Ͷ��\n");
				continue;
			}
		}
		}
	return 0;
	}
	