#include <iostream>
#include <pqxx/pqxx>
#include <string>
#include <vector>
#include <fstream>

using namespace std;
using namespace pqxx;

int main(int argc, char* argv[]) {
	try {
		string ip, user, passwd;
		cout << "Enter PostgreSQL server IP address : " << endl;
		getline(cin, ip);
		cout << "Enter Username : " << endl;
		getline(cin, user);
		cout << "Enter Password : " << endl;
		getline(cin, passwd);

		string connection_string("dbname = postgres user = " + user + " password = " + passwd + " hostaddr = " + ip + " port = 5432");
		//string connection_string("dbname = postgres user = postgres password = admin hostaddr = 127.0.0.1 port = 5432");
		pqxx::connection C(connection_string.c_str());	//To connect postgreSQL database
		if (C.is_open()) {
			cout << "Connection Successful!" << endl;
		}
		else {
			cout << "Connection Failed!" << endl;
			return 1;
		}
		
		while (1) {

			string sql;
			cout << "Enter SQL querry:" << endl;
			getline(cin, sql);

			pqxx::work wrk(C);
			pqxx::result res = wrk.exec(sql);		// To execute SQL query 
			//result PrintTuples(res);
			if (res.size() < 1)
			{
				C.disconnect();						//To disconnect from postgreSQL
				cout << "Connection closed" << endl;
				return 1;
			}
			cout << "personid\t" << "lastname\t" << "firstname\t" << "address\t\t" << "city\t" << endl;
			for (int i = 0; i < res.size(); i++)
			{
				cout << res[i][0] << "\t\t" << res[i][1] << "\t\t" << res[i][2] << "\t\t" << res[i][3] << "\t\t" << res[i][4] << "\t\t" << endl;
			}
		}
	}

	catch (const std::exception & e) {
		cerr << e.what() << std::endl;
		return 1;
	}
}