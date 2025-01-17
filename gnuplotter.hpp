#include <iostream>
#include <fstream>
#include <cstdio>

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
		outfile << "plot 'data1.dat'\n";
		outfile.close();
	}

	/**
	 * 2D scatter plot function, which is the fundemental 2D plot
	 */
	void ScatterPlot2D(std::vector<double> x, std::vector<double> y) {
		std::ofstream outfile(data_file);
		if (x.size() != y.size()) {
			std::cerr << "ERROR: mismatched dims!\n";
			exit(1);
		}
		for (int i = 0; i < x.size(); ++i) {
			outfile << x[i] << " " << y[i] << std::endl;
		}
		outfile.close();

		// TODO this needs to make more logical sense
		this->InitPlot2D();
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
