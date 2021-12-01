// Created by Jeremy Bogacz on 11/30/2021
//
// This program creates a web browser that is able to
// read the state of GPIO46 and output whether a button
// has been pressed or not. GPIO46 has been configured 
// to in+.

#include <iostream>        
#include <stdlib.h>        
#include <sys/sysinfo.h>   
#include <cgicc/Cgicc.h>   
#include <cgicc/CgiDefs.h>
#include <cgicc/HTTPHTMLHeader.h>
#include <cgicc/HTMLClasses.h>
#include "GPIO.h"

using namespace std;
using namespace cgicc;
using namespace exploringBB;

int main(){
	GPIO button(46);	// Create GPIO object
	
	// Generate HTML webpage with submit button
	cout << HTTPHTMLHeader() << endl;      
	cout << html() << head() << title("Read Button") << head() << endl;
	cout << body() << h1("CPE 422 Reading a Push Button as Digital Input") << endl;
	cout << h2("Reading a Push Button on GPIO46 Via a Web Browser") << endl;
	cout << "<form action=\"/cgi-bin/read_button.cgi\" method=\"POST\">\n";
	cout << "<div><input type=\"submit\" value=\"Read Button\" />";
	cout << "</div></form>";
	cout << h3("Push Button State") << endl;
	
	// Get input value of GPIO46 and output if button is pressed or not
	if(button.getValue() == 0){
		cout << "<body>Button Pressed</body";
	}
	else if(button.getValue() == 1){
		cout << "<body>Button Not Pressed</body>";
	}	
}
