#include <iostream>

using namespace std;

template<typename T>
class Matrix
{
private:
	T** Mat;
	int m;
	int n;
public:
	Matrix()
	{
		n = m = 0;
		Mat = nullptr;
	}
	Matrix(int m, int n)
	{
		this->m = m;
		this->n = n;
		Mat = new T* [m];
		for (int i = 0; i < m; i++) {Mat[i] = new T[n];}

		for (int i = 0; i < m; i++){
			for (int j = 0; j < n; j++){
				Mat[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& other)
	{
		this->m = other.m;
		this->n = other.n;
		Mat = new T*[m];
		for (int i = 0; i < m; i++) { Mat[i] = new T[n]; }

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				this->Mat[i][j] = other.Mat[i][j];
			}
		}
	}
	~Matrix()
	{
		if (n > 0)
			for (int i = 0; i < m; i++) {delete[] Mat[i];}
		if (m > 0)
			delete[]Mat;
	}

    T  GetMatrix(int i,int j) const
	{
		return Mat[i][j];
	}
	void SetMatrix( int i, int j,T value) 
	{
		Mat[i][j] = value;
	}
	int  GetRows()const
	{
		return this->m;
	}
	int  GetCols()const
	{
		return n;
	}
	void PrintMatrix()
	{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cout << Mat[i][j] << "\t";
			}
			cout << endl;
		}
	}
	void FillMatrix()
	{
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				Mat[i][j] = rand() %5;
			}
		}
	}
	
	Matrix& operator =(const Matrix& other)
	{
		if (n > 0){
			for (int i = 0; i < m; i++){
				delete[] Mat[i];
			}
		}
		if (m > 0) {
			delete[]Mat;
		}

		this->m = other.m;
		this->n = other.n;
		Mat = new T* [m];
		for (int i = 0; i < m; i++) { Mat[i] = new T[n]; }

		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				this->Mat[i][j] = other.Mat[i][j];
			}
		}
		return *this;
	}
};

template <typename T>
Matrix<T> operator +(const Matrix<T> left,const Matrix<T> right)
{
	Matrix newMat(left.GetRows(), left.GetCols());
	try{
		Check(left, right);
		for (int i = 0; i < left.GetRows(); i++) {
			for (int j = 0; j < left.GetCols(); j++) {
				newMat.SetMatrix(i, j, left.GetMatrix(i, j) + right.GetMatrix(i, j));
			}
		}
		return newMat;
	}
	catch (const std::exception& ex){
		cout << ex.what() << endl;
	}
}
template <typename T>
Matrix<T> operator -(const Matrix<T> left, const Matrix<T> right)
{
	Matrix newMat(left.GetRows(), left.GetCols());
	try{
		Check(left, right);
		for (int i = 0; i < left.GetRows(); i++) {
			for (int j = 0; j < left.GetCols(); j++) {
				newMat.SetMatrix(i, j, left.GetMatrix(i, j) + (-1*right.GetMatrix(i, j)));
			}
		}
		return newMat;
	}
	catch (const std::exception& ex){
		cout << ex.what() << endl;
	}
}
template <typename T>
Matrix<T> operator *(const Matrix<T> left, const Matrix<T> right)
{
	Matrix newMat(left.GetRows(), left.GetCols());
	T sum = 0;
	for (int i = 0; i < left.GetRows(); i++) {
		for (int j = 0; j < left.GetCols(); j++) {
			sum = 0;
			for (int k = 0; k < left.GetCols(); k++) {
				sum += left.GetMatrix(i, k) * right.GetMatrix(k, j);
			}
			newMat.SetMatrix(i, j, sum);
		}
	}
    return newMat;
}
template <typename T>
Matrix<T> operator /(Matrix<T> left, const Matrix<T> right)
{
	Matrix<T> newMat(left.GetRows(), left.GetCols());
	Matrix<T> newMat2(left.GetRows(), left.GetCols());
	T sum = 0;
	newMat2 = InversMatrix(left);
	for (int i = 0; i < left.GetRows(); i++) {
		for (int j = 0; j < left.GetCols(); j++) {
			sum = 0;
			for (int k = 0; k < left.GetCols(); k++) {
				sum += newMat2.GetMatrix(i, k) * right.GetMatrix(k, j);
			}
			newMat.SetMatrix(i, j, sum);
		}
	}
	return newMat;
}


