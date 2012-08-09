/*
 * \file Callback.h
 *
 *  Created on: \date 8 aožt 2012
 *      Author: \author joda
 *  \brief :
 */

#ifndef CALLBACK_H_
#define CALLBACK_H_

/*
 *
 */

class CallbackMaster
{
public:
virtual ~CallbackMaster(){};
virtual void Call()=0;
};


template <class TClass>

class Callback : public CallbackMaster {
public:
	Callback(TClass* _Object, void(TClass::*_fpt)())
	{
		Object = _Object;
		fpt=_fpt;
	};
	virtual ~Callback(){};

	virtual void Call()
	{
		(*Object.*fpt)();
	};

private:

	void (TClass::*fpt)();
	TClass* Object;


};

#endif /* CALLBACK_H_ */
