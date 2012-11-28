/*
 * \file Callback.h
 *
 *  Created on: \date 8 ao�t 2012
 *      Author: \author joda
 *  \brief :
 */
 /*! \class callback
   * \brief
   */
#ifndef CALLBACK_H_
#define CALLBACK_H_

/*
 *
 */

class CallbackMaster
{
public:

    /*!
     *  \brief Destructeur
     *
     *  Destructeur de la classe CallbackMaster
     *
     *  \param
     */
virtual ~CallbackMaster(){};

/*!
 *  \brief Call
 *
 *  brief ???
 *
 *  \param
 */


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