template <typename T>
std::ostream& operator << (std::ostream& os, const Matrix<T>& obj)
{
	for (int i = 0; i < obj.GetRows(); i++) {
		for (int j = 0; j < obj.GetCols(); j++) {
			os << obj.GetMatrix(i,j) << "\t";
		}
		cout << endl;
	}
	return os;
}
template <typename T>
std::istream& operator >> (std::istream& is ,Matrix<T> &obj)
{
	T value;
	for (int i = 0; i < obj.GetRows(); i++) {
		for (int j = 0; j < obj.GetCols(); j++) {
			is >> value;
			obj.SetMatrix(i, j,value);
		}
		cout<< endl;
	}
	return is;
}


template <typename T>
T    Determinant(Matrix<T>& mat)
{
	T det = 0;
	int degree = 1;
	if (mat.GetRows() < 1) cout << "Определитель вычислить невозможно!" << endl;
	if (mat.GetRows() == 1) return mat.GetMatrix(0, 0);
	if (mat.GetRows() == 2) return mat.GetMatrix(0, 0) * mat.GetMatrix(1, 1) - (mat.GetMatrix(1, 0) * mat.GetMatrix(0, 1));

	Matrix<T> newMat(mat.GetRows() - 1, mat.GetCols() - 1);
	for (int j = 0; j < mat.GetRows(); j++) {
		GetMatrixWithoutIJ(mat, mat.GetRows(), 0, j, newMat);
		det = det + (degree * mat.GetMatrix(0, j) * Determinant(newMat));
		degree = -degree;
	}
	return det;
}
template <typename T>
void   GetMatrixWithoutIJ(Matrix<T>&mat,int size,int row,int col, Matrix<T>&newMat)
{
	int indexOffRow = 0;
	int indexOffCol = 0;
	for (int i = 0; i < size-1; i++) {
		if (i == row) {
			indexOffRow = 1;
		}
		indexOffCol = 0;
			for (int j = 0; j < size-1 ; j++) {
				if (j == col) {
					indexOffCol = 1;
				}
				newMat.SetMatrix(i, j, mat.GetMatrix(i + indexOffRow, j + indexOffCol));
			}
	}
}
template <typename T>
Matrix<T> TransponMatrix(Matrix<T>&mat)
{
	Matrix<T> newMat(mat.GetRows(), mat.GetCols());
	for (int i = 0; i < mat.GetRows(); i++) {
		for (int j = 0; j < mat.GetRows(); j++) {
			newMat.SetMatrix(j, i, mat.GetMatrix(i,j));
		}
	}
	return newMat;
}
template <typename T>
Matrix<T> InversMatrix(Matrix<T>& mat)
{
	Matrix<T> newMat(mat.GetRows() - 1, mat.GetCols() - 1);
	Matrix<T> obrMat(mat.GetRows(), mat.GetCols());
	try
	{
		Check2(mat);
		for (int i = 0; i < mat.GetRows(); i++) {
			for (int j = 0; j < mat.GetRows(); j++) {
				int m = mat.GetRows() - 1;
				for (int k = 0; k < m; k++) {
					GetMatrixWithoutIJ(mat, mat.GetRows(), i, j, newMat);
					obrMat.SetMatrix(i, j, pow(-1.0, i + j + 2) * Determinant(newMat) / Determinant(mat));
				}
			}
		}
	}
	catch (const std::exception& ex)
	{
		cout << ex.what() << endl;
	}
	TransponMatrix(obrMat);
	return obrMat;
}
template <typename T>
void   Check(Matrix<T> left, Matrix<T> right)
{
	if (left.GetRows() != right.GetRows() || left.GetCols() != right.GetRows()) throw exception("Матрицы разной размерности!");
}
template <typename T>
void   Check2(Matrix<T> mat)
{
	if (Determinant(mat) == 0) throw exception("Обратной матрицы не существует!");
}

int main()
{
	setlocale(LC_ALL, "Rus");
	Matrix<double> arr(3, 3);
	Matrix<double> brr(3, 3);
	Matrix<double> crr(3, 3);
	Matrix<double> lrr(3, 3);
	arr.FillMatrix();
	brr.FillMatrix();
	arr.PrintMatrix();
	cout << endl;
	brr.PrintMatrix();
	cout << "Определитель матрицы A: " << Determinant(arr) << endl;
	cout << "Определитель матрицы B: " << Determinant(brr) << endl;
	cout << endl;
	cout << "Обратная матрица A: " << endl;
	cout << InversMatrix(arr) << endl;
	crr = arr / brr;
	cout << crr << endl;
	cout<<InversMatrix(lrr);
	
	
}