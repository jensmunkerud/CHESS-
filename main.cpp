#include "std_lib_facilities.h"
#include "mainWindow.h"

int main() {
	MainWindow mainWindow;
	mainWindow.wait_for_close();
	return 0;
}