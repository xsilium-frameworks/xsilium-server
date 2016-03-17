/*
 * Model.h
 *
 *  Created on: 15 déc. 2015
 *      Author: Aeden
 */

#ifndef SRC_SERVER_SHARED_DATABASES_MODEL_H_
#define SRC_SERVER_SHARED_DATABASES_MODEL_H_

#include <typeinfo>
#include <string>

class Model {

public:
    Model();
    virtual ~Model();

    std::string getTypeModel() const;

    bool isOnline() const;
    void setOnline(bool online);

    bool isUpdate();
    void setUpdate(bool updateData);

protected:

    bool updateData;

    bool online;

};

#endif /* SRC_SERVER_SHARED_DATABASES_MODEL_H_ */
