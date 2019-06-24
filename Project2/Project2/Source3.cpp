/**
*@file lp_nikolenko.c
*@author ��������� �.�. , ��. 515� , ������� 14
*@date ��������: 23.06.2019
*@brief ������� �� ������ �������� 2019 ���� 1 ����
* ������� ������ 32-������� ��������� ����� � ����� �� ����������
*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <conio.h>
#include <locale.h>
#include <ctype.h> 
/*
* ������� ������ 32-������� ��������� ����� � ����� �� ����������
* @param number ���� ��������
* @param *s ����� ��������
*/
void numbers_to_words(int number, char *s);

int main()
{
	setlocale(LC_ALL, "Rus");
	printf("*--------------------------------------------*\n| ������� ������ ����� � ����� �� ���������� |\n*--------------------------------------------*\n\n");
	int res = 0;
	long long int number;
reinput:
	do
	{
		printf("������� �������� �������� � ��������� 32-������� ��������� ����� :");
		res = scanf_s("%llu", &number);
		if (res == 0)
			printf("������ ! �� ����� ���������� �������� .\n");
		while (getchar() != '\n');
	} while (res != 1);
	if (number > LONG_MAX || number < LONG_MIN)
	{
		printf("�� ����� �������� , ������� �� ������� � �������� 32-������� ��������� �����\n");
		goto reinput;
	}
	char string[120];
	printf("%d ----> ", number);
	if (number == 0)
	{
		printf(" ���� \n");
		_getch();
		return 1;
	}
	string[0] = '\0';
	numbers_to_words(number, string);
	printf("%s\n", string);
	_getch();
	return 0;
}

