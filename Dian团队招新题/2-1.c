#include<stdio.h>
#include<string.h>

int face = 0; // ÿһ��Ͷ���Ʊ��
int per = 0; // ÿһ�ι�������Ľ��
int total = 0; // �踶���ܽ��
int sum = 0; // Ͷ���ܽ��
int change = 0; // ������
char name; // ��������������
int passage=0; // ��������ͨ��
int n = 0; // ��¼������������
int cnt1 = 0; // ��¼�ڻ�����
int cnt2; // ��¼�������
char jieshu[100]; // ����ʵ������END����
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
struct stuff goods[5]; // �ṹ������ֱ����ڰڷ����ͨ���Ļ���
int main() {
	while (1) {
		printf("�������������ƣ�ͨ���ţ��밴�մ�1��5��˳�����룩�����ۼ�����������END�����ڻ�������END�����ⵥ�ʼ����ڻ�����\n");
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
			printf("������ڷŻ���\n");
		}
		if (goods[cnt1].channel == goods[cnt1 - 1].channel && goods[cnt1].label == goods[cnt1 - 1].label) { // �ж��û��Ƿ���ͬһ��ͨ���ڷŶ��ֻ���
			printf("һ��ͨ��ֻ����ڷ�һ�ֻ���Ŷ");
			continue;
		}
	    if (goods[cnt1].channel == goods[cnt1 - 1].channel) { // �ж��û��ڷŵĻ����Ƿ�λ��ͬһͨ��
			printf("��ͨ���Ѵ��ڻ�������������ͨ��\n");
			continue;
		}
	    if (cnt1 < 5) {  // �ж��Ƿ��ж���ͨ�����ڷŻ���
			cnt1++;
			continue;
		}
		else {
			printf("�Ѿ�û���㹻��ͨ���ڷŻ�����\n");
			break;
		}
	}
	while (1) {
		printf("����END���κε��ʿ�ʼ����ѡ����Ʒ������END��������\n");
		while ((c = getchar()) != EOF && c != '\n');
		scanf_s("%s", jieshu, 100);
		if (strcmp(jieshu, "END") == 0) {
			break;
		}
		printf("��������Ҫ�����������ƣ�\n");
		while ((c = getchar()) != EOF && c != '\n');
		scanf_s("%c", &name, 1);
		for (i1 = 0;i1 < 5;) {
			if (name == goods[i1].label) {
				printf("������ȷ\n"); // �ж��û��Ƿ���ȷ��������
				break;
			}
			else {
				i1++;
				continue;
			}
		}
		printf("��������Ҫ��������ͨ����\n");
		scanf_s("%d", &passage);
		for (i2 = 0;i2 < 5;) {
			if (passage == goods[i2].channel) {
				printf("ͨ������ȷ\n"); // �ж��û��Ƿ���ȷ����ͨ����
				break;
			}
			else {
				i2++;
				continue;
			}
		}
		printf("��������Ҫ������������\n");
		scanf_s("%d", &n);
		if (goods[passage - 1].num >= n) {
			goods[passage - 1].num -= n;
			per = goods[passage - 1].price * n;
			total += per;
			continue;
		}
		else {
			printf("��ʱû����ô�����Ŷ,����������\n");
			continue;
		}
		if (goods[0].num == 0 && goods[1].num == 0 && goods[2].num == 0 && goods[3].num == 0 && goods[4].num == 0) { // �ж��ۻ������Ƿ��л���
			printf("��Ʒ�Ѿ�����������Ŷ\n");
			break;
		}
	}
		while (1) {
			printf("�뿪ʼͶ�ң�ֻ��Ͷ��1��2��5Ԫ����\n");
			while ((c = getchar()) != EOF && c != '\n');
			scanf_s("%d", &face);
			if (!(face == 1 || face == 2 || face == 5)) {
				printf("ֻ��Ͷ��1��2��5ԪŶ��������Ͷ��\n");
				continue;
			}
			else {
				sum += face;
				if (sum >= total) {
					change = sum - total;
					printf("����%dԪ\n", change);
					break;
				}
				else {
					printf("��Ͷ��Ǯ��������\n");
					continue;
				}
			}
		}
		return 0;
	}
	

