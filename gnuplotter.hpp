#include <algorithm>
#include <iostream>
#include <fstream>

class Plot {
private:
	bool is3D;
	const std::string filename = "dat.gnu";
	const std::string data_file = "data1.dat";
	std::string title;
public:

	/**
	 * Default constructor for the class
	 */
	Plot(bool _is3D=false, std::string _title="Plot") {
		this->is3D = _is3D;
		this->title = _title;
	}

	/**
	 * Initialize a 2D plotting script. this is a utility function which will
	 * setup a basic .gnu script for 2D plots
	 */
	void InitPlot2D() {
		std::ofstream outfile(filename);
		outfile << "set title \"" << this->title << "\"" << std::endl;
		outfile.close();
	}

	/**
	 * 2D scatter plot function, which is the fundemental 2D plot
	 */
	void ScatterPlot2D(std::vector<double> x, std::vector<double> y) {
		this->InitPlot2D();
		std::ofstream outfile(data_file);
		if (x.size() != y.size()) {
			std::cerr << "ERROR: mismatched dims!\n";
			exit(1);
		}
		for (int i = 0; i < x.size(); ++i) {
			outfile << x[i] << " " << y[i] << std::endl;
		}
		outfile.close();

		// add the data file to the main plot script
		outfile.open(filename, std::ios::app);
		outfile << "plot 'data1.dat'\n";
	}

	/**
	 * Plotting boxplots overtime this is pretty good for dealing with timeseries
	 * trading data where a bunch of orders were filled overtime
	 * 
	 * TODO finish this not sure how the boxplot works in gnuplot
	 */
	void CandleStickPlot(std::vector<std::vector<double> > data) {
		std::ofstream outfile(data_file);
		for (int i = 0; i < data[0].size(); ++i) {
			for (int j = 0; j < data.size(); ++j) {
				outfile << data[j][i] << "\t";
			}
			outfile << "\n";
		}
		outfile.close();

		outfile.open(filename);
		outfile << "set boxwidth 0.2\n";
		outfile << "plot '" << data_file << "' with candlesticks\n";
	}

	/**
	 * Plot a histogram, I was thinking this seemed pretty useful, as I was
	 * randomly generating some values and wanted to see what the distribution
	 * look liked. Data is 1D in a histogram i.e. freq data, I mean... this
	 * technically works I guess
	 *
	 * TODO bins
	 */
	void Histogram(std::vector<double> data) {
		std::ofstream outfile(data_file);
		for (int i = 0; i < data.size(); ++i) {
			outfile << data[i] << "\n";
		}
		outfile << "\n";
		outfile.close();

		outfile.open(filename);
		outfile << "set style histogram cluster\n";
		outfile << "set style data histogram\n";
		outfile << "set boxwidth 0.9\n";
		outfile << "plot '" << data_file << "'\n";
	}

	void BoxPlot(std::vector<double> data) {
		// TODO write a function for this
		std::ofstream outfile(data_file);
		for (int i = 0; i < data.size(); ++i) {
			outfile << data[i] << "\n";
		}
		outfile << "\n";
		outfile.close();

		outfile.open(filename);
		outfile << "set style fill solid 0.5 border -1\n";
		outfile << "set style boxplot outliers pointtype 7\n";
		outfile << "set style data boxplot\n";
		outfile << "set boxwidth 0.5\n";
		outfile << "set pointsize 0.5\n";
		outfile << "set xrange [*:*]\n";
		outfile << "set yrange [*:*]\n";
		outfile << "set xtics auto\n";
		outfile << "set size 0.8\n";
		outfile << "plot '" << data_file << "' lc \"sea-green\"\n";
	}

	/**
	 * Delete Script cleans up after the process of plotting something using
	 * gnuplot as there's a tempfile created called dat.gnu
	 */
	void DeleteScript() {
		if (remove(filename.c_str()) != 0) {
			std::cerr << "ERROR: failed to remove the temp file dat.gnu!" << std::endl;
			exit(1);
		}
		if (remove(data_file.c_str()) != 0) {
			std::cerr << "ERROR: failed to remove the temp file data1.dat!" << std::endl;
			exit(1);
		}
	}

	/**
	 * Similar in nature to the plt.show() function in matplotlib essentially it
	 * will run the actual plotter script and show the plot
	 */
	void show() {
		system("gnuplot -p dat.gnu");
		this->DeleteScript();
	}
};
