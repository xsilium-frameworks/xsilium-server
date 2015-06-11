/*
 * \file SessionListener.h
 *
 *  Created on: \date 25 mai 2015
 *      Author: \author joda
 *  \brief :
 */
#ifndef SRC_SERVER_SHARED_SESSION_SESSIONLISTENER_H_
#define SRC_SERVER_SHARED_SESSION_SESSIONLISTENER_H_

/*
 *
 */
class SessionListener {
public:
	SessionListener();
	virtual ~SessionListener();

	int getSessionListenerType() const;
	void setSessionListenerType(int sessionListenerType);

protected:
	int sessionListenerType ;
};

#endif /* SRC_SERVER_SHARED_SESSION_SESSIONLISTENER_H_ */
