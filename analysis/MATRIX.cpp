#include <iostream>
#include <iomanip>
#include <vector>
#include <cassert>
using namespace std; 

using num = double; 

class matrix {
protected:
	vector<vector<num>> data; 
	int m, n; 
public:
	explicit matrix(int m_, int n_) {
		m = m_; n = n_; 
		data.resize(m+1); 
		for(int i=0; i<=m; i++)
			data[i].resize(n+1); 
	}

	vector<num>& operator[](int i) { 
		return data[i];
	}
	num get(int i, int j) const { 
		return data[i][j]; 
	}
	int rows() const {
		return m; 
	}
	int cols() const {
		return n; 
	}
	
	explicit operator num(){
		// Convert to scalar (if 1x1)
		assert(m==1 && n==1);
		return data[1][1]; 
	}
	
	matrix operator+(const matrix& B) { // Return self+B
		assert(m==B.m && n==B.n); 
		matrix C(m, n); 
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				C.data[i][j] = data[i][j] + B.data[i][j]; 
		return C; 
	}
	
	matrix operator*(num c) { // Scalar multiplication
		matrix C(m, n);
		for(int i=1; i<=m; i++)
			for(int j=1; j<=n; j++)
				C.data[i][j] = c * data[i][j]; 
		return C; 
	}
	
	matrix operator*(const matrix& B) { // Return self * B
		int p = B.n; 
		assert(n == B.m); 
		matrix C(m, p); 
		for(int i=1; i<=m; i++)
			for(int j=1; j<=p; j++)
				for(int k=1; k<=n; k++)
					C.data[i][j] += data[i][k] * B.data[k][j]; 
		return C; 
	}
	
	num trace() { // Return the sum of the elements on the main diagonal
		assert(m == n); 
		num s = 0; 
		for(int i=1; i<=n; i++) s += data[i][i]; 
		return s; 
	}
	
	matrix tp() { // Return the transpose of A
		matrix At(n, m); 
		for(int i=1; i<=n; i++)
			for(int j=1; j<=m; j++)
				At.data[i][j] = data[j][i]; 
		return At; 
	}
	
	void write(ostream& out) { // Write to output stream
		out << rows() << " " << cols() << "\n"; 
		out << fixed << setprecision(2); 
		for(int i=1; i<=rows(); i++) {
			for(int j=1; j<=cols(); j++) {
				out << data[i][j]; 
				if(j < cols()) out << "\t"; 
			}
			if(i < rows()) out << "\n"; 
		}
		out << endl; 
	}
	
	void read(istream& in) { // Read from input stream
		for(int i=1; i<=rows(); i++)
			for(int j=1; j<=cols(); j++)
				in >> data[i][j]; 
		in >> ws; 
	}
}; 

struct cvec : public matrix { // Column vector class
	cvec(int m_) : matrix(m_, 1){

	 }
	num& operator[](int i) { 
		return data[i][1];
	}
	cvec(const matrix& A, int j) : matrix(A.rows(), 1) { // Copy the j-th column of A 
		for(int i=1; i<=m; i++){
			data[i][1] = A.get(i,j); 
		}
	}
	cvec operator+(const cvec& b) { 
		return cvec(matrix::operator+(b), 1);
	}
	cvec operator*(num c) {
		return cvec(matrix::operator*(c), 1); 
	} 
}; 

struct rvec : public matrix { // Row vector class
	rvec(int n_) : matrix(1, n_) { }
	num& operator[](int j) { 
		return data[1][j]; 
	}
	rvec(const matrix& A, int i) : matrix(1, A.cols()) { // Copy the i-th row of A
		for(int j=1; j<=n; j++) {
			data[1][j] = A.get(i,j); 
		}
	}
}; 

#ifdef M_MATRIX
int main() {
	int m, n; cin >> m >> n; 
	matrix A(m, n); 
	A.read(cin); 
	matrix B = A.tp() * A; 
	B.write(cout); 
}
#endif

