#include <iostream>
#include <fstream>
#include <cstdio>

class Plot {
private:
	bool is3D;
	const std::string filename = "dat.gnu";
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
	 *
	 * TODO actually setup the boilerplate here for a plot function
	 */
	void InitPlot2D() {
		std::ofstream outfile(filename);
		outfile << "# set terminal pngcairo  transparent enhanced font \"arial,10\" fontscale 1.0 size 600, 400\n";
		outfile << "# set output 'simple.1.png'\n";
		outfile << "set key fixed left top vertical Right noreverse enhanced autotitle box lt black linewidth 1.000 dashtype solid\n";
		outfile << "set title \"" << this->title << "\"\n";
		outfile << "set title  font \",20\" textcolor lt -1 norotate\n";
		outfile << "set trange [ * : * ] noreverse nowriteback\n";
		outfile << "set urange [ * : * ] noreverse nowriteback\n";
		outfile << "set vrange [ * : * ] noreverse nowriteback\n";
		outfile << "set xrange [ * : * ] noreverse writeback\n";
		outfile << "set x2range [ * : * ] noreverse writeback\n";
		outfile << "set yrange [ * : * ] noreverse writeback\n";
		outfile << "set y2range [ * : * ] noreverse writeback\n";
		outfile << "set zrange [ * : * ] noreverse writeback\n";
		outfile << "set cbrange [ * : * ] noreverse writeback\n";
		outfile << "set rrange [ * : * ] noreverse writeback\n";
		outfile << "set colorbox vertical origin screen 0.9, 0.2 size screen 0.05, 0.6 front  noinvert bdefault\n";
		outfile << "NO_ANIMATION = 1\n";
		outfile << "plot [-10:10] sin(x),atan(x),cos(atan(x))\n";
		outfile.close();
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
	}

	/**
	 * Similar in nature to the plt.show() function in matplotlib essentially it
	 * will run the actual plotter script and show the plot
	 */
	void show() {
		system("gnuplot -p dat.gnu");
		// this->DeleteScript();
	}
};
