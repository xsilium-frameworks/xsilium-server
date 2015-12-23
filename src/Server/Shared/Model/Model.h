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

	virtual void disconnect() = 0;

protected:
	int sessionListenerType;
	bool updateData;

};

#endif /* SRC_SERVER_SHARED_DATABASES_MODEL_H_ */
