/*
 * authServer.h
 *
 *  Created on: 2 févr. 2012
 *      Author: joda2
 */

#ifndef AUTHSERVER_H_
#define AUTHSERVER_H_

class authServer {
public:
	authServer();
	virtual ~authServer();

	void startThread();
	void stopThread();
	void restartThread();

	void setEndThread(bool);
	bool getEndThread();

private:
	bool endThread;








};

#endif /* AUTHSERVER_H_ */
