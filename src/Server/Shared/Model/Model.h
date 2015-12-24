/*
 * Model.h
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_DATABASES_MODEL_H_
#define SRC_SERVER_SHARED_DATABASES_MODEL_H_

class Model {

public:
	Model();
	virtual ~Model();

	int getSessionListenerType() const;
	void setSessionListenerType(int sessionListenerType);

	void disconnect();

    bool isOnline() const;

protected:
	int sessionListenerType;
	bool updateData;

	bool online;

};

#endif /* SRC_SERVER_SHARED_DATABASES_MODEL_H_ */
