//============================================================================
// Name        : Lab4.cpp
// Author      : Alyssa Gibson
// Version     :
// Copyright   : 
// Description : Lab4 - Linux Programming
//============================================================================

#include <iostream>
#include <unistd.h>
#include <fcntl.h>
#include <string>
using namespace std;

string encrypt(string uin) {
	for (int i = 0; i < uin.length(); i++) {
		if (uin[i] == 'A' || uin[i] == 'a') {
			uin[i] = 'N';
		}
		else if (uin[i] == 'B' || uin[i] == 'b') {
			uin[i] = 'O';
		}
		else if (uin[i] == 'C' || uin[i] == 'c') {
			uin[i] = 'P';
		}
		else if (uin[i] == 'D' || uin[i] == 'd') {
			uin[i] = 'Q';
		}
		else if (uin[i] == 'E' || uin[i] == 'e') {
			uin[i] = 'R';
		}
		else if (uin[i] == 'F' || uin[i] == 'f') {
		// F to pay respects
			uin[i] = 'S';
		}
		else if (uin[i] == 'G' || uin[i] == 'g') {
			uin[i] = 'T';
		}
		else if (uin[i] == 'H' || uin[i] == 'h') {
			uin[i] = 'U';
		}
		else if (uin[i] == 'I' || uin[i] == 'i') {
			uin[i] = 'V';
		}
		else if (uin[i] == 'J' || uin[i] == 'j') {
			uin[i] = 'W';
		}
		else if (uin[i] == 'K' || uin[i] == 'k') {
			uin[i] = 'X';
		}
		else if (uin[i] == 'L' || uin[i] == 'l') {
			uin[i] = 'Y';
		}
		else if (uin[i] == 'M' || uin[i] == 'm') {
			uin[i] = 'Z';
		}
		else if (uin[i] == 'N' || uin[i] == 'n') {
			uin[i] = 'A';
		}
		else if (uin[i] == 'O' || uin[i] == 'o') {
			uin[i] = 'B';
		}
		else if (uin[i] == 'P' || uin[i] == 'p') {
			uin[i] = 'C';
		}
		else if (uin[i] == 'Q' || uin[i] == 'q') {
			uin[i] = 'D';
		}
		else if (uin[i] == 'R' || uin[i] == 'r') {
			uin[i] = 'E';
		}
		else if (uin[i] == 'S' || uin[i] == 's') {
			uin[i] = 'F'; // to pay respects
		}
		else if (uin[i] == 'T' || uin[i] == 't') {
			uin[i] = 'G';
		}
		else if (uin[i] == 'U' || uin[i] == 'u') {
			uin[i] = 'H';
		}
		else if (uin[i] == 'V' || uin[i] == 'v') {
			uin[i] = 'I';
		}
		else if (uin[i] == 'W' || uin[i] == 'w') {
			uin[i] = 'J';
		}
		else if (uin[i] == 'X' || uin[i] == 'x') {
			uin[i] = 'K';
		}
		else if (uin[i] == 'Y' || uin[i] == 'y') {
			uin[i] = 'L';
		}
		else if (uin[i] == 'Z' || uin[i] == 'z') {
			uin[i] = 'M';
		}
	}
	return uin;
}

int main() {
	string uin;
	int mypipe[2];
	pipe(mypipe);
	if(!fork()) {
		while (uin != "QUIT") {
			dup2(mypipe[1], STDOUT_FILENO);
			cin >> uin;
			cout << encrypt(uin) << endl;
			close(mypipe[0]);
		}
	}
	else {
		dup2(mypipe[0], STDIN_FILENO);
		string mystring;
		cin >> mystring;
		int newfd = open("/tmp/hello", O_CREAT | O_WRONLY, S_IRWXU);
		cout << "From the parent:  " << mystring << endl;
		write(newfd, mystring.c_str(), mystring.length());
		close(mypipe[1]);
	}
	sleep(5);
	return 0;
}
