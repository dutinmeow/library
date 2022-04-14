#include "convolution/ultra-fast-fourier-transform.hpp"

namespace conv {
	template<typename T, typename U = double>
	vector<T> fast_convolution(const vector<T> &a, const vector<T> &b) {
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;
		vector<complex<U>> c(n);
		for (int i = 0; i < a.size(); i++)
			c[i] = static_cast<U>(a[i]);
		for (int i = 0; i < b.size(); i++)
			c[i] = {c[i].real(), static_cast<U>(b[i])};
		ultra_fast_fourier_transform(c);

		vector<complex<U>> d(n);
		for (int i = 0, j; i < n; i++) {
			j = (n - i) & (n - 1);
			d[i] = (c[j] * c[j] - conj(c[i] * c[i])) * complex<U>{0, -0.25 / n};
		}
		ultra_fast_fourier_transform(d);

		n = a.size() + b.size() - 1;
		vector<T> ret(n);
		for (int i = 0; i < n; i++)
			ret[i] = static_cast<T>(d[i].real() + 0.5);
		return ret;
	}
}