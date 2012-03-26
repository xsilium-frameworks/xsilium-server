/*!
 * \file PostgreSQLInterface.h
 * \brief
 * \author joda2
 *
 */

#ifndef __POSTGRESQL_INTERFACE_H
#define __POSTGRESQL_INTERFACE_H

struct pg_conn;
typedef struct pg_conn PGconn;

struct pg_result;
typedef struct pg_result PGresult;

#include "RakString.h"
#include "DS_OrderedList.h"

// libpq-fe.h is part of PostgreSQL which must be installed on this computer to use the PostgreRepository
#include "libpq-fe.h"


/*! \class PostgreSQLInterface
 * \brief
 *
 */
class PostgreSQLInterface
{
public:
    /*!
     *  \brief PostgreSQLInterface
     *
     *  Constructeur de la classe PostgreSQLInterface
     *
     *  \param
     */
	PostgreSQLInterface();
    /*!
     *  \brief ~PostgreSQLInterface
     *
     *  Destructeur de la classe PostgreSQLInterface
     *
     *  \param
     */
	virtual ~PostgreSQLInterface();
    /*!
     *  \brief Connect
     *
     *  Connect to the database using the connection string
     *  param[in] conninfo See the postgre docs
     *  \return True on success, false on failure.
     *
     *  \param
     */
	bool Connect(const char *conninfo);

    /*!
     *  \brief AssignConnection
     *
     *  Use a connection allocated elsewehre
     *
     *  \param
     */
	void AssignConnection(PGconn *_pgConn);

    /*!
     *  \brief GetPGConn
     *
     *  Get the instance of PGconn
     *
     *  \param
     */
	PGconn *GetPGConn(void) const;

	   /*!
	     *  \brief Disconnect
	     *
	     *  Disconnect from the database
	     *
	     *  \param
	     */
	void Disconnect(void);

	   /*!
	     *  \brief GetLastError
	     *
	     *  If any of the above functions fail, the error string is stored internally.  Call this to get it.
	     *
	     *  \param
	     */
	virtual const char *GetLastError(void) const;
	   /*!
	     *  \brief GetEpoch
	     *
	     *  Returns  DEFAULT EXTRACT(EPOCH FROM current_timestamp))
	     *
	     *  \param
	     */
	long long GetEpoch(void);
	   /*!
	     *  \brief GetLocalTimestamp
	     *
	     *  Returns a string containing LOCALTIMESTAMP on the server
	     *
	     *  \param
	     */
	char *GetLocalTimestamp(void);

	static bool PQGetValueFromBinary(int *output, PGresult *result, unsigned int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(int *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(unsigned int *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(long long *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(float *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(double *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(bool *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(RakNet::RakString *output, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(char **output, unsigned int *outputLength, PGresult *result, int rowIndex, const char *columnName);
	static bool PQGetValueFromBinary(char **output, int *outputLength, PGresult *result, int rowIndex, const char *columnName);

	static void EncodeQueryInput(const char *colName, unsigned int value, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryInput(const char *colName, bool value, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryInput(const char *colName, int value, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryInput(const char *colName, float value, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryInput(const char *colName, char *binaryData, int binaryDataLength, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat, bool writeEmpty);
	static void EncodeQueryInput(const char *colName, const char *str, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat, bool writeEmpty, const char *type = "text");
	static void EncodeQueryInput(const char *colName, const RakNet::RakString &str, RakNet::RakString &paramTypeStr, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat, bool writeEmpty, const char *type = "text");

	static void EncodeQueryUpdate(const char *colName, unsigned int value, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryUpdate(const char *colName, int value, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryUpdate(const char *colName, float value, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryUpdate(const char *colName, char *binaryData, int binaryDataLength, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat);
	static void EncodeQueryUpdate(const char *colName, const char *str, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat, const char *type = "text");
	static void EncodeQueryUpdate(const char *colName, const RakNet::RakString &str, RakNet::RakString &valueStr, int &numParams, char **paramData, int *paramLength, int *paramFormat, const char *type = "text");

	// Standard query
	PGresult * QueryVariadic( const char *input, ... );
	static void ClearResult(PGresult *result);

	// Pass queries to the server
	bool ExecuteBlockingCommand(const char *command, PGresult **result, bool rollbackOnFailure);
	bool IsResultSuccessful(PGresult *result, bool rollbackOnFailure);
	void Rollback(void);
	static void EndianSwapInPlace(char* data, int dataLength);
	RakNet::RakString GetEscapedString(const char *input) const;
protected:	

	PGconn *pgConn;
	bool pgConnAllocatedHere;
	bool isConnected;
	char lastError[1024];

	// Connection parameters
	RakNet::RakString _conninfo;

	//	DataStructures::List<RakNet::RakString> preparedStatements;
	DataStructures::List<RakNet::RakString> preparedQueries;
};

#endif
