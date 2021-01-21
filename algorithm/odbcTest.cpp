// SQLTest.cpp : 이 파일에는 'main' 함수가 포함됩니다. 거기서 프로그램 실행이 시작되고 종료됩니다.
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
	* 환경, 연결, 그리고 명령문 핸들을 위한 메모리를 할당하고 초기화 한다.
	*/
	if (SQLAllocHandle(SQL_HANDLE_ENV, SQL_NULL_HANDLE, &mEnvironment) == SQL_ERROR)
		return -1;

	/*
	 * ODBC: Version: Set
	 * (현재 환경에 대한 환경 속성을 설정한다.)
	 */
	if (SQLSetEnvAttr(mEnvironment, SQL_ATTR_ODBC_VERSION, reinterpret_cast<SQLPOINTER>(SQL_OV_ODBC3), 0) == SQL_ERROR)
		return -1;


	if (NULL == mEnvironment)
		return -1;

	// Connection 할당
	// DBC: Allocate
	SQLHDBC DBConnection = nullptr;
	if (SQLAllocHandle(SQL_HANDLE_DBC, mEnvironment, &DBConnection) == SQL_ERROR)
		return -1;

	/*
	 * DB와의 연결을 설정한다.
	 */
	if (SQLConnectA(DBConnection, reinterpret_cast<SQLCHAR*>(const_cast<char*>(mDBName.c_str())), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(const_cast<char*>(mDBId.c_str())), SQL_NTS,
		reinterpret_cast<SQLCHAR*>(const_cast<char*>(mDBPwd.c_str())), SQL_NTS) != SQL_SUCCESS)
		return -1;

	SQLHSTMT    mStmt = NULL;   // Handle statement
	SQLAllocHandle(SQL_HANDLE_STMT, DBConnection, &mStmt);

	//// 삽입
	//SQLRETURN ret = SQLExecDirect(mStmt, (SQLWCHAR*)L"insert into account (userId, password, Loggedin) values ('test2', '1234', 0)", SQL_NTS);

	//// 검색
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

