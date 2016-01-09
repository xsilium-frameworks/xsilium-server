/*
 * LogManagerTest.cpp
 *
 *  Created on: 9 janv. 2016
 *      Author: joda
 */

#ifndef TEST_LOGMANAGER
#define TEST_LOGMANAGER


#include <boost/test/auto_unit_test.hpp>
#include <boost/test/output_test_stream.hpp>
#include <Manager/Log/LogManager.h>


BOOST_AUTO_TEST_SUITE(LogManagerTest)

struct cout_redirect {
    cout_redirect( std::streambuf * new_buffer )
        : old( std::cout.rdbuf( new_buffer ) )
    { }

    ~cout_redirect( ) {
        std::cout.rdbuf( old );
    }

private:
    std::streambuf * old;
};


BOOST_AUTO_TEST_CASE(testError)
{


    LogManager * logManager = LogManager::getInstance();
    logManager->start(LogManager::DEBUG);

    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        logManager->write(LogManager::ERROR,"");
    }

    BOOST_CHECK( !output.is_empty());

    LogManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testWarning)
{


    LogManager * logManager = LogManager::getInstance();
    logManager->start(LogManager::DEBUG);

    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        logManager->write(LogManager::WARNING,"");
    }

    BOOST_CHECK( !output.is_empty());

    LogManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testInfo)
{


    LogManager * logManager = LogManager::getInstance();
    logManager->start(LogManager::DEBUG);

    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        logManager->write(LogManager::INFO,"");
    }

    BOOST_CHECK( !output.is_empty());

    LogManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testConfig)
{


    LogManager * logManager = LogManager::getInstance();
    logManager->start(LogManager::DEBUG);

    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        logManager->write(LogManager::CONFIG,"");
    }

    BOOST_CHECK( !output.is_empty());

    LogManager::DestroyInstance();
}

BOOST_AUTO_TEST_CASE(testDebug)
{


    LogManager * logManager = LogManager::getInstance();
    logManager->start(LogManager::DEBUG);

    boost::test_tools::output_test_stream output;
    {
        cout_redirect guard( output.rdbuf( ) );
        logManager->write(LogManager::DEBUG,"");
    }

    BOOST_CHECK( !output.is_empty());

    LogManager::DestroyInstance();
}

BOOST_AUTO_TEST_SUITE_END()

#endif


