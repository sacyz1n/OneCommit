// SQLTest.cpp : �� ���Ͽ��� 'main' �Լ��� ���Ե˴ϴ�. �ű⼭ ���α׷� ������ ���۵ǰ� ����˴ϴ�.
//

#include <Windows.h>
#include <sql.h>
#include <sqlext.h>
#include <iostream>

int main()
{
	// DB Info
	std::string mDBName = "LoginDB";
	std::string mDBId = "root";
	std::string mDBPwd = "root";

	// Handle
	SQLHENV     mEnvironment = NULL;    // Handle ODBC enviroment

	/*
	* ȯ��, ����, �׸��� ��ɹ� �ڵ��� ���� �޸𸮸� �Ҵ��ϰ� �ʱ�ȭ �Ѵ�.
	*/
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &mEnvironment) == SQL_ERROR)
		return -1;

	/*
	 * ODBC: Version: Set
	 * (���� ȯ�濡 ���� ȯ�� �Ӽ��� �����Ѵ�.)
	 */
	if (SQLSetEnvAttr(mEnvironment, SQL_ATTR_ODBC_VERSION, reinterpret_cast<SQLPOINTER>(SQL_OV_ODBC3), 0) == SQL_ERROR)
		return -1;


	if (NULL == mEnvironment)
		return -1;

	// Connection �Ҵ�
	// DBC: Allocate
	SQLHDBC DBConnection = nullptr;
	if (SQLAllocHandle(SQL_HANDLE_DBC, mEnvironment, &DBConnection) == SQL_ERROR)
		return -1;

	/*
	 * DB���� ������ �����Ѵ�.
	 */
	if (SQLConnectA(DBConnection, reinterpret_cast<SQLCHAR*>(const_cast<char*>(mDBName.c_str())), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(const_cast<char*>(mDBId.c_str())), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(const_cast<char*>(mDBPwd.c_str())), SQL_NTS) != SQL_SUCCESS)
		return -1;

	SQLHSTMT    mStmt = NULL;   // Handle statement
	SQLAllocHandle(SQL_HANDLE_STMT, DBConnection, &mStmt);

	//// ����
	//SQLRETURN ret = SQLExecDirect(mStmt, (SQLWCHAR*)L"insert into account (userId, password, Loggedin) values ('test2', '1234', 0)", SQL_NTS);

	//// �˻�
	//std::string id("tste23");
	//std::string query = "select * from account where userId = '" + id + "'";
	//SQLRETURN ret = SQLExecDirectA(mStmt, (SQLCHAR*)query.c_str(), SQL_NTS);


	std::string query = "update account set Loggedin = 1 where id = 1";
	SQLRETURN ret = SQLExecDirectA(mStmt, (SQLCHAR*)query.c_str(), SQL_NTS);


	// Release
	SQLDisconnect(DBConnection);
	SQLFreeHandle(SQL_HANDLE_STMT, mStmt);
	SQLFreeHandle(SQL_HANDLE_DBC, DBConnection);
	SQLFreeHandle(SQL_HANDLE_ENV, mEnvironment);
}

