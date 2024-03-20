#include <iostream>
#include <fstream>
#include <string>
using namespace std;

struct Player {
	string nickname;
	int age;
	double scores[5];

	void Display() {
		cout << "\n----------------------------------\n";
		cout << "Nickname: " << nickname << "\n";
		cout << "Age: " << age << "\n";
		cout << "\nScores: ";
		for (int i = 0; i < 5; ++i) {
			cout << scores[i] << " ";
		}
		cout << "\n----------------------------------\n";
	}
};

struct Node {
	Player playerData;
	Node* next;
};

int MainMenu();
void AddPlayer(Player&);
void AddRecord(Player&, Node*&, Node*&);
void ViewRecords(Node*&);
void ComputeAverage(Node*&);
void ShowMaxAverage(Node*&);
void ShowMinAverage(Node*&);
void OpenFile(Node*&);
void CloseFile();

int main() {
	int choice;
	Player playerDataHolder;
	Node* head = NULL, * tail = NULL; 

	do {
		do {
			choice = MainMenu();
		} while (choice < 1 || choice > 8);

		switch (choice)
		{
		case 1:
			AddPlayer(playerDataHolder);
			AddRecord(playerDataHolder, head, tail);
			break;
		case 2:
			ViewRecords(head);
			break;
		case 3:
			ComputeAverage(head);
			break;
		case 4:
			ShowMaxAverage(head);
			break;
		case 5:
			ShowMinAverage(head);
			break;
		case 6:
			OpenFile(head);
			break;
		case 7:
			CloseFile();
			break;
		case 8:
			cout << "Thank you for using the program!\n";
			system("pause");
			exit(0);
		default:
			break;
		}
	} while (true);
	return 0;
}

int MainMenu() {
	int menuChoice;

	cout << "==============================================\n"
		<< "                     MENU\n"
		<< "==============================================\n"
		<< "1. Add record\n"
		<< "2. View players records\n"
		<< "3. Compute for the average\n"
		<< "4. Show the player(s) who gets the max average.\n"
		<< "5. Show the player(s) who gets the min average.\n"
		<< "6. Open the file.\n"
		<< "7. Close the File\n"
		<< "8. Exit\n"
		<< "\nEnter choice here: ";
	cin >> menuChoice;

	system("pause");
	system("CLS");

	return menuChoice;
}

void AddPlayer(Player& playerInfo) {

	cout << "Enter player name: ";
	cin >> playerInfo.nickname;
	cout << "Enter player age: ";
	cin >> playerInfo.age;
	cout << "Enter player scores (5 scores)\n\n";
	for (int i = 0; i < 5; ++i) {
		cout << "Player score " << i + 1 << " : ";
		cin >> playerInfo.scores[i];
	}
}

void AddRecord(Player& playerInfo, Node*& head, Node*& tail) {
	Node* temp = new Node;

	temp->playerData = playerInfo;
	temp->next = NULL;

	if (!head) {
		head=temp;
	}
	else 
		tail->next = temp;
		tail = temp;
		system("pause");
		system("CLS");
}

void ViewRecords(Node*& head) {
	Node* temp = head;

	if (!head) {
		cout << "No data yet!";
	}
	else {
		while (temp) {
			temp->playerData.Display();
			temp = temp->next;
		}
	}
	system("pause");
	system("CLS");
}

void ComputeAverage(Node*& head) {
	Node* temp = head;
	double sum, average;

	if (!head) {
		cout << "No data yet!";
	}
	else {
		while (temp != nullptr) {
			sum = 0;
			for (int i = 0; i < 5; ++i) {
				sum += temp->playerData.scores[i];
			}
			average = sum / 5.0;
			cout << "\n----------------------------------\n";
			cout << "Nickname: " << temp->playerData.nickname;
			cout << "\nAverage Score: " << average;
			cout << "\n----------------------------------\n";
			temp = temp->next;
		}
	}
	system("pause");
	system("CLS");
}

void ShowMaxAverage(Node*& head) {
	Node* temp = head;
	double maxAverage = -1;
	double sum, average;

	while (temp != nullptr) {
		sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += temp->playerData.scores[i];
		}
		average = sum / 5.0;
		if (average > maxAverage) {
			maxAverage = average;
		}
		temp = temp->next;
	}

	temp = head;
	while (temp != nullptr) {
		sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += temp->playerData.scores[i];
		}
		average = sum / 5.0;
		if (average == maxAverage) {
			cout << "\n----------------------------------\n"; 
			cout << "Nickname: " << temp->playerData.nickname;
			cout << "\nAverage Score: " << average;
			cout << "\n----------------------------------\n";
		}
		temp = temp->next;
	}
	system("pause");
	system("CLS");

}

void ShowMinAverage(Node*& head) {
	Node* temp = head;
	double minAverage = 100; 
	double sum, average;

	while (temp != nullptr) {
		sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += temp->playerData.scores[i];
		}
		average = sum / 5.0;
		if (average < minAverage) {
			minAverage = average;
		}
		temp = temp->next;
	}

	temp = head;
	while (temp != nullptr) {
		sum = 0;
		for (int i = 0; i < 5; ++i) {
			sum += temp->playerData.scores[i];
		}
		average = sum / 5.0;
		if (average == minAverage) {
			cout << "\n----------------------------------\n";
			cout << "Nickname: " << temp->playerData.nickname;
			cout << "\nAverage Score: " << average;
			cout << "\n----------------------------------\n";
		}
		temp = temp->next;
	}

	system("pause");
	system("CLS");

}

void OpenFile(Node*& head) {
	ofstream outFile("player_records.txt");
	Node* temp = head;

	while (temp != nullptr) {
		outFile << "\n-------------------------------\n";
		outFile << temp->playerData.nickname << "\n";
		outFile << temp->playerData.age << "\n";
		for (int i = 0; i < 5; ++i) {
			outFile << temp->playerData.scores[i] << " ";
		}
		outFile << "\n";
		temp = temp->next;
	}
	outFile.close();
	cout << "Records saved to 'player_records.txt'." << endl;
}

void CloseFile() {
	cout << "File closed." << endl;
}