#include "MyForm2.h"
[STAThreadAttribute]
void main(/*int argc, char **argv*/) {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Project1::MyForm2 form;
	Application::Run(%form);
}