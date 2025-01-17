#include "gnuplotter.hpp"

int main(void) {
	Plot plot;

	int n = 100;
	std::vector<double> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		x[i] = 0.1 * i;
		y[i] = sin(x[i]);
	}

	plot.ScatterPlot2D(x, y);
	plot.show();
}
