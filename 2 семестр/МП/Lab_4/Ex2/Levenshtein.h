#pragma once
// -- ���������   �������e��� (������������ ����������������)
int levenshtein(
	int lx,           // ����� ����� x 
	const char x[],   // ����� ������ lx
	int ly,           // ����� ����� y
	const char y[]    // ����� y
);
// -- ���������   �������e��� (��������)
int levenshtein_r(
	int lx,           // ����� ������ x 
	const char x[],   // ������ ������ lx
	int ly,           // ����� ������ y
	const char y[]    // ������ y
);
