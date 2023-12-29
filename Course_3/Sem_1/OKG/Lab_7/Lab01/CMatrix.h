#ifndef CMATRIXH
# define CMATRIXH 1
class CMatrix
{
	double **array;
	int n_rows;							// ����� �����
	int n_cols;							// ����� ��������
public:
	CMatrix();							// ����������� �� ��������� (1 �� 1)	
	CMatrix(int, int);		    		// �����������	
	CMatrix(int);						// ����������� -������� (���� �������)
	CMatrix(const CMatrix&);			// ����������� �����������	
	~CMatrix();
	double &operator()(int, int);        // ����� �������� ������� �� ������� 
	double &operator()(int);            // ����� �������� ������� �� ������� 
	CMatrix operator-();			    // �������� "-"
	CMatrix operator=(const CMatrix&);	// �������� "���������":    M1=M2
	CMatrix operator*(CMatrix&);        // �������� "������������": �1*�2
	CMatrix operator+(CMatrix&);	    // �������� "+": M1+M2
	CMatrix operator-(CMatrix&);	    // �������� "-": M1-M2
	CMatrix operator+(double);		    // �������� "+": M+a
	CMatrix operator-(double);		    // �������� "-": M-a
	CMatrix operator*(double);		    // �������� "-": M-a
	int rows()const { return n_rows; };   // ���������� ����� �����
	int cols()const { return n_cols; };    // ���������� ����� �����
	CMatrix Transp();				    // ���������� �������,����������������� � �������
	CMatrix GetRow(int);			    // ���������� ������ �� ������
	CMatrix GetRow(int, int, int);
	CMatrix GetCol(int);			    // ���������� ������� �� ������
	CMatrix GetCol(int, int, int);
	CMatrix RedimMatrix(int, int);	    // �������� ������ ������� � ������������ ������
	CMatrix RedimData(int, int);         // �������� ������ ������� � ����������� ������, 
										//������� ����� ���������
	CMatrix RedimMatrix(int);	        // �������� ������ ������� � ������������ ������
	CMatrix RedimData(int);             // �������� ������ ������� � ����������� ������,
										//������� ����� ���������
	double MaxElement();			  	// ������������ ������� �������
	double MinElement();				// ����������� ������� �������
};


#endif