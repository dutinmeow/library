#include "convolution/fast-fourier-transform.hpp"

#pragma region complex_convolution

namespace conv {
	template<typename T, typename U = double>
	typename enable_if<is_floating_point<T>::value, vector<complex<T>>>::type
	complex_convolution(const vector<complex<T>> &a, const vector<complex<T>> &b) {
		int n = 1;
		while (n < a.size() + b.size()) 
			n <<= 1;
		vector<complex<U>> pa(n), pb(n);
		for (int i = 0; i < a.size(); i++)
			pa[i] = complex<U>(a[i].real(), a[i].imag());
		for (int i = 0; i < b.size(); i++)
			pb[i] = complex<U>(b[i].real(), b[i].imag());

		fast_fourier_transform(pa);
		fast_fourier_transform(pb);
		vector<complex<U>> c(n);
		for (int i = 0; i < n; i++) 
			c[i] = pa[i] * pb[i] / static_cast<U>(n);
		reverse(c.begin() + 1, c.end());
		fast_fourier_transform(c);

		n = a.size() + b.size() - 1;
		vector<complex<T>> ret(n);
		for (int i = 0; i < n; i++)
			ret[i] = complex<T>(static_cast<T>(c[i].real()), static_cast<T>(c[i].imag()));
		return ret;
	}
}

#pragma endregion complex_convolution