void numbers_to_words(int number, char *s) {
	if (number < 0)
	{
		number *= -1;
		printf("�i��� ");
	}
	int position = 0, div = 1000000000, chastnoe = number, remainder; // ������� � ������ ��� ������, ����������� �������� , ������� � ������� �� �������
	int number_position[10]; // ������� 
	for (int i = 0; i < 10; i++)
	{
		remainder = (int)(chastnoe / div);
		number_position[i] = remainder;
		chastnoe = chastnoe - remainder * div;
		div = div / 10;
	}
	// �i������
	switch (number_position[0])
	{
	case 1: strcpy(s, "���� �i����� "); break;
	case 2: strcpy(s, "��� �i������ "); break;
	default:break;
	}
	position = strlen(s);
	// �i������
	switch (number_position[1])
	{
	case 1: strcpy(s + position, "��� "); break;
	case 2: strcpy(s + position, "��i��� "); break;
	case 3: strcpy(s + position, "������ "); break;
	case 4: strcpy(s + position, "��������� "); break;
	case 5: strcpy(s + position, "�`����� "); break;
	case 6: strcpy(s + position, "�i����� "); break;
	case 7: strcpy(s + position, "�i���� "); break;
	case 8: strcpy(s + position, "�i�i���� "); break;
	case 9: strcpy(s + position, "���`������ "); break;
	default: break;
	}
	position = strlen(s);
	switch (number_position[2])
	{
	case 1:
		// ����� �� 10kk �� 19kk
		switch (number_position[3])
		{
		case 0: strcpy(s + position, "������ �i�����i� "); break;
		case 1: strcpy(s + position, "���������� �i�����i� "); break;
		case 2: strcpy(s + position, "���������� �i�����i� "); break;
		case 3: strcpy(s + position, "���������� �i�����i� "); break;
		case 4: strcpy(s + position, "������������ �i�����i� "); break;
		case 5: strcpy(s + position, "�`��������� �i�����i� "); break;
		case 6: strcpy(s + position, "�i��������� �i�����i� "); break;
		case 7: strcpy(s + position, "�i�������� �i�����i� "); break;
		case 8: strcpy(s + position, "�i�i�������� �i�����i� "); break;
		case 9: strcpy(s + position, "���`��������� �i�����i� "); break;
		}
		number_position[3] = -1;
		position = strlen(s);
		break;
	case 2: strcpy(s + position, "�������� "); break;
	case 3: strcpy(s + position, "�������� "); break;
	case 4: strcpy(s + position, "����� "); break;
	case 5: strcpy(s + position, "�`������� "); break;
	case 6: strcpy(s + position, "�i������� "); break;
	case 7: strcpy(s + position, "�i������ "); break;
	case 8: strcpy(s + position, "�i�i������ "); break;
	case 9: strcpy(s + position, "���`������ "); break;
	default: break;
	}
	position = strlen(s);
	switch (number_position[3])
	{
	case 0: if (number_position[2] || number_position[1])strcpy(s + position, "�i�����i� "); break;
	case 1: strcpy(s + position, "���� �i����� "); break;
	case 2: strcpy(s + position, "��� �i������ "); break;
	case 3: strcpy(s + position, "��� �i������"); break;
	case 4: strcpy(s + position, "������ �i������ "); break;
	case 5: strcpy(s + position, "�`��� �i�����i� "); break;
	case 6: strcpy(s + position, "�i��� �i�����i� "); break;
	case 7: strcpy(s + position, "�i� �i�����i� "); break;
	case 8: strcpy(s + position, "�i�i� �i�����i� "); break;
	case 9: strcpy(s + position, "���`��� �i�����i� "); break;
	default: break;
	}
	position = strlen(s);
	//������
	switch (number_position[4])
	{
	case 1: strcpy(s + position, "��� "); break;
	case 2: strcpy(s + position, "��i��� "); break;
	case 3: strcpy(s + position, "������ "); break;
	case 4: strcpy(s + position, "��������� "); break;
	case 5: strcpy(s + position, "�`����� "); break;
	case 6: strcpy(s + position, "�i����� "); break;
	case 7: strcpy(s + position, "�i���� "); break;
	case 8: strcpy(s + position, "�i�i���� "); break;
	case 9: strcpy(s + position, "���`������ "); break;
	default: break;
	}
	position = strlen(s);
	switch (number_position[5])
	{
	case 1:
		// ����� �� 10k �� 19k
		switch (number_position[6])
		{
		case 0: strcpy(s + position, "������ ����� "); break;
		case 1: strcpy(s + position, "���������� ����� "); break;
		case 2: strcpy(s + position, "���������� ����� "); break;
		case 3: strcpy(s + position, "���������� ����� "); break;
		case 4: strcpy(s + position, "������������ ����� "); break;
		case 5: strcpy(s + position, "�`��������� ����� "); break;
		case 6: strcpy(s + position, "�i��������� ����� "); break;
		case 7: strcpy(s + position, "�i�������� ����� "); break;
		case 8: strcpy(s + position, "�i�i�������� ����� "); break;
		case 9: strcpy(s + position, "���`��������� ����� "); break;
		}
		number_position[6] = -1;
		position = strlen(s);
		break;
	case 2: strcpy(s + position, "�������� "); break;
	case 3: strcpy(s + position, "�������� "); break;
	case 4: strcpy(s + position, "����� "); break;
	case 5: strcpy(s + position, "�`�������� "); break;
	case 6: strcpy(s + position, "�i�������� "); break;
	case 7: strcpy(s + position, "�i������ "); break;
	case 8: strcpy(s + position, "�i�i������ "); break;
	case 9: strcpy(s + position, "���`������ "); break;
	default: break;
	}
	position = strlen(s);
	switch (number_position[6])
	{
	case 0: if (number_position[5] || number_position[4])strcpy(s + position, "����� "); break;
	case 1: strcpy(s + position, "���� ������ "); break;
	case 2: strcpy(s + position, "��i �����i "); break;
	case 3: strcpy(s + position, "��� �����i "); break;
	case 4: strcpy(s + position, "������ �����i "); break;
	case 5: strcpy(s + position, "�`��� ����� "); break;
	case 6: strcpy(s + position, "�i��� ����� "); break;
	case 7: strcpy(s + position, "�i� ����� "); break;
	case 8: strcpy(s + position, "�i�i� ����� "); break;
	case 9: strcpy(s + position, "���`��� ����� "); break;
	default: break;
	}
	position = strlen(s);
	// �����
	switch (number_position[7])
	{
	case 1: strcpy(s + position, "��� "); break;
	case 2: strcpy(s + position, "��i��i "); break;
	case 3: strcpy(s + position, "������ "); break;
	case 4: strcpy(s + position, "��������� "); break;
	case 5: strcpy(s + position, "�`����� "); break;
	case 6: strcpy(s + position, "�i����� "); break;
	case 7: strcpy(s + position, "�i���� "); break;
	case 8: strcpy(s + position, "�i�i���� "); break;
	case 9: strcpy(s + position, "���`������ "); break;
	default: break;
	}
	position = strlen(s);
	// �������
	switch (number_position[8])
	{
	case 1:
		// ����� �� 10 �� 19
		switch (number_position[9])
		{
		case 0: strcpy(s + position, "������ "); break;
		case 1: strcpy(s + position, "���������� "); break;
		case 2: strcpy(s + position, "���������� "); break;
		case 3: strcpy(s + position, "���������� "); break;
		case 4: strcpy(s + position, "������������ "); break;
		case 5: strcpy(s + position, "�`��������� "); break;
		case 6: strcpy(s + position, "�i��������� "); break;
		case 7: strcpy(s + position, "�i�������� "); break;
		case 8: strcpy(s + position, "�i�i�������� "); break;
		case 9: strcpy(s + position, "���`��������� "); break;
		}
		number_position[9] = 0;
		position = strlen(s);
		break;
	case 2: strcpy(s + position, "�������� "); break;
	case 3: strcpy(s + position, "�������� "); break;
	case 4: strcpy(s + position, "����� "); break;
	case 5: strcpy(s + position, "�`�������� "); break;
	case 6: strcpy(s + position, "�i�������� "); break;
	case 7: strcpy(s + position, "�i������ "); break;
	case 8: strcpy(s + position, "�i�i������ "); break;
	case 9: strcpy(s + position, "���`������ "); break;
	default: break;
	}
	position = strlen(s);
	// �������
	switch (number_position[9]) {
	case 1: strcpy(s + position, "���� "); break;
	case 2: strcpy(s + position, "��� "); break;
	case 3: strcpy(s + position, "��� "); break;
	case 4: strcpy(s + position, "������ "); break;
	case 5: strcpy(s + position, "�`��� "); break;
	case 6: strcpy(s + position, "�i��� "); break;
	case 7: strcpy(s + position, "�i� "); break;
	case 8: strcpy(s + position, "�i�i� "); break;
	case 9: strcpy(s + position, "���`��� "); break;
	default: break;
	}
	position = strlen(s);
}
