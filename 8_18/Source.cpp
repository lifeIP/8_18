#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <stdio.h>
#include <fstream>
#include <string.h>
#include <windows.h>

using namespace std;

void process(const char* file, const char* file1);
void diy(const char* strin, char* strout);


int main() {
	setlocale(LC_ALL, "RUS");
	process("file.txt", "file1.txt");
}

void process(const char* file, const char* file1)
{
	FILE* f = fopen(file, "rt");
	if (f == NULL)
	{
		cout << "File is not open  " << endl;
		return;
	}
	ofstream fo;
	fo.open(file1);
	if (!fo.is_open())
	{
		cout << "File is not open " << endl;
		fclose(f);
		return;
	}
	while (!feof(f))
	{
		char buff[2500];
		buff[0] = 0;
		fgets(buff, 2500, f);
		if (strlen(buff) > 0)
		{
			char buff2[2500];
			diy(buff, buff2);
			cout << buff2;
			fo << buff2;
		}
	}
	fclose(f);
	fo.close();
}



void diy(const char* str_l, char* resault_l) {
	memset(resault_l, 0, sizeof(char) * 2500);
	int count = 0;
	for (int i = 0; i < strlen(str_l); i++) {
		if ((str_l[i] >= 'A') && (str_l[i] <= 'Z') || (str_l[i] >= 'a') && (str_l[i] <= 'z')){}
		else{
			count++;
		}
	}
	strncpy(resault_l, str_l, strlen(str_l)-1);
	char b[5] = {};
	sprintf(b, " %d\n", count-1);
	strcat(resault_l, b);
}