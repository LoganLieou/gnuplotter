#include "gnuplotter.hpp"
#include <random>
#include <vector>

int main(void) {
	Plot plot;

	int n = 100;
	std::vector<double> x(n), y(n);
	for (int i = 0; i < n; ++i) {
		x[i] = 0.1 * i;
		y[i] = sin(x[i]);
	}

	// plot.ScatterPlot2D(x, y);
	// plot.show();

	// NOTE: there's a major flaw here, we must run .show() between each plot and
	// cannot handle more than 1 plot
	/*
	std::vector<std::vector<double> > data = {
		{1.1, 2.1, 3.1, 2.0, 7.0},
		{1.1, 2.1, 2.2, 6.0, 3.7},
		{8.1, 8.2, 8.4, 9.0, 9.1}
	};
	plot.CandleStickPlot(data);
	plot.show();
	*/

	// testing the histogram plot
	std::vector<double> vals;
	std::default_random_engine rd;
	std::normal_distribution<double> norm(0.0, 1.0);
	for (int i = 0; i < 100; ++i) {
		vals.push_back(norm(rd));
	}
	plot.BoxPlot(vals);
	plot.show();
}